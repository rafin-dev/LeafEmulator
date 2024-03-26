#include "CPU.h"

// Define to help passing a method as function pointer
#define ADDFUNC(x) std::bind(&CPU::x, this)
#define MAPPAIR(...) std::make_pair<uint8_t, InstructionFunc>(__VA_ARGS__)

namespace GameBoyEmulator {

	// CPU constructor
	CPU::CPU(uint8_t* mem)
		: Memory(mem), InstructionMap()
	{
		// Sets all the instruction functions on the map

		// Increment Instructions
		
		// 16 bit increments
		InstructionMap.insert(MAPPAIR(0x03, ADDFUNC(INC_BC)));
		InstructionMap.insert(MAPPAIR(0x13, ADDFUNC(INC_DE)));
		InstructionMap.insert(MAPPAIR(0x23, ADDFUNC(INC_HL)));
		InstructionMap.insert(MAPPAIR(0x33, ADDFUNC(INC_SP)));

		// 8 bit increments
		InstructionMap.insert(MAPPAIR(0x04, ADDFUNC(INC_B)));
		InstructionMap.insert(MAPPAIR(0x14, ADDFUNC(INC_D)));
		InstructionMap.insert(MAPPAIR(0x25, ADDFUNC(INC_H)));
		InstructionMap.insert(MAPPAIR(0x34, ADDFUNC(INC_MHL)));
		InstructionMap.insert(MAPPAIR(0x0C, ADDFUNC(INC_C)));
		InstructionMap.insert(MAPPAIR(0x1C, ADDFUNC(INC_E)));
		InstructionMap.insert(MAPPAIR(0x2C, ADDFUNC(INC_L)));
		InstructionMap.insert(MAPPAIR(0x3C, ADDFUNC(INC_A)));

		// Decrement Instructions

		// 16 bit decrements
		InstructionMap.insert(MAPPAIR(0x0B, ADDFUNC(DEC_BC)));
		InstructionMap.insert(MAPPAIR(0x1B, ADDFUNC(DEC_DE)));
		InstructionMap.insert(MAPPAIR(0x2B, ADDFUNC(DEC_HL)));
		InstructionMap.insert(MAPPAIR(0x3B, ADDFUNC(DEC_SP)));

		// 8 bit decrements
		InstructionMap.insert(MAPPAIR(0x05, ADDFUNC(DEC_B)));
		InstructionMap.insert(MAPPAIR(0x15, ADDFUNC(DEC_D)));
		InstructionMap.insert(MAPPAIR(0x25, ADDFUNC(DEC_H)));
		InstructionMap.insert(MAPPAIR(0x35, ADDFUNC(DEC_MHL)));
		InstructionMap.insert(MAPPAIR(0x0D, ADDFUNC(DEC_C)));
		InstructionMap.insert(MAPPAIR(0x1D, ADDFUNC(DEC_E)));
		InstructionMap.insert(MAPPAIR(0x2D, ADDFUNC(DEC_L)));
		InstructionMap.insert(MAPPAIR(0x3D, ADDFUNC(DEC_A)));

		// ADD Instructions

		// 16 bit ADDs
		InstructionMap.insert(MAPPAIR(0x09, ADDFUNC(ADD_HL_BC)));
		InstructionMap.insert(MAPPAIR(0x09, ADDFUNC(ADD_HL_BC)));
		InstructionMap.insert(MAPPAIR(0x29, ADDFUNC(ADD_HL_HL)));
		InstructionMap.insert(MAPPAIR(0x39, ADDFUNC(ADD_HL_SP)));
		InstructionMap.insert(MAPPAIR(0xE8, ADDFUNC(ADD_SP_I8)));

		// 8 bit ADDs
		InstructionMap.insert(MAPPAIR(0x80, ADDFUNC(ADD_A_B)));
		InstructionMap.insert(MAPPAIR(0x81, ADDFUNC(ADD_A_C)));
		InstructionMap.insert(MAPPAIR(0x82, ADDFUNC(ADD_A_D)));
		InstructionMap.insert(MAPPAIR(0x83, ADDFUNC(ADD_A_E)));
		InstructionMap.insert(MAPPAIR(0x84, ADDFUNC(ADD_A_H)));
		InstructionMap.insert(MAPPAIR(0x85, ADDFUNC(ADD_A_L)));
		InstructionMap.insert(MAPPAIR(0x86, ADDFUNC(ADD_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x87, ADDFUNC(ADD_A_A)));
		InstructionMap.insert(MAPPAIR(0xC6, ADDFUNC(ADD_A_U8)));

		// ADC instructions(all 8 bit)
		InstructionMap.insert(MAPPAIR(0x88, ADDFUNC(ADC_A_B)));
		InstructionMap.insert(MAPPAIR(0x89, ADDFUNC(ADC_A_C)));
		InstructionMap.insert(MAPPAIR(0x8A, ADDFUNC(ADC_A_D)));
		InstructionMap.insert(MAPPAIR(0x8B, ADDFUNC(ADC_A_E)));
		InstructionMap.insert(MAPPAIR(0x8C, ADDFUNC(ADC_A_H)));
		InstructionMap.insert(MAPPAIR(0x8D, ADDFUNC(ADC_A_L)));
		InstructionMap.insert(MAPPAIR(0x8E, ADDFUNC(ADC_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x8F, ADDFUNC(ADC_A_A)));
		InstructionMap.insert(MAPPAIR(0xCE, ADDFUNC(ADC_A_U8)));

		// SUB instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0x90, ADDFUNC(SUB_A_B)));
		InstructionMap.insert(MAPPAIR(0x91, ADDFUNC(SUB_A_C)));
		InstructionMap.insert(MAPPAIR(0x92, ADDFUNC(SUB_A_D)));
		InstructionMap.insert(MAPPAIR(0x93, ADDFUNC(SUB_A_E)));
		InstructionMap.insert(MAPPAIR(0x94, ADDFUNC(SUB_A_H)));
		InstructionMap.insert(MAPPAIR(0x95, ADDFUNC(SUB_A_L)));
		InstructionMap.insert(MAPPAIR(0x96, ADDFUNC(SUB_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x97, ADDFUNC(SUB_A_A)));
		InstructionMap.insert(MAPPAIR(0xD6, ADDFUNC(SUB_A_U8)));
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
#ifdef DEBUG
			// If it doens't, throw a exception
			throw std::exception("Unknown Instruction");
#endif // DEBUG
		}

		// Execute the instrcution, and also gets the amount of bytes used by that opcode
		int PCincrementAmount = mappedInstruction->second();

		// Increment PC
		Registers.PC += PCincrementAmount;
	}

	uint16_t GBRegisters::Combine(uint8_t register1, uint8_t register2)
	{
		return (register1 << 8) | register2;
	}

	void GBRegisters::SetCombination(uint16_t value, uint8_t* register1, uint8_t* register2)
	{
		*register1 = value >> 8;
		*register2 = value & 0x00FF;
	}
}