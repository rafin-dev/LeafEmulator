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

		inline bool GetZeroFlag()
		{
			return GetFlag(7);
		}

		inline void SetNegativeFlag(bool n) 
		{ 
			SetFlag(6, n);
		}

		inline bool GetNegativeFlag()
		{
			return GetFlag(6);
		}
		
		inline void SetHalfCarryFlag(bool n)
		{ 
			SetFlag(5, n);
		}

		inline bool GetHalfCarryFlag()
		{
			return GetFlag(5);
		}
		
		inline void SetCarryFlag(bool n) 
		{ 
			SetFlag(4, n);
		}

		inline bool GetCarryFlag()
		{
			return GetFlag(4);
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

		bool GetFlag(int flagIndex)
		{
			return F & (1 << flagIndex);
		}
	};

	// CPU class
	class CPU
	{
	public:

		CPU(uint8_t* mem);

		void Step();

	private:

		void AddInstructionsToMap();

		// Helper functions for the ADD and ADC instructions
		void SetAddInstructionsFlags16bit(long ADDresult);
		void SetAddInstructionsFlags8bit(int ADDresult);
		void ADDtoHL(int n);
		void ADDtoA(int n);

		// Helper functions for the SUB, SBC and CP instructions
		void SetSubInstructionsFlags(int N);
		void SubFromA(int n);

		// Helper functions for the AND instructions
		void SetAndInstructionFlags(uint8_t Result);

		// Helper functions for the XOR instructions
		void SetXorInstructionFlags(uint8_t Result);

		// Helper functions for the OR instrcutions
		void SetORInstructionFlags(uint8_t Result);


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
		int ADD_SP_I8();

		// 8 bit
		int ADD_A_B();
		int ADD_A_C();
		int ADD_A_D();
		int ADD_A_E();
		int ADD_A_H();
		int ADD_A_L();
		// MHL stands for memory at HL, this instruction adds the value of HL to A
		int ADD_A_MHL();
		int ADD_A_A();
		int ADD_A_U8();

		// ADC instructions(all 8 bit), the diference to ADD is that it also adds the carry flag to the operation
		int ADC_A_B();
		int ADC_A_C();
		int ADC_A_D();
		int ADC_A_E();
		int ADC_A_H();
		int ADC_A_L();
		// MHL stands for memory at HL, this instruction adds the value of HL plus the carry flag to A
		int ADC_A_MHL();
		int ADC_A_A();
		int ADC_A_U8();

		// SUB instructions (all 8 bit)
		int SUB_A_B();
		int SUB_A_C();
		int SUB_A_D();
		int SUB_A_E();
		int SUB_A_H();
		int SUB_A_L();
		// MHL stands for memory at HL, this instruction subtracts A by the value in memory at address HL
		int SUB_A_MHL();
		int SUB_A_A();
		int SUB_A_U8();

		// SBC instructions (all 8 bit)
		int SBC_A_B();
		int SBC_A_C();
		int SBC_A_D();
		int SBC_A_E();
		int SBC_A_H();
		int SBC_A_L();
		// From now on, I will not put the usual comment on top of MHL
		int SBC_A_MHL();
		int SBC_A_A();
		int SBC_A_U8();

		// AND instructions (all 8 bit)
		int AND_A_B();
		int AND_A_C();
		int AND_A_D();
		int AND_A_E();
		int AND_A_H();
		int AND_A_L();
		int AND_A_MHL();
		int AND_A_A();
		int AND_A_U8();

		// XOR instructions (all 8 bit)
		int XOR_A_B();
		int XOR_A_C();
		int XOR_A_D();
		int XOR_A_E();
		int XOR_A_H();
		int XOR_A_L();
		int XOR_A_MHL();
		int XOR_A_A();
		int XOR_A_U8();

		// OR instruction definitions
		int OR_A_B();
		int OR_A_C();
		int OR_A_D();
		int OR_A_E();
		int OR_A_H();
		int OR_A_L();
		int OR_A_MHL();
		int OR_A_A();
		int OR_A_U8();

		// CP instructions (all 8 bit)
		int CP_A_B();
		int CP_A_C();
		int CP_A_D();
		int CP_A_E();
		int CP_A_H();
		int CP_A_L();
		int CP_A_MHL();
		int CP_A_A();
		int CP_A_U8();

		// LD instructions

		// 16 bit
		int LD_BC_U16();
		int LD_DE_U16();
		int LD_HL_U16();
		int LD_SP_U16();
		// MU16 stands for Memory at 16 bit unsigned int, write SP onto the addres u16
		int LD_MU16_SP();
		int LD_SP_HL();
		// SPpI8 stands for Sp + 8 bit integer
		int LD_HL_SPpI8();

		// 8 bit
		// M{Register name} stands for memory at the addres pointed by the register
		int LD_MBC_A();
		int LD_MDE_A();
		// The "p" after hl indicates that after writing the valeu of A into MHL, HL will be increased, "m" means decreased
		int LD_MHLp_A();
		int LD_MHLm_A();
		int LD_B_U8();
		int LD_D_U8();
		int LD_H_U8();
		int LD_MHL_U8();
		int LD_A_MBC();
		int LD_A_MDE();
		int LD_A_MHLp();
		int LD_A_MHLm();
		int LD_C_U8();
		int LD_E_U8();
		int LD_L_U8();
		int LD_A_U8();
		int LD_B_B();
		int LD_B_C();
		int LD_B_D();
		int LD_B_E();
		int LD_B_H();
		int LD_B_L();
		int LD_B_MHL();
		int LD_B_A();
		int LD_C_B();
		int LD_C_C();
		int LD_C_D();
		int LD_C_E();
		int LD_C_H();
		int LD_C_L();
		int LD_C_MHL();
		int LD_C_A();
		int LD_D_B();
		int LD_D_C();
		int LD_D_D();
		int LD_D_E();
		int LD_D_H();
		int LD_D_L();
		int LD_D_MHL();
		int LD_D_A();
		int LD_E_B();
		int LD_E_C();
		int LD_E_D();
		int LD_E_E();
		int LD_E_H();
		int LD_E_L();
		int LD_E_MHL();
		int LD_E_A();
		int LD_H_B();
		int LD_H_C();
		int LD_H_D();
		int LD_H_E();
		int LD_H_H();
		int LD_H_L();
		int LD_H_MHL();
		int LD_H_A();
		int LD_L_B();
		int LD_L_C();
		int LD_L_D();
		int LD_L_E();
		int LD_L_H();
		int LD_L_L();
		int LD_L_MHL();
		int LD_L_A();
		int LD_MHL_B();
		int LD_MHL_C();
		int LD_MHL_D();
		int LD_MHL_E();
		int LD_MHL_H();
		int LD_MHL_L();
		int LD_MHL_A();
		int LD_A_B();
		int LD_A_C();
		int LD_A_D();
		int LD_A_E();
		int LD_A_H();
		int LD_A_L();
		int LD_A_MHL();
		int LD_A_A();

		CPU()
		: Memory(nullptr)
		{
		}
	};
}