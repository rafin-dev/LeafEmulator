#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions
	void CPU::SetAndInstructionFlags(uint8_t Result)
	{
		Registers.SetZeroFlag(Result == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(true);
		Registers.SetCarryFlag(true);
	}

	// Actual instruction definitions
	int CPU::AND_A_B()
	{
		Registers.A = Registers.A & Registers.B;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_C()
	{
		Registers.A = Registers.A & Registers.C;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_D()
	{
		Registers.A = Registers.A & Registers.B;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_E()
	{
		Registers.A = Registers.A & Registers.E;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_H()
	{
		Registers.A = Registers.A & Registers.H;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_L()
	{
		Registers.A = Registers.A & Registers.L;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_MHL()
	{
		Registers.A = Registers.A & Memory[Registers.GetHL()];
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_A()
	{
		Registers.A = Registers.A & Registers.A;
		SetAndInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::AND_A_U8()
	{
		Registers.A = Registers.A & Memory[Registers.PC + 1];
		SetAndInstructionFlags(Registers.A);

		return 2;
	}

}