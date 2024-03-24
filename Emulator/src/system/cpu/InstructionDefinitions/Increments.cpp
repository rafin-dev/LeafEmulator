#include "system/cpu/CPU.h"

// File Containing all the Increment instructions function definitions
namespace GameBoyEmulator {

	// 16 bit increments
	int CPU::INC_BC()
	{
		Registers.SetBC(Registers.GetBC() + 1);

		return 1;
	}

	int CPU::INC_DE()
	{
		Registers.SetDE(Registers.GetDE() + 1);

		return 1;
	}

	int CPU::INC_HL()
	{
		Registers.SetHL(Registers.GetHL() + 1);

		return 1;
	}

	int CPU::INC_SP()
	{
		Registers.SP++;

		return 1;
	}

	// 8 bit increments
	int CPU::INC_B()
	{
		Registers.B++;

		return 1;
	}

	int CPU::INC_D()
	{
		Registers.D++;

		return 1;
	}

	int CPU::INC_H()
	{
		Registers.H++;

		return 1;
	}

	int CPU::INC_MHL()
	{
		Memory[Registers.GetHL()]++;

		return 1;
	}

	int CPU::INC_C()
	{
		Registers.C++;

		return 1;
	}

	int CPU::INC_E()
	{
		Registers.E++;

		return 1;
	}

	int CPU::INC_L()
	{
		Registers.L++;

		return 1;
	}

	int CPU::INC_A()
	{
		Registers.A++;

		return 1;
	}
}