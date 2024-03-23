#include "CPU.h"

namespace GameBoyEmulator {

	// CPU constructor
	CPU::CPU(uint8_t* mem)
		: Memory(mem), InstructionMap()
	{
	}

	void CPU::Step()
	{
		// Gets the firts byte of a Game Boy opcode (the first byte indicate what instruction to execute)
		uint8_t instructionNibble = Memory[Registers.PC];

		// Search for the function of the instruction in the Instructions map
		auto mappedInstruction = InstructionMap.find(instructionNibble);

		// Checks to see if the map contains a definition for the instruction
		if (mappedInstruction == InstructionMap.end())
		{
			// If it doens't, throw a exception
			throw std::exception("Unknown Instruction");
		}

		// Execute the instrcution, and also gets the amount of bytes used by that opcode
		int PCincrementAmount = mappedInstruction->second();

		// Increment PC
		Registers.PC += PCincrementAmount;
	}

	inline uint16_t GBRegisters::Combine(uint8_t register1, uint8_t register2)
	{
		return (register1 << 8) | register2;
	}

	inline void GBRegisters::SetCombination(uint16_t value, uint8_t* register1, uint8_t* register2)
	{
		*register1 = value >> 8;
		*register2 = value & 0x00FF;
	}
}