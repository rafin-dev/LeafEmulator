#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	void CPU::SetORInstructionFlags(uint8_t Result)
	{
		Registers.SetZeroFlag(Result == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(false);
	}

	// Instruction definitions

	int CPU::OR_A_B()
	{
		Registers.A = Registers.A | Registers.B;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_C()
	{
		Registers.A = Registers.A | Registers.C;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_D()
	{
		Registers.A = Registers.A | Registers.D;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_E()
	{
		Registers.A = Registers.A | Registers.E;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_H()
	{
		Registers.A = Registers.A | Registers.H;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_L()
	{
		Registers.A = Registers.A | Registers.L;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_MHL()
	{
		Registers.A = Registers.A | Memory[Registers.GetHL()];
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_A()
	{
		Registers.A = Registers.A | Registers.A;
		SetORInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::OR_A_U8()
	{
		Registers.A = Registers.A | Memory[Registers.PC + 1];
		SetORInstructionFlags(Registers.A);

		return 2;
	}

}