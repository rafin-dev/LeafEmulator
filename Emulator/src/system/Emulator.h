#pragma once

#include "cpu/CPU.h"
#include "string"

#include "system/Memory/GameBoyMemory.h"

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator();
		~Emulator();

		bool LoadROM();

		void Update();

	private:

		GameBoyMemory GBMemory;

		CPU processor;
	};
}