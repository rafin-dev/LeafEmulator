#include "Emulator.h"

namespace GameBoyEmulator {

	Emulator::Emulator(std::string& ROMpath)
		: processor(GBMemory)
	{
		memset(GBMemory, 0, sizeof(GBMemory));
	}

	void Emulator::Update()
	{

	}

}
