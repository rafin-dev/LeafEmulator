#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions
	void CPU::SetSubInstructionsFlags(int N)
	{
		Registers.SetZeroFlag((Registers.A - N) == 0);
		Registers.SetSubtractionFlag(true);
		Registers.SetHalfCarryFlag((((Registers.A & 0xF) - (N & 0xF)) < 0));
		Registers.SetCarryFlag(N > Registers.A);
	}

	void CPU::SubFromA(int n)
	{
		Registers.A -= n;

		SetSubInstructionsFlags(n);
	}

	// Actual instruction definitions
	// SUB instructions
	int CPU::SUB_A_B()
	{
		SubFromA(Registers.B);

		return 1;
	}

	int CPU::SUB_A_C()
	{
		SubFromA(Registers.C);

		return 1;
	}

	int CPU::SUB_A_D()
	{
		SubFromA(Registers.D);

		return 1;
	}

	int CPU::SUB_A_E()
	{
		SubFromA(Registers.E);

		return 1;
	}

	int CPU::SUB_A_H()
	{
		SubFromA(Registers.H);

		return 1;
	}

	int CPU::SUB_A_L()
	{
		SubFromA(Registers.L);

		return 1;
	}

	int CPU::SUB_A_MHL()
	{
		SubFromA(Memory[Registers.GetHL()]);

		return 1;
	}

	// I honestly have no idea why this instruction exists, maybe for the sake of completion?
	// but anyway, even though I could just set A to zero and set the Zero flag, I decided to do the normal procedure
	// in case I just didn't understand something
	int CPU::SUB_A_A()
	{
		SubFromA(Registers.A);

		return 1;
	}

	int CPU::SUB_A_U8()
	{
		SubFromA(Memory[Registers.PC + 1]);

		return 2;
	}

	// SBC instructions
	int CPU::SBC_A_B()
	{
		SubFromA(Registers.B + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_C()
	{
		SubFromA(Registers.C + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_D()
	{
		SubFromA(Registers.D + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_E()
	{
		SubFromA(Registers.E + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_H()
	{
		SubFromA(Registers.H + Registers.GetCarryFlag());

		return 1;
	}

	int GameBoyEmulator::CPU::SBC_A_L()
	{
		SubFromA(Registers.L + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_MHL()
	{
		SubFromA(Memory[Registers.GetHL()] + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_A()
	{
		SubFromA(Registers.A + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::SBC_A_U8()
	{
		SubFromA(Memory[Registers.PC + 1] + Registers.GetCarryFlag());

		return 2;
	}
	
}