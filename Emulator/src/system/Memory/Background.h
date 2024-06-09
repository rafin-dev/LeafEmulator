#pragma once

#include <iostream>

#define BeginTileMap1 0x9800
#define BeginTileMap2 0x9C00

namespace GameBoyEmulator {

	class GameBoyMemory;

	struct Background
	{
	public:
		uint8_t GetTile(int tile) const
		{
			if (!mem->GetGraphicsControl().BG_TileMap_Selected)
			{
				return mem->ReadData(BeginTileMap1 + tile);
			}
			else
			{
				return mem->ReadData(BeginTileMap2 + tile);
			}
		}

	private:
		GameBoyMemory* mem;

		friend class GameBoyMemory;

	};
}