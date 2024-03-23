#pragma once

namespace GameBoyEmulator {

	class CPU
	{
	private:
		// The system's RAM
		uint8_t Memory[8192];

		// The system's registers
		GameBoyCpuRegisters Registers;
	};

	// Struct Used to manage all the cpu registers
	struct GameBoyCpuRegisters
	{
		// Sets of 2 8bit registers that can be used as a singular 16bit register
		uint8_t A;
		uint8_t F;

		uint8_t B;
		uint8_t C;

		uint8_t D;
		uint8_t E;

		uint8_t H;
		uint8_t L;

		// The 2 16bit registers of the system
		uint16_t SP;
		uint16_t PC;

		// Inline functions used to simplificate the usage of the conbination of registers
		inline uint16_t* BC() { return (uint16_t*)&B; }
		inline uint16_t* DE() { return (uint16_t*)&D; }
		inline uint16_t* HL() { return (uint16_t*)&H; }

		GameBoyCpuRegisters()
		{
			// Making sure to clean all the registers as soon as possible
			A = 0;
			F = 0;

			B = 0;
			C = 0;

			D = 0;
			E = 0;

			H = 0;
			L = 0;

			SP = 0;
			PC = 0;
		}
	};
}