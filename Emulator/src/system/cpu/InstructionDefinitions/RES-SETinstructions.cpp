#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	uint8_t CPU::RES_u3_8bitRegister(uint8_t u3, uint8_t reg)
	{
		reg = reg & (~(1 << u3));

		return reg;
	}

	uint8_t CPU::SET_u3_8bitRegister(uint8_t u3, uint8_t reg)
	{
		reg = reg | (1 << u3);

		return reg;
	}

	// Instruction definitions

	// RES instructions

	int GameBoyEmulator::CPU::RES_0_B()
	{
		Registers.B = RES_u3_8bitRegister(0, Registers.B);

		return 2;
	}

	int CPU::RES_0_C()
	{
		Registers.C = RES_u3_8bitRegister(0, Registers.C);

		return 2;
	}

	int CPU::RES_0_D()
	{
		Registers.D = RES_u3_8bitRegister(0, Registers.D);

		return 2;
	}

	int CPU::RES_0_E()
	{
		Registers.E = RES_u3_8bitRegister(0, Registers.E);

		return 2;
	}

	int CPU::RES_0_H()
	{
		Registers.H = RES_u3_8bitRegister(0, Registers.H);

		return 2;
	}

	int CPU::RES_0_L()
	{
		Registers.L = RES_u3_8bitRegister(0, Registers.L);

		return 2;
	}

	int CPU::RES_0_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(0, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_0_A()
	{
		Registers.A = RES_u3_8bitRegister(0, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_1_B()
	{
		Registers.B = RES_u3_8bitRegister(1, Registers.B);

		return 2;
	}

	int CPU::RES_1_C()
	{
		Registers.C = RES_u3_8bitRegister(1, Registers.C);

		return 2;
	}

	int CPU::RES_1_D()
	{
		Registers.D = RES_u3_8bitRegister(1, Registers.D);

		return 2;
	}

	int CPU::RES_1_E()
	{
		Registers.E = RES_u3_8bitRegister(1, Registers.E);

		return 2;
	}

	int CPU::RES_1_H()
	{
		Registers.H = RES_u3_8bitRegister(1, Registers.H);

		return 2;
	}

	int CPU::RES_1_L()
	{
		Registers.L = RES_u3_8bitRegister(1, Registers.L);

		return 2;
	}

	int CPU::RES_1_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(1, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_1_A()
	{
		Registers.A = RES_u3_8bitRegister(1, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_2_B()
	{
		Registers.B = RES_u3_8bitRegister(2, Registers.B);

		return 2;
	}

	int CPU::RES_2_C()
	{
		Registers.C = RES_u3_8bitRegister(2, Registers.C);

		return 2;
	}

	int CPU::RES_2_D()
	{
		Registers.D = RES_u3_8bitRegister(2, Registers.D);

		return 2;
	}

	int CPU::RES_2_E()
	{
		Registers.E = RES_u3_8bitRegister(2, Registers.E);

		return 2;
	}

	int CPU::RES_2_H()
	{
		Registers.H = RES_u3_8bitRegister(2, Registers.H);

		return 2;
	}

	int CPU::RES_2_L()
	{
		Registers.L = RES_u3_8bitRegister(2, Registers.L);

		return 2;
	}

	int CPU::RES_2_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(2, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_2_A()
	{
		Registers.A = RES_u3_8bitRegister(2, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_3_B()
	{
		Registers.B = RES_u3_8bitRegister(3, Registers.B);

		return 2;
	}

	int CPU::RES_3_C()
	{
		Registers.C = RES_u3_8bitRegister(3, Registers.C);

		return 2;
	}

	int CPU::RES_3_D()
	{
		Registers.D = RES_u3_8bitRegister(3, Registers.D);

		return 2;
	}

	int CPU::RES_3_E()
	{
		Registers.E = RES_u3_8bitRegister(3, Registers.E);

		return 2;
	}

	int CPU::RES_3_H()
	{
		Registers.H = RES_u3_8bitRegister(3, Registers.H);

		return 2;
	}

	int CPU::RES_3_L()
	{
		Registers.L = RES_u3_8bitRegister(3, Registers.L);

		return 2;
	}

	int CPU::RES_3_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(3, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_3_A()
	{
		Registers.A = RES_u3_8bitRegister(3, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_4_B()
	{
		Registers.B = RES_u3_8bitRegister(4, Registers.B);

		return 2;
	}

	int CPU::RES_4_C()
	{
		Registers.C = RES_u3_8bitRegister(4, Registers.C);

		return 2;
	}

	int CPU::RES_4_D()
	{
		Registers.D = RES_u3_8bitRegister(4, Registers.D);

		return 2;
	}

	int CPU::RES_4_E()
	{
		Registers.E = RES_u3_8bitRegister(4, Registers.E);

		return 2;
	}

	int CPU::RES_4_H()
	{
		Registers.H = RES_u3_8bitRegister(4, Registers.H);

		return 2;
	}

	int CPU::RES_4_L()
	{
		Registers.L = RES_u3_8bitRegister(4, Registers.L);

		return 2;
	}

	int CPU::RES_4_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(4, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_4_A()
	{
		Registers.A = RES_u3_8bitRegister(4, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_5_B()
	{
		Registers.B = RES_u3_8bitRegister(5, Registers.B);

		return 2;
	}

	int CPU::RES_5_C()
	{
		Registers.C = RES_u3_8bitRegister(5, Registers.C);

		return 2;
	}

	int CPU::RES_5_D()
	{
		Registers.D = RES_u3_8bitRegister(5, Registers.D);

		return 2;
	}

	int CPU::RES_5_E()
	{
		Registers.E = RES_u3_8bitRegister(5, Registers.E);

		return 2;
	}

	int CPU::RES_5_H()
	{
		Registers.H = RES_u3_8bitRegister(5, Registers.H);

		return 2;
	}

	int CPU::RES_5_L()
	{
		Registers.L = RES_u3_8bitRegister(5, Registers.L);

		return 2;
	}

	int CPU::RES_5_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(5, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_5_A()
	{
		Registers.A = RES_u3_8bitRegister(5, Registers.A);

		return 2;
	}
	



	int GameBoyEmulator::CPU::RES_6_B()
	{
		Registers.B = RES_u3_8bitRegister(6, Registers.B);

		return 2;
	}

	int CPU::RES_6_C()
	{
		Registers.C = RES_u3_8bitRegister(6, Registers.C);

		return 2;
	}

	int CPU::RES_6_D()
	{
		Registers.D = RES_u3_8bitRegister(6, Registers.D);

		return 2;
	}

	int CPU::RES_6_E()
	{
		Registers.E = RES_u3_8bitRegister(6, Registers.E);

		return 2;
	}

	int CPU::RES_6_H()
	{
		Registers.H = RES_u3_8bitRegister(6, Registers.H);

		return 2;
	}

	int CPU::RES_6_L()
	{
		Registers.L = RES_u3_8bitRegister(6, Registers.L);

		return 2;
	}

	int CPU::RES_6_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(6, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_6_A()
	{
		Registers.A = RES_u3_8bitRegister(6, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::RES_7_B()
	{
		Registers.B = RES_u3_8bitRegister(7, Registers.B);

		return 2;
	}

	int CPU::RES_7_C()
	{
		Registers.C = RES_u3_8bitRegister(7, Registers.C);

		return 2;
	}

	int CPU::RES_7_D()
	{
		Registers.D = RES_u3_8bitRegister(7, Registers.D);

		return 2;
	}

	int CPU::RES_7_E()
	{
		Registers.E = RES_u3_8bitRegister(7, Registers.E);

		return 2;
	}

	int CPU::RES_7_H()
	{
		Registers.H = RES_u3_8bitRegister(7, Registers.H);

		return 2;
	}

	int CPU::RES_7_L()
	{
		Registers.L = RES_u3_8bitRegister(7, Registers.L);

		return 2;
	}

	int CPU::RES_7_MHL()
	{
		Memory.WriteData(RES_u3_8bitRegister(7, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RES_7_A()
	{
		Registers.A = RES_u3_8bitRegister(7, Registers.A);

		return 2;
	}

	// SET instructions

	int GameBoyEmulator::CPU::SET_0_B()
	{
		Registers.B = SET_u3_8bitRegister(0, Registers.B);

		return 2;
	}

	int CPU::SET_0_C()
	{
		Registers.C = SET_u3_8bitRegister(0, Registers.C);

		return 2;
	}

	int CPU::SET_0_D()
	{
		Registers.D = SET_u3_8bitRegister(0, Registers.D);

		return 2;
	}

	int CPU::SET_0_E()
	{
		Registers.E = SET_u3_8bitRegister(0, Registers.E);

		return 2;
	}

	int CPU::SET_0_H()
	{
		Registers.H = SET_u3_8bitRegister(0, Registers.H);

		return 2;
	}

	int CPU::SET_0_L()
	{
		Registers.L = SET_u3_8bitRegister(0, Registers.L);

		return 2;
	}

	int CPU::SET_0_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(0, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_0_A()
	{
		Registers.A = SET_u3_8bitRegister(0, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_1_B()
	{
		Registers.B = SET_u3_8bitRegister(1, Registers.B);

		return 2;
	}

	int CPU::SET_1_C()
	{
		Registers.C = SET_u3_8bitRegister(1, Registers.C);

		return 2;
	}

	int CPU::SET_1_D()
	{
		Registers.D = SET_u3_8bitRegister(1, Registers.D);

		return 2;
	}

	int CPU::SET_1_E()
	{
		Registers.E = SET_u3_8bitRegister(1, Registers.E);

		return 2;
	}

	int CPU::SET_1_H()
	{
		Registers.H = SET_u3_8bitRegister(1, Registers.H);

		return 2;
	}

	int CPU::SET_1_L()
	{
		Registers.L = SET_u3_8bitRegister(1, Registers.L);

		return 2;
	}

	int CPU::SET_1_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(1, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_1_A()
	{
		Registers.A = SET_u3_8bitRegister(1, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_2_B()
	{
		Registers.B = SET_u3_8bitRegister(2, Registers.B);

		return 2;
	}

	int CPU::SET_2_C()
	{
		Registers.C = SET_u3_8bitRegister(2, Registers.C);

		return 2;
	}

	int CPU::SET_2_D()
	{
		Registers.D = SET_u3_8bitRegister(2, Registers.D);

		return 2;
	}

	int CPU::SET_2_E()
	{
		Registers.E = SET_u3_8bitRegister(2, Registers.E);

		return 2;
	}

	int CPU::SET_2_H()
	{
		Registers.H = SET_u3_8bitRegister(2, Registers.H);

		return 2;
	}

	int CPU::SET_2_L()
	{
		Registers.L = SET_u3_8bitRegister(2, Registers.L);

		return 2;
	}

	int CPU::SET_2_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(2, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_2_A()
	{
		Registers.A = SET_u3_8bitRegister(2, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_3_B()
	{
		Registers.B = SET_u3_8bitRegister(3, Registers.B);

		return 2;
	}

	int CPU::SET_3_C()
	{
		Registers.C = SET_u3_8bitRegister(3, Registers.C);

		return 2;
	}

	int CPU::SET_3_D()
	{
		Registers.D = SET_u3_8bitRegister(3, Registers.D);

		return 2;
	}

	int CPU::SET_3_E()
	{
		Registers.E = SET_u3_8bitRegister(3, Registers.E);

		return 2;
	}

	int CPU::SET_3_H()
	{
		Registers.H = SET_u3_8bitRegister(3, Registers.H);

		return 2;
	}

	int CPU::SET_3_L()
	{
		Registers.L = SET_u3_8bitRegister(3, Registers.L);

		return 2;
	}

	int CPU::SET_3_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(3, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_3_A()
	{
		Registers.A = SET_u3_8bitRegister(3, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_4_B()
	{
		Registers.B = SET_u3_8bitRegister(4, Registers.B);

		return 2;
	}

	int CPU::SET_4_C()
	{
		Registers.C = SET_u3_8bitRegister(4, Registers.C);

		return 2;
	}

	int CPU::SET_4_D()
	{
		Registers.D = SET_u3_8bitRegister(4, Registers.D);

		return 2;
	}

	int CPU::SET_4_E()
	{
		Registers.E = SET_u3_8bitRegister(4, Registers.E);

		return 2;
	}

	int CPU::SET_4_H()
	{
		Registers.H = SET_u3_8bitRegister(4, Registers.H);

		return 2;
	}

	int CPU::SET_4_L()
	{
		Registers.L = SET_u3_8bitRegister(4, Registers.L);

		return 2;
	}

	int CPU::SET_4_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(4, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_4_A()
	{
		Registers.A = SET_u3_8bitRegister(4, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_5_B()
	{
		Registers.B = SET_u3_8bitRegister(5, Registers.B);

		return 2;
	}

	int CPU::SET_5_C()
	{
		Registers.C = SET_u3_8bitRegister(5, Registers.C);

		return 2;
	}

	int CPU::SET_5_D()
	{
		Registers.D = SET_u3_8bitRegister(5, Registers.D);

		return 2;
	}

	int CPU::SET_5_E()
	{
		Registers.E = SET_u3_8bitRegister(5, Registers.E);

		return 2;
	}

	int CPU::SET_5_H()
	{
		Registers.H = SET_u3_8bitRegister(5, Registers.H);

		return 2;
	}

	int CPU::SET_5_L()
	{
		Registers.L = SET_u3_8bitRegister(5, Registers.L);

		return 2;
	}

	int CPU::SET_5_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(5, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_5_A()
	{
		Registers.A = SET_u3_8bitRegister(5, Registers.A);

		return 2;
	}




	int GameBoyEmulator::CPU::SET_6_B()
	{
		Registers.B = SET_u3_8bitRegister(6, Registers.B);

		return 2;
	}

	int CPU::SET_6_C()
	{
		Registers.C = SET_u3_8bitRegister(6, Registers.C);

		return 2;
	}

	int CPU::SET_6_D()
	{
		Registers.D = SET_u3_8bitRegister(6, Registers.D);

		return 2;
	}

	int CPU::SET_6_E()
	{
		Registers.E = SET_u3_8bitRegister(6, Registers.E);

		return 2;
	}

	int CPU::SET_6_H()
	{
		Registers.H = SET_u3_8bitRegister(6, Registers.H);

		return 2;
	}

	int CPU::SET_6_L()
	{
		Registers.L = SET_u3_8bitRegister(6, Registers.L);

		return 2;
	}

	int CPU::SET_6_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(6, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_6_A()
	{
		Registers.A = SET_u3_8bitRegister(6, Registers.A);

		return 2;
	}



	int GameBoyEmulator::CPU::SET_7_B()
	{
		Registers.B = SET_u3_8bitRegister(7, Registers.B);

		return 2;
	}

	int CPU::SET_7_C()
	{
		Registers.C = SET_u3_8bitRegister(7, Registers.C);

		return 2;
	}

	int CPU::SET_7_D()
	{
		Registers.D = SET_u3_8bitRegister(7, Registers.D);

		return 2;
	}

	int CPU::SET_7_E()
	{
		Registers.E = SET_u3_8bitRegister(7, Registers.E);

		return 2;
	}

	int CPU::SET_7_H()
	{
		Registers.H = SET_u3_8bitRegister(7, Registers.H);

		return 2;
	}

	int CPU::SET_7_L()
	{
		Registers.L = SET_u3_8bitRegister(7, Registers.L);

		return 2;
	}

	int CPU::SET_7_MHL()
	{
		Memory.WriteData(SET_u3_8bitRegister(7, Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SET_7_A()
	{
		Registers.A = SET_u3_8bitRegister(7, Registers.A);

		return 2;
	}

}