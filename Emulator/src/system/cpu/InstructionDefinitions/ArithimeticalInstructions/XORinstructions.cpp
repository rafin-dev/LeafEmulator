#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions
	void CPU::SetXorInstructionFlags(uint8_t Result)
	{
		Registers.SetZeroFlag(Result == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(false);
	}

	// Instruction definitions
	int CPU::XOR_A_B()
	{
		Registers.A = Registers.A ^ Registers.B;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_C()
	{
		Registers.A = Registers.A ^ Registers.C;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}
	
	int CPU::XOR_A_D()
	{
		Registers.A = Registers.A ^ Registers.D;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_E()
	{
		Registers.A = Registers.A ^ Registers.E;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_H()
	{
		Registers.A = Registers.A ^ Registers.H;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_L()
	{
		Registers.A = Registers.A ^ Registers.L;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_MHL()
	{
		Registers.A = Registers.A ^ Memory[Registers.GetHL()];
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_A()
	{
		Registers.A = Registers.A ^ Registers.A;
		SetXorInstructionFlags(Registers.A);

		return 1;
	}

	int CPU::XOR_A_U8()
	{
		Registers.A = Registers.A ^ Memory[Registers.PC + 1];
		SetXorInstructionFlags(Registers.A);

		return 2;
	}
}