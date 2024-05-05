#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Non prefixed bit shift instructions instructions
	int CPU::RRCA()
	{
		bool bit = Registers.A & 1;
		Registers.A = Registers.A >> 1;

		if (bit)
		{
			Registers.A = Registers.A | (1 << 7);
		}
		else
		{
			Registers.A = Registers.A & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return 1;
	}

	int CPU::RRA()
	{
		bool bit = Registers.A & 1;
		Registers.A = Registers.A >> 1;

		if (Registers.GetCarryFlag())
		{
			Registers.A = Registers.A | (1 << 7);
		}
		else
		{
			Registers.A = Registers.A & (~(1 << 7));
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return 1;
	}

	int CPU::RLCA()
	{
		bool bit = Registers.A >> 7;

		Registers.A = Registers.A << 1;
		
		if (bit)
		{
			Registers.A = Registers.A | 1;
		}
		else 
		{
			Registers.A = Registers.A & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return 1;
	}

	int CPU::RLA()
	{
		bool bit = Registers.A >> 7;

		Registers.A = Registers.A << 1;

		if (Registers.GetCarryFlag())
		{
			Registers.A = Registers.A | 1;
		}
		else
		{
			Registers.A = Registers.A & (~1);
		}

		Registers.SetZeroFlag(false);
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(false);
		Registers.SetCarryFlag(bit);

		return 1;
	}

}