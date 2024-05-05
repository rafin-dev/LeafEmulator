#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	int CPU::PUSH_BC()
	{
		PushIntoStack(Registers.GetBC());

		return 1;
	}

	int CPU::PUSH_DE()
	{
		PushIntoStack(Registers.GetDE());

		return 1;
	}

	int CPU::PUSH_HL()
	{
		PushIntoStack(Registers.GetHL());

		return 1;
	}

	int CPU::PUSH_AF()
	{
		PushIntoStack(Registers.GetAF());

		return 1;
	}

	int CPU::POP_BC()
	{
		Registers.SetBC(PopFromStack());

		return 1;
	}

	int CPU::POP_DE()
	{
		Registers.SetDE(PopFromStack());

		return 1;
	}

	int CPU::POP_HL()
	{
		Registers.SetHL(PopFromStack());

		return 1;
	}

	int CPU::POP_AF()
	{
		Registers.SetAF(PopFromStack());

		return 1;
	}

}