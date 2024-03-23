#pragma once

#include "cpu/CPU.h"
#include "string"

#define KILOBYTE 1024

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator(std::string& ROMpath);

	private:

		uint8_t Memory[65536];

		CPU processor;
	};
}