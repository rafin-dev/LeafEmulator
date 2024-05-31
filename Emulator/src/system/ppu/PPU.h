#pragma once

#include <string>

#include "system/Memory/GameBoyMemory.h"

namespace GameBoyEmulator {

	class PPU
	{
	public:

		PPU(GameBoyMemory* mem);

		void Render();

	private:

		GameBoyMemory* Memory;


	};
}