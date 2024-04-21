#include "CPU.h"

// Define to help passing a method as function pointer
#define ADDFUNC(x) std::bind(&CPU::x, this)
#define MAPPAIR(...) std::make_pair<uint8_t, InstructionFunc>(__VA_ARGS__)

namespace GameBoyEmulator {

	void CPU::AddInstructionsToMap()
	{
		// Sets all the instruction functions on the map

		// Increment Instructions

		// 16 bit increments
		InstructionMap.insert(MAPPAIR(0x03, ADDFUNC(INC_BC)));
		InstructionMap.insert(MAPPAIR(0x13, ADDFUNC(INC_DE)));
		InstructionMap.insert(MAPPAIR(0x23, ADDFUNC(INC_HL)));
		InstructionMap.insert(MAPPAIR(0x33, ADDFUNC(INC_SP)));

		// 8 bit increments
		InstructionMap.insert(MAPPAIR(0x04, ADDFUNC(INC_B)));
		InstructionMap.insert(MAPPAIR(0x14, ADDFUNC(INC_D)));
		InstructionMap.insert(MAPPAIR(0x25, ADDFUNC(INC_H)));
		InstructionMap.insert(MAPPAIR(0x34, ADDFUNC(INC_MHL)));
		InstructionMap.insert(MAPPAIR(0x0C, ADDFUNC(INC_C)));
		InstructionMap.insert(MAPPAIR(0x1C, ADDFUNC(INC_E)));
		InstructionMap.insert(MAPPAIR(0x2C, ADDFUNC(INC_L)));
		InstructionMap.insert(MAPPAIR(0x3C, ADDFUNC(INC_A)));

		// Decrement Instructions

		// 16 bit decrements
		InstructionMap.insert(MAPPAIR(0x0B, ADDFUNC(DEC_BC)));
		InstructionMap.insert(MAPPAIR(0x1B, ADDFUNC(DEC_DE)));
		InstructionMap.insert(MAPPAIR(0x2B, ADDFUNC(DEC_HL)));
		InstructionMap.insert(MAPPAIR(0x3B, ADDFUNC(DEC_SP)));

		// 8 bit decrements
		InstructionMap.insert(MAPPAIR(0x05, ADDFUNC(DEC_B)));
		InstructionMap.insert(MAPPAIR(0x15, ADDFUNC(DEC_D)));
		InstructionMap.insert(MAPPAIR(0x25, ADDFUNC(DEC_H)));
		InstructionMap.insert(MAPPAIR(0x35, ADDFUNC(DEC_MHL)));
		InstructionMap.insert(MAPPAIR(0x0D, ADDFUNC(DEC_C)));
		InstructionMap.insert(MAPPAIR(0x1D, ADDFUNC(DEC_E)));
		InstructionMap.insert(MAPPAIR(0x2D, ADDFUNC(DEC_L)));
		InstructionMap.insert(MAPPAIR(0x3D, ADDFUNC(DEC_A)));

		InstructionMap.insert(MAPPAIR(0x3F, ADDFUNC(CCF)));
		InstructionMap.insert(MAPPAIR(0x37, ADDFUNC(SCF)));

		// ADD Instructions

		// 16 bit ADDs
		InstructionMap.insert(MAPPAIR(0x09, ADDFUNC(ADD_HL_BC)));
		InstructionMap.insert(MAPPAIR(0x09, ADDFUNC(ADD_HL_BC)));
		InstructionMap.insert(MAPPAIR(0x29, ADDFUNC(ADD_HL_HL)));
		InstructionMap.insert(MAPPAIR(0x39, ADDFUNC(ADD_HL_SP)));
		InstructionMap.insert(MAPPAIR(0xE8, ADDFUNC(ADD_SP_I8)));

		// 8 bit ADDs
		InstructionMap.insert(MAPPAIR(0x80, ADDFUNC(ADD_A_B)));
		InstructionMap.insert(MAPPAIR(0x81, ADDFUNC(ADD_A_C)));
		InstructionMap.insert(MAPPAIR(0x82, ADDFUNC(ADD_A_D)));
		InstructionMap.insert(MAPPAIR(0x83, ADDFUNC(ADD_A_E)));
		InstructionMap.insert(MAPPAIR(0x84, ADDFUNC(ADD_A_H)));
		InstructionMap.insert(MAPPAIR(0x85, ADDFUNC(ADD_A_L)));
		InstructionMap.insert(MAPPAIR(0x86, ADDFUNC(ADD_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x87, ADDFUNC(ADD_A_A)));
		InstructionMap.insert(MAPPAIR(0xC6, ADDFUNC(ADD_A_U8)));

		// ADC instructions(all 8 bit)
		InstructionMap.insert(MAPPAIR(0x88, ADDFUNC(ADC_A_B)));
		InstructionMap.insert(MAPPAIR(0x89, ADDFUNC(ADC_A_C)));
		InstructionMap.insert(MAPPAIR(0x8A, ADDFUNC(ADC_A_D)));
		InstructionMap.insert(MAPPAIR(0x8B, ADDFUNC(ADC_A_E)));
		InstructionMap.insert(MAPPAIR(0x8C, ADDFUNC(ADC_A_H)));
		InstructionMap.insert(MAPPAIR(0x8D, ADDFUNC(ADC_A_L)));
		InstructionMap.insert(MAPPAIR(0x8E, ADDFUNC(ADC_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x8F, ADDFUNC(ADC_A_A)));
		InstructionMap.insert(MAPPAIR(0xCE, ADDFUNC(ADC_A_U8)));

		// SUB instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0x90, ADDFUNC(SUB_A_B)));
		InstructionMap.insert(MAPPAIR(0x91, ADDFUNC(SUB_A_C)));
		InstructionMap.insert(MAPPAIR(0x92, ADDFUNC(SUB_A_D)));
		InstructionMap.insert(MAPPAIR(0x93, ADDFUNC(SUB_A_E)));
		InstructionMap.insert(MAPPAIR(0x94, ADDFUNC(SUB_A_H)));
		InstructionMap.insert(MAPPAIR(0x95, ADDFUNC(SUB_A_L)));
		InstructionMap.insert(MAPPAIR(0x96, ADDFUNC(SUB_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x97, ADDFUNC(SUB_A_A)));
		InstructionMap.insert(MAPPAIR(0xD6, ADDFUNC(SUB_A_U8)));

		// SBC instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0x98, ADDFUNC(SBC_A_B)));
		InstructionMap.insert(MAPPAIR(0x99, ADDFUNC(SBC_A_C)));
		InstructionMap.insert(MAPPAIR(0x9A, ADDFUNC(SBC_A_D)));
		InstructionMap.insert(MAPPAIR(0x9B, ADDFUNC(SBC_A_E)));
		InstructionMap.insert(MAPPAIR(0x9C, ADDFUNC(SBC_A_H)));
		InstructionMap.insert(MAPPAIR(0x9D, ADDFUNC(SBC_A_L)));
		InstructionMap.insert(MAPPAIR(0x9E, ADDFUNC(SBC_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x9F, ADDFUNC(SBC_A_A)));
		InstructionMap.insert(MAPPAIR(0xCE, ADDFUNC(SBC_A_U8)));

		// AND instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0xA0, ADDFUNC(AND_A_B)));
		InstructionMap.insert(MAPPAIR(0xA1, ADDFUNC(AND_A_C)));
		InstructionMap.insert(MAPPAIR(0xA2, ADDFUNC(AND_A_D)));
		InstructionMap.insert(MAPPAIR(0xA3, ADDFUNC(AND_A_E)));
		InstructionMap.insert(MAPPAIR(0xA4, ADDFUNC(AND_A_H)));
		InstructionMap.insert(MAPPAIR(0xA5, ADDFUNC(AND_A_L)));
		InstructionMap.insert(MAPPAIR(0xA6, ADDFUNC(AND_A_MHL)));
		InstructionMap.insert(MAPPAIR(0xA7, ADDFUNC(AND_A_A)));
		InstructionMap.insert(MAPPAIR(0xE6, ADDFUNC(AND_A_U8)));

		// XOR instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0xA8, ADDFUNC(XOR_A_B)));
		InstructionMap.insert(MAPPAIR(0xA9, ADDFUNC(XOR_A_C)));
		InstructionMap.insert(MAPPAIR(0xAA, ADDFUNC(XOR_A_D)));
		InstructionMap.insert(MAPPAIR(0xAB, ADDFUNC(XOR_A_E)));
		InstructionMap.insert(MAPPAIR(0xAC, ADDFUNC(XOR_A_H)));
		InstructionMap.insert(MAPPAIR(0xAD, ADDFUNC(XOR_A_L)));
		InstructionMap.insert(MAPPAIR(0xAE, ADDFUNC(XOR_A_MHL)));
		InstructionMap.insert(MAPPAIR(0xAF, ADDFUNC(XOR_A_A)));
		InstructionMap.insert(MAPPAIR(0xEE, ADDFUNC(XOR_A_U8)));

		// OR instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0xB0, ADDFUNC(OR_A_B)));
		InstructionMap.insert(MAPPAIR(0xB1, ADDFUNC(OR_A_C)));
		InstructionMap.insert(MAPPAIR(0xB2, ADDFUNC(OR_A_D)));
		InstructionMap.insert(MAPPAIR(0xB3, ADDFUNC(OR_A_E)));
		InstructionMap.insert(MAPPAIR(0xB4, ADDFUNC(OR_A_H)));
		InstructionMap.insert(MAPPAIR(0xB5, ADDFUNC(OR_A_L)));
		InstructionMap.insert(MAPPAIR(0xB6, ADDFUNC(OR_A_MHL)));
		InstructionMap.insert(MAPPAIR(0xB7, ADDFUNC(OR_A_A)));
		InstructionMap.insert(MAPPAIR(0xF6, ADDFUNC(OR_A_U8)));

		// CP instructions (all 8 bit)
		InstructionMap.insert(MAPPAIR(0xB8, ADDFUNC(CP_A_B)));
		InstructionMap.insert(MAPPAIR(0xB9, ADDFUNC(CP_A_C)));
		InstructionMap.insert(MAPPAIR(0xBA, ADDFUNC(CP_A_D)));
		InstructionMap.insert(MAPPAIR(0xBB, ADDFUNC(CP_A_E)));
		InstructionMap.insert(MAPPAIR(0xBC, ADDFUNC(CP_A_H)));
		InstructionMap.insert(MAPPAIR(0xBD, ADDFUNC(CP_A_L)));
		InstructionMap.insert(MAPPAIR(0xBE, ADDFUNC(CP_A_MHL)));
		InstructionMap.insert(MAPPAIR(0xBF, ADDFUNC(CP_A_A)));
		InstructionMap.insert(MAPPAIR(0xFE, ADDFUNC(CP_A_U8)));

		// LD instructions

		// 16 bit
		InstructionMap.insert(MAPPAIR(0x01, ADDFUNC(LD_BC_U16)));
		InstructionMap.insert(MAPPAIR(0x11, ADDFUNC(LD_DE_U16)));
		InstructionMap.insert(MAPPAIR(0x21, ADDFUNC(LD_HL_U16)));
		InstructionMap.insert(MAPPAIR(0x31, ADDFUNC(LD_SP_U16)));
		InstructionMap.insert(MAPPAIR(0x08, ADDFUNC(LD_MU16_SP)));
		InstructionMap.insert(MAPPAIR(0xF9, ADDFUNC(LD_SP_HL)));
		InstructionMap.insert(MAPPAIR(0xF8, ADDFUNC(LD_HL_SPpI8)));

		// 8 bit
		InstructionMap.insert(MAPPAIR(0x02, ADDFUNC(LD_MBC_A)));
		InstructionMap.insert(MAPPAIR(0x12, ADDFUNC(LD_MDE_A)));
		InstructionMap.insert(MAPPAIR(0x22, ADDFUNC(LD_MHLp_A)));
		InstructionMap.insert(MAPPAIR(0x32, ADDFUNC(LD_MHLm_A)));
		InstructionMap.insert(MAPPAIR(0x06, ADDFUNC(LD_B_U8)));
		InstructionMap.insert(MAPPAIR(0x16, ADDFUNC(LD_D_U8)));
		InstructionMap.insert(MAPPAIR(0x26, ADDFUNC(LD_H_U8)));
		InstructionMap.insert(MAPPAIR(0x36, ADDFUNC(LD_MHL_U8)));
		InstructionMap.insert(MAPPAIR(0x0A, ADDFUNC(LD_A_MBC)));
		InstructionMap.insert(MAPPAIR(0x1A, ADDFUNC(LD_A_MDE)));
		InstructionMap.insert(MAPPAIR(0x2A, ADDFUNC(LD_A_MHLp)));
		InstructionMap.insert(MAPPAIR(0x3A, ADDFUNC(LD_A_MHLm)));
		InstructionMap.insert(MAPPAIR(0x0E, ADDFUNC(LD_C_U8)));
		InstructionMap.insert(MAPPAIR(0x1E, ADDFUNC(LD_E_U8)));
		InstructionMap.insert(MAPPAIR(0x2E, ADDFUNC(LD_L_U8)));
		InstructionMap.insert(MAPPAIR(0x40, ADDFUNC(LD_B_B)));
		InstructionMap.insert(MAPPAIR(0x41, ADDFUNC(LD_B_C)));
		InstructionMap.insert(MAPPAIR(0x42, ADDFUNC(LD_B_D)));
		InstructionMap.insert(MAPPAIR(0x43, ADDFUNC(LD_B_E)));
		InstructionMap.insert(MAPPAIR(0x44, ADDFUNC(LD_B_H)));
		InstructionMap.insert(MAPPAIR(0x45, ADDFUNC(LD_B_L)));
		InstructionMap.insert(MAPPAIR(0x46, ADDFUNC(LD_B_MHL)));
		InstructionMap.insert(MAPPAIR(0x47, ADDFUNC(LD_B_A)));
		InstructionMap.insert(MAPPAIR(0x48, ADDFUNC(LD_C_B)));
		InstructionMap.insert(MAPPAIR(0x49, ADDFUNC(LD_C_C)));
		InstructionMap.insert(MAPPAIR(0x4A, ADDFUNC(LD_C_D)));
		InstructionMap.insert(MAPPAIR(0x4B, ADDFUNC(LD_C_E)));
		InstructionMap.insert(MAPPAIR(0x4C, ADDFUNC(LD_C_H)));
		InstructionMap.insert(MAPPAIR(0x4D, ADDFUNC(LD_C_L)));
		InstructionMap.insert(MAPPAIR(0x4E, ADDFUNC(LD_C_MHL)));
		InstructionMap.insert(MAPPAIR(0x4F, ADDFUNC(LD_C_A)));
		InstructionMap.insert(MAPPAIR(0x50, ADDFUNC(LD_D_B)));
		InstructionMap.insert(MAPPAIR(0x51, ADDFUNC(LD_D_C)));
		InstructionMap.insert(MAPPAIR(0x52, ADDFUNC(LD_D_D)));
		InstructionMap.insert(MAPPAIR(0x53, ADDFUNC(LD_D_E)));
		InstructionMap.insert(MAPPAIR(0x54, ADDFUNC(LD_D_H)));
		InstructionMap.insert(MAPPAIR(0x55, ADDFUNC(LD_D_L)));
		InstructionMap.insert(MAPPAIR(0x56, ADDFUNC(LD_D_MHL)));
		InstructionMap.insert(MAPPAIR(0x57, ADDFUNC(LD_D_A)));
		InstructionMap.insert(MAPPAIR(0x58, ADDFUNC(LD_E_B)));
		InstructionMap.insert(MAPPAIR(0x59, ADDFUNC(LD_E_C)));
		InstructionMap.insert(MAPPAIR(0x5A, ADDFUNC(LD_E_D)));
		InstructionMap.insert(MAPPAIR(0x5B, ADDFUNC(LD_E_E)));
		InstructionMap.insert(MAPPAIR(0x5C, ADDFUNC(LD_E_H)));
		InstructionMap.insert(MAPPAIR(0x5D, ADDFUNC(LD_E_L)));
		InstructionMap.insert(MAPPAIR(0x5E, ADDFUNC(LD_E_MHL)));
		InstructionMap.insert(MAPPAIR(0x5F, ADDFUNC(LD_E_A)));
		InstructionMap.insert(MAPPAIR(0x60, ADDFUNC(LD_H_B)));
		InstructionMap.insert(MAPPAIR(0x61, ADDFUNC(LD_H_C)));
		InstructionMap.insert(MAPPAIR(0x62, ADDFUNC(LD_H_D)));
		InstructionMap.insert(MAPPAIR(0x63, ADDFUNC(LD_H_E)));
		InstructionMap.insert(MAPPAIR(0x64, ADDFUNC(LD_H_H)));
		InstructionMap.insert(MAPPAIR(0x65, ADDFUNC(LD_H_L)));
		InstructionMap.insert(MAPPAIR(0x66, ADDFUNC(LD_H_MHL)));
		InstructionMap.insert(MAPPAIR(0x67, ADDFUNC(LD_H_A)));
		InstructionMap.insert(MAPPAIR(0x68, ADDFUNC(LD_L_B)));
		InstructionMap.insert(MAPPAIR(0x69, ADDFUNC(LD_L_C)));
		InstructionMap.insert(MAPPAIR(0x6A, ADDFUNC(LD_L_D)));
		InstructionMap.insert(MAPPAIR(0x6B, ADDFUNC(LD_L_E)));
		InstructionMap.insert(MAPPAIR(0x6C, ADDFUNC(LD_L_H)));
		InstructionMap.insert(MAPPAIR(0x6D, ADDFUNC(LD_L_L)));
		InstructionMap.insert(MAPPAIR(0x6E, ADDFUNC(LD_L_MHL)));
		InstructionMap.insert(MAPPAIR(0x6F, ADDFUNC(LD_L_A)));
		InstructionMap.insert(MAPPAIR(0x70, ADDFUNC(LD_MHL_B)));
		InstructionMap.insert(MAPPAIR(0x71, ADDFUNC(LD_MHL_C)));
		InstructionMap.insert(MAPPAIR(0x72, ADDFUNC(LD_MHL_D)));
		InstructionMap.insert(MAPPAIR(0x73, ADDFUNC(LD_MHL_E)));
		InstructionMap.insert(MAPPAIR(0x74, ADDFUNC(LD_MHL_H)));
		InstructionMap.insert(MAPPAIR(0x75, ADDFUNC(LD_MHL_L)));
		InstructionMap.insert(MAPPAIR(0x76, ADDFUNC(LD_MHL_A)));
		InstructionMap.insert(MAPPAIR(0x78, ADDFUNC(LD_A_B)));
		InstructionMap.insert(MAPPAIR(0x79, ADDFUNC(LD_A_C)));
		InstructionMap.insert(MAPPAIR(0x7A, ADDFUNC(LD_A_D)));
		InstructionMap.insert(MAPPAIR(0x7B, ADDFUNC(LD_A_E)));
		InstructionMap.insert(MAPPAIR(0x7C, ADDFUNC(LD_A_H)));
		InstructionMap.insert(MAPPAIR(0x7D, ADDFUNC(LD_A_L)));
		InstructionMap.insert(MAPPAIR(0x7E, ADDFUNC(LD_A_MHL)));
		InstructionMap.insert(MAPPAIR(0x7F, ADDFUNC(LD_A_A)));

		// Flow control instructions
		InstructionMap.insert(MAPPAIR(0xC3, ADDFUNC(JP_U16)));
		InstructionMap.insert(MAPPAIR(0xE9, ADDFUNC(JP_HL)));
		InstructionMap.insert(MAPPAIR(0xDA, ADDFUNC(JP_C_U16)));
		InstructionMap.insert(MAPPAIR(0xCA, ADDFUNC(JP_Z_U16)));
		InstructionMap.insert(MAPPAIR(0xD2, ADDFUNC(JP_NC_U16)));
		InstructionMap.insert(MAPPAIR(0xC2, ADDFUNC(JP_NZ_U16)));
		InstructionMap.insert(MAPPAIR(0x18, ADDFUNC(JR_I8)));
		InstructionMap.insert(MAPPAIR(0x28, ADDFUNC(JR_Z_I8)));
		InstructionMap.insert(MAPPAIR(0x38, ADDFUNC(JR_C_I8)));
		InstructionMap.insert(MAPPAIR(0x20, ADDFUNC(JR_NZ_I8)));
		InstructionMap.insert(MAPPAIR(0x30, ADDFUNC(JR_NC_I8)));
		InstructionMap.insert(MAPPAIR(0xCD, ADDFUNC(CALL_U16)));
		InstructionMap.insert(MAPPAIR(0xCC, ADDFUNC(CALL_Z_U16)));
		InstructionMap.insert(MAPPAIR(0xDC, ADDFUNC(CALL_C_U16)));
		InstructionMap.insert(MAPPAIR(0xC4, ADDFUNC(CALL_NZ_U16)));
		InstructionMap.insert(MAPPAIR(0xD4, ADDFUNC(CALL_NC_U16)));
		InstructionMap.insert(MAPPAIR(0xC9, ADDFUNC(RET)));
		InstructionMap.insert(MAPPAIR(0xC8, ADDFUNC(RET_Z)));
		InstructionMap.insert(MAPPAIR(0xD8, ADDFUNC(RET_C)));
		InstructionMap.insert(MAPPAIR(0xC0, ADDFUNC(RET_NZ)));
		InstructionMap.insert(MAPPAIR(0xD0, ADDFUNC(RET_NC)));
		InstructionMap.insert(MAPPAIR(0xD9, ADDFUNC(RETI)));
		InstructionMap.insert(MAPPAIR(0xC7, ADDFUNC(RST_0x00)));
		InstructionMap.insert(MAPPAIR(0xD7, ADDFUNC(RST_0x10)));
		InstructionMap.insert(MAPPAIR(0xE7, ADDFUNC(RST_0x20)));
		InstructionMap.insert(MAPPAIR(0xF7, ADDFUNC(RST_0x30)));
		InstructionMap.insert(MAPPAIR(0xCF, ADDFUNC(RST_0x08)));
		InstructionMap.insert(MAPPAIR(0xDF, ADDFUNC(RST_0x18)));
		InstructionMap.insert(MAPPAIR(0xEF, ADDFUNC(RST_0x28)));
		InstructionMap.insert(MAPPAIR(0xEF, ADDFUNC(RST_0x38)));
	}

}