#include "system/cpu/CPU.h"

namespace GameBoyEmulator {

	// Helper functions for the ADD instructions

	void CPU::SetAddInstructionsFlags16bit(long ADDresult)
	{
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(ADDresult > 0xFFF);
		Registers.SetCarryFlag(ADDresult > 0xFFFF);
	}

	void CPU::SetAddInstructionsFlags8bit(int ADDresult)
	{
		Registers.SetNegativeFlag(false);
		Registers.SetHalfCarryFlag(ADDresult > 0xF);
		Registers.SetCarryFlag(ADDresult > 0xFF);
		Registers.SetZeroFlag(ADDresult == 0);
	}

	void CPU::ADDtoHL(int n)
	{
		int Result = Registers.GetHL() + n;
		SetAddInstructionsFlags16bit(Result);
		Registers.SetHL(Result);
	}

	void CPU::ADDtoA(int n)
	{
		int Result = Registers.A + n;
		SetAddInstructionsFlags8bit(Result);
		Registers.A = Result;
	}

	// Actual Instruction definitions

	// 16 bit
	int CPU::ADD_HL_BC()
	{
		ADDtoHL(Registers.GetBC());

		return 1;
	}

	int CPU::ADD_HL_DE()
	{
		ADDtoHL(Registers.GetDE());

		return 1;
	}

	int CPU::ADD_HL_HL()
	{
		ADDtoHL(Registers.GetHL());

		return 1;
	}

	int CPU::ADD_HL_SP()
	{
		ADDtoHL(Registers.SP);

		return 1;
	}

	int CPU::ADD_SP_I8()
	{
		int8_t* n = (int8_t*)&Memory[Registers.PC + 1];
		int Result = Registers.SP + *n;

		Registers.SetZeroFlag(false);
		SetAddInstructionsFlags16bit(Result);

		Registers.SP = Result;

		return 2;
	}

	// 8 bit
	int CPU::ADD_A_B()
	{
		ADDtoA(Registers.B);

		return 1;
	}

	int CPU::ADD_A_C()
	{
		ADDtoA(Registers.C);

		return 1;
	}

	int CPU::ADD_A_D()
	{
		ADDtoA(Registers.D);

		return 1;
	}

	int CPU::ADD_A_E()
	{
		ADDtoA(Registers.E);

		return 1;
	}

	int CPU::ADD_A_H()
	{
		ADDtoA(Registers.H);

		return 1;
	}

	int CPU::ADD_A_L()
	{
		ADDtoA(Registers.L);

		return 1;
	}

	int CPU::ADD_A_MHL()
	{
		ADDtoA(Memory[Registers.GetHL()]);

		return 1;
	}

	int CPU::ADD_A_A()
	{
		ADDtoA(Registers.A);

		return 1;
	}

	int CPU::ADD_A_U8()
	{
		ADDtoA(Memory[Registers.PC + 1]);

		return 2;
	}

	// ADC instructions(all 8 bit)
	int CPU::ADC_A_B()
	{
		ADDtoA(Registers.B + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_C()
	{
		ADDtoA(Registers.C + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_D()
	{
		ADDtoA(Registers.D + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_E()
	{
		ADDtoA(Registers.E + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_H()
	{
		ADDtoA(Registers.H + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_L()
	{
		ADDtoA(Registers.L + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_MHL()
	{
		ADDtoA(Memory[Registers.GetHL()] + Registers.GetCarryFlag());

		return 1;
	}

	int CPU::ADC_A_A()
	{
		ADDtoA(Registers.A);

		return 1;
	}

	int CPU::ADC_A_U8()
	{
		ADDtoA(Memory[Registers.PC + 1] + Registers.GetCarryFlag());

		return 2;
	}
}