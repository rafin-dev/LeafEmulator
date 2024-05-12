#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	void CPU::RES_u3_8bitRegister(uint8_t u3, uint8_t* reg)
	{
		*reg = (*reg) & (~(1 << u3));
	}

	void CPU::SET_u3_8bitRegister(uint8_t u3, uint8_t* reg)
	{
		*reg = (*reg) | (1 << u3);
	}

	// Instruction definitions

	// RES instructions

	int GameBoyEmulator::CPU::RES_0_B()
	{
		RES_u3_8bitRegister(0, &Registers.B);

		return 2;
	}

	int CPU::RES_0_C()
	{
		RES_u3_8bitRegister(0, &Registers.C);

		return 2;
	}

	int CPU::RES_0_D()
	{
		RES_u3_8bitRegister(0, &Registers.D);

		return 2;
	}

	int CPU::RES_0_E()
	{
		RES_u3_8bitRegister(0, &Registers.E);

		return 2;
	}

	int CPU::RES_0_H()
	{
		RES_u3_8bitRegister(0, &Registers.H);

		return 2;
	}

	int CPU::RES_0_L()
	{
		RES_u3_8bitRegister(0, &Registers.L);

		return 2;
	}

	int CPU::RES_0_MHL()
	{
		RES_u3_8bitRegister(0, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_0_A()
	{
		RES_u3_8bitRegister(0, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_1_B()
	{
		RES_u3_8bitRegister(1, &Registers.B);

		return 2;
	}

	int CPU::RES_1_C()
	{
		RES_u3_8bitRegister(1, &Registers.C);

		return 2;
	}

	int CPU::RES_1_D()
	{
		RES_u3_8bitRegister(1, &Registers.D);

		return 2;
	}

	int CPU::RES_1_E()
	{
		RES_u3_8bitRegister(1, &Registers.E);

		return 2;
	}

	int CPU::RES_1_H()
	{
		RES_u3_8bitRegister(1, &Registers.H);

		return 2;
	}

	int CPU::RES_1_L()
	{
		RES_u3_8bitRegister(1, &Registers.L);

		return 2;
	}

	int CPU::RES_1_MHL()
	{
		RES_u3_8bitRegister(1, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_1_A()
	{
		RES_u3_8bitRegister(1, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_2_B()
	{
		RES_u3_8bitRegister(2, &Registers.B);

		return 2;
	}

	int CPU::RES_2_C()
	{
		RES_u3_8bitRegister(2, &Registers.C);

		return 2;
	}

	int CPU::RES_2_D()
	{
		RES_u3_8bitRegister(2, &Registers.D);

		return 2;
	}

	int CPU::RES_2_E()
	{
		RES_u3_8bitRegister(2, &Registers.E);

		return 2;
	}

	int CPU::RES_2_H()
	{
		RES_u3_8bitRegister(2, &Registers.H);

		return 2;
	}

	int CPU::RES_2_L()
	{
		RES_u3_8bitRegister(2, &Registers.L);

		return 2;
	}

	int CPU::RES_2_MHL()
	{
		RES_u3_8bitRegister(2, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_2_A()
	{
		RES_u3_8bitRegister(2, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_3_B()
	{
		RES_u3_8bitRegister(3, &Registers.B);

		return 2;
	}

	int CPU::RES_3_C()
	{
		RES_u3_8bitRegister(3, &Registers.C);

		return 2;
	}

	int CPU::RES_3_D()
	{
		RES_u3_8bitRegister(3, &Registers.D);

		return 2;
	}

	int CPU::RES_3_E()
	{
		RES_u3_8bitRegister(3, &Registers.E);

		return 2;
	}

	int CPU::RES_3_H()
	{
		RES_u3_8bitRegister(3, &Registers.H);

		return 2;
	}

	int CPU::RES_3_L()
	{
		RES_u3_8bitRegister(3, &Registers.L);

		return 2;
	}

	int CPU::RES_3_MHL()
	{
		RES_u3_8bitRegister(3, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_3_A()
	{
		RES_u3_8bitRegister(3, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_4_B()
	{
		RES_u3_8bitRegister(4, &Registers.B);

		return 2;
	}

	int CPU::RES_4_C()
	{
		RES_u3_8bitRegister(4, &Registers.C);

		return 2;
	}

	int CPU::RES_4_D()
	{
		RES_u3_8bitRegister(4, &Registers.D);

		return 2;
	}

	int CPU::RES_4_E()
	{
		RES_u3_8bitRegister(4, &Registers.E);

		return 2;
	}

	int CPU::RES_4_H()
	{
		RES_u3_8bitRegister(4, &Registers.H);

		return 2;
	}

	int CPU::RES_4_L()
	{
		RES_u3_8bitRegister(4, &Registers.L);

		return 2;
	}

	int CPU::RES_4_MHL()
	{
		RES_u3_8bitRegister(4, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_4_A()
	{
		RES_u3_8bitRegister(4, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_5_B()
	{
		RES_u3_8bitRegister(5, &Registers.B);

		return 2;
	}

	int CPU::RES_5_C()
	{
		RES_u3_8bitRegister(5, &Registers.C);

		return 2;
	}

	int CPU::RES_5_D()
	{
		RES_u3_8bitRegister(5, &Registers.D);

		return 2;
	}

	int CPU::RES_5_E()
	{
		RES_u3_8bitRegister(5, &Registers.E);

		return 2;
	}

	int CPU::RES_5_H()
	{
		RES_u3_8bitRegister(5, &Registers.H);

		return 2;
	}

	int CPU::RES_5_L()
	{
		RES_u3_8bitRegister(5, &Registers.L);

		return 2;
	}

	int CPU::RES_5_MHL()
	{
		RES_u3_8bitRegister(5, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_5_A()
	{
		RES_u3_8bitRegister(5, &Registers.A);

		return 2;
	}
	



	int GameBoyEmulator::CPU::RES_6_B()
	{
		RES_u3_8bitRegister(6, &Registers.B);

		return 2;
	}

	int CPU::RES_6_C()
	{
		RES_u3_8bitRegister(6, &Registers.C);

		return 2;
	}

	int CPU::RES_6_D()
	{
		RES_u3_8bitRegister(6, &Registers.D);

		return 2;
	}

	int CPU::RES_6_E()
	{
		RES_u3_8bitRegister(6, &Registers.E);

		return 2;
	}

	int CPU::RES_6_H()
	{
		RES_u3_8bitRegister(6, &Registers.H);

		return 2;
	}

	int CPU::RES_6_L()
	{
		RES_u3_8bitRegister(6, &Registers.L);

		return 2;
	}

	int CPU::RES_6_MHL()
	{
		RES_u3_8bitRegister(6, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_6_A()
	{
		RES_u3_8bitRegister(6, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_7_B()
	{
		RES_u3_8bitRegister(7, &Registers.B);

		return 2;
	}

	int CPU::RES_7_C()
	{
		RES_u3_8bitRegister(7, &Registers.C);

		return 2;
	}

	int CPU::RES_7_D()
	{
		RES_u3_8bitRegister(7, &Registers.D);

		return 2;
	}

	int CPU::RES_7_E()
	{
		RES_u3_8bitRegister(7, &Registers.E);

		return 2;
	}

	int CPU::RES_7_H()
	{
		RES_u3_8bitRegister(7, &Registers.H);

		return 2;
	}

	int CPU::RES_7_L()
	{
		RES_u3_8bitRegister(7, &Registers.L);

		return 2;
	}

	int CPU::RES_7_MHL()
	{
		RES_u3_8bitRegister(7, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RES_7_A()
	{
		RES_u3_8bitRegister(7, &Registers.A);

		return 2;
	}

	// SET instructions

	int GameBoyEmulator::CPU::SET_0_B()
	{
		SET_u3_8bitRegister(0, &Registers.B);

		return 2;
	}

	int CPU::SET_0_C()
	{
		SET_u3_8bitRegister(0, &Registers.C);

		return 2;
	}

	int CPU::SET_0_D()
	{
		SET_u3_8bitRegister(0, &Registers.D);

		return 2;
	}

	int CPU::SET_0_E()
	{
		SET_u3_8bitRegister(0, &Registers.E);

		return 2;
	}

	int CPU::SET_0_H()
	{
		SET_u3_8bitRegister(0, &Registers.H);

		return 2;
	}

	int CPU::SET_0_L()
	{
		SET_u3_8bitRegister(0, &Registers.L);

		return 2;
	}

	int CPU::SET_0_MHL()
	{
		SET_u3_8bitRegister(0, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_0_A()
	{
		SET_u3_8bitRegister(0, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_1_B()
	{
		SET_u3_8bitRegister(1, &Registers.B);

		return 2;
	}

	int CPU::SET_1_C()
	{
		SET_u3_8bitRegister(1, &Registers.C);

		return 2;
	}

	int CPU::SET_1_D()
	{
		SET_u3_8bitRegister(1, &Registers.D);

		return 2;
	}

	int CPU::SET_1_E()
	{
		SET_u3_8bitRegister(1, &Registers.E);

		return 2;
	}

	int CPU::SET_1_H()
	{
		SET_u3_8bitRegister(1, &Registers.H);

		return 2;
	}

	int CPU::SET_1_L()
	{
		SET_u3_8bitRegister(1, &Registers.L);

		return 2;
	}

	int CPU::SET_1_MHL()
	{
		SET_u3_8bitRegister(1, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_1_A()
	{
		SET_u3_8bitRegister(1, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_2_B()
	{
		SET_u3_8bitRegister(2, &Registers.B);

		return 2;
	}

	int CPU::SET_2_C()
	{
		SET_u3_8bitRegister(2, &Registers.C);

		return 2;
	}

	int CPU::SET_2_D()
	{
		SET_u3_8bitRegister(2, &Registers.D);

		return 2;
	}

	int CPU::SET_2_E()
	{
		SET_u3_8bitRegister(2, &Registers.E);

		return 2;
	}

	int CPU::SET_2_H()
	{
		SET_u3_8bitRegister(2, &Registers.H);

		return 2;
	}

	int CPU::SET_2_L()
	{
		SET_u3_8bitRegister(2, &Registers.L);

		return 2;
	}

	int CPU::SET_2_MHL()
	{
		SET_u3_8bitRegister(2, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_2_A()
	{
		SET_u3_8bitRegister(2, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_3_B()
	{
		SET_u3_8bitRegister(3, &Registers.B);

		return 2;
	}

	int CPU::SET_3_C()
	{
		SET_u3_8bitRegister(3, &Registers.C);

		return 2;
	}

	int CPU::SET_3_D()
	{
		SET_u3_8bitRegister(3, &Registers.D);

		return 2;
	}

	int CPU::SET_3_E()
	{
		SET_u3_8bitRegister(3, &Registers.E);

		return 2;
	}

	int CPU::SET_3_H()
	{
		SET_u3_8bitRegister(3, &Registers.H);

		return 2;
	}

	int CPU::SET_3_L()
	{
		SET_u3_8bitRegister(3, &Registers.L);

		return 2;
	}

	int CPU::SET_3_MHL()
	{
		SET_u3_8bitRegister(3, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_3_A()
	{
		SET_u3_8bitRegister(3, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_4_B()
	{
		SET_u3_8bitRegister(4, &Registers.B);

		return 2;
	}

	int CPU::SET_4_C()
	{
		SET_u3_8bitRegister(4, &Registers.C);

		return 2;
	}

	int CPU::SET_4_D()
	{
		SET_u3_8bitRegister(4, &Registers.D);

		return 2;
	}

	int CPU::SET_4_E()
	{
		SET_u3_8bitRegister(4, &Registers.E);

		return 2;
	}

	int CPU::SET_4_H()
	{
		SET_u3_8bitRegister(4, &Registers.H);

		return 2;
	}

	int CPU::SET_4_L()
	{
		SET_u3_8bitRegister(4, &Registers.L);

		return 2;
	}

	int CPU::SET_4_MHL()
	{
		SET_u3_8bitRegister(4, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_4_A()
	{
		SET_u3_8bitRegister(4, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_5_B()
	{
		SET_u3_8bitRegister(5, &Registers.B);

		return 2;
	}

	int CPU::SET_5_C()
	{
		SET_u3_8bitRegister(5, &Registers.C);

		return 2;
	}

	int CPU::SET_5_D()
	{
		SET_u3_8bitRegister(5, &Registers.D);

		return 2;
	}

	int CPU::SET_5_E()
	{
		SET_u3_8bitRegister(5, &Registers.E);

		return 2;
	}

	int CPU::SET_5_H()
	{
		SET_u3_8bitRegister(5, &Registers.H);

		return 2;
	}

	int CPU::SET_5_L()
	{
		SET_u3_8bitRegister(5, &Registers.L);

		return 2;
	}

	int CPU::SET_5_MHL()
	{
		SET_u3_8bitRegister(5, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_5_A()
	{
		SET_u3_8bitRegister(5, &Registers.A);

		return 2;
	}




	int GameBoyEmulator::CPU::SET_6_B()
	{
		SET_u3_8bitRegister(6, &Registers.B);

		return 2;
	}

	int CPU::SET_6_C()
	{
		SET_u3_8bitRegister(6, &Registers.C);

		return 2;
	}

	int CPU::SET_6_D()
	{
		SET_u3_8bitRegister(6, &Registers.D);

		return 2;
	}

	int CPU::SET_6_E()
	{
		SET_u3_8bitRegister(6, &Registers.E);

		return 2;
	}

	int CPU::SET_6_H()
	{
		SET_u3_8bitRegister(6, &Registers.H);

		return 2;
	}

	int CPU::SET_6_L()
	{
		SET_u3_8bitRegister(6, &Registers.L);

		return 2;
	}

	int CPU::SET_6_MHL()
	{
		SET_u3_8bitRegister(6, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_6_A()
	{
		SET_u3_8bitRegister(6, &Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_7_B()
	{
		SET_u3_8bitRegister(7, &Registers.B);

		return 2;
	}

	int CPU::SET_7_C()
	{
		SET_u3_8bitRegister(7, &Registers.C);

		return 2;
	}

	int CPU::SET_7_D()
	{
		SET_u3_8bitRegister(7, &Registers.D);

		return 2;
	}

	int CPU::SET_7_E()
	{
		SET_u3_8bitRegister(7, &Registers.E);

		return 2;
	}

	int CPU::SET_7_H()
	{
		SET_u3_8bitRegister(7, &Registers.H);

		return 2;
	}

	int CPU::SET_7_L()
	{
		SET_u3_8bitRegister(7, &Registers.L);

		return 2;
	}

	int CPU::SET_7_MHL()
	{
		SET_u3_8bitRegister(7, &Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SET_7_A()
	{
		SET_u3_8bitRegister(7, &Registers.A);

		return 2;
	}

}