#pragma once

#include <string>
#include <map>
#include <unordered_map>
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

		// Interrup Master Enabled
		bool IME = false;

		void SetIMEnextCycle()
		{
			SetIME = true;
			CycleCounter = 1;
		}

		void CancelIMEupdate()
		{
			SetIME = false;
			CycleCounter = 0;
		}

		void UpdateIME()
		{
			if (SetIME)
			{
				CycleCounter--;
				if (CycleCounter == 0)
				{
					IME = true;
					SetIME = false;
				}
			}
		}

		// Getters and Setters for the register combinations
		inline uint16_t GetBC() { return Combine(B, C); }
		inline void SetBC(uint16_t value) { SetCombination(value, &B, &C); }

		inline uint16_t GetDE() { return Combine(D, E); }
		inline void SetDE(uint16_t value) { SetCombination(value, &D, &E); }

		inline uint16_t GetHL() { return Combine(H, L); }
		inline void SetHL(uint16_t value) { SetCombination(value, &H, &L); }

		inline uint16_t GetAF() { return Combine(A, F); }
		inline void SetAF(uint16_t value) { SetCombination(value, &A, &F); }

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

		int CycleCounter = 0;
		bool SetIME = false;

		// functions to automate the mixing and separating of the registers, and flag setting
		uint16_t Combine(uint8_t register1, uint8_t register2);

		void SetCombination(uint16_t value, uint8_t* register1, uint8_t* register2);

		// Helper function for the flag register
		void SetFlag(int flagIndex, bool n)
		{
			// If n is true, do a simple bitmap setting
			if (n)
			{
				F = F | (1 << flagIndex);
			}
			else // If not, set the bit to false by left shifting 1 by the bit index, reverting all the bits in the result and ANDING(&) it with the flag register
			{
				F = F & (~(1 << flagIndex));
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

		~CPU();

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

		// Helper functiosn for flow control instructiosn
		void PushIntoStack(uint16_t value);
		uint16_t PopFromStack();

		// Helper functions for bit shifitng instructions
		void RLC8bitRegister(uint8_t* reg);
		void RRC8bitRegister(uint8_t* reg);
		void RL8bitRegister(uint8_t* reg);
		void RR8bitRegister(uint8_t* reg);
		void SLA8bitRegister(uint8_t* reg);
		void SRA8bitRegister(uint8_t* reg);
		void SWAP8bitRegister(uint8_t* reg);
		void SRL8bitRegister(uint8_t* reg);

		// Helper functions for the BIT instructions
		void BIT_u3_8bitRegister(uint8_t u3, uint8_t* reg);

		// Pointer to the memory (other objects such as the PPU will utilize the same memory)
		uint8_t* Memory;

		// CPU registers
		GBRegisters Registers;

		// Map to instruction functions definitions
		std::unordered_map<uint8_t, InstructionFunc> InstructionMap;
		std::unordered_map<uint8_t, InstructionFunc> PrefixedInstructionMap;

		bool Halted = false;

		int DecodePrefixedOpcode();

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

		// Miscelanious instructions

		int CCF();
		int SCF();
		int CPL();
		int DAA();
		int NOP();
		int STOP();
		int EI();
		int DI();

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
		int LD_A_MU16();
		int LD_MU16_A();
		int LD_A_0xFFU8();
		int LD_0xFFU8_A();
		int LD_A_0xFFRC();
		int LD_0xFFRC_A();

		// Flow control instructions
		int JP_U16();
		int JP_HL();
		int JP_C_U16();
		int JP_Z_U16();
		int JP_NC_U16();
		int JP_NZ_U16();
		int JR_I8();
		int JR_Z_I8();
		int JR_C_I8();
		int JR_NZ_I8();
		int JR_NC_I8();
		int CALL_U16();
		int CALL_Z_U16();
		int CALL_C_U16();
		int CALL_NZ_U16();
		int CALL_NC_U16();
		int RET();
		int RET_Z();
		int RET_C();
		int RET_NZ();
		int RET_NC();
		int RETI();
		int RST_0x00();
		int RST_0x10();
		int RST_0x20();
		int RST_0x30();
		int RST_0x08();
		int RST_0x18();
		int RST_0x28();
		int RST_0x38();
		int HALT();

		// Stack, Push and Pop
		int PUSH_BC();
		int PUSH_DE();
		int PUSH_HL();
		int PUSH_AF();
		int POP_BC();
		int POP_DE();
		int POP_HL();
		int POP_AF();

		// Bit Shift instructions (not prefixed)
		int RRCA();
		int RRA();
		int RLCA();
		int RLA();

		// Prefixed instructions

		// Bit Shift instructions
		int RLC_B();
		int RLC_C();
		int RLC_D();
		int RLC_E();
		int RLC_H();
		int RLC_L();
		int RLC_MHL();
		int RLC_A();

		int RRC_B();
		int RRC_C();
		int RRC_D();
		int RRC_E();
		int RRC_H();
		int RRC_L();
		int RRC_MHL();
		int RRC_A();

		int RL_B();
		int RL_C();
		int RL_D();
		int RL_E();
		int RL_H();
		int RL_L();
		int RL_MHL();
		int RL_A();

		int RR_B();
		int RR_C();
		int RR_D();
		int RR_E();
		int RR_H();
		int RR_L();
		int RR_MHL();
		int RR_A();

		int SLA_B();
		int SLA_C();
		int SLA_D();
		int SLA_E();
		int SLA_H();
		int SLA_L();
		int SLA_MHL();
		int SLA_A();

		int SRA_B();
		int SRA_C();
		int SRA_D();
		int SRA_E();
		int SRA_H();
		int SRA_L();
		int SRA_MHL();
		int SRA_A();

		int SWAP_B();
		int SWAP_C();
		int SWAP_D();
		int SWAP_E();
		int SWAP_H();
		int SWAP_L();
		int SWAP_MHL();
		int SWAP_A();

		int SRL_B();
		int SRL_C();
		int SRL_D();
		int SRL_E();
		int SRL_H();
		int SRL_L();
		int SRL_MHL();
		int SRL_A();

		// BIT instructions

		int BIT_0_B();
		int BIT_0_C();
		int BIT_0_D();
		int BIT_0_E();
		int BIT_0_H();
		int BIT_0_L();
		int BIT_0_MHL();
		int BIT_0_A();

		int BIT_1_B();
		int BIT_1_C();
		int BIT_1_D();
		int BIT_1_E();
		int BIT_1_H();
		int BIT_1_L();
		int BIT_1_MHL();
		int BIT_1_A();

		int BIT_2_B();
		int BIT_2_C();
		int BIT_2_D();
		int BIT_2_E();
		int BIT_2_H();
		int BIT_2_L();
		int BIT_2_MHL();
		int BIT_2_A();

		int BIT_3_B();
		int BIT_3_C();
		int BIT_3_D();
		int BIT_3_E();
		int BIT_3_H();
		int BIT_3_L();
		int BIT_3_MHL();
		int BIT_3_A();

		int BIT_4_B();
		int BIT_4_C();
		int BIT_4_D();
		int BIT_4_E();
		int BIT_4_H();
		int BIT_4_L();
		int BIT_4_MHL();
		int BIT_4_A();

		int BIT_5_B();
		int BIT_5_C();
		int BIT_5_D();
		int BIT_5_E();
		int BIT_5_H();
		int BIT_5_L();
		int BIT_5_MHL();
		int BIT_5_A();

		int BIT_6_B();
		int BIT_6_C();
		int BIT_6_D();
		int BIT_6_E();
		int BIT_6_H();
		int BIT_6_L();
		int BIT_6_MHL();
		int BIT_6_A();

		int BIT_7_B();
		int BIT_7_C();
		int BIT_7_D();
		int BIT_7_E();
		int BIT_7_H();
		int BIT_7_L();
		int BIT_7_MHL();
		int BIT_7_A();

		CPU()
		: Memory(nullptr)
		{
		}
	};
}

// Defines used by multiple instruction sets to simplify the code
#define GETU16M (Memory[Registers.PC + 1] << 8) | Memory[Registers.PC + 2]