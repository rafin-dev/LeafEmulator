#include "Emulator.h"

namespace GameBoyEmulator {

	Emulator::Emulator(std::string& ROMpath)
		: processor(GBMemory)
	{
		GBMemory = new uint8_t[0xFFFF];
		memset(GBMemory, 0, sizeof(GBMemory));
	}

	Emulator::~Emulator()
	{
		if (GBMemory != nullptr)
		{
			delete[] GBMemory;
		}
	}

	void Emulator::Update()
	{

	}

}
