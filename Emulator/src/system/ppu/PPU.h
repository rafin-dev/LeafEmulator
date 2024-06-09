#pragma once

#include <string>

#include "system/Memory/GameBoyMemory.h"

namespace GameBoyEmulator {

	class PPU
	{
	public:

		PPU(GameBoyMemory* mem);

		void Render();

		ScreenColors GetPixel(int x, int y);

	private:

		GameBoyMemory* Memory;
		ScreenColors Pixels[144][160];


	};
}