#include "system/ppu/PPU.h"

#define TilesInScreenRow (160 /8 )
#define TilesInScreenCollum (144 / 8)
#define TilesInBackgroundRow 32
#define TilesInBackgroundCollum 32

namespace GameBoyEmulator {

    PPU::PPU(GameBoyMemory* mem)
        : Memory(mem)
    {

    }

    void PPU::Render()
    {
        // Get graphics info from the memory
        const LCDC& GraphicsSettings = Memory->GetGraphicsControl();
        const Scroll& ScreenScroll = Memory->GetScreenScroll();
        const WindowData& Window = Memory->GetWindowPosition();
        const Background& background = Memory->GetBackground();

        if (!GraphicsSettings.LCD_PPU_Enabled)
        {
            return;
        }

        int firstTileCollum = (ScreenScroll.BottomRight / 8) - TilesInScreenRow;

        for (int y = 0; y < 144; y++)
        {
            for (int x = 0; x < 160; x++)
            {
                // Clear the pixel
                Pixels[y][x] = ScreenColors::White;

                // Search for all the sprites that should be rendered in the line
                const OBJ* VisibleSprites[10];
                int spritesFound = 0;

                for (int i = 0; i < 40 && spritesFound < 10; i++)
                {
                    const OBJ& sprite = Memory->GetSprite(i);

                    int SpritesHeight = GraphicsSettings.OBJ_DoubleSize_Enabled ? 16 : 8;

                    // Checks if the sprite is within the current line
                    if (sprite.X == 0)
                    {
                        return;
                    }

                    if (sprite.Y <= y && (sprite.Y + SpritesHeight) > y)
                    {
                        VisibleSprites[spritesFound] = &sprite;
                        spritesFound++;
                    }
                }
                // Adjusts the Sprite counte to actually counte the number of sprites found
                spritesFound += 1;


                bool IsPixelWindow = false;

                if (!GraphicsSettings.LCDC_0)
                {
                    if (GraphicsSettings.Window_Enabled && Window.WindowX >= x && Window.WindowY >= y)
                    {
                        // TODO: render the window

                        int cWindowRow = (y - Window.WindowY) / 8;
                        int cWindowTile = (x - Window.WindowX) / 8 + (cWindowRow * TilesInBackgroundRow);
                        int cWindowPixelx = (x - Window.WindowX) % 8;
                        int cWindowPixely = (y - Window.WindowY) % 8;

                        const Tile& tile = Memory->GetTile(Window.GetTile(cWindowTile), TileType::Background_Window);

                        Pixels[y][x] = tile.Pixels[cWindowPixely][cWindowPixelx];

                        IsPixelWindow = true;
                    }
                    else
                    {
                        int CurrentBackgroundTileRow = (ScreenScroll.TopLeft + y) / 8;
                        int CurrentTile = firstTileCollum + CurrentBackgroundTileRow + (x / 8);

                        const Tile& tile = Memory->GetTile(background.GetTile(CurrentTile), TileType::Background_Window);

                        Pixels[y][x] = tile.Pixels[(ScreenScroll.TopLeft + y) % 8][x % 8];
                    }
                }

                // Find the first sprite that appears in the pixel
                const OBJ* sprite;

                for (int i = 0; i < spritesFound; i++)
                {
                    if (VisibleSprites[i]->X <= x && (VisibleSprites[i]->X + 8) > x)
                    {
                        sprite = VisibleSprites[i];
                        break;
                    }
                }

                // Render Sprite

                int SpriteCollum = x - sprite->X;
                int SpriteRow = y - sprite->Y;

                ScreenColors pixel;

                // If the sprites have normal sizes
                if (!GraphicsSettings.OBJ_DoubleSize_Enabled)
                {
                    const Tile& objTile = Memory->GetTile(sprite->Tile, TileType::Sprite);

                    pixel = objTile.Pixels[SpriteRow][SpriteCollum];
                }
                else // If the sprites have double sizes
                {
                    const Tile* objTile;
                    if (SpriteRow > 7) // If the pixel to be rendered is in the second tile of the sprite
                    {
                        objTile = &Memory->GetTile(sprite->Tile + TilesInBackgroundRow, TileType::Sprite);
                    }
                    else // If the pixel to be rendered is in the first tile of the sprite
                    {
                        objTile = &Memory->GetTile(sprite->Tile, TileType::Sprite);
                    }

                    pixel = objTile->Pixels[SpriteRow % 8][SpriteCollum];
                }

                if (pixel != ScreenColors::White) // White pixels are "transparent" in sprites
                {
                    Pixels[y][x] = pixel;
                }

                // TODO: call interrupt on the horizontal timing
            }

            // TODO: call interrupt on the vertical timing
        }
        
        
    }

    ScreenColors PPU::GetPixel(int x, int y)
    {
        return Pixels[y][x];
    }



}