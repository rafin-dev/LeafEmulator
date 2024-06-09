#include "system/Memory/GameBoyMemory.h"

#define VRAM_START 0x8000
#define VRAM_END 0x9FFF

#define OAM_START 0xFE00
#define OAM_END 0xFE9F

namespace GameBoyEmulator {

	GameBoyMemory::GameBoyMemory()
	{
		memset(Memory, 0, sizeof(Memory));
		BG.mem = this;
	}

	void GameBoyMemory::WriteData(uint8_t data, uint16_t addres)
	{
		Memory[addres] = data;

		// Checks if the addres especified is within the VRAM
		if (VRAM_START >= addres && addres <= VRAM_END)
		{
			WriteVRAMdata(data, addres);
			return;
		}

		// Checks if the addres is within the OAM
		if (OAM_START >= addres && addres <= OAM_END)
		{
			WriteOAMdata(data, addres);
			return;
		}

		// Checks if the addres is within the scroll data
		if (addres == 0xFF42 || addres == 0xFF43)
		{
			ScreenScroll.BottomRight = (Memory[0xFF42] + 143) % 256;
			ScreenScroll.TopLeft = (Memory[0xFF43] + 159) % 256;
		}

		// Checks if the addres changes the window position data
		if (addres == 0xFF4A || addres == 0xFF4B)
		{
			Wpos.WindowY = Memory[0xFF4A];
			Wpos.WindowX = Memory[0xFF4B] - 7;
		}
	}

	uint8_t GameBoyMemory::ReadData(uint16_t addres)
	{
		return Memory[addres];
	}

	const Tile& GameBoyMemory::GetTile(uint8_t tileIndex, TileType type)
	{
		switch (type)
		{
		case GameBoyEmulator::None:
			return Tiles[tileIndex];
			break;

		case GameBoyEmulator::Sprite:
			return Tiles[tileIndex];
			break;

		case GameBoyEmulator::Background_Window:
			if (!GraphicsControl.TileData_AddresingMode_Selected)
			{
				return Tiles[tileIndex];
			}
			else
			{
				return Tiles[tileIndex + 128];
			}

			break;
		}
	}

	const OBJ& GameBoyMemory::GetSprite(uint8_t OBJindex)
	{
		return Sprites[OBJindex];
	}

	void GameBoyMemory::WriteVRAMdata(uint8_t data, uint16_t addres)
	{
		// Checks to see if the addres is NOT within tile data boundaries
		if (addres >= 9800)
		{
			return;
		}

		// Update Tiles array
		uint16_t tileIndex = (addres - VRAM_START) / 16;
		uint16_t tileRow = ((addres - VRAM_START) % 16) / 2;

		uint16_t FirstByteIndex = addres & 0xFFFE;

		uint8_t firstByte = Memory[FirstByteIndex];
		uint8_t secondByte = Memory[FirstByteIndex + 1];

		for (int i = 0; i < 8; i++)
		{
			uint8_t bitMask = 1 << (7 - i);
			bool lsb = (firstByte & bitMask) != 0;
			bool msb = (secondByte & bitMask) != 0;

			uint8_t color = (msb << 1) | lsb;

			Tiles[tileIndex].Pixels[tileRow][i] = (ScreenColors)color;
		}
	}

	void GameBoyMemory::WriteOAMdata(uint8_t data, uint16_t addres)
	{
		// Update Sprites array
		uint8_t OBJindex = (addres - OAM_START) / 3;
		uint16_t OBJbyte = (addres - OAM_START) % 3;

		switch (OBJbyte)
		{
		case 0:
			Sprites[OBJindex].Y = data;

			return;

		case 1:
			Sprites[OBJindex].X = data;

			return;

		case 2:
			Sprites[OBJindex].Priotity = data & (1 << 7);
			Sprites[OBJindex].Yflip = data & (1 << 6);
			Sprites[OBJindex].Xflip = data & (1 << 5);
			Sprites[OBJindex].Pallete = data & (1 << 4);

			return;
		}
	}

}