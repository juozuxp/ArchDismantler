#pragma once
#include "InstructionSet.h"

typedef enum _x86_x64OperandType
{
	x86_x64OperandType_None,
	x86_x64OperandType_M,
	x86_x64OperandType_R,

	x86_x64OperandType_SR = 1 << 3, // Set register
	x86_x64OperandType_SSR = 1 << 4, // Static register

	x86_x64OperandType_AX = 1 << 3,
	x86_x64OperandType_CX,
	x86_x64OperandType_DX,
	x86_x64OperandType_BX,
	x86_x64OperandType_SP,
	x86_x64OperandType_BP,
	x86_x64OperandType_SI,
	x86_x64OperandType_DI,

	x86_x64OperandType_IMM = 1 << 5,
	x86_x64OperandType_IMMN64 = 1 << 5,	// No 64
	x86_x64OperandType_IMM64,	// 64 Compatible
	x86_x64OperandType_MIMM
} x86_x64OperandType, *Px86_x64OperandType;

typedef enum _x86_x64Segments
{
	x86_x64Segments_GS = 1,
	x86_x64Segments_FS
};

typedef struct _x86_x64Operand
{
	struct
	{
		unsigned char O8 : 1;  // Operation modes from 8 bit to 64 bit
		unsigned char O16 : 1;
		unsigned char O32 : 1;
		unsigned char O64 : 1;
	};

	x86_x64OperandType Type;
} x86_x64Operand, *Px86_x64Operand;

typedef union _x86_x64PrefixMap
{
	unsigned char Value;
	struct
	{
		unsigned char REX : 1;
		unsigned char REXB : 1;
		unsigned char REXX : 1;
		unsigned char REXR : 1;
		unsigned char REXW : 1;
		unsigned char GS : 1;
		unsigned char FS : 1;
	};
} x86_x64PrefixMap, *Px86_x64PrefixMap;

typedef struct _x86_x64Instruction
{
	struct
	{
		unsigned short Prefix : 1;
		unsigned short Behaviour : 15;
	};

	union
	{
		struct Instruction
		{

			x86_x64Operand Operands[4];
		} I;

		struct
		{
			x86_x64PrefixMap Prefix;
		} P;
	};
} x86_x64Instruction, *Px86_x64Instruction;

