#pragma once

#include "cpu/CPU.h"
#include "string"

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator(std::string& ROMpath);
		~Emulator();

		bool LoadROM();

		void Update();

	private:

		uint8_t* GBMemory;

		CPU processor;
	};
}