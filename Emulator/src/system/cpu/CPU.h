#pragma once

#include <string>
#include <map>
#include <functional>

using InstructionFunc = std::function<int(void)>;

namespace GameBoyEmulator {

	// Struct used to manage and organize the Game Boy cpu Registers
	struct GBRegisters
	{
	public:
		// 1 byte REgisters
		uint8_t A = 0;
		uint8_t F = 0;

		// sets of 2 1byte registers that can be combined into one 2byte
		uint8_t B = 0;
		uint8_t C = 0;

		uint8_t D = 0;
		uint8_t E = 0;

		uint8_t H = 0;
		uint8_t L = 0;

		// 2bytes registers
		uint16_t SP = 0;

		uint16_t PC = 0x100;

		// Getters and Setters for the register combinations
		inline uint16_t GetBC() { return Combine(B, C); }
		inline void SetBC(uint16_t value) { SetCombination(value, &B, &C); }

		inline uint16_t GetDE() { return Combine(D, E); }
		inline void SetDE(uint16_t value) { SetCombination(value, &D, &E); }

		inline uint16_t GetHL() { return Combine(H, L); }
		inline void SetHL(uint16_t value) { SetCombination(value, &H, &L); }

		inline void SetZeroFlag(bool n)
		{ 
			SetFlag(7, n);
		}

		inline void SetSubtractionFlag(bool n) 
		{ 
			SetFlag(6, n);
		}
		
		inline void SetHalfCarryFlag(bool n)
		{ 
			SetFlag(5, n);
		}
		
		inline void SetCarryFlag(bool n) 
		{ 
			SetFlag(4, n);
		}

	private:

		// functions to automate the mixing and separating of the registers, and flag setting
		uint16_t Combine(uint8_t register1, uint8_t register2);

		void SetCombination(uint16_t value, uint8_t* register1, uint8_t* register2);

		// Helper function for the flag register
		void SetFlag(int flagIndex, bool n)
		{
			// If n is true, do a simple bitmap setting
			if (n)
			{
				F | (1 << flagIndex);
			}
			else // If not, set the bit to false by left shifting 1 by the bit index, reverting all the bits in the result and ANDING(&) it with the flag register
			{
				F & (~(1 << flagIndex));
			}
		}
	};

	// CPU class
	class CPU
	{
	public:

		CPU(uint8_t* mem);

		void Step();

	private:

		// Helper functions for the ADD instructions
		void SetAddInstructionsFlags(int ADDresult);
		void ADDtoHL(uint16_t n);
		void AddtoA(uint8_t n);


		// Pointer to the memory (other objects such as the PPU will utilize the same memory)
		uint8_t* Memory;

		// CPU registers
		GBRegisters Registers;

		// Map to instruction functions definitions
		std::map<uint8_t, InstructionFunc> InstructionMap;

		// Instruction functions declarations

		// Increment functions
		// 16 bit increments
		int INC_BC();
		int INC_DE();
		int INC_HL();
		int INC_SP();

		// 8 bit increments
		int INC_B();
		int INC_D();
		int INC_H();
		// MHL stands for memory at HL, this instruction increments the byte at addres HL
		int INC_MHL();
		int INC_C();
		int INC_E();
		int INC_L();
		int INC_A();

		// Decrement functions
		// 16 bit decrements
		int DEC_BC();
		int DEC_DE();
		int DEC_HL();
		int DEC_SP();

		// 8 bit decrements
		int DEC_B();
		int DEC_D();
		int DEC_H();
		// MHL stands for memory at HL, this instruction decrements the byte at addres HL
		int DEC_MHL();
		int DEC_C();
		int DEC_E();
		int DEC_L();
		int DEC_A();

		// Arithimetical Instructions

		// ADD instructions

		// 16 bit
		int ADD_HL_BC();
		int ADD_HL_DE();
		int ADD_HL_HL();
		int ADD_HL_SP();

		// 8 bit
		int ADD_A_B();
		int ADD_A_C();
		int ADD_A_D();
		int ADD_A_E();

		CPU()
		: Memory(nullptr)
		{
		}
	};
}