static void ConstructInstructionSet(x86_x64Instruction* SetBuffer)
{
	memset(SetBuffer, 0, 255 * sizeof(x86_x64Instruction));

	SetBuffer[0x00].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x00].I.Operands[0].O8 = 1;
	SetBuffer[0x00].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x00].I.Operands[1].O8 = 1;
	SetBuffer[0x00].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x01].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x01].I.Operands[0].O16 = 1;
	SetBuffer[0x01].I.Operands[0].O32 = 1;
	SetBuffer[0x01].I.Operands[0].O64 = 1;
	SetBuffer[0x01].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x01].I.Operands[1].O16 = 1;
	SetBuffer[0x01].I.Operands[1].O32 = 1;
	SetBuffer[0x01].I.Operands[1].O64 = 1;
	SetBuffer[0x01].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x02].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x02].I.Operands[0].O8 = 1;
	SetBuffer[0x02].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x02].I.Operands[1].O8 = 1;
	SetBuffer[0x02].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x03].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x03].I.Operands[0].O16 = 1;
	SetBuffer[0x03].I.Operands[0].O32 = 1;
	SetBuffer[0x03].I.Operands[0].O64 = 1;
	SetBuffer[0x03].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x03].I.Operands[1].O16 = 1;
	SetBuffer[0x03].I.Operands[1].O32 = 1;
	SetBuffer[0x03].I.Operands[1].O64 = 1;
	SetBuffer[0x03].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x04].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x04].I.Operands[0].O8 = 1;
	SetBuffer[0x04].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x04].I.Operands[1].O8 = 1;
	SetBuffer[0x04].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x05].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x05].I.Operands[0].O16 = 1;
	SetBuffer[0x05].I.Operands[0].O32 = 1;
	SetBuffer[0x05].I.Operands[0].O64 = 1;
	SetBuffer[0x05].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x05].I.Operands[1].O16 = 1;
	SetBuffer[0x05].I.Operands[1].O32 = 1;
	SetBuffer[0x05].I.Operands[1].O64 = 1;
	SetBuffer[0x05].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x08].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x08].I.Operands[0].O8 = 1;
	SetBuffer[0x08].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x08].I.Operands[1].O8 = 1;
	SetBuffer[0x08].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x09].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x09].I.Operands[0].O16 = 1;
	SetBuffer[0x09].I.Operands[0].O32 = 1;
	SetBuffer[0x09].I.Operands[0].O64 = 1;
	SetBuffer[0x09].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x09].I.Operands[1].O16 = 1;
	SetBuffer[0x09].I.Operands[1].O32 = 1;
	SetBuffer[0x09].I.Operands[1].O64 = 1;
	SetBuffer[0x09].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x0A].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0A].I.Operands[0].O8 = 1;
	SetBuffer[0x0A].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x0A].I.Operands[1].O8 = 1;
	SetBuffer[0x0A].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x0B].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0B].I.Operands[0].O16 = 1;
	SetBuffer[0x0B].I.Operands[0].O32 = 1;
	SetBuffer[0x0B].I.Operands[0].O64 = 1;
	SetBuffer[0x0B].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x0B].I.Operands[1].O16 = 1;
	SetBuffer[0x0B].I.Operands[1].O32 = 1;
	SetBuffer[0x0B].I.Operands[1].O64 = 1;
	SetBuffer[0x0B].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x0C].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0C].I.Operands[0].O8 = 1;
	SetBuffer[0x0C].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x0C].I.Operands[1].O8 = 1;
	SetBuffer[0x0C].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x0D].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0D].I.Operands[0].O16 = 1;
	SetBuffer[0x0D].I.Operands[0].O32 = 1;
	SetBuffer[0x0D].I.Operands[0].O64 = 1;
	SetBuffer[0x0D].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x0D].I.Operands[1].O16 = 1;
	SetBuffer[0x0D].I.Operands[1].O32 = 1;
	SetBuffer[0x0D].I.Operands[1].O64 = 1;
	SetBuffer[0x0D].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x10].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x10].I.Operands[0].O8 = 1;
	SetBuffer[0x10].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x10].I.Operands[1].O8 = 1;
	SetBuffer[0x10].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x11].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x11].I.Operands[0].O16 = 1;
	SetBuffer[0x11].I.Operands[0].O32 = 1;
	SetBuffer[0x11].I.Operands[0].O64 = 1;
	SetBuffer[0x11].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x11].I.Operands[1].O16 = 1;
	SetBuffer[0x11].I.Operands[1].O32 = 1;
	SetBuffer[0x11].I.Operands[1].O64 = 1;
	SetBuffer[0x11].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x12].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x12].I.Operands[0].O8 = 1;
	SetBuffer[0x12].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x12].I.Operands[1].O8 = 1;
	SetBuffer[0x12].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x13].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x13].I.Operands[0].O16 = 1;
	SetBuffer[0x13].I.Operands[0].O32 = 1;
	SetBuffer[0x13].I.Operands[0].O64 = 1;
	SetBuffer[0x13].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x13].I.Operands[1].O16 = 1;
	SetBuffer[0x13].I.Operands[1].O32 = 1;
	SetBuffer[0x13].I.Operands[1].O64 = 1;
	SetBuffer[0x13].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x14].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x14].I.Operands[0].O8 = 1;
	SetBuffer[0x14].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x14].I.Operands[1].O8 = 1;
	SetBuffer[0x14].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x15].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x15].I.Operands[0].O16 = 1;
	SetBuffer[0x15].I.Operands[0].O32 = 1;
	SetBuffer[0x15].I.Operands[0].O64 = 1;
	SetBuffer[0x15].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x15].I.Operands[1].O16 = 1;
	SetBuffer[0x15].I.Operands[1].O32 = 1;
	SetBuffer[0x15].I.Operands[1].O64 = 1;
	SetBuffer[0x15].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x18].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x18].I.Operands[0].O8 = 1;
	SetBuffer[0x18].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x18].I.Operands[1].O8 = 1;
	SetBuffer[0x18].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x19].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x19].I.Operands[0].O16 = 1;
	SetBuffer[0x19].I.Operands[0].O32 = 1;
	SetBuffer[0x19].I.Operands[0].O64 = 1;
	SetBuffer[0x19].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x19].I.Operands[1].O16 = 1;
	SetBuffer[0x19].I.Operands[1].O32 = 1;
	SetBuffer[0x19].I.Operands[1].O64 = 1;
	SetBuffer[0x19].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x1A].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1A].I.Operands[0].O8 = 1;
	SetBuffer[0x1A].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x1A].I.Operands[1].O8 = 1;
	SetBuffer[0x1A].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x1B].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1B].I.Operands[0].O16 = 1;
	SetBuffer[0x1B].I.Operands[0].O32 = 1;
	SetBuffer[0x1B].I.Operands[0].O64 = 1;
	SetBuffer[0x1B].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x1B].I.Operands[1].O16 = 1;
	SetBuffer[0x1B].I.Operands[1].O32 = 1;
	SetBuffer[0x1B].I.Operands[1].O64 = 1;
	SetBuffer[0x1B].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x1C].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1C].I.Operands[0].O8 = 1;
	SetBuffer[0x1C].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x1C].I.Operands[1].O8 = 1;
	SetBuffer[0x1C].I.Operands[1].Type = x86_x64OperandType_IMMN64;
	
	SetBuffer[0x1D].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1D].I.Operands[0].O16 = 1;
	SetBuffer[0x1D].I.Operands[0].O32 = 1;
	SetBuffer[0x1D].I.Operands[0].O64 = 1;
	SetBuffer[0x1D].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x1D].I.Operands[1].O16 = 1;
	SetBuffer[0x1D].I.Operands[1].O32 = 1;
	SetBuffer[0x1D].I.Operands[1].O64 = 1;
	SetBuffer[0x1D].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x20].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x20].I.Operands[0].O8 = 1;
	SetBuffer[0x20].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x20].I.Operands[1].O8 = 1;
	SetBuffer[0x20].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x21].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x21].I.Operands[0].O16 = 1;
	SetBuffer[0x21].I.Operands[0].O32 = 1;
	SetBuffer[0x21].I.Operands[0].O64 = 1;
	SetBuffer[0x21].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x21].I.Operands[1].O16 = 1;
	SetBuffer[0x21].I.Operands[1].O32 = 1;
	SetBuffer[0x21].I.Operands[1].O64 = 1;
	SetBuffer[0x21].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x22].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x22].I.Operands[0].O8 = 1;
	SetBuffer[0x22].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x22].I.Operands[1].O8 = 1;
	SetBuffer[0x22].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x23].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x23].I.Operands[0].O16 = 1;
	SetBuffer[0x23].I.Operands[0].O32 = 1;
	SetBuffer[0x23].I.Operands[0].O64 = 1;
	SetBuffer[0x23].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x23].I.Operands[1].O16 = 1;
	SetBuffer[0x23].I.Operands[1].O32 = 1;
	SetBuffer[0x23].I.Operands[1].O64 = 1;
	SetBuffer[0x23].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x24].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x24].I.Operands[0].O8 = 1;
	SetBuffer[0x24].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x24].I.Operands[1].O8 = 1;
	SetBuffer[0x24].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x25].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x25].I.Operands[0].O16 = 1;
	SetBuffer[0x25].I.Operands[0].O32 = 1;
	SetBuffer[0x25].I.Operands[0].O64 = 1;
	SetBuffer[0x25].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x25].I.Operands[1].O16 = 1;
	SetBuffer[0x25].I.Operands[1].O32 = 1;
	SetBuffer[0x25].I.Operands[1].O64 = 1;
	SetBuffer[0x25].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x26].Prefix = 1;
	SetBuffer[0x26].P.Prefix.Value = 0;

	SetBuffer[0x28].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x28].I.Operands[0].O8 = 1;
	SetBuffer[0x28].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x28].I.Operands[1].O8 = 1;
	SetBuffer[0x28].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x29].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x29].I.Operands[0].O16 = 1;
	SetBuffer[0x29].I.Operands[0].O32 = 1;
	SetBuffer[0x29].I.Operands[0].O64 = 1;
	SetBuffer[0x29].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x29].I.Operands[1].O16 = 1;
	SetBuffer[0x29].I.Operands[1].O32 = 1;
	SetBuffer[0x29].I.Operands[1].O64 = 1;
	SetBuffer[0x29].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x2A].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2A].I.Operands[0].O8 = 1;
	SetBuffer[0x2A].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x2A].I.Operands[1].O8 = 1;
	SetBuffer[0x2A].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x2B].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2B].I.Operands[0].O16 = 1;
	SetBuffer[0x2B].I.Operands[0].O32 = 1;
	SetBuffer[0x2B].I.Operands[0].O64 = 1;
	SetBuffer[0x2B].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x2B].I.Operands[1].O16 = 1;
	SetBuffer[0x2B].I.Operands[1].O32 = 1;
	SetBuffer[0x2B].I.Operands[1].O64 = 1;
	SetBuffer[0x2B].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x2C].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2C].I.Operands[0].O8 = 1;
	SetBuffer[0x2C].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x2C].I.Operands[1].O8 = 1;
	SetBuffer[0x2C].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x2D].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2D].I.Operands[0].O16 = 1;
	SetBuffer[0x2D].I.Operands[0].O32 = 1;
	SetBuffer[0x2D].I.Operands[0].O64 = 1;
	SetBuffer[0x2D].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x2D].I.Operands[1].O16 = 1;
	SetBuffer[0x2D].I.Operands[1].O32 = 1;
	SetBuffer[0x2D].I.Operands[1].O64 = 1;
	SetBuffer[0x2D].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x2E].Prefix = 1;
	SetBuffer[0x2E].P.Prefix.Value = 0;

	SetBuffer[0x30].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x30].I.Operands[0].O8 = 1;
	SetBuffer[0x30].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x30].I.Operands[1].O8 = 1;
	SetBuffer[0x30].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x31].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x31].I.Operands[0].O16 = 1;
	SetBuffer[0x31].I.Operands[0].O32 = 1;
	SetBuffer[0x31].I.Operands[0].O64 = 1;
	SetBuffer[0x31].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x31].I.Operands[1].O16 = 1;
	SetBuffer[0x31].I.Operands[1].O32 = 1;
	SetBuffer[0x31].I.Operands[1].O64 = 1;
	SetBuffer[0x31].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x32].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x32].I.Operands[0].O8 = 1;
	SetBuffer[0x32].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x32].I.Operands[1].O8 = 1;
	SetBuffer[0x32].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x33].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x33].I.Operands[0].O16 = 1;
	SetBuffer[0x33].I.Operands[0].O32 = 1;
	SetBuffer[0x33].I.Operands[0].O64 = 1;
	SetBuffer[0x33].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x33].I.Operands[1].O16 = 1;
	SetBuffer[0x33].I.Operands[1].O32 = 1;
	SetBuffer[0x33].I.Operands[1].O64 = 1;
	SetBuffer[0x33].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x34].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x34].I.Operands[0].O8 = 1;
	SetBuffer[0x34].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x34].I.Operands[1].O8 = 1;
	SetBuffer[0x34].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x35].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x35].I.Operands[0].O16 = 1;
	SetBuffer[0x35].I.Operands[0].O32 = 1;
	SetBuffer[0x35].I.Operands[0].O64 = 1;
	SetBuffer[0x35].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x35].I.Operands[1].O16 = 1;
	SetBuffer[0x35].I.Operands[1].O32 = 1;
	SetBuffer[0x35].I.Operands[1].O64 = 1;
	SetBuffer[0x35].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x36].Prefix = 1;
	SetBuffer[0x36].P.Prefix.Value = 0;

	SetBuffer[0x38].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x38].I.Operands[0].O8 = 1;
	SetBuffer[0x38].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x38].I.Operands[1].O8 = 1;
	SetBuffer[0x38].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x39].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x39].I.Operands[0].O16 = 1;
	SetBuffer[0x39].I.Operands[0].O32 = 1;
	SetBuffer[0x39].I.Operands[0].O64 = 1;
	SetBuffer[0x39].I.Operands[0].Type = x86_x64OperandType_M;

	SetBuffer[0x39].I.Operands[1].O16 = 1;
	SetBuffer[0x39].I.Operands[1].O32 = 1;
	SetBuffer[0x39].I.Operands[1].O64 = 1;
	SetBuffer[0x39].I.Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x3A].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3A].I.Operands[0].O8 = 1;
	SetBuffer[0x3A].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x3A].I.Operands[1].O8 = 1;
	SetBuffer[0x3A].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x3B].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3B].I.Operands[0].O16 = 1;
	SetBuffer[0x3B].I.Operands[0].O32 = 1;
	SetBuffer[0x3B].I.Operands[0].O64 = 1;
	SetBuffer[0x3B].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x3B].I.Operands[1].O16 = 1;
	SetBuffer[0x3B].I.Operands[1].O32 = 1;
	SetBuffer[0x3B].I.Operands[1].O64 = 1;
	SetBuffer[0x3B].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x3C].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3C].I.Operands[0].O8 = 1;
	SetBuffer[0x3C].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x3C].I.Operands[1].O8 = 1;
	SetBuffer[0x3C].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x3D].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3D].I.Operands[0].O16 = 1;
	SetBuffer[0x3D].I.Operands[0].O32 = 1;
	SetBuffer[0x3D].I.Operands[0].O64 = 1;
	SetBuffer[0x3D].I.Operands[0].Type = (x86_x64OperandType)(x86_x64OperandType_AX | x86_x64OperandType_SSR);

	SetBuffer[0x3D].I.Operands[1].O16 = 1;
	SetBuffer[0x3D].I.Operands[1].O32 = 1;
	SetBuffer[0x3D].I.Operands[1].O64 = 1;
	SetBuffer[0x3D].I.Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x3E].Prefix = 1;
	SetBuffer[0x3E].P.Prefix.Value = 0;

	SetBuffer[0x40].Prefix = 1;
	SetBuffer[0x40].P.Prefix.REX = 1;

	SetBuffer[0x41].Prefix = 1;
	SetBuffer[0x41].P.Prefix.REX = 1;
	SetBuffer[0x41].P.Prefix.REXB = 1;

	SetBuffer[0x42].Prefix = 1;
	SetBuffer[0x42].P.Prefix.REX = 1;
	SetBuffer[0x42].P.Prefix.REXX = 1;

	SetBuffer[0x43].Prefix = 1;
	SetBuffer[0x43].P.Prefix.REX = 1;
	SetBuffer[0x43].P.Prefix.REXB = 1;
	SetBuffer[0x43].P.Prefix.REXX = 1;

	SetBuffer[0x44].Prefix = 1;
	SetBuffer[0x44].P.Prefix.REX = 1;
	SetBuffer[0x44].P.Prefix.REXR = 1;

	SetBuffer[0x45].Prefix = 1;
	SetBuffer[0x45].P.Prefix.REX = 1;
	SetBuffer[0x45].P.Prefix.REXR = 1;
	SetBuffer[0x45].P.Prefix.REXB = 1;

	SetBuffer[0x46].Prefix = 1;
	SetBuffer[0x46].P.Prefix.REX = 1;
	SetBuffer[0x46].P.Prefix.REXR = 1;
	SetBuffer[0x46].P.Prefix.REXX = 1;

	SetBuffer[0x47].Prefix = 1;
	SetBuffer[0x47].P.Prefix.REX = 1;
	SetBuffer[0x47].P.Prefix.REXR = 1;
	SetBuffer[0x47].P.Prefix.REXX = 1;
	SetBuffer[0x47].P.Prefix.REXB = 1;

	SetBuffer[0x48].Prefix = 1;
	SetBuffer[0x48].P.Prefix.REX = 1;
	SetBuffer[0x48].P.Prefix.REXW = 1;

	SetBuffer[0x49].Prefix = 1;
	SetBuffer[0x49].P.Prefix.REX = 1;
	SetBuffer[0x49].P.Prefix.REXW = 1;
	SetBuffer[0x49].P.Prefix.REXB = 1;

	SetBuffer[0x4A].Prefix = 1;
	SetBuffer[0x4A].P.Prefix.REX = 1;
	SetBuffer[0x4A].P.Prefix.REXW = 1;
	SetBuffer[0x4A].P.Prefix.REXX = 1;

	SetBuffer[0x4B].Prefix = 1;
	SetBuffer[0x4B].P.Prefix.REX = 1;
	SetBuffer[0x4B].P.Prefix.REXW = 1;
	SetBuffer[0x4B].P.Prefix.REXX = 1;
	SetBuffer[0x4B].P.Prefix.REXB = 1;

	SetBuffer[0x4C].Prefix = 1;
	SetBuffer[0x4C].P.Prefix.REX = 1;
	SetBuffer[0x4C].P.Prefix.REXW = 1;
	SetBuffer[0x4C].P.Prefix.REXR = 1;

	SetBuffer[0x4D].Prefix = 1;
	SetBuffer[0x4D].P.Prefix.REX = 1;
	SetBuffer[0x4D].P.Prefix.REXW = 1;
	SetBuffer[0x4D].P.Prefix.REXR = 1;
	SetBuffer[0x4D].P.Prefix.REXB = 1;

	SetBuffer[0x4E].Prefix = 1;
	SetBuffer[0x4E].P.Prefix.REX = 1;
	SetBuffer[0x4E].P.Prefix.REXW = 1;
	SetBuffer[0x4E].P.Prefix.REXR = 1;
	SetBuffer[0x4E].P.Prefix.REXX = 1;

	SetBuffer[0x4F].Prefix = 1;
	SetBuffer[0x4F].P.Prefix.REX = 1;
	SetBuffer[0x4F].P.Prefix.REXW = 1;
	SetBuffer[0x4F].P.Prefix.REXR = 1;
	SetBuffer[0x4F].P.Prefix.REXX = 1;
	SetBuffer[0x4F].P.Prefix.REXB = 1;

	SetBuffer[0x50].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x50].I.Operands[0].O16 = 1;
	SetBuffer[0x50].I.Operands[0].O64 = 1;
	SetBuffer[0x50].I.Operands[0].Type = x86_x64OperandType_AX;

	SetBuffer[0x51].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x51].I.Operands[0].O16 = 1;
	SetBuffer[0x51].I.Operands[0].O64 = 1;
	SetBuffer[0x51].I.Operands[0].Type = x86_x64OperandType_CX;

	SetBuffer[0x52].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x52].I.Operands[0].O16 = 1;
	SetBuffer[0x52].I.Operands[0].O64 = 1;
	SetBuffer[0x52].I.Operands[0].Type = x86_x64OperandType_DX;

	SetBuffer[0x53].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x53].I.Operands[0].O16 = 1;
	SetBuffer[0x53].I.Operands[0].O64 = 1;
	SetBuffer[0x53].I.Operands[0].Type = x86_x64OperandType_BX;

	SetBuffer[0x54].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x54].I.Operands[0].O16 = 1;
	SetBuffer[0x54].I.Operands[0].O64 = 1;
	SetBuffer[0x54].I.Operands[0].Type = x86_x64OperandType_SP;

	SetBuffer[0x55].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x55].I.Operands[0].O16 = 1;
	SetBuffer[0x55].I.Operands[0].O64 = 1;
	SetBuffer[0x55].I.Operands[0].Type = x86_x64OperandType_BP;

	SetBuffer[0x56].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x56].I.Operands[0].O16 = 1;
	SetBuffer[0x56].I.Operands[0].O64 = 1;
	SetBuffer[0x56].I.Operands[0].Type = x86_x64OperandType_SI;

	SetBuffer[0x57].Behaviour = InstructionBehaviour_Push;

	SetBuffer[0x57].I.Operands[0].O16 = 1;
	SetBuffer[0x57].I.Operands[0].O64 = 1;
	SetBuffer[0x57].I.Operands[0].Type = x86_x64OperandType_DI;

	SetBuffer[0x58].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x58].I.Operands[0].O16 = 1;
	SetBuffer[0x58].I.Operands[0].O64 = 1;
	SetBuffer[0x58].I.Operands[0].Type = x86_x64OperandType_AX;

	SetBuffer[0x59].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x59].I.Operands[0].O16 = 1;
	SetBuffer[0x59].I.Operands[0].O64 = 1;
	SetBuffer[0x59].I.Operands[0].Type = x86_x64OperandType_CX;

	SetBuffer[0x5A].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5A].I.Operands[0].O16 = 1;
	SetBuffer[0x5A].I.Operands[0].O64 = 1;
	SetBuffer[0x5A].I.Operands[0].Type = x86_x64OperandType_DX;

	SetBuffer[0x5B].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5B].I.Operands[0].O16 = 1;
	SetBuffer[0x5B].I.Operands[0].O64 = 1;
	SetBuffer[0x5B].I.Operands[0].Type = x86_x64OperandType_BX;

	SetBuffer[0x5C].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5C].I.Operands[0].O16 = 1;
	SetBuffer[0x5C].I.Operands[0].O64 = 1;
	SetBuffer[0x5C].I.Operands[0].Type = x86_x64OperandType_SP;

	SetBuffer[0x5D].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5D].I.Operands[0].O16 = 1;
	SetBuffer[0x5D].I.Operands[0].O64 = 1;
	SetBuffer[0x5D].I.Operands[0].Type = x86_x64OperandType_BP;

	SetBuffer[0x5E].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5E].I.Operands[0].O16 = 1;
	SetBuffer[0x5E].I.Operands[0].O64 = 1;
	SetBuffer[0x5E].I.Operands[0].Type = x86_x64OperandType_SI;

	SetBuffer[0x5F].Behaviour = InstructionBehaviour_Pop;

	SetBuffer[0x5F].I.Operands[0].O16 = 1;
	SetBuffer[0x5F].I.Operands[0].O64 = 1;
	SetBuffer[0x5F].I.Operands[0].Type = x86_x64OperandType_DI;

	SetBuffer[0x63].Behaviour = InstructionBehaviour_Movsxd;

	SetBuffer[0x63].I.Operands[0].O32 = 1;
	SetBuffer[0x63].I.Operands[0].O64 = 1;
	SetBuffer[0x63].I.Operands[0].Type = x86_x64OperandType_R;

	SetBuffer[0x63].I.Operands[1].O32 = 1;
	SetBuffer[0x63].I.Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x64].Prefix = 1;
	SetBuffer[0x64].P.Prefix.GS = 1;

	SetBuffer[0x65].Prefix = 1;
	SetBuffer[0x65].P.Prefix.FS = 1;
}

