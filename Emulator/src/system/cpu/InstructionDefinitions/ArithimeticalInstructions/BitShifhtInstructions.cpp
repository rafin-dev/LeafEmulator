#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions

	void CPU::RLC8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) >> 7;
		*reg = (*reg) << 1;

		if (bit)
		{
			*reg = (*reg) | 1;
		}
		else
		{
			*reg = (*reg) & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::RRC8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) & 1;
		*reg = (*reg) >> 1;

		if (bit)
		{
			*reg = (*reg) | (1 << 7);
		}
		else
		{
			*reg = (*reg) & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::RL8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) >> 7;
		*reg = (*reg) << 1;

		if (Registers.GetCarryFlag())
		{
			*reg = (*reg) | 1;
		}
		else
		{
			*reg = (*reg) & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::RR8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) & 1;
		*reg = (*reg) >> 1;

		if (Registers.GetCarryFlag())
		{
			*reg = (*reg) | (1 << 7);
		}
		else
		{
			*reg = (*reg) & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::SLA8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) >> 7;
		*reg = (*reg) << 1;

		Registers.SetZeroFlag((*reg) == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::SRA8bitRegister(uint8_t* reg)
	{
		bool bit7 = (*reg) >> 7;
		bool bit = (*reg) & 1;
		*reg = (*reg) >> 1;
		if (bit7)
		{
			*reg = (*reg) | (1 << 7);
		}

		Registers.SetZeroFlag((*reg) == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	void CPU::SWAP8bitRegister(uint8_t* reg)
	{
		uint8_t Upper4bits = (*reg) >> 4;
		uint8_t Lower4bits = (*reg) & 0x0F;

		*reg = (Lower4bits << 4) | Upper4bits;

		Registers.SetZeroFlag((*reg) == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(false);
	}

	void CPU::SRL8bitRegister(uint8_t* reg)
	{
		bool bit = (*reg) & 1;
		*reg = (*reg) >> 1;

		Registers.SetZeroFlag((*reg) == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
	}

	// Actual instruction definitions

	// Non prefixed bit shift instructions instructions
	int CPU::RRCA()
	{
		RRC8bitRegister(&Registers.A);

		return 1;
	}

	int CPU::RRA()
	{
		RR8bitRegister(&Registers.A);

		return 1;
	}

	int CPU::RLCA()
	{
		RLC8bitRegister(&Registers.A);

		return 1;
	}

	int CPU::RLA()
	{
		RL8bitRegister(&Registers.A);

		return 1;
	}

	// Prefixed instructions

	int CPU::RLC_B()
	{
		RLC8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::RLC_C()
	{
		RLC8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::RLC_D()
	{
		RLC8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::RLC_E()
	{
		RLC8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::RLC_H()
	{
		RLC8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::RLC_L()
	{
		RLC8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::RLC_MHL()
	{
		RLC8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RLC_A()
	{
		RLC8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::RRC_B()
	{
		RRC8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::RRC_C()
	{
		RRC8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::RRC_D()
	{
		RRC8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::RRC_E()
	{
		RRC8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::RRC_H()
	{
		RRC8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::RRC_L()
	{
		RRC8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::RRC_MHL()
	{
		RRC8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RRC_A()
	{
		RRC8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::RL_B()
	{
		RL8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::RL_C()
	{
		RL8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::RL_D()
	{
		RL8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::RL_E()
	{
		RL8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::RL_H()
	{
		RL8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::RL_L()
	{
		RL8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::RL_MHL()
	{
		RL8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RL_A()
	{
		RL8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::RR_B()
	{
		RR8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::RR_C()
	{
		RR8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::RR_D()
	{
		RR8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::RR_E()
	{
		RR8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::RR_H()
	{
		RR8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::RR_L()
	{
		RR8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::RR_MHL()
	{
		RR8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::RR_A()
	{
		RR8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::SLA_B()
	{
		SLA8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::SLA_C()
	{
		SLA8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::SLA_D()
	{
		SLA8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::SLA_E()
	{
		SLA8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::SLA_H()
	{
		SLA8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::SLA_L()
	{
		SLA8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::SLA_MHL()
	{
		SLA8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SLA_A()
	{
		SLA8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::SRA_B()
	{
		SRA8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::SRA_C()
	{
		SRA8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::SRA_D()
	{
		SRA8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::SRA_E()
	{
		SRA8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::SRA_H()
	{
		SRA8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::SRA_L()
	{
		SRA8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::SRA_MHL()
	{
		SRA8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SRA_A()
	{
		SRA8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::SWAP_B()
	{
		SWAP8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::SWAP_C()
	{
		SWAP8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::SWAP_D()
	{
		SWAP8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::SWAP_E()
	{
		SWAP8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::SWAP_H()
	{
		SWAP8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::SWAP_L()
	{
		SWAP8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::SWAP_MHL()
	{
		SWAP8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SWAP_A()
	{
		SWAP8bitRegister(&Registers.A);

		return 2;
	}

	int CPU::SRL_B()
	{
		SRL8bitRegister(&Registers.B);

		return 2;
	}

	int CPU::SRL_C()
	{
		SRL8bitRegister(&Registers.C);

		return 2;
	}

	int CPU::SRL_D()
	{
		SRL8bitRegister(&Registers.D);

		return 2;
	}

	int CPU::SRL_E()
	{
		SRL8bitRegister(&Registers.E);

		return 2;
	}

	int CPU::SRL_H()
	{
		SRL8bitRegister(&Registers.H);

		return 2;
	}

	int CPU::SRL_L()
	{
		SRL8bitRegister(&Registers.L);

		return 2;
	}

	int CPU::SRL_MHL()
	{
		SRL8bitRegister(&Memory[Registers.GetHL()]);

		return 2;
	}

	int CPU::SRL_A()
	{
		SRL8bitRegister(&Registers.A);

		return 2;
	}

}