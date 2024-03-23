#pragma once

#include <string>
#include <map>
#include <functional>

namespace GameBoyEmulator {

	// Struct used to manage and organize the Game Boy cpu Registers
	struct GBRegisters
	{
	public:

		// sets of 2 1byte registers that can be combined into one 2byte
		uint8_t A = 0;
		uint8_t F = 0;

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

	private:

		// Inline function to automate the mixing and separating of the registers
		inline uint16_t Combine(uint8_t register1, uint8_t register2);

		inline void SetCombination(uint16_t value, uint8_t* register1, uint8_t* register2);
	};

	// CPU class
	class CPU
	{
	public:

		CPU(uint8_t* mem);

		void Step();

	private:

		// Pointer to the memory (other objects such as the PPU will utilize the same memory)
		uint8_t* Memory;

		// CPU registers
		GBRegisters Registers;

		// Map to instruction functions definitions
		std::map<uint8_t, std::function<int(void)>> InstructionMap;

		// Instruction functions declarations
		int ADD();

		CPU() {}
	};
}