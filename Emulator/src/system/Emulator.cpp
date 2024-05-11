#include "Emulator.h"

namespace GameBoyEmulator {

	Emulator::Emulator()
		: processor(GBMemory)
	{
		memset(GBMemory, 0, sizeof(GBMemory));
	}

	Emulator::~Emulator()
	{

	}

	void Emulator::Update()
	{

	}

}