static void ParseCode(x86_x64Instruction* SetBuffer, void* Code, unsigned long long CodeSize, Operation* OperationBuffer, unsigned long long* OperationCount)
{
	x86_x64Instruction* Instruction;
	x86_x64PrefixMap PrefixMap;

	unsigned char OperandByte;
	unsigned char MainOperand;

	PrefixMap.Value = 0;
	*OperationCount = 0;
	while (CodeSize)
	{
		Instruction = &SetBuffer[*((unsigned char*)Code)];

		CodeSize--;
		Code = ((unsigned char*)Code) + 1;

		if (Instruction->Prefix)
		{
			PrefixMap.Value |= Instruction->P.Prefix.Value;
			continue;
		}

		memset(OperationBuffer, 0, sizeof(Operation));

		OperationBuffer->Behaviour = (InstructionBehaviour)Instruction->Behaviour;

		MainOperand = 5;
		if (Instruction->I.Operands[0].Type == x86_x64OperandType_M)
			MainOperand = 0;
		else if (Instruction->I.Operands[1].Type == x86_x64OperandType_M)
			MainOperand = 1;
		
		if (MainOperand < 4 && Instruction->I.Operands[MainOperand].Type == x86_x64OperandType_M)
		{
			OperandByte = *((unsigned char*)Code);

			CodeSize--;
			Code = ((unsigned char*)Code) + 1;

			if (OperandByte >> 6 == 3) // Operation register to register
			{
				OperationBuffer->Operands[MainOperand].Type = OperandType_IR;

				if (PrefixMap.REX)
				{
					OperationBuffer->Operands[MainOperand].IRegister.HighLowPart = 0;
					OperationBuffer->Operands[MainOperand].IRegister.Register = (OperandByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->Operands[MainOperand].IRegister.HighLowPart = (OperandByte & ((1 << 3) - 1)) > 3;
					OperationBuffer->Operands[MainOperand].IRegister.Register = ((OperandByte & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
				}
			}
			else
			{
				unsigned char SegmentIndex;

				SegmentIndex = 0;
				if (PrefixMap.GS)
					SegmentIndex = x86_x64Segments_GS;
				else if (PrefixMap.FS)
					SegmentIndex = x86_x64Segments_FS;

				OperationBuffer->Operands[MainOperand].Type = OperandType_M;
				OperationBuffer->Operands[MainOperand].Memory.Segment = SegmentIndex;
				OperationBuffer->Operands[MainOperand].Memory.OffsetSize = OperandByte >> 6;
				switch (OperandByte & ((1 << 3) - 1))
				{
				case 4:
				{
					unsigned char ExtendedByte;

					ExtendedByte = *((unsigned char*)Code);

					CodeSize--;
					Code = ((unsigned char*)Code) + 1;
					if (((ExtendedByte >> 3) & ((1 << 3) - 1)) == 4) // if 4 then we head into another exception case
					{
						if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0) // Another exception for segments
						{
							OperationBuffer->Operands[MainOperand].Type = OperandType_ML;
							OperationBuffer->Operands[MainOperand].MemoryLarge.ValueSize = 3;
							OperationBuffer->Operands[MainOperand].MemoryLarge.Segment = SegmentIndex;
							OperationBuffer->Operands[MainOperand].MemoryLarge.Value = *(unsigned long*)Code;

							CodeSize -= 4;
							Code = ((unsigned char*)Code) + 4;

							break;
						}

						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;
					}
					else if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0)
					{
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXX ? 8 : 0) + 1;
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;
					}
					else
					{
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;
						OperationBuffer->Operands[MainOperand].Memory.SecondRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXX ? 8 : 0) + 1;
					}

					if (OperandByte >> 6 == 1)
					{
						OperationBuffer->Operands[MainOperand].Memory.Offset = (long)*(char*)Code;

						CodeSize--;
						Code = ((unsigned char*)Code) + 1;
					}
					else if (OperandByte >> 6 == 2)
					{
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;
					}

					OperationBuffer->Operands[MainOperand].Memory.Multiplier = ExtendedByte >> 6;
				} break;
				case 5:
				{
					if (OperandByte >> 6 == 0)
					{
						OperationBuffer->Operands[MainOperand].Memory.OffsetSize = 2;
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = ~0;
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;

						break;
					}
				}
				default:
				{
					OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (OperandByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;

					if (OperandByte >> 6 == 1)
					{
						OperationBuffer->Operands[MainOperand].Memory.Offset = (long)*(char*)Code;

						CodeSize--;
						Code = ((unsigned char*)Code) + 1;
					}
					else if (OperandByte >> 6 == 2)
					{
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;
					}
				} break;
				}
			}

			if (Instruction->I.Operands[!MainOperand].Type == x86_x64OperandType_R)
			{
				OperationBuffer->Operands[!MainOperand].Type = OperandType_IR;

				if (PrefixMap.REX)
				{
					OperationBuffer->Operands[!MainOperand].IRegister.HighLowPart = 0;
					OperationBuffer->Operands[!MainOperand].IRegister.Register = ((OperandByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXR ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->Operands[!MainOperand].IRegister.HighLowPart = ((OperandByte >> 3) & ((1 << 3) - 1)) > 3;
					OperationBuffer->Operands[!MainOperand].IRegister.Register = (((OperandByte >> 3) & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
				}
			}
		}

		for (unsigned char i = 0; i < 4; i++)
		{
			if (!Instruction->I.Operands[i].Type)
				break;

			if (Instruction->I.Operands[i].O8) // Establish default size
				OperationBuffer->Operands[i].OperandSize = OperandSize_8;

			else if (Instruction->I.Operands[i].O32)
				OperationBuffer->Operands[i].OperandSize = OperandSize_32;

			else if (Instruction->I.Operands[i].O64)
				OperationBuffer->Operands[i].OperandSize = OperandSize_64;

			else if (Instruction->I.Operands[i].O16)
				OperationBuffer->Operands[i].OperandSize = OperandSize_16;

			if (Instruction->I.Operands[i].O64 && PrefixMap.REXW)
				OperationBuffer->Operands[i].OperandSize = OperandSize_64;
		}

		for (unsigned char i = MainOperand > 4 ? 0 : 2; i < 4; i++)
		{
			if (!Instruction->I.Operands[i].Type)
				break;

			if (Instruction->I.Operands[i].Type & x86_x64OperandType_IMM)
			{
				switch (Instruction->I.Operands[i].Type)
				{
				case x86_x64OperandType_IMM64:
				{
					if (OperationBuffer->Operands[i].OperandSize == OperandSize_64)
					{
						OperationBuffer->Operands[i].Type = OperandType_V;
						OperationBuffer->Operands[i].Value.ValueSize = 1;
						OperationBuffer->Operands[i].Value.Value = *(unsigned char*)Code;

						CodeSize -= 8;
						Code = ((unsigned char*)Code) + 8;

						break;
					}
				}
				case x86_x64OperandType_IMMN64:
				{
					OperationBuffer->Operands[i].Type = OperandType_V;
					switch (OperationBuffer->Operands[i].OperandSize)
					{
					case OperandSize_8:
					{
						OperationBuffer->Operands[i].Value.ValueSize = 1;
						OperationBuffer->Operands[i].Value.Value = *(unsigned char*)Code;

						CodeSize--;
						Code = ((unsigned char*)Code) + 1;
					} break;
					case OperandSize_16:
					{
						OperationBuffer->Operands[i].Value.ValueSize = 2;
						OperationBuffer->Operands[i].Value.Value = *(unsigned short*)Code;

						CodeSize -= 2;
						Code = ((unsigned char*)Code) + 2;
					} break;
					case OperandSize_32:
					{
						OperationBuffer->Operands[i].Value.ValueSize = 3;
						OperationBuffer->Operands[i].Value.Value = *(unsigned long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;
					} break;
					}
				} break;
				}
			}
			else if (Instruction->I.Operands[i].Type & x86_x64OperandType_SR)
			{
				OperationBuffer->Operands[i].Type = OperandType_IR;

				OperationBuffer->Operands[i].IRegister.HighLowPart = (Instruction->I.Operands[i].Type & (x86_x64OperandType_SR - 1)) > 3;
				OperationBuffer->Operands[i].IRegister.Register = (Instruction->I.Operands[i].Type & (x86_x64OperandType_SR - 1)) + ((PrefixMap.REXR && !(Instruction->I.Operands[i].Type & x86_x64OperandType_SSR)) ? 8 : 0) + 1;
			}
		}

		OperationBuffer++;
		(*OperationCount)++;

		PrefixMap.Value = 0;
	}
}