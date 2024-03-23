#pragma once

#include "cpu/CPU.h"
#include "string"

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator(std::string& ROMpath);

	private:

		CPU processor;
	};
}