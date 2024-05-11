#pragma once

#include "cpu/CPU.h"
#include "string"

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator();
		~Emulator();

		bool LoadROM();

		void Update();

	private:

		uint8_t GBMemory[0xFFFF];

		CPU processor;
	};
}