#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

#define GETU16M (Memory[Registers.PC + 1] << 8) | Memory[Registers.PC + 2]

	// Instruction definitons

	// 16 bit
	int CPU::LD_BC_U16()
	{
		Registers.SetBC(GETU16M);

		return 3;
	}

	int CPU::LD_DE_U16()
	{
		Registers.SetDE(GETU16M);

		return 3;
	}

	int CPU::LD_HL_U16()
	{
		Registers.SetHL(GETU16M);

		return 3;
	}

	int CPU::LD_SP_U16()
	{
		Registers.SP = GETU16M;

		return 3;
	}

	int CPU::LD_MU16_SP()
	{
		Memory[GETU16M] = Registers.SP >> 8;
		Memory[GETU16M] = Registers.SP & 0x00FF;

		return 3;
	}

	int CPU::LD_SP_HL()
	{
		Registers.SP = Registers.GetHL();

		return 1;
	}

	int CPU::LD_HL_SPpI8()
	{
		int R = Registers.SP + *((int8_t*)&Memory[Registers.PC + 1]);
		Registers.SetZeroFlag(false);
		SetAddInstructionsFlags16bit(R);
		Registers.SetHL(R);

		return 2;
	}

	// 8 bit

	int CPU::LD_MBC_A()
	{
		Memory[Registers.GetBC()] = Registers.A;

		return 1;
	}

	int CPU::LD_MDE_A()
	{
		Memory[Registers.GetDE()] = Registers.A;

		return 1;
	}

	int CPU::LD_MHLp_A()
	{
		Memory[Registers.GetHL()];
		Registers.SetHL(Registers.GetHL() + 1);

		return 1;
	}

	int CPU::LD_MHLm_A()
	{
		Memory[Registers.GetHL()];
		Registers.SetHL(Registers.GetHL() - 1);

		return 1;
	}

	int CPU::LD_B_U8()
	{
		Registers.B = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_D_U8()
	{
		Registers.D = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_H_U8()
	{
		Registers.H = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_MHL_U8()
	{
		Memory[Registers.GetHL()] = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_A_MBC()
	{
		Registers.A = Memory[Registers.GetBC()];

		return 1;
	}

	int CPU::LD_A_MDE()
	{
		Registers.A = Memory[Registers.GetDE()];

		return 1;
	}

	int CPU::LD_A_MHLp()
	{
		Registers.A = Memory[Registers.GetHL()];
		Registers.SetHL(Registers.GetHL() + 1);

		return 1;
	}

	int CPU::LD_A_MHLm()
	{
		Registers.A = Memory[Registers.GetHL()];
		Registers.SetHL(Registers.GetHL() + 1);

		return 1;
	}

	int CPU::LD_C_U8()
	{
		Registers.C = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_E_U8()
	{
		Registers.E = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_L_U8()
	{
		Registers.L = Memory[Registers.PC + 1];

		return 2;
	}

	int CPU::LD_A_U8()
	{
		Registers.A = Memory[Registers.PC + 1];

		return 2;
	}

}