#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions

	uint8_t CPU::RLC8bitRegister(uint8_t reg)
	{
		bool bit = reg >> 7;
		reg = reg << 1;

		if (bit)
		{
			reg = reg | 1;
		}
		else
		{
			reg = reg & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);
		
		return reg;
	}

	uint8_t CPU::RRC8bitRegister(uint8_t reg)
	{
		bool bit = reg & 1;
		reg = reg >> 1;

		if (bit)
		{
			reg = reg | (1 << 7);
		}
		else
		{
			reg = reg & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	uint8_t CPU::RL8bitRegister(uint8_t reg)
	{
		bool bit = reg >> 7;
		reg = reg << 1;

		if (Registers.GetCarryFlag())
		{
			reg = reg | 1;
		}
		else
		{
			reg = reg & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	uint8_t CPU::RR8bitRegister(uint8_t reg)
	{
		bool bit = reg & 1;
		reg = reg >> 1;

		if (Registers.GetCarryFlag())
		{
			reg = reg | (1 << 7);
		}
		else
		{
			reg = reg & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	uint8_t CPU::SLA8bitRegister(uint8_t reg)
	{
		bool bit = reg >> 7;
		reg = reg << 1;

		Registers.SetZeroFlag(reg == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	uint8_t CPU::SRA8bitRegister(uint8_t reg)
	{
		bool bit7 = reg >> 7;
		bool bit = reg & 1;
		reg = reg >> 1;
		if (bit7)
		{
			reg = reg | (1 << 7);
		}

		Registers.SetZeroFlag(reg == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	uint8_t CPU::SWAP8bitRegister(uint8_t reg)
	{
		uint8_t Upper4bits = reg >> 4;
		uint8_t Lower4bits = reg & 0x0F;

		reg = (Lower4bits << 4) | Upper4bits;

		Registers.SetZeroFlag(reg == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(false);

		return reg;
	}

	uint8_t CPU::SRL8bitRegister(uint8_t reg)
	{
		bool bit = reg & 1;
		reg = reg >> 1;

		Registers.SetZeroFlag(reg == 0);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return reg;
	}

	// Actual instruction definitions

	// Non prefixed bit shift instructions instructions
	int CPU::RRCA()
	{
		Registers.A = RRC8bitRegister(Registers.A);

		return 1;
	}

	int CPU::RRA()
	{
		Registers.A = RR8bitRegister(Registers.A);

		return 1;
	}

	int CPU::RLCA()
	{
		Registers.A = RLC8bitRegister(Registers.A);

		return 1;
	}

	int CPU::RLA()
	{
		Registers.A = RL8bitRegister(Registers.A);

		return 1;
	}

	// Prefixed instructions

	int CPU::RLC_B()
	{
		Registers.B = RLC8bitRegister(Registers.B);

		return 2;
	}

	int CPU::RLC_C()
	{
		Registers.C = RLC8bitRegister(Registers.C);

		return 2;
	}

	int CPU::RLC_D()
	{
		Registers.D = RLC8bitRegister(Registers.D);

		return 2;
	}

	int CPU::RLC_E()
	{
		Registers.E = RLC8bitRegister(Registers.E);

		return 2;
	}

	int CPU::RLC_H()
	{
		Registers.H = RLC8bitRegister(Registers.H);

		return 2;
	}

	int CPU::RLC_L()
	{
		Registers.L = RLC8bitRegister(Registers.L);

		return 2;
	}

	int CPU::RLC_MHL()
	{
		Memory.WriteData(RLC8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RLC_A()
	{
		Registers.A = RLC8bitRegister(Registers.A);

		return 2;
	}

	int CPU::RRC_B()
	{
		Registers.B = RRC8bitRegister(Registers.B);

		return 2;
	}

	int CPU::RRC_C()
	{
		Registers.C = RRC8bitRegister(Registers.C);

		return 2;
	}

	int CPU::RRC_D()
	{
		Registers.D = RRC8bitRegister(Registers.D);

		return 2;
	}

	int CPU::RRC_E()
	{
		Registers.E = RRC8bitRegister(Registers.E);

		return 2;
	}

	int CPU::RRC_H()
	{
		Registers.H = RRC8bitRegister(Registers.H);

		return 2;
	}

	int CPU::RRC_L()
	{
		Registers.L = RRC8bitRegister(Registers.L);

		return 2;
	}

	int CPU::RRC_MHL()
	{
		Memory.WriteData(RRC8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RRC_A()
	{
		Registers.A = RRC8bitRegister(Registers.A);

		return 2;
	}

	int CPU::RL_B()
	{
		Registers.B = RL8bitRegister(Registers.B);

		return 2;
	}

	int CPU::RL_C()
	{
		Registers.C = RL8bitRegister(Registers.C);

		return 2;
	}

	int CPU::RL_D()
	{
		Registers.D = RL8bitRegister(Registers.D);

		return 2;
	}

	int CPU::RL_E()
	{
		Registers.E = RL8bitRegister(Registers.E);

		return 2;
	}

	int CPU::RL_H()
	{
		Registers.H = RL8bitRegister(Registers.H);

		return 2;
	}

	int CPU::RL_L()
	{
		Registers.L = RL8bitRegister(Registers.L);

		return 2;
	}

	int CPU::RL_MHL()
	{
		Memory.WriteData(RL8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RL_A()
	{
		Registers.A = RL8bitRegister(Registers.A);

		return 2;
	}

	int CPU::RR_B()
	{
		Registers.B = RR8bitRegister(Registers.B);

		return 2;
	}

	int CPU::RR_C()
	{
		Registers.C = RR8bitRegister(Registers.C);

		return 2;
	}

	int CPU::RR_D()
	{
		Registers.D = RR8bitRegister(Registers.D);

		return 2;
	}

	int CPU::RR_E()
	{
		Registers.E = RR8bitRegister(Registers.E);

		return 2;
	}

	int CPU::RR_H()
	{
		Registers.H = RR8bitRegister(Registers.H);

		return 2;
	}

	int CPU::RR_L()
	{
		Registers.L = RR8bitRegister(Registers.L);

		return 2;
	}

	int CPU::RR_MHL()
	{
		Memory.WriteData(RR8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::RR_A()
	{
		Registers.A = RR8bitRegister(Registers.A);

		return 2;
	}

	int CPU::SLA_B()
	{
		Registers.B = SLA8bitRegister(Registers.B);

		return 2;
	}

	int CPU::SLA_C()
	{
		Registers.C = SLA8bitRegister(Registers.C);

		return 2;
	}

	int CPU::SLA_D()
	{
		Registers.D = SLA8bitRegister(Registers.D);

		return 2;
	}

	int CPU::SLA_E()
	{
		Registers.E = SLA8bitRegister(Registers.E);

		return 2;
	}

	int CPU::SLA_H()
	{
		Registers.H = SLA8bitRegister(Registers.H);

		return 2;
	}

	int CPU::SLA_L()
	{
		Registers.L = SLA8bitRegister(Registers.L);

		return 2;
	}

	int CPU::SLA_MHL()
	{
		Memory.WriteData(SLA8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SLA_A()
	{
		Registers.A = SLA8bitRegister(Registers.A);

		return 2;
	}

	int CPU::SRA_B()
	{
		Registers.B = SRA8bitRegister(Registers.B);

		return 2;
	}

	int CPU::SRA_C()
	{
		Registers.C = SRA8bitRegister(Registers.C);

		return 2;
	}

	int CPU::SRA_D()
	{
		Registers.D = SRA8bitRegister(Registers.D);

		return 2;
	}

	int CPU::SRA_E()
	{
		Registers.E = SRA8bitRegister(Registers.E);

		return 2;
	}

	int CPU::SRA_H()
	{
		Registers.H = SRA8bitRegister(Registers.H);

		return 2;
	}

	int CPU::SRA_L()
	{
		Registers.L = SRA8bitRegister(Registers.L);

		return 2;
	}

	int CPU::SRA_MHL()
	{
		Memory.WriteData(SRA8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SRA_A()
	{
		Registers.A = SRA8bitRegister(Registers.A);

		return 2;
	}

	int CPU::SWAP_B()
	{
		Registers.B = SWAP8bitRegister(Registers.B);

		return 2;
	}

	int CPU::SWAP_C()
	{
		Registers.C = SWAP8bitRegister(Registers.C);

		return 2;
	}

	int CPU::SWAP_D()
	{
		Registers.D = SWAP8bitRegister(Registers.D);

		return 2;
	}

	int CPU::SWAP_E()
	{
		Registers.E = SWAP8bitRegister(Registers.E);

		return 2;
	}

	int CPU::SWAP_H()
	{
		Registers.H = SWAP8bitRegister(Registers.H);

		return 2;
	}

	int CPU::SWAP_L()
	{
		Registers.L = SWAP8bitRegister(Registers.L);

		return 2;
	}

	int CPU::SWAP_MHL()
	{
		Memory.WriteData(SWAP8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SWAP_A()
	{
		Registers.A = SWAP8bitRegister(Registers.A);

		return 2;
	}

	int CPU::SRL_B()
	{
		Registers.B = SRL8bitRegister(Registers.B);

		return 2;
	}

	int CPU::SRL_C()
	{
		Registers.C = SRL8bitRegister(Registers.C);

		return 2;
	}

	int CPU::SRL_D()
	{
		Registers.D = SRL8bitRegister(Registers.D);

		return 2;
	}

	int CPU::SRL_E()
	{
		Registers.E = SRL8bitRegister(Registers.E);

		return 2;
	}

	int CPU::SRL_H()
	{
		Registers.H = SRL8bitRegister(Registers.H);

		return 2;
	}

	int CPU::SRL_L()
	{
		Registers.L = SRL8bitRegister(Registers.L);

		return 2;
	}

	int CPU::SRL_MHL()
	{
		Memory.WriteData(SRL8bitRegister(Memory.ReadData(Registers.GetHL())), Registers.GetHL());

		return 2;
	}

	int CPU::SRL_A()
	{
		Registers.A = SRL8bitRegister(Registers.A);

		return 2;
	}

}