#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

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

	int CPU::LD_B_B()
	{
		Registers.B = Registers.B;

		return 1;
	}

	int CPU::LD_B_C()
	{
		Registers.B = Registers.C;

		return 1;
	}

	int CPU::LD_B_D()
	{
		Registers.B = Registers.D;

		return 1;
	}

	int CPU::LD_B_E()
	{
		Registers.B = Registers.E;

		return 1;
	}

	int CPU::LD_B_H()
	{
		Registers.B = Registers.H;

		return 1;
	}

	int CPU::LD_B_L()
	{
		Registers.B = Registers.L;

		return 1;
	}

	int CPU::LD_B_MHL()
	{
		Registers.B = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_B_A()
	{
		Registers.B = Registers.A;

		return 1;
	}

	int CPU::LD_C_B()
	{
		Registers.C = Registers.B;

		return 1;
	}

	int CPU::LD_C_C()
	{
		Registers.C = Registers.C;

		return 1;
	}

	int CPU::LD_C_D()
	{
		Registers.C = Registers.D;

		return 1;
	}

	int CPU::LD_C_E()
	{
		Registers.C = Registers.E;

		return 1;
	}

	int CPU::LD_C_H()
	{
		Registers.C = Registers.H;

		return 1;
	}

	int CPU::LD_C_L()
	{
		Registers.C = Registers.L;

		return 1;
	}

	int CPU::LD_C_MHL()
	{
		Registers.C = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_C_A()
	{
		Registers.C = Registers.A;

		return 1;
	}

	int CPU::LD_D_B()
	{
		Registers.D = Registers.B;

		return 1;
	}

	int CPU::LD_D_C()
	{
		Registers.D = Registers.C;

		return 1;
	}

	int CPU::LD_D_D()
	{
		Registers.D = Registers.D;

		return 1;
	}

	int CPU::LD_D_E()
	{
		Registers.D = Registers.E;

		return 1;
	}

	int CPU::LD_D_H()
	{
		Registers.D = Registers.H;

		return 1;
	}

	int CPU::LD_D_L()
	{
		Registers.D = Registers.L;

		return 1;
	}

	int CPU::LD_D_MHL()
	{
		Registers.D = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_D_A()
	{
		Registers.D = Registers.A;

		return 1;
	}

	int CPU::LD_E_B()
	{
		Registers.E = Registers.B;

		return 1;
	}

	int CPU::LD_E_C()
	{
		Registers.E = Registers.C;

		return 1;
	}

	int CPU::LD_E_D()
	{
		Registers.E = Registers.D;

		return 1;
	}

	int CPU::LD_E_E()
	{
		Registers.E = Registers.E;

		return 1;
	}

	int CPU::LD_E_H()
	{
		Registers.E = Registers.H;

		return 1;
	}

	int CPU::LD_E_L()
	{
		Registers.E = Registers.L;

		return 1;
	}

	int CPU::LD_E_MHL()
	{
		Registers.E = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_E_A()
	{
		Registers.E = Registers.A;

		return 1;
	}

	int CPU::LD_H_B()
	{
		Registers.H = Registers.B;

		return 1;
	}

	int CPU::LD_H_C()
	{
		Registers.H = Registers.C;

		return 1;
	}

	int CPU::LD_H_D()
	{
		Registers.H = Registers.D;

		return 1;
	}

	int CPU::LD_H_E()
	{
		Registers.H = Registers.E;

		return 1;
	}

	int CPU::LD_H_H()
	{
		Registers.H = Registers.H;

		return 1;
	}

	int CPU::LD_H_L()
	{
		Registers.H = Registers.L;

		return 1;
	}

	int CPU::LD_H_MHL()
	{
		Registers.H = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_H_A()
	{
		Registers.H = Registers.A;

		return 1;
	}

	int CPU::LD_L_B()
	{
		Registers.L = Registers.B;

		return 1;
	}

	int CPU::LD_L_C()
	{
		Registers.L = Registers.C;

		return 1;
	}

	int CPU::LD_L_D()
	{
		Registers.L = Registers.D;

		return 1;
	}

	int CPU::LD_L_E()
	{
		Registers.L = Registers.E;

		return 1;
	}

	int CPU::LD_L_H()
	{
		Registers.L = Registers.H;

		return 1;
	}

	int CPU::LD_L_L()
	{
		Registers.L = Registers.L;

		return 1;
	}

	int CPU::LD_L_MHL()
	{
		Registers.L = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_L_A()
	{
		Registers.L = Registers.A;

		return 1;
	}

	int CPU::LD_MHL_B()
	{
		Memory[Registers.GetHL()] = Registers.B;

		return 1;
	}

	int CPU::LD_MHL_C()
	{
		Memory[Registers.GetHL()] = Registers.C;

		return 1;
	}

	int CPU::LD_MHL_D()
	{
		Memory[Registers.GetHL()] = Registers.D;

		return 1;
	}

	int CPU::LD_MHL_E()
	{
		Memory[Registers.GetHL()] = Registers.E;

		return 1;
	}

	int CPU::LD_MHL_H()
	{
		Memory[Registers.GetHL()] = Registers.H;

		return 1;
	}

	int CPU::LD_MHL_L()
	{
		Memory[Registers.GetHL()] = Registers.L;

		return 1;
	}

	int CPU::LD_MHL_A()
	{
		Memory[Registers.GetHL()] = Registers.A;

		return 1;
	}

	int CPU::LD_A_B()
	{
		Registers.A = Registers.B;

		return 1;
	}

	int CPU::LD_A_C()
	{
		Registers.A = Registers.C;

		return 1;
	}

	int CPU::LD_A_D()
	{
		Registers.A = Registers.D;

		return 1;
	}

	int CPU::LD_A_E()
	{
		Registers.A = Registers.E;

		return 1;
	}

	int CPU::LD_A_H()
	{
		Registers.A = Registers.H;

		return 1;
	}

	int CPU::LD_A_L()
	{
		Registers.A = Registers.L;

		return 1;
	}

	int CPU::LD_A_MHL()
	{
		Registers.A = Memory[Registers.GetHL()];

		return 1;
	}

	int CPU::LD_A_A()
	{
		Registers.A = Registers.A;

		return 1;
	}

}