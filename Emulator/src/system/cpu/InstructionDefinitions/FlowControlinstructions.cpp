#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// The desing for the instruction functions makes so that the function
	// return the size of it's instruction, that value will be later added into
	// PC, some flow control instructions would either leadd into wrong behaviour
	// or weird code if I followwed that convention created by myself
	// So, some instructions will return 0 and make the changes in PC by themselves

	int CPU::JP_U16()
	{
		Registers.PC = GETU16M;

		// This function does not take 0 bytes, but I dont wnat to increment the
		// recently updated PC
		return 0;
	}

	int CPU::JP_HL()
	{
		Registers.PC = Registers.GetHL();

		// This function does not take 0 bytes, but I dont wnat to increment the
		// recently updated PC
		return 0;
	}

	int CPU::JP_C_U16()
	{
		if (Registers.GetCarryFlag())
		{
			Registers.PC = GETU16M;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::JP_Z_U16()
	{
		if (Registers.GetZeroFlag())
		{
			Registers.PC = GETU16M;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::JP_NC_U16()
	{
		if (!Registers.GetCarryFlag())
		{
			Registers.PC = GETU16M;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::JP_NZ_U16()
	{
		if (!Registers.GetZeroFlag())
		{
			Registers.PC = GETU16M;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::JR_I8()
	{
		int relativeAddres = *((int*)(&Memory[Registers.PC + 1]));
		Registers.PC += 2;
		Registers.PC = Registers.PC + relativeAddres;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::JR_Z_I8()
	{
		if (Registers.GetZeroFlag())
		{
			int relativeAddres = *((int*)(&Memory[Registers.PC + 1]));
			Registers.PC += 2;
			Registers.PC = Registers.PC + relativeAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 2;
	}

	int CPU::JR_C_I8()
	{
		if (Registers.GetCarryFlag())
		{
			int relativeAddres = *((int*)(&Memory[Registers.PC + 1]));
			Registers.PC += 2;
			Registers.PC = Registers.PC + relativeAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 2;
	}

	int CPU::JR_NZ_I8()
	{
		if (!Registers.GetZeroFlag())
		{
			int relativeAddres = *((int*)(&Memory[Registers.PC + 1]));
			Registers.PC += 2;
			Registers.PC = Registers.PC + relativeAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 2;
	}

	int CPU::JR_NC_I8()
	{
		if (!Registers.GetCarryFlag())
		{
			int relativeAddres = *((int*)(&Memory[Registers.PC + 1]));
			Registers.PC += 2;
			Registers.PC = Registers.PC + relativeAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 2;
	}

	int CPU::CALL_U16()
	{
		uint16_t functionAddres = GETU16M;
		PushIntoStack(Registers.PC);
		Registers.PC = functionAddres;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::CALL_Z_U16()
	{
		if (Registers.GetZeroFlag())
		{
			uint16_t functionAddres = GETU16M;
			PushIntoStack(Registers.PC);
			Registers.PC = functionAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::CALL_C_U16()
	{
		if (Registers.GetCarryFlag())
		{
			uint16_t functionAddres = GETU16M;
			PushIntoStack(Registers.PC);
			Registers.PC = functionAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::CALL_NZ_U16()
	{
		if (!Registers.GetZeroFlag())
		{
			uint16_t functionAddres = GETU16M;
			PushIntoStack(Registers.PC);
			Registers.PC = functionAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::CALL_NC_U16()
	{
		if (!Registers.GetCarryFlag())
		{
			uint16_t functionAddres = GETU16M;
			PushIntoStack(Registers.PC);
			Registers.PC = functionAddres;

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 3;
	}

	int CPU::RET()
	{
		Registers.PC = PopFromStack();

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RET_Z()
	{
		if (Registers.GetZeroFlag())
		{
			Registers.PC = PopFromStack();

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 1;
	}

	int CPU::RET_C()
	{
		if (Registers.GetCarryFlag())
		{
			Registers.PC = PopFromStack();

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 1;
	}

	int CPU::RET_NZ()
	{
		if (!Registers.GetZeroFlag())
		{
			Registers.PC = PopFromStack();

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 1;
	}

	int CPU::RET_NC()
	{
		if (!Registers.GetCarryFlag())
		{
			Registers.PC = PopFromStack();

			// Return 0 here so the new PC value is not incrmented
			return 0;
		}

		return 1;
	}

	int CPU::RETI()
	{
		Registers.PC = PopFromStack();
		Registers.IME = true;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x00()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x00;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x10()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x10;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x20()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x20;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x30()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x30;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x08()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x08;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x18()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x18;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x28()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x28;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}

	int CPU::RST_0x38()
	{
		PushIntoStack(Registers.PC);
		Registers.PC = 0x38;

		// Return 0 here so the new PC value is not incrmented
		return 0;
	}


}