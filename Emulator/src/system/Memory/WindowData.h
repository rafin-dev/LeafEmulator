#pragma once

#define BeginTileMap1 0x9800
#define BeginTileMap2 0x9C00

#include <string>

namespace GameBoyEmulator {

	class GameBoyMemory;

	struct WindowData
	{
		int WindowX;
		int WindowY;

		uint8_t GetTile(int tile) const;

	private:

		GameBoyMemory* mem;

		friend class GameBoyMemory;
	};
}