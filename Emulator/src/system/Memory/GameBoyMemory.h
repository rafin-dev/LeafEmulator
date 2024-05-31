#pragma once

#include <string>

#include "system/Memory/Tile.h"
#include "system/Memory/LCDC.h"
#include "system/Memory/OBJ.h"

namespace GameBoyEmulator {

	class GameBoyMemory
	{
	public:

		GameBoyMemory();

		// Proper way to write and read data
		void WriteData(uint8_t data, uint16_t addres);
		uint8_t ReadData(uint16_t addres);

		// Simplified way to read important data from the memory
		const Tile& GetTile(uint8_t tileIndex);
		const OBJ& GetSprite(uint8_t OBJindex);
		const LCDC& GetGraphicsControl() { return GraphicsControl; }

	private:

		uint8_t Memory[0xFFFF];
		Tile Tiles[384];
		OBJ Sprites[40];
		LCDC GraphicsControl;

		void WriteVRAMdata(uint8_t data, uint16_t addres);
		void WriteOAMdata(uint8_t data, uint16_t addres);
	};
}