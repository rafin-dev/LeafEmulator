#pragma once

#include <string>

#include "Tile.h"
#include "LCDC.h"
#include "OBJ.h"
#include "Scroll.h"
#include "WindowData.h"
#include "Background.h"

namespace GameBoyEmulator {

	enum TileType
	{
		None = 0,
		Sprite = 1,
		Background_Window = 2
	};

	class GameBoyMemory
	{
	public:

		GameBoyMemory();

		// Proper way to write and read data
		void WriteData(uint8_t data, uint16_t addres);
		uint8_t ReadData(uint16_t addres);

		// Simplified way to read important data from the memory
		const Tile& GetTile(uint8_t tileIndex, TileType type);
		const OBJ& GetSprite(uint8_t OBJindex);
		const LCDC& GetGraphicsControl() { return GraphicsControl; }
		const Scroll& GetScreenScroll() { return ScreenScroll; }
		const WindowData& GetWindowPosition() { return Wpos; }
		const Background& GetBackground() { return BG; }

	private:

		uint8_t Memory[0xFFFF];
		Tile Tiles[384];
		OBJ Sprites[40];
		LCDC GraphicsControl;
		Scroll ScreenScroll;
		WindowData Wpos;
		Background BG;

		void WriteVRAMdata(uint8_t data, uint16_t addres);
		void WriteOAMdata(uint8_t data, uint16_t addres);
	};
}