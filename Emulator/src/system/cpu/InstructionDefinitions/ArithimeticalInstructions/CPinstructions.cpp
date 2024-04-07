#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Instruction definitions

	int CPU::CP_A_B()
	{
		SetSubInstructionsFlags(Registers.B);

		return 1;
	}

	int CPU::CP_A_C()
	{
		SetSubInstructionsFlags(Registers.C);

		return 1;
	}

	int CPU::CP_A_D()
	{
		SetSubInstructionsFlags(Registers.D);

		return 1;
	}

	int CPU::CP_A_E()
	{
		SetSubInstructionsFlags(Registers.E);

		return 1;
	}

	int CPU::CP_A_H()
	{
		SetSubInstructionsFlags(Registers.H);

		return 1;
	}

	int CPU::CP_A_L()
	{
		SetSubInstructionsFlags(Registers.L);

		return 1;
	}

	int CPU::CP_A_MHL()
	{
		SetSubInstructionsFlags(Memory[Registers.GetHL()]);

		return 1;
	}

	int CPU::CP_A_A()
	{
		SetSubInstructionsFlags(Registers.A);

		return 1;
	}

	int CPU::CP_A_U8()
	{
		SetSubInstructionsFlags(Memory[Registers.PC + 1]);

		return 2;
	}

}