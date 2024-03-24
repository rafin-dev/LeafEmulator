#include "system/cpu/CPU.h"

// All decremnet functions definitions
namespace GameBoyEmulator {

	// 16 bit decrements
	int CPU::DEC_BC()
	{
		Registers.SetBC(Registers.GetBC() - 1);

		return 1;
	}

	int CPU::DEC_DE()
	{
		Registers.SetDE(Registers.GetDE() - 1);

		return 1;
	}

	int CPU::DEC_HL()
	{
		Registers.SetHL(Registers.GetHL() - 1);

		return 1;
	}

	int CPU::DEC_SP()
	{
		Registers.SP--;

		return 1;
	}

	// 8 bit decrements
	int CPU::DEC_B()
	{
		Registers.B--;

		return 1;
	}

	int CPU::DEC_D()
	{
		Registers.D--;

		return 1;
	}

	int CPU::DEC_H()
	{
		Registers.H--;

		return 1;
	}

	int CPU::DEC_MHL()
	{
		Memory[Registers.GetHL()]--;

		return 1;
	}

	int CPU::DEC_C()
	{
		Registers.C--;

		return 1;
	}

	int CPU::DEC_E()
	{
		Registers.E--;

		return 1;
	}

	int CPU::DEC_L()
	{
		Registers.L--;

		return 1;
	}

	int CPU::DEC_A()
	{
		Registers.A--;

		return 1;
	}

}