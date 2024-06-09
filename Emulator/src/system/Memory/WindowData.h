#pragma once

#define BeginTileMap1 0x9800
#define BeginTileMap2 0x9C00

namespace GameBoyEmulator {

	class GameBoyMemory;

	struct WindowData
	{
		int WindowX;
		int WindowY;

		uint8_t GetTile(int tile) const
		{
			if (!mem->GetGraphicsControl().Window_TileMap_Selected)
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