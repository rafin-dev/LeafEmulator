#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions
	void CPU::SetAndInstructionFlags(uint8_t Result)
	{
		Registers.SetZeroFlag(Result == 0);
		Registers.SetSubtractionFlag(false);
		Registers.SetHalfCarryFlag(true);
		Registers.SetCarryFlag(true);
	}

	// Actual instruction definitions
	int CPU::AND_A_B()
	{
		SetAndInstructionFlags(Registers.A & Registers.B);

		return 1;
	}

	int CPU::AND_A_C()
	{
		SetAndInstructionFlags(Registers.A & Registers.B);

		return 1;
	}

	int CPU::AND_A_D()
	{
		SetAndInstructionFlags(Registers.A & Registers.B);

		return 1;
	}

	int CPU::AND_A_E()
	{
		SetAndInstructionFlags(Registers.A & Registers.E);

		return 1;
	}

	int CPU::AND_A_H()
	{
		SetAndInstructionFlags(Registers.A & Registers.H);

		return 1;
	}

	int CPU::AND_A_L()
	{
		SetAndInstructionFlags(Registers.A & Registers.L);

		return 1;
	}

	int CPU::AND_A_MHL()
	{
		SetAndInstructionFlags(Registers.A & Memory[Registers.GetHL()]);

		return 1;
	}

	int CPU::AND_A_A()
	{
		SetAndInstructionFlags(Registers.A & Registers.A);

		return 1;
	}

	int CPU::AND_A_U8()
	{
		SetAndInstructionFlags(Registers.A & Memory[Registers.PC + 1]);

		return 2;
	}

}