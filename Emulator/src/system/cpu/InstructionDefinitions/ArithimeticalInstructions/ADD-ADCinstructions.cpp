#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions for the ADD instructions

	void CPU::SetAddInstructionsFlags(int ADDresult)
	{
		Registers.SetSubtractionFlag(false);
		Registers.SetHalfCarryFlag(ADDresult > 0x00FF);
		Registers.SetCarryFlag(ADDresult > 0xFFFF);
	}

	void CPU::ADDtoHL(uint16_t n)
	{
		int Result = Registers.GetHL() + n;
		SetAddInstructionsFlags(Result);
		Registers.SetHL(Result);
	}

	void CPU::AddtoA(uint8_t n)
	{
		int Result = Registers.A + n;
		SetAddInstructionsFlags(Result);
		Registers.A = Result;
	}

	// Actual Instruction definitions

	// 16 bit
	int CPU::ADD_HL_BC()
	{
		ADDtoHL(Registers.GetBC());

		return 1;
	}

	int CPU::ADD_HL_DE()
	{
		ADDtoHL(Registers.GetDE());

		return 1;
	}

	int CPU::ADD_HL_HL()
	{
		ADDtoHL(Registers.GetHL());

		return 1;
	}

	int CPU::ADD_HL_SP()
	{
		ADDtoHL(Registers.SP);

		return 1;
	}

	// 8 bit
	int CPU::ADD_A_B()
	{
		AddtoA(Registers.B);

		return 1;
	}

	int CPU::ADD_A_C()
	{
		AddtoA(Registers.C);

		return 1;
	}

	int CPU::ADD_A_D()
	{
		AddtoA(Registers.D);

		return 1;
	}

	int CPU::ADD_A_E()
	{
		AddtoA(Registers.E);

		return 1;
	}

}