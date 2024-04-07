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
		SetXorInstructionFlags(Registers.A ^ Registers.B);

		return 1;
	}

	int CPU::XOR_A_C()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.B);

		return 1;
	}
	
	int CPU::XOR_A_D()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.B);

		return 1;
	}

	int CPU::XOR_A_E()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.E);

		return 1;
	}

	int CPU::XOR_A_H()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.H);

		return 1;
	}

	int CPU::XOR_A_L()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.L);

		return 1;
	}

	int CPU::XOR_A_MHL()
	{
		SetXorInstructionFlags(Registers.A ^ Memory[Registers.GetHL()]);

		return 1;
	}

	int CPU::XOR_A_A()
	{
		SetXorInstructionFlags(Registers.A ^ Registers.A);

		return 1;
	}

	int CPU::XOR_A_U8()
	{
		SetXorInstructionFlags(Registers.A ^ Memory[Registers.PC + 1]);

		return 2;
	}
}