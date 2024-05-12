#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// helper functions

	void CPU::BIT_u3_8bitRegister(uint8_t u3, uint8_t* reg)
	{
		bool bit = (*reg) << u3;

		Registers.SetZeroFlag(bit == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(true);
	}

	// INstruction definitions

	int GameBoyEmulator::CPU::BIT_0_B()
	{
		BIT_u3_8bitRegister(0, &Registers.B);

		return 2;
	}

	int CPU::BIT_0_C()
	{
		BIT_u3_8bitRegister(0, &Registers.C);

		return 2;
	}

	int CPU::BIT_0_D()
	{
		BIT_u3_8bitRegister(0, &Registers.D);

		return 2;
	}

	int CPU::BIT_0_E()
	{
		BIT_u3_8bitRegister(0, &Registers.E);

		return 2;
	}

	int CPU::BIT_0_H()
	{
		BIT_u3_8bitRegister(0, &Registers.H);

		return 2;
	}

	int CPU::BIT_0_L()
	{
		BIT_u3_8bitRegister(0, &Registers.L);

		return 2;
	}

	int CPU::BIT_0_MHL()
	{
		BIT_u3_8bitRegister(0, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_0_A()
	{
		BIT_u3_8bitRegister(0, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_1_B()
	{
		BIT_u3_8bitRegister(1, &Registers.B);

		return 2;
	}

	int CPU::BIT_1_C()
	{
		BIT_u3_8bitRegister(1, &Registers.C);

		return 2;
	}

	int CPU::BIT_1_D()
	{
		BIT_u3_8bitRegister(1, &Registers.D);

		return 2;
	}

	int CPU::BIT_1_E()
	{
		BIT_u3_8bitRegister(1, &Registers.E);

		return 2;
	}

	int CPU::BIT_1_H()
	{
		BIT_u3_8bitRegister(1, &Registers.H);

		return 2;
	}

	int CPU::BIT_1_L()
	{
		BIT_u3_8bitRegister(1, &Registers.L);

		return 2;
	}

	int CPU::BIT_1_MHL()
	{
		BIT_u3_8bitRegister(1, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_1_A()
	{
		BIT_u3_8bitRegister(1, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_2_B()
	{
		BIT_u3_8bitRegister(2, &Registers.B);

		return 2;
	}

	int CPU::BIT_2_C()
	{
		BIT_u3_8bitRegister(2, &Registers.C);

		return 2;
	}

	int CPU::BIT_2_D()
	{
		BIT_u3_8bitRegister(2, &Registers.D);

		return 2;
	}

	int CPU::BIT_2_E()
	{
		BIT_u3_8bitRegister(2, &Registers.E);

		return 2;
	}

	int CPU::BIT_2_H()
	{
		BIT_u3_8bitRegister(2, &Registers.H);

		return 2;
	}

	int CPU::BIT_2_L()
	{
		BIT_u3_8bitRegister(2, &Registers.L);

		return 2;
	}

	int CPU::BIT_2_MHL()
	{
		BIT_u3_8bitRegister(2, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_2_A()
	{
		BIT_u3_8bitRegister(2, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_3_B()
	{
		BIT_u3_8bitRegister(3, &Registers.B);

		return 2;
	}

	int CPU::BIT_3_C()
	{
		BIT_u3_8bitRegister(3, &Registers.C);

		return 2;
	}

	int CPU::BIT_3_D()
	{
		BIT_u3_8bitRegister(3, &Registers.D);

		return 2;
	}

	int CPU::BIT_3_E()
	{
		BIT_u3_8bitRegister(3, &Registers.E);

		return 2;
	}

	int CPU::BIT_3_H()
	{
		BIT_u3_8bitRegister(3, &Registers.H);

		return 2;
	}

	int CPU::BIT_3_L()
	{
		BIT_u3_8bitRegister(3, &Registers.L);

		return 2;
	}

	int CPU::BIT_3_MHL()
	{
		BIT_u3_8bitRegister(3, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_3_A()
	{
		BIT_u3_8bitRegister(3, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_4_B()
	{
		BIT_u3_8bitRegister(4, &Registers.B);

		return 2;
	}

	int CPU::BIT_4_C()
	{
		BIT_u3_8bitRegister(4, &Registers.C);

		return 2;
	}

	int CPU::BIT_4_D()
	{
		BIT_u3_8bitRegister(4, &Registers.D);

		return 2;
	}

	int CPU::BIT_4_E()
	{
		BIT_u3_8bitRegister(4, &Registers.E);

		return 2;
	}

	int CPU::BIT_4_H()
	{
		BIT_u3_8bitRegister(4, &Registers.H);

		return 2;
	}

	int CPU::BIT_4_L()
	{
		BIT_u3_8bitRegister(4, &Registers.L);

		return 2;
	}

	int CPU::BIT_4_MHL()
	{
		BIT_u3_8bitRegister(4, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_4_A()
	{
		BIT_u3_8bitRegister(4, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_5_B()
	{
		BIT_u3_8bitRegister(5, &Registers.B);

		return 2;
	}

	int CPU::BIT_5_C()
	{
		BIT_u3_8bitRegister(5, &Registers.C);

		return 2;
	}

	int CPU::BIT_5_D()
	{
		BIT_u3_8bitRegister(5, &Registers.D);

		return 2;
	}

	int CPU::BIT_5_E()
	{
		BIT_u3_8bitRegister(5, &Registers.E);

		return 2;
	}

	int CPU::BIT_5_H()
	{
		BIT_u3_8bitRegister(5, &Registers.H);

		return 2;
	}

	int CPU::BIT_5_L()
	{
		BIT_u3_8bitRegister(5, &Registers.L);

		return 2;
	}

	int CPU::BIT_5_MHL()
	{
		BIT_u3_8bitRegister(5, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_5_A()
	{
		BIT_u3_8bitRegister(5, &Registers.A);

		return 2;
	}
	



	int GameBoyEmulator::CPU::BIT_6_B()
	{
		BIT_u3_8bitRegister(6, &Registers.B);

		return 2;
	}

	int CPU::BIT_6_C()
	{
		BIT_u3_8bitRegister(6, &Registers.C);

		return 2;
	}

	int CPU::BIT_6_D()
	{
		BIT_u3_8bitRegister(6, &Registers.D);

		return 2;
	}

	int CPU::BIT_6_E()
	{
		BIT_u3_8bitRegister(6, &Registers.E);

		return 2;
	}

	int CPU::BIT_6_H()
	{
		BIT_u3_8bitRegister(6, &Registers.H);

		return 2;
	}

	int CPU::BIT_6_L()
	{
		BIT_u3_8bitRegister(6, &Registers.L);

		return 2;
	}

	int CPU::BIT_6_MHL()
	{
		BIT_u3_8bitRegister(6, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_6_A()
	{
		BIT_u3_8bitRegister(6, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::BIT_7_B()
	{
		BIT_u3_8bitRegister(7, &Registers.B);

		return 2;
	}

	int CPU::BIT_7_C()
	{
		BIT_u3_8bitRegister(7, &Registers.C);

		return 2;
	}

	int CPU::BIT_7_D()
	{
		BIT_u3_8bitRegister(7, &Registers.D);

		return 2;
	}

	int CPU::BIT_7_E()
	{
		BIT_u3_8bitRegister(7, &Registers.E);

		return 2;
	}

	int CPU::BIT_7_H()
	{
		BIT_u3_8bitRegister(7, &Registers.H);

		return 2;
	}

	int CPU::BIT_7_L()
	{
		BIT_u3_8bitRegister(7, &Registers.L);

		return 2;
	}

	int CPU::BIT_7_MHL()
	{
		BIT_u3_8bitRegister(7, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::BIT_7_A()
	{
		BIT_u3_8bitRegister(7, &Registers.A);

		return 2;
	}

}