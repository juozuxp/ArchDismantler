#pragma once
#include "InstructionSet.h"

#define ALLOCATE_BUFFER(AllocationArrow, Buffer, Size) (((x86_x64Instruction*)(Buffer)) + (AllocationArrow)); memset(((x86_x64Instruction*)(Buffer)) + (AllocationArrow), 0, (Size) * sizeof(x86_x64Instruction)); (AllocationArrow) += (Size)
#define INDEX_BUFFER(From, To) ((((unsigned char*)(To)) - ((unsigned char*)(From))) / sizeof(x86_x64Instruction))

typedef enum _x86_x64OperandType
{
	x86_x64OperandType_None,
	x86_x64OperandType_M,
	x86_x64OperandType_R,
	x86_x64OperandType_IMM,
	x86_x64OperandType_Rel,
	x86_x64OperandType_Value,

	x86_x64OperandType_AX, // Static registers
	x86_x64OperandType_CX,
	x86_x64OperandType_DX,
	x86_x64OperandType_BX,
	x86_x64OperandType_SP,
	x86_x64OperandType_BP,
	x86_x64OperandType_SI,
	x86_x64OperandType_DI
} x86_x64OperandType, * Px86_x64OperandType;

typedef enum _x86_x64RegisterType
{
	x86_x64RegisterType_Normal,
	x86_x64RegisterType_Segment,
} x86_x64RegisterType, * Px86_x64RegisterType;

typedef enum _x86_x64Segments
{
	x86_x64Segments_ES = 1,
	x86_x64Segments_CS,
	x86_x64Segments_SS,
	x86_x64Segments_DS,
	x86_x64Segments_FS,
	x86_x64Segments_GS
} x86_x64Segments, * Px86_x64Segments;

typedef enum _x86_x64InstructionType
{
	x86_x64InstructionType_None,
	x86_x64InstructionType_Normal,
	x86_x64InstructionType_Prefix,
	x86_x64InstructionType_LowerRedirect,
	x86_x64InstructionType_UpperRedirect,
	x86_x64InstructionType_GlobalRedirect
} x86_x64InstructionType, * Px86_x64InstructionType;

typedef struct _x86_x64Operand
{
	struct
	{
		unsigned char Type : 4;
		unsigned char RType : 4;
	};

	struct
	{
		unsigned char O8 : 1;  // Operation modes from 8 bit to 64 bit
		unsigned char O16 : 1;
		unsigned char O32 : 1;
		unsigned char O64 : 1;

		struct
		{
			unsigned char MO8 : 1;  // Operation modes not allowed for M from 8 bit to 64 bit
			unsigned char MO16 : 1;
			unsigned char MO32 : 1;
			unsigned char MO64 : 1;
		};

		union
		{
			struct
			{
				unsigned char IM : 1; // Operand immutable
				unsigned char DSO : 1; // Derefrence static operand
			};

			unsigned char Value;
		};
	};
} x86_x64Operand, * Px86_x64Operand;

typedef union _x86_x64PrefixMap
{
	unsigned short Value;
	struct
	{
		unsigned short REX : 1;
		unsigned short REXB : 1;
		unsigned short REXX : 1;
		unsigned short REXR : 1;
		unsigned short REXW : 1;
		unsigned short GS : 1;
		unsigned short FS : 1;
		unsigned short WORD : 1;
		unsigned short WAIT : 1;
	};
} x86_x64PrefixMap, * Px86_x64PrefixMap;

typedef struct _x86_x64Instruction
{
	struct
	{
		unsigned short Type : 3;
		unsigned short Behaviour : 13;
	};

	union
	{
		struct
		{
			x86_x64Operand Operands[4];
		} N;

		struct
		{
			x86_x64PrefixMap Prefix;
		} P;

		struct
		{
			unsigned short Index;
			union
			{
				struct
				{
					unsigned char A0 : 1;
					unsigned char A1 : 1;
					unsigned char A2 : 1;
					unsigned char A3 : 1;
					unsigned char A4 : 1;
					unsigned char A5 : 1;
					unsigned char A6 : 1;
					unsigned char A7 : 1;
				};
				unsigned char Available;
			};
		} R;

		struct
		{
			unsigned short Index;
			union
			{
				struct
				{
					unsigned char A0 : 1;
					unsigned char A1 : 1;
					unsigned char A2 : 1;
					unsigned char A3 : 1;

					unsigned char H0 : 1; // Hard redirect [If not available = invalid, else default to 0]
					unsigned char H1 : 1;
					unsigned char H2 : 1;
					unsigned char H3 : 1;
				};
				unsigned char Available;
			};
		} RG;
	};
} x86_x64Instruction, * Px86_x64Instruction;

static void ConstructInstructionSet(x86_x64Instruction* SetBuffer)
{
	unsigned long AllocationArrow;

	x86_x64Instruction* BaseSet;
	x86_x64Instruction* SubSet;

	AllocationArrow = 0;

	BaseSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 255);

	BaseSet[0x00].Type = x86_x64InstructionType_Normal;
	BaseSet[0x00].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x00].N.Operands[0].O8 = 1;
	BaseSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x00].N.Operands[1].O8 = 1;
	BaseSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x01].Type = x86_x64InstructionType_Normal;
	BaseSet[0x01].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x01].N.Operands[0].O16 = 1;
	BaseSet[0x01].N.Operands[0].O32 = 1;
	BaseSet[0x01].N.Operands[0].O64 = 1;
	BaseSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x01].N.Operands[1].O16 = 1;
	BaseSet[0x01].N.Operands[1].O32 = 1;
	BaseSet[0x01].N.Operands[1].O64 = 1;
	BaseSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x02].Type = x86_x64InstructionType_Normal;
	BaseSet[0x02].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x02].N.Operands[0].O8 = 1;
	BaseSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x02].N.Operands[1].O8 = 1;
	BaseSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x03].Type = x86_x64InstructionType_Normal;
	BaseSet[0x03].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x03].N.Operands[0].O16 = 1;
	BaseSet[0x03].N.Operands[0].O32 = 1;
	BaseSet[0x03].N.Operands[0].O64 = 1;
	BaseSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x03].N.Operands[1].O16 = 1;
	BaseSet[0x03].N.Operands[1].O32 = 1;
	BaseSet[0x03].N.Operands[1].O64 = 1;
	BaseSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x04].Type = x86_x64InstructionType_Normal;
	BaseSet[0x04].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x04].N.Operands[0].IM = 1;
	BaseSet[0x04].N.Operands[0].O8 = 1;
	BaseSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x04].N.Operands[1].O8 = 1;
	BaseSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x05].Type = x86_x64InstructionType_Normal;
	BaseSet[0x05].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x05].N.Operands[0].IM = 1;
	BaseSet[0x05].N.Operands[0].O16 = 1;
	BaseSet[0x05].N.Operands[0].O32 = 1;
	BaseSet[0x05].N.Operands[0].O64 = 1;
	BaseSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x05].N.Operands[1].O16 = 1;
	BaseSet[0x05].N.Operands[1].O32 = 1;
	BaseSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x08].Type = x86_x64InstructionType_Normal;
	BaseSet[0x08].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x08].N.Operands[0].O8 = 1;
	BaseSet[0x08].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x08].N.Operands[1].O8 = 1;
	BaseSet[0x08].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x09].Type = x86_x64InstructionType_Normal;
	BaseSet[0x09].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x09].N.Operands[0].O16 = 1;
	BaseSet[0x09].N.Operands[0].O32 = 1;
	BaseSet[0x09].N.Operands[0].O64 = 1;
	BaseSet[0x09].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x09].N.Operands[1].O16 = 1;
	BaseSet[0x09].N.Operands[1].O32 = 1;
	BaseSet[0x09].N.Operands[1].O64 = 1;
	BaseSet[0x09].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x0A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0A].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0A].N.Operands[0].O8 = 1;
	BaseSet[0x0A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x0A].N.Operands[1].O8 = 1;
	BaseSet[0x0A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x0B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0B].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0B].N.Operands[0].O16 = 1;
	BaseSet[0x0B].N.Operands[0].O32 = 1;
	BaseSet[0x0B].N.Operands[0].O64 = 1;
	BaseSet[0x0B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x0B].N.Operands[1].O16 = 1;
	BaseSet[0x0B].N.Operands[1].O32 = 1;
	BaseSet[0x0B].N.Operands[1].O64 = 1;
	BaseSet[0x0B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x0C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0C].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0C].N.Operands[0].IM = 1;
	BaseSet[0x0C].N.Operands[0].O8 = 1;
	BaseSet[0x0C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x0C].N.Operands[1].O8 = 1;
	BaseSet[0x0C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x0D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0D].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0D].N.Operands[0].IM = 1;
	BaseSet[0x0D].N.Operands[0].O16 = 1;
	BaseSet[0x0D].N.Operands[0].O32 = 1;
	BaseSet[0x0D].N.Operands[0].O64 = 1;
	BaseSet[0x0D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x0D].N.Operands[1].O16 = 1;
	BaseSet[0x0D].N.Operands[1].O32 = 1;
	BaseSet[0x0D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x10].Type = x86_x64InstructionType_Normal;
	BaseSet[0x10].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x10].N.Operands[0].O8 = 1;
	BaseSet[0x10].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x10].N.Operands[1].O8 = 1;
	BaseSet[0x10].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x11].Type = x86_x64InstructionType_Normal;
	BaseSet[0x11].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x11].N.Operands[0].O16 = 1;
	BaseSet[0x11].N.Operands[0].O32 = 1;
	BaseSet[0x11].N.Operands[0].O64 = 1;
	BaseSet[0x11].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x11].N.Operands[1].O16 = 1;
	BaseSet[0x11].N.Operands[1].O32 = 1;
	BaseSet[0x11].N.Operands[1].O64 = 1;
	BaseSet[0x11].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x12].Type = x86_x64InstructionType_Normal;
	BaseSet[0x12].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x12].N.Operands[0].O8 = 1;
	BaseSet[0x12].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x12].N.Operands[1].O8 = 1;
	BaseSet[0x12].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x13].Type = x86_x64InstructionType_Normal;
	BaseSet[0x13].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x13].N.Operands[0].O16 = 1;
	BaseSet[0x13].N.Operands[0].O32 = 1;
	BaseSet[0x13].N.Operands[0].O64 = 1;
	BaseSet[0x13].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x13].N.Operands[1].O16 = 1;
	BaseSet[0x13].N.Operands[1].O32 = 1;
	BaseSet[0x13].N.Operands[1].O64 = 1;
	BaseSet[0x13].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x14].Type = x86_x64InstructionType_Normal;
	BaseSet[0x14].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x14].N.Operands[0].IM = 1;
	BaseSet[0x14].N.Operands[0].O8 = 1;
	BaseSet[0x14].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x14].N.Operands[1].O8 = 1;
	BaseSet[0x14].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x15].Type = x86_x64InstructionType_Normal;
	BaseSet[0x15].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x15].N.Operands[0].IM = 1;
	BaseSet[0x15].N.Operands[0].O16 = 1;
	BaseSet[0x15].N.Operands[0].O32 = 1;
	BaseSet[0x15].N.Operands[0].O64 = 1;
	BaseSet[0x15].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x15].N.Operands[1].O16 = 1;
	BaseSet[0x15].N.Operands[1].O32 = 1;
	BaseSet[0x15].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x18].Type = x86_x64InstructionType_Normal;
	BaseSet[0x18].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x18].N.Operands[0].O8 = 1;
	BaseSet[0x18].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x18].N.Operands[1].O8 = 1;
	BaseSet[0x18].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x19].Type = x86_x64InstructionType_Normal;
	BaseSet[0x19].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x19].N.Operands[0].O16 = 1;
	BaseSet[0x19].N.Operands[0].O32 = 1;
	BaseSet[0x19].N.Operands[0].O64 = 1;
	BaseSet[0x19].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x19].N.Operands[1].O16 = 1;
	BaseSet[0x19].N.Operands[1].O32 = 1;
	BaseSet[0x19].N.Operands[1].O64 = 1;
	BaseSet[0x19].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x1A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1A].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1A].N.Operands[0].O8 = 1;
	BaseSet[0x1A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x1A].N.Operands[1].O8 = 1;
	BaseSet[0x1A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x1B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1B].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1B].N.Operands[0].O16 = 1;
	BaseSet[0x1B].N.Operands[0].O32 = 1;
	BaseSet[0x1B].N.Operands[0].O64 = 1;
	BaseSet[0x1B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x1B].N.Operands[1].O16 = 1;
	BaseSet[0x1B].N.Operands[1].O32 = 1;
	BaseSet[0x1B].N.Operands[1].O64 = 1;
	BaseSet[0x1B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x1C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1C].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1C].N.Operands[0].IM = 1;
	BaseSet[0x1C].N.Operands[0].O8 = 1;
	BaseSet[0x1C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x1C].N.Operands[1].O8 = 1;
	BaseSet[0x1C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x1D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1D].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1D].N.Operands[0].IM = 1;
	BaseSet[0x1D].N.Operands[0].O16 = 1;
	BaseSet[0x1D].N.Operands[0].O32 = 1;
	BaseSet[0x1D].N.Operands[0].O64 = 1;
	BaseSet[0x1D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x1D].N.Operands[1].O16 = 1;
	BaseSet[0x1D].N.Operands[1].O32 = 1;
	BaseSet[0x1D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x20].Type = x86_x64InstructionType_Normal;
	BaseSet[0x20].Behaviour = InstructionBehaviour_And;

	BaseSet[0x20].N.Operands[0].O8 = 1;
	BaseSet[0x20].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x20].N.Operands[1].O8 = 1;
	BaseSet[0x20].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x21].Type = x86_x64InstructionType_Normal;
	BaseSet[0x21].Behaviour = InstructionBehaviour_And;

	BaseSet[0x21].N.Operands[0].O16 = 1;
	BaseSet[0x21].N.Operands[0].O32 = 1;
	BaseSet[0x21].N.Operands[0].O64 = 1;
	BaseSet[0x21].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x21].N.Operands[1].O16 = 1;
	BaseSet[0x21].N.Operands[1].O32 = 1;
	BaseSet[0x21].N.Operands[1].O64 = 1;
	BaseSet[0x21].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x22].Type = x86_x64InstructionType_Normal;
	BaseSet[0x22].Behaviour = InstructionBehaviour_And;

	BaseSet[0x22].N.Operands[0].O8 = 1;
	BaseSet[0x22].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x22].N.Operands[1].O8 = 1;
	BaseSet[0x22].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x23].Type = x86_x64InstructionType_Normal;
	BaseSet[0x23].Behaviour = InstructionBehaviour_And;

	BaseSet[0x23].N.Operands[0].O16 = 1;
	BaseSet[0x23].N.Operands[0].O32 = 1;
	BaseSet[0x23].N.Operands[0].O64 = 1;
	BaseSet[0x23].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x23].N.Operands[1].O16 = 1;
	BaseSet[0x23].N.Operands[1].O32 = 1;
	BaseSet[0x23].N.Operands[1].O64 = 1;
	BaseSet[0x23].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x24].Type = x86_x64InstructionType_Normal;
	BaseSet[0x24].Behaviour = InstructionBehaviour_And;

	BaseSet[0x24].N.Operands[0].IM = 1;
	BaseSet[0x24].N.Operands[0].O8 = 1;
	BaseSet[0x24].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x24].N.Operands[1].O8 = 1;
	BaseSet[0x24].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x25].Type = x86_x64InstructionType_Normal;
	BaseSet[0x25].Behaviour = InstructionBehaviour_And;

	BaseSet[0x25].N.Operands[0].IM = 1;
	BaseSet[0x25].N.Operands[0].O16 = 1;
	BaseSet[0x25].N.Operands[0].O32 = 1;
	BaseSet[0x25].N.Operands[0].O64 = 1;
	BaseSet[0x25].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x25].N.Operands[1].O16 = 1;
	BaseSet[0x25].N.Operands[1].O32 = 1;
	BaseSet[0x25].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x26].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x26].P.Prefix.Value = 0;

	BaseSet[0x28].Type = x86_x64InstructionType_Normal;
	BaseSet[0x28].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x28].N.Operands[0].O8 = 1;
	BaseSet[0x28].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x28].N.Operands[1].O8 = 1;
	BaseSet[0x28].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x29].Type = x86_x64InstructionType_Normal;
	BaseSet[0x29].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x29].N.Operands[0].O16 = 1;
	BaseSet[0x29].N.Operands[0].O32 = 1;
	BaseSet[0x29].N.Operands[0].O64 = 1;
	BaseSet[0x29].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x29].N.Operands[1].O16 = 1;
	BaseSet[0x29].N.Operands[1].O32 = 1;
	BaseSet[0x29].N.Operands[1].O64 = 1;
	BaseSet[0x29].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x2A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2A].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2A].N.Operands[0].O8 = 1;
	BaseSet[0x2A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x2A].N.Operands[1].O8 = 1;
	BaseSet[0x2A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x2B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2B].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2B].N.Operands[0].O16 = 1;
	BaseSet[0x2B].N.Operands[0].O32 = 1;
	BaseSet[0x2B].N.Operands[0].O64 = 1;
	BaseSet[0x2B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x2B].N.Operands[1].O16 = 1;
	BaseSet[0x2B].N.Operands[1].O32 = 1;
	BaseSet[0x2B].N.Operands[1].O64 = 1;
	BaseSet[0x2B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x2C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2C].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2C].N.Operands[0].IM = 1;
	BaseSet[0x2C].N.Operands[0].O8 = 1;
	BaseSet[0x2C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x2C].N.Operands[1].O8 = 1;
	BaseSet[0x2C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x2D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2D].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2D].N.Operands[0].IM = 1;
	BaseSet[0x2D].N.Operands[0].O16 = 1;
	BaseSet[0x2D].N.Operands[0].O32 = 1;
	BaseSet[0x2D].N.Operands[0].O64 = 1;
	BaseSet[0x2D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x2D].N.Operands[1].O16 = 1;
	BaseSet[0x2D].N.Operands[1].O32 = 1;
	BaseSet[0x2D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x2E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x2E].P.Prefix.Value = 0;

	BaseSet[0x30].Type = x86_x64InstructionType_Normal;
	BaseSet[0x30].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x30].N.Operands[0].O8 = 1;
	BaseSet[0x30].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x30].N.Operands[1].O8 = 1;
	BaseSet[0x30].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x31].Type = x86_x64InstructionType_Normal;
	BaseSet[0x31].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x31].N.Operands[0].O16 = 1;
	BaseSet[0x31].N.Operands[0].O32 = 1;
	BaseSet[0x31].N.Operands[0].O64 = 1;
	BaseSet[0x31].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x31].N.Operands[1].O16 = 1;
	BaseSet[0x31].N.Operands[1].O32 = 1;
	BaseSet[0x31].N.Operands[1].O64 = 1;
	BaseSet[0x31].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x32].Type = x86_x64InstructionType_Normal;
	BaseSet[0x32].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x32].N.Operands[0].O8 = 1;
	BaseSet[0x32].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x32].N.Operands[1].O8 = 1;
	BaseSet[0x32].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x33].Type = x86_x64InstructionType_Normal;
	BaseSet[0x33].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x33].N.Operands[0].O16 = 1;
	BaseSet[0x33].N.Operands[0].O32 = 1;
	BaseSet[0x33].N.Operands[0].O64 = 1;
	BaseSet[0x33].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x33].N.Operands[1].O16 = 1;
	BaseSet[0x33].N.Operands[1].O32 = 1;
	BaseSet[0x33].N.Operands[1].O64 = 1;
	BaseSet[0x33].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x34].Type = x86_x64InstructionType_Normal;
	BaseSet[0x34].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x34].N.Operands[0].IM = 1;
	BaseSet[0x34].N.Operands[0].O8 = 1;
	BaseSet[0x34].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x34].N.Operands[1].O8 = 1;
	BaseSet[0x34].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x35].Type = x86_x64InstructionType_Normal;
	BaseSet[0x35].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x35].N.Operands[0].IM = 1;
	BaseSet[0x35].N.Operands[0].O16 = 1;
	BaseSet[0x35].N.Operands[0].O32 = 1;
	BaseSet[0x35].N.Operands[0].O64 = 1;
	BaseSet[0x35].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x35].N.Operands[1].O16 = 1;
	BaseSet[0x35].N.Operands[1].O32 = 1;
	BaseSet[0x35].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x36].Type = x86_x64InstructionType_Normal;
	BaseSet[0x36].P.Prefix.Value = 0;

	BaseSet[0x38].Type = x86_x64InstructionType_Normal;
	BaseSet[0x38].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x38].N.Operands[0].O8 = 1;
	BaseSet[0x38].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x38].N.Operands[1].O8 = 1;
	BaseSet[0x38].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x39].Type = x86_x64InstructionType_Normal;
	BaseSet[0x39].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x39].N.Operands[0].O16 = 1;
	BaseSet[0x39].N.Operands[0].O32 = 1;
	BaseSet[0x39].N.Operands[0].O64 = 1;
	BaseSet[0x39].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x39].N.Operands[1].O16 = 1;
	BaseSet[0x39].N.Operands[1].O32 = 1;
	BaseSet[0x39].N.Operands[1].O64 = 1;
	BaseSet[0x39].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x3A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3A].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3A].N.Operands[0].O8 = 1;
	BaseSet[0x3A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x3A].N.Operands[1].O8 = 1;
	BaseSet[0x3A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x3B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3B].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3B].N.Operands[0].O16 = 1;
	BaseSet[0x3B].N.Operands[0].O32 = 1;
	BaseSet[0x3B].N.Operands[0].O64 = 1;
	BaseSet[0x3B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x3B].N.Operands[1].O16 = 1;
	BaseSet[0x3B].N.Operands[1].O32 = 1;
	BaseSet[0x3B].N.Operands[1].O64 = 1;
	BaseSet[0x3B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x3C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3C].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3C].N.Operands[0].IM = 1;
	BaseSet[0x3C].N.Operands[0].O8 = 1;
	BaseSet[0x3C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x3C].N.Operands[1].O8 = 1;
	BaseSet[0x3C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x3D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3D].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3D].N.Operands[0].IM = 1;
	BaseSet[0x3D].N.Operands[0].O16 = 1;
	BaseSet[0x3D].N.Operands[0].O32 = 1;
	BaseSet[0x3D].N.Operands[0].O64 = 1;
	BaseSet[0x3D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x3D].N.Operands[1].O16 = 1;
	BaseSet[0x3D].N.Operands[1].O32 = 1;
	BaseSet[0x3D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x3E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x3E].P.Prefix.Value = 0;

	BaseSet[0x40].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x40].P.Prefix.REX = 1;

	BaseSet[0x41].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x41].P.Prefix.REX = 1;
	BaseSet[0x41].P.Prefix.REXB = 1;

	BaseSet[0x42].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x42].P.Prefix.REX = 1;
	BaseSet[0x42].P.Prefix.REXX = 1;

	BaseSet[0x43].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x43].P.Prefix.REX = 1;
	BaseSet[0x43].P.Prefix.REXB = 1;
	BaseSet[0x43].P.Prefix.REXX = 1;

	BaseSet[0x44].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x44].P.Prefix.REX = 1;
	BaseSet[0x44].P.Prefix.REXR = 1;

	BaseSet[0x45].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x45].P.Prefix.REX = 1;
	BaseSet[0x45].P.Prefix.REXR = 1;
	BaseSet[0x45].P.Prefix.REXB = 1;

	BaseSet[0x46].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x46].P.Prefix.REX = 1;
	BaseSet[0x46].P.Prefix.REXR = 1;
	BaseSet[0x46].P.Prefix.REXX = 1;

	BaseSet[0x47].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x47].P.Prefix.REX = 1;
	BaseSet[0x47].P.Prefix.REXR = 1;
	BaseSet[0x47].P.Prefix.REXX = 1;
	BaseSet[0x47].P.Prefix.REXB = 1;

	BaseSet[0x48].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x48].P.Prefix.REX = 1;
	BaseSet[0x48].P.Prefix.REXW = 1;

	BaseSet[0x49].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x49].P.Prefix.REX = 1;
	BaseSet[0x49].P.Prefix.REXW = 1;
	BaseSet[0x49].P.Prefix.REXB = 1;

	BaseSet[0x4A].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4A].P.Prefix.REX = 1;
	BaseSet[0x4A].P.Prefix.REXW = 1;
	BaseSet[0x4A].P.Prefix.REXX = 1;

	BaseSet[0x4B].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4B].P.Prefix.REX = 1;
	BaseSet[0x4B].P.Prefix.REXW = 1;
	BaseSet[0x4B].P.Prefix.REXX = 1;
	BaseSet[0x4B].P.Prefix.REXB = 1;

	BaseSet[0x4C].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4C].P.Prefix.REX = 1;
	BaseSet[0x4C].P.Prefix.REXW = 1;
	BaseSet[0x4C].P.Prefix.REXR = 1;

	BaseSet[0x4D].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4D].P.Prefix.REX = 1;
	BaseSet[0x4D].P.Prefix.REXW = 1;
	BaseSet[0x4D].P.Prefix.REXR = 1;
	BaseSet[0x4D].P.Prefix.REXB = 1;

	BaseSet[0x4E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4E].P.Prefix.REX = 1;
	BaseSet[0x4E].P.Prefix.REXW = 1;
	BaseSet[0x4E].P.Prefix.REXR = 1;
	BaseSet[0x4E].P.Prefix.REXX = 1;

	BaseSet[0x4F].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4F].P.Prefix.REX = 1;
	BaseSet[0x4F].P.Prefix.REXW = 1;
	BaseSet[0x4F].P.Prefix.REXR = 1;
	BaseSet[0x4F].P.Prefix.REXX = 1;
	BaseSet[0x4F].P.Prefix.REXB = 1;

	BaseSet[0x50].Type = x86_x64InstructionType_Normal;
	BaseSet[0x50].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x50].N.Operands[0].O16 = 1;
	BaseSet[0x50].N.Operands[0].O64 = 1;
	BaseSet[0x50].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x51].Type = x86_x64InstructionType_Normal;
	BaseSet[0x51].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x51].N.Operands[0].O16 = 1;
	BaseSet[0x51].N.Operands[0].O64 = 1;
	BaseSet[0x51].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x52].Type = x86_x64InstructionType_Normal;
	BaseSet[0x52].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x52].N.Operands[0].O16 = 1;
	BaseSet[0x52].N.Operands[0].O64 = 1;
	BaseSet[0x52].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x53].Type = x86_x64InstructionType_Normal;
	BaseSet[0x53].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x53].N.Operands[0].O16 = 1;
	BaseSet[0x53].N.Operands[0].O64 = 1;
	BaseSet[0x53].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x54].Type = x86_x64InstructionType_Normal;
	BaseSet[0x54].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x54].N.Operands[0].O16 = 1;
	BaseSet[0x54].N.Operands[0].O64 = 1;
	BaseSet[0x54].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x55].Type = x86_x64InstructionType_Normal;
	BaseSet[0x55].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x55].N.Operands[0].O16 = 1;
	BaseSet[0x55].N.Operands[0].O64 = 1;
	BaseSet[0x55].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x56].Type = x86_x64InstructionType_Normal;
	BaseSet[0x56].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x56].N.Operands[0].O16 = 1;
	BaseSet[0x56].N.Operands[0].O64 = 1;
	BaseSet[0x56].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x57].Type = x86_x64InstructionType_Normal;
	BaseSet[0x57].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x57].N.Operands[0].O16 = 1;
	BaseSet[0x57].N.Operands[0].O64 = 1;
	BaseSet[0x57].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x58].Type = x86_x64InstructionType_Normal;
	BaseSet[0x58].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x58].N.Operands[0].O16 = 1;
	BaseSet[0x58].N.Operands[0].O64 = 1;
	BaseSet[0x58].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x59].Type = x86_x64InstructionType_Normal;
	BaseSet[0x59].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x59].N.Operands[0].O16 = 1;
	BaseSet[0x59].N.Operands[0].O64 = 1;
	BaseSet[0x59].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x5A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5A].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5A].N.Operands[0].O16 = 1;
	BaseSet[0x5A].N.Operands[0].O64 = 1;
	BaseSet[0x5A].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x5B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5B].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5B].N.Operands[0].O16 = 1;
	BaseSet[0x5B].N.Operands[0].O64 = 1;
	BaseSet[0x5B].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x5C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5C].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5C].N.Operands[0].O16 = 1;
	BaseSet[0x5C].N.Operands[0].O64 = 1;
	BaseSet[0x5C].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x5D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5D].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5D].N.Operands[0].O16 = 1;
	BaseSet[0x5D].N.Operands[0].O64 = 1;
	BaseSet[0x5D].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x5E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5E].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5E].N.Operands[0].O16 = 1;
	BaseSet[0x5E].N.Operands[0].O64 = 1;
	BaseSet[0x5E].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x5F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5F].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5F].N.Operands[0].O16 = 1;
	BaseSet[0x5F].N.Operands[0].O64 = 1;
	BaseSet[0x5F].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x63].Type = x86_x64InstructionType_Normal;
	BaseSet[0x63].Behaviour = InstructionBehaviour_Movsxd;

	BaseSet[0x63].N.Operands[0].O32 = 1;
	BaseSet[0x63].N.Operands[0].O64 = 1;
	BaseSet[0x63].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x63].N.Operands[1].O32 = 1;
	BaseSet[0x63].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x64].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x64].P.Prefix.FS = 1;

	BaseSet[0x65].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x65].P.Prefix.GS = 1;

	BaseSet[0x66].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x66].P.Prefix.WORD = 1;

	BaseSet[0x67].Type = x86_x64InstructionType_Prefix; // not yet implemented
	BaseSet[0x67].P.Prefix.Value = 0;

	BaseSet[0x68].Type = x86_x64InstructionType_Normal;
	BaseSet[0x68].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x68].N.Operands[0].O16 = 1;
	BaseSet[0x68].N.Operands[0].O32 = 1;
	BaseSet[0x68].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0x69].Type = x86_x64InstructionType_Normal;
	BaseSet[0x69].Behaviour = InstructionBehaviour_Imul;

	BaseSet[0x69].N.Operands[0].O16 = 1;
	BaseSet[0x69].N.Operands[0].O32 = 1;
	BaseSet[0x69].N.Operands[0].O64 = 1;
	BaseSet[0x69].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x69].N.Operands[1].O16 = 1;
	BaseSet[0x69].N.Operands[1].O32 = 1;
	BaseSet[0x69].N.Operands[1].O64 = 1;
	BaseSet[0x69].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x69].N.Operands[2].O16 = 1;
	BaseSet[0x69].N.Operands[2].O32 = 1;
	BaseSet[0x69].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0x6A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6A].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x6A].N.Operands[0].O8 = 1;
	BaseSet[0x6A].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0x6B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6B].Behaviour = InstructionBehaviour_Imul;

	BaseSet[0x6B].N.Operands[0].O16 = 1;
	BaseSet[0x6B].N.Operands[0].O32 = 1;
	BaseSet[0x6B].N.Operands[0].O64 = 1;
	BaseSet[0x6B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x6B].N.Operands[1].O16 = 1;
	BaseSet[0x6B].N.Operands[1].O32 = 1;
	BaseSet[0x6B].N.Operands[1].O64 = 1;
	BaseSet[0x6B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x6B].N.Operands[2].O8 = 1;
	BaseSet[0x6B].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0x6C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6C].Behaviour = InstructionBehaviour_Ins;

	BaseSet[0x6C].N.Operands[0].O8 = 1;
	BaseSet[0x6C].N.Operands[0].IM = 1;
	BaseSet[0x6C].N.Operands[0].DSO = 1;
	BaseSet[0x6C].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x6C].N.Operands[1].IM = 1;
	BaseSet[0x6C].N.Operands[1].O16 = 1;
	BaseSet[0x6C].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0x6D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6D].Behaviour = InstructionBehaviour_Ins;

	BaseSet[0x6D].N.Operands[0].IM = 1;
	BaseSet[0x6D].N.Operands[0].DSO = 1;
	BaseSet[0x6D].N.Operands[0].O16 = 1;
	BaseSet[0x6D].N.Operands[0].O32 = 1;
	BaseSet[0x6D].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x6D].N.Operands[1].IM = 1;
	BaseSet[0x6D].N.Operands[1].O16 = 1;
	BaseSet[0x6D].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0x6E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6E].Behaviour = InstructionBehaviour_Outs;

	BaseSet[0x6E].N.Operands[0].IM = 1;
	BaseSet[0x6E].N.Operands[0].O16 = 1;
	BaseSet[0x6E].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x6E].N.Operands[1].O8 = 1;
	BaseSet[0x6E].N.Operands[1].IM = 1;
	BaseSet[0x6E].N.Operands[1].DSO = 1;
	BaseSet[0x6E].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0x6F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6F].Behaviour = InstructionBehaviour_Outs;

	BaseSet[0x6F].N.Operands[0].IM = 1;
	BaseSet[0x6F].N.Operands[0].O16 = 1;
	BaseSet[0x6F].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x6F].N.Operands[1].IM = 1;
	BaseSet[0x6F].N.Operands[1].DSO = 1;
	BaseSet[0x6F].N.Operands[1].O16 = 1;
	BaseSet[0x6f].N.Operands[1].O32 = 1;
	BaseSet[0x6F].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0x70].Type = x86_x64InstructionType_Normal;
	BaseSet[0x70].Behaviour = InstructionBehaviour_Jo;

	BaseSet[0x70].N.Operands[0].O8 = 1;
	BaseSet[0x70].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x71].Type = x86_x64InstructionType_Normal;
	BaseSet[0x71].Behaviour = InstructionBehaviour_Jno;

	BaseSet[0x71].N.Operands[0].O8 = 1;
	BaseSet[0x71].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x72].Type = x86_x64InstructionType_Normal;
	BaseSet[0x72].Behaviour = InstructionBehaviour_Jb;

	BaseSet[0x72].N.Operands[0].O8 = 1;
	BaseSet[0x72].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x73].Type = x86_x64InstructionType_Normal;
	BaseSet[0x73].Behaviour = InstructionBehaviour_Jae;

	BaseSet[0x73].N.Operands[0].O8 = 1;
	BaseSet[0x73].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x74].Type = x86_x64InstructionType_Normal;
	BaseSet[0x74].Behaviour = InstructionBehaviour_Je;

	BaseSet[0x74].N.Operands[0].O8 = 1;
	BaseSet[0x74].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x75].Type = x86_x64InstructionType_Normal;
	BaseSet[0x75].Behaviour = InstructionBehaviour_Jne;

	BaseSet[0x75].N.Operands[0].O8 = 1;
	BaseSet[0x75].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x76].Type = x86_x64InstructionType_Normal;
	BaseSet[0x76].Behaviour = InstructionBehaviour_Jbe;

	BaseSet[0x76].N.Operands[0].O8 = 1;
	BaseSet[0x76].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x77].Type = x86_x64InstructionType_Normal;
	BaseSet[0x77].Behaviour = InstructionBehaviour_Ja;

	BaseSet[0x77].N.Operands[0].O8 = 1;
	BaseSet[0x77].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x78].Type = x86_x64InstructionType_Normal;
	BaseSet[0x78].Behaviour = InstructionBehaviour_Js;

	BaseSet[0x78].N.Operands[0].O8 = 1;
	BaseSet[0x78].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x79].Type = x86_x64InstructionType_Normal;
	BaseSet[0x79].Behaviour = InstructionBehaviour_Jns;

	BaseSet[0x79].N.Operands[0].O8 = 1;
	BaseSet[0x79].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7A].Behaviour = InstructionBehaviour_Jp;

	BaseSet[0x7A].N.Operands[0].O8 = 1;
	BaseSet[0x7A].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7B].Behaviour = InstructionBehaviour_Jnp;

	BaseSet[0x7B].N.Operands[0].O8 = 1;
	BaseSet[0x7B].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7C].Behaviour = InstructionBehaviour_Jl;

	BaseSet[0x7C].N.Operands[0].O8 = 1;
	BaseSet[0x7C].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7D].Behaviour = InstructionBehaviour_Jge;

	BaseSet[0x7D].N.Operands[0].O8 = 1;
	BaseSet[0x7D].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7E].Behaviour = InstructionBehaviour_Jle;

	BaseSet[0x7E].N.Operands[0].O8 = 1;
	BaseSet[0x7E].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7F].Behaviour = InstructionBehaviour_Jg;

	BaseSet[0x7F].N.Operands[0].O8 = 1;
	BaseSet[0x7F].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x80].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x80].R.A0 = 1;
	BaseSet[0x80].R.A1 = 1;
	BaseSet[0x80].R.A2 = 1;
	BaseSet[0x80].R.A3 = 1;
	BaseSet[0x80].R.A4 = 1;
	BaseSet[0x80].R.A5 = 1;
	BaseSet[0x80].R.A6 = 1;
	BaseSet[0x80].R.A7 = 1;

	BaseSet[0x80].R.Index = INDEX_BUFFER(&BaseSet[0x80], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x81].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x81].R.A0 = 1;
	BaseSet[0x81].R.A1 = 1;
	BaseSet[0x81].R.A2 = 1;
	BaseSet[0x81].R.A3 = 1;
	BaseSet[0x81].R.A4 = 1;
	BaseSet[0x81].R.A5 = 1;
	BaseSet[0x81].R.A6 = 1;
	BaseSet[0x81].R.A7 = 1;

	BaseSet[0x81].R.Index = INDEX_BUFFER(&BaseSet[0x81], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O16 = 1;
	SubSet[0x03].N.Operands[1].O32 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O16 = 1;
	SubSet[0x04].N.Operands[1].O32 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O16 = 1;
	SubSet[0x05].N.Operands[1].O32 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O16 = 1;
	SubSet[0x06].N.Operands[1].O32 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O16 = 1;
	SubSet[0x07].N.Operands[1].O32 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x83].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x83].R.A0 = 1;
	BaseSet[0x83].R.A1 = 1;
	BaseSet[0x83].R.A2 = 1;
	BaseSet[0x83].R.A3 = 1;
	BaseSet[0x83].R.A4 = 1;
	BaseSet[0x83].R.A5 = 1;
	BaseSet[0x83].R.A6 = 1;
	BaseSet[0x83].R.A7 = 1;

	BaseSet[0x83].R.Index = INDEX_BUFFER(&BaseSet[0x83], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x84].Type = x86_x64InstructionType_Normal;
	BaseSet[0x84].Behaviour = InstructionBehaviour_Test;

	BaseSet[0x84].N.Operands[0].O8 = 1;
	BaseSet[0x84].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x84].N.Operands[1].O8 = 1;
	BaseSet[0x84].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x85].Type = x86_x64InstructionType_Normal;
	BaseSet[0x85].Behaviour = InstructionBehaviour_Test;

	BaseSet[0x85].N.Operands[0].O16 = 1;
	BaseSet[0x85].N.Operands[0].O32 = 1;
	BaseSet[0x85].N.Operands[0].O64 = 1;
	BaseSet[0x85].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x85].N.Operands[1].O16 = 1;
	BaseSet[0x85].N.Operands[1].O32 = 1;
	BaseSet[0x85].N.Operands[1].O64 = 1;
	BaseSet[0x85].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x86].Type = x86_x64InstructionType_Normal;
	BaseSet[0x86].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x86].N.Operands[0].O8 = 1;
	BaseSet[0x86].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x86].N.Operands[1].O8 = 1;
	BaseSet[0x86].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x87].Type = x86_x64InstructionType_Normal;
	BaseSet[0x87].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x87].N.Operands[0].O16 = 1;
	BaseSet[0x87].N.Operands[0].O32 = 1;
	BaseSet[0x87].N.Operands[0].O64 = 1;
	BaseSet[0x87].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x87].N.Operands[1].O16 = 1;
	BaseSet[0x87].N.Operands[1].O32 = 1;
	BaseSet[0x87].N.Operands[1].O64 = 1;
	BaseSet[0x87].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x88].Type = x86_x64InstructionType_Normal;
	BaseSet[0x88].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x88].N.Operands[0].O8 = 1;
	BaseSet[0x88].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x88].N.Operands[1].O8 = 1;
	BaseSet[0x88].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x89].Type = x86_x64InstructionType_Normal;
	BaseSet[0x89].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x89].N.Operands[0].O16 = 1;
	BaseSet[0x89].N.Operands[0].O32 = 1;
	BaseSet[0x89].N.Operands[0].O64 = 1;
	BaseSet[0x89].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x89].N.Operands[1].O16 = 1;
	BaseSet[0x89].N.Operands[1].O32 = 1;
	BaseSet[0x89].N.Operands[1].O64 = 1;
	BaseSet[0x89].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x8A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8A].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8A].N.Operands[0].O8 = 1;
	BaseSet[0x8A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x8A].N.Operands[1].O8 = 1;
	BaseSet[0x8A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8B].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8B].N.Operands[0].O16 = 1;
	BaseSet[0x8B].N.Operands[0].O32 = 1;
	BaseSet[0x8B].N.Operands[0].O64 = 1;
	BaseSet[0x8B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x8B].N.Operands[1].O16 = 1;
	BaseSet[0x8B].N.Operands[1].O32 = 1;
	BaseSet[0x8B].N.Operands[1].O64 = 1;
	BaseSet[0x8B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8C].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8C].N.Operands[0].IM = 1;
	BaseSet[0x8C].N.Operands[0].O16 = 1;
	BaseSet[0x8C].N.Operands[0].O32 = 1;
	BaseSet[0x8C].N.Operands[0].O64 = 1;
	BaseSet[0x8C].N.Operands[0].MO32 = 1;
	BaseSet[0x8C].N.Operands[0].MO64 = 1;
	BaseSet[0x8C].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x8C].N.Operands[1].O16 = 1;
	BaseSet[0x8C].N.Operands[1].Type = x86_x64OperandType_R;
	BaseSet[0x8C].N.Operands[1].RType = x86_x64RegisterType_Segment;

	BaseSet[0x8D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8D].Behaviour = InstructionBehaviour_Lea;

	BaseSet[0x8D].N.Operands[0].O16 = 1;
	BaseSet[0x8D].N.Operands[0].O32 = 1;
	BaseSet[0x8D].N.Operands[0].O64 = 1;

	BaseSet[0x8D].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0x8D].RG.A0 = 1;
	BaseSet[0x8D].RG.A1 = 0;
	BaseSet[0x8D].RG.A2 = 0;
	BaseSet[0x8D].RG.A3 = 0;

	BaseSet[0x8D].RG.H0 = 1;
	BaseSet[0x8D].RG.H1 = 0;
	BaseSet[0x8D].RG.H2 = 0;
	BaseSet[0x8D].RG.H3 = 1;

	BaseSet[0x8D].R.Index = INDEX_BUFFER(&BaseSet[0x8D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lea;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8E].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8E].N.Operands[0].IM = 1;
	BaseSet[0x8E].N.Operands[0].O16 = 1;
	BaseSet[0x8E].N.Operands[0].Type = x86_x64OperandType_R;
	BaseSet[0x8E].N.Operands[0].RType = x86_x64RegisterType_Segment;

	BaseSet[0x8E].N.Operands[1].O16 = 1;
	BaseSet[0x8E].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8F].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0x8F].R.A0 = 1;

	BaseSet[0x8F].R.Index = INDEX_BUFFER(&BaseSet[0x8F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pop;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x90].Type = x86_x64InstructionType_Normal;
	BaseSet[0x90].Behaviour = InstructionBehaviour_Nop;

	BaseSet[0x91].Type = x86_x64InstructionType_Normal;
	BaseSet[0x91].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x91].N.Operands[0].O16 = 1;
	BaseSet[0x91].N.Operands[0].O32 = 1;
	BaseSet[0x91].N.Operands[0].O64 = 1;
	BaseSet[0x91].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x91].N.Operands[1].IM = 1;
	BaseSet[0x91].N.Operands[1].O16 = 1;
	BaseSet[0x91].N.Operands[1].O32 = 1;
	BaseSet[0x91].N.Operands[1].O64 = 1;
	BaseSet[0x91].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x92].Type = x86_x64InstructionType_Normal;
	BaseSet[0x92].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x92].N.Operands[0].O16 = 1;
	BaseSet[0x92].N.Operands[0].O32 = 1;
	BaseSet[0x92].N.Operands[0].O64 = 1;
	BaseSet[0x92].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x92].N.Operands[1].IM = 1;
	BaseSet[0x92].N.Operands[1].O16 = 1;
	BaseSet[0x92].N.Operands[1].O32 = 1;
	BaseSet[0x92].N.Operands[1].O64 = 1;
	BaseSet[0x92].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x93].Type = x86_x64InstructionType_Normal;
	BaseSet[0x93].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x93].N.Operands[0].O16 = 1;
	BaseSet[0x93].N.Operands[0].O32 = 1;
	BaseSet[0x93].N.Operands[0].O64 = 1;
	BaseSet[0x93].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x93].N.Operands[1].IM = 1;
	BaseSet[0x93].N.Operands[1].O16 = 1;
	BaseSet[0x93].N.Operands[1].O32 = 1;
	BaseSet[0x93].N.Operands[1].O64 = 1;
	BaseSet[0x93].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x94].Type = x86_x64InstructionType_Normal;
	BaseSet[0x94].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x94].N.Operands[0].O16 = 1;
	BaseSet[0x94].N.Operands[0].O32 = 1;
	BaseSet[0x94].N.Operands[0].O64 = 1;
	BaseSet[0x94].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x94].N.Operands[1].IM = 1;
	BaseSet[0x94].N.Operands[1].O16 = 1;
	BaseSet[0x94].N.Operands[1].O32 = 1;
	BaseSet[0x94].N.Operands[1].O64 = 1;
	BaseSet[0x94].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x95].Type = x86_x64InstructionType_Normal;
	BaseSet[0x95].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x95].N.Operands[0].O16 = 1;
	BaseSet[0x95].N.Operands[0].O32 = 1;
	BaseSet[0x95].N.Operands[0].O64 = 1;
	BaseSet[0x95].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x95].N.Operands[1].IM = 1;
	BaseSet[0x95].N.Operands[1].O16 = 1;
	BaseSet[0x95].N.Operands[1].O32 = 1;
	BaseSet[0x95].N.Operands[1].O64 = 1;
	BaseSet[0x95].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x96].Type = x86_x64InstructionType_Normal;
	BaseSet[0x96].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x96].N.Operands[0].O16 = 1;
	BaseSet[0x96].N.Operands[0].O32 = 1;
	BaseSet[0x96].N.Operands[0].O64 = 1;
	BaseSet[0x96].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x96].N.Operands[1].IM = 1;
	BaseSet[0x96].N.Operands[1].O16 = 1;
	BaseSet[0x96].N.Operands[1].O32 = 1;
	BaseSet[0x96].N.Operands[1].O64 = 1;
	BaseSet[0x96].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x97].Type = x86_x64InstructionType_Normal;
	BaseSet[0x97].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x97].N.Operands[0].O16 = 1;
	BaseSet[0x97].N.Operands[0].O32 = 1;
	BaseSet[0x97].N.Operands[0].O64 = 1;
	BaseSet[0x97].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x97].N.Operands[1].IM = 1;
	BaseSet[0x97].N.Operands[1].O16 = 1;
	BaseSet[0x97].N.Operands[1].O32 = 1;
	BaseSet[0x97].N.Operands[1].O64 = 1;
	BaseSet[0x97].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x9B].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x9B].Behaviour = InstructionBehaviour_Fwait;

	BaseSet[0x9B].P.Prefix.WAIT = 1;

	BaseSet[0x9C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9C].Behaviour = InstructionBehaviour_Pushf;

	BaseSet[0x9D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9D].Behaviour = InstructionBehaviour_Popf;

	BaseSet[0x9E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9E].Behaviour = InstructionBehaviour_Sahf;

	BaseSet[0x9F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9F].Behaviour = InstructionBehaviour_Lahf;

	BaseSet[0xA0].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA0].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA0].N.Operands[0].IM = 1;
	BaseSet[0xA0].N.Operands[0].O8 = 1;
	BaseSet[0xA0].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA0].N.Operands[1].O8 = 1;
	BaseSet[0xA0].N.Operands[1].DSO = 1;
	BaseSet[0xA0].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA1].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA1].N.Operands[0].IM = 1;
	BaseSet[0xA1].N.Operands[0].O16 = 1;
	BaseSet[0xA1].N.Operands[0].O32 = 1;
	BaseSet[0xA1].N.Operands[0].O64 = 1;
	BaseSet[0xA1].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA1].N.Operands[1].O16 = 1;
	BaseSet[0xA1].N.Operands[1].O32 = 1;
	BaseSet[0xA1].N.Operands[1].O64 = 1;
	BaseSet[0xA1].N.Operands[1].DSO = 1;
	BaseSet[0xA1].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA2].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA2].N.Operands[0].O8 = 1;
	BaseSet[0xA2].N.Operands[0].DSO = 1;
	BaseSet[0xA2].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xA2].N.Operands[1].IM = 1;
	BaseSet[0xA2].N.Operands[1].O8 = 1;
	BaseSet[0xA2].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xA3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA3].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA3].N.Operands[0].O16 = 1;
	BaseSet[0xA3].N.Operands[0].O32 = 1;
	BaseSet[0xA3].N.Operands[0].O64 = 1;
	BaseSet[0xA3].N.Operands[0].DSO = 1;
	BaseSet[0xA3].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xA3].N.Operands[1].IM = 1;
	BaseSet[0xA3].N.Operands[1].O16 = 1;
	BaseSet[0xA3].N.Operands[1].O32 = 1;
	BaseSet[0xA3].N.Operands[1].O64 = 1;
	BaseSet[0xA3].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xA4].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA4].Behaviour = InstructionBehaviour_Movs;

	BaseSet[0xA4].N.Operands[0].IM = 1;
	BaseSet[0xA4].N.Operands[0].O8 = 1;
	BaseSet[0xA4].N.Operands[0].DSO = 1;
	BaseSet[0xA4].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA4].N.Operands[1].IM = 1;
	BaseSet[0xA4].N.Operands[1].O8 = 1;
	BaseSet[0xA4].N.Operands[1].DSO = 1;
	BaseSet[0xA4].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA5].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA5].Behaviour = InstructionBehaviour_Movs;

	BaseSet[0xA5].N.Operands[0].IM = 1;
	BaseSet[0xA5].N.Operands[0].O16 = 1;
	BaseSet[0xA5].N.Operands[0].O32 = 1;
	BaseSet[0xA5].N.Operands[0].O64 = 1;
	BaseSet[0xA5].N.Operands[0].DSO = 1;
	BaseSet[0xA5].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA5].N.Operands[1].IM = 1;
	BaseSet[0xA5].N.Operands[1].O16 = 1;
	BaseSet[0xA5].N.Operands[1].O32 = 1;
	BaseSet[0xA5].N.Operands[1].O64 = 1;
	BaseSet[0xA5].N.Operands[1].DSO = 1;
	BaseSet[0xA5].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA6].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA6].Behaviour = InstructionBehaviour_Cmps;

	BaseSet[0xA6].N.Operands[0].IM = 1;
	BaseSet[0xA6].N.Operands[0].O8 = 1;
	BaseSet[0xA6].N.Operands[0].DSO = 1;
	BaseSet[0xA6].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA6].N.Operands[1].IM = 1;
	BaseSet[0xA6].N.Operands[1].O8 = 1;
	BaseSet[0xA6].N.Operands[1].DSO = 1;
	BaseSet[0xA6].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA7].Behaviour = InstructionBehaviour_Cmps;

	BaseSet[0xA7].N.Operands[0].IM = 1;
	BaseSet[0xA7].N.Operands[0].O16 = 1;
	BaseSet[0xA7].N.Operands[0].O32 = 1;
	BaseSet[0xA7].N.Operands[0].O64 = 1;
	BaseSet[0xA7].N.Operands[0].DSO = 1;
	BaseSet[0xA7].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA7].N.Operands[1].IM = 1;
	BaseSet[0xA7].N.Operands[1].O16 = 1;
	BaseSet[0xA7].N.Operands[1].O32 = 1;
	BaseSet[0xA7].N.Operands[1].O64 = 1;
	BaseSet[0xA7].N.Operands[1].DSO = 1;
	BaseSet[0xA7].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA8].Behaviour = InstructionBehaviour_Test;

	BaseSet[0xA8].N.Operands[0].IM = 1;
	BaseSet[0xA8].N.Operands[0].O8 = 1;
	BaseSet[0xA8].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA8].N.Operands[1].O8 = 1;
	BaseSet[0xA8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA9].Behaviour = InstructionBehaviour_Test;

	BaseSet[0xA9].N.Operands[0].IM = 1;
	BaseSet[0xA9].N.Operands[0].O16 = 1;
	BaseSet[0xA9].N.Operands[0].O32 = 1;
	BaseSet[0xA9].N.Operands[0].O64 = 1;
	BaseSet[0xA9].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA9].N.Operands[1].O16 = 1;
	BaseSet[0xA9].N.Operands[1].O32 = 1;
	BaseSet[0xA9].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xAA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAA].Behaviour = InstructionBehaviour_Stos;

	BaseSet[0xAA].N.Operands[0].IM = 1;
	BaseSet[0xAA].N.Operands[0].O8 = 1;
	BaseSet[0xAA].N.Operands[0].DSO = 1;
	BaseSet[0xAA].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAA].N.Operands[1].IM = 1;
	BaseSet[0xAA].N.Operands[1].O8 = 1;
	BaseSet[0xAA].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAB].Behaviour = InstructionBehaviour_Stos;

	BaseSet[0xAB].N.Operands[0].IM = 1;
	BaseSet[0xAB].N.Operands[0].O16 = 1;
	BaseSet[0xAB].N.Operands[0].O32 = 1;
	BaseSet[0xAB].N.Operands[0].O64 = 1;
	BaseSet[0xAB].N.Operands[0].DSO = 1;
	BaseSet[0xAB].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAB].N.Operands[1].IM = 1;
	BaseSet[0xAB].N.Operands[1].O16 = 1;
	BaseSet[0xAB].N.Operands[1].O32 = 1;
	BaseSet[0xAB].N.Operands[1].O64 = 1;
	BaseSet[0xAB].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAC].Behaviour = InstructionBehaviour_Lods;

	BaseSet[0xAC].N.Operands[0].IM = 1;
	BaseSet[0xAC].N.Operands[0].O8 = 1;
	BaseSet[0xAC].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xAC].N.Operands[1].IM = 1;
	BaseSet[0xAC].N.Operands[1].O8 = 1;
	BaseSet[0xAC].N.Operands[1].DSO = 1;
	BaseSet[0xAC].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0xAD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAD].Behaviour = InstructionBehaviour_Lods;

	BaseSet[0xAD].N.Operands[0].IM = 1;
	BaseSet[0xAD].N.Operands[0].O16 = 1;
	BaseSet[0xAD].N.Operands[0].O32 = 1;
	BaseSet[0xAD].N.Operands[0].O64 = 1;
	BaseSet[0xAD].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xAD].N.Operands[1].IM = 1;
	BaseSet[0xAD].N.Operands[1].O16 = 1;
	BaseSet[0xAD].N.Operands[1].O32 = 1;
	BaseSet[0xAD].N.Operands[1].O64 = 1;
	BaseSet[0xAD].N.Operands[1].DSO = 1;
	BaseSet[0xAD].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0xAE].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAE].Behaviour = InstructionBehaviour_Scas;

	BaseSet[0xAE].N.Operands[0].IM = 1;
	BaseSet[0xAE].N.Operands[0].O8 = 1;
	BaseSet[0xAE].N.Operands[0].DSO = 1;
	BaseSet[0xAE].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAE].N.Operands[1].IM = 1;
	BaseSet[0xAE].N.Operands[1].O8 = 1;
	BaseSet[0xAE].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAF].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAF].Behaviour = InstructionBehaviour_Scas;

	BaseSet[0xAF].N.Operands[0].IM = 1;
	BaseSet[0xAF].N.Operands[0].O16 = 1;
	BaseSet[0xAF].N.Operands[0].O32 = 1;
	BaseSet[0xAF].N.Operands[0].O64 = 1;
	BaseSet[0xAF].N.Operands[0].DSO = 1;
	BaseSet[0xAF].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAF].N.Operands[1].IM = 1;
	BaseSet[0xAF].N.Operands[1].O16 = 1;
	BaseSet[0xAF].N.Operands[1].O32 = 1;
	BaseSet[0xAF].N.Operands[1].O64 = 1;
	BaseSet[0xAF].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xB0].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB0].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB0].N.Operands[0].O8 = 1;
	BaseSet[0xB0].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xB0].N.Operands[1].O8 = 1;
	BaseSet[0xB0].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB1].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB1].N.Operands[0].O8 = 1;
	BaseSet[0xB1].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xB1].N.Operands[1].O8 = 1;
	BaseSet[0xB1].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB2].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB2].N.Operands[0].O8 = 1;
	BaseSet[0xB2].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xB2].N.Operands[1].O8 = 1;
	BaseSet[0xB2].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB3].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB3].N.Operands[0].O8 = 1;
	BaseSet[0xB3].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0xB3].N.Operands[1].O8 = 1;
	BaseSet[0xB3].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB4].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB4].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB4].N.Operands[0].O8 = 1;
	BaseSet[0xB4].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0xB4].N.Operands[1].O8 = 1;
	BaseSet[0xB4].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB5].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB5].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB5].N.Operands[0].O8 = 1;
	BaseSet[0xB5].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xB5].N.Operands[1].O8 = 1;
	BaseSet[0xB5].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB6].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB6].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB6].N.Operands[0].O8 = 1;
	BaseSet[0xB6].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0xB6].N.Operands[1].O8 = 1;
	BaseSet[0xB6].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB7].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB7].N.Operands[0].O8 = 1;
	BaseSet[0xB7].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xB7].N.Operands[1].O8 = 1;
	BaseSet[0xB7].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB8].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB8].N.Operands[0].O16 = 1;
	BaseSet[0xB8].N.Operands[0].O32 = 1;
	BaseSet[0xB8].N.Operands[0].O64 = 1;
	BaseSet[0xB8].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xB8].N.Operands[1].O16 = 1;
	BaseSet[0xB8].N.Operands[1].O32 = 1;
	BaseSet[0xB8].N.Operands[1].O64 = 1;
	BaseSet[0xB8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB9].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB9].N.Operands[0].O16 = 1;
	BaseSet[0xB9].N.Operands[0].O32 = 1;
	BaseSet[0xB9].N.Operands[0].O64 = 1;
	BaseSet[0xB9].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xB9].N.Operands[1].O16 = 1;
	BaseSet[0xB9].N.Operands[1].O32 = 1;
	BaseSet[0xB9].N.Operands[1].O64 = 1;
	BaseSet[0xB9].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBA].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBA].N.Operands[0].O16 = 1;
	BaseSet[0xBA].N.Operands[0].O32 = 1;
	BaseSet[0xBA].N.Operands[0].O64 = 1;
	BaseSet[0xBA].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xBA].N.Operands[1].O16 = 1;
	BaseSet[0xBA].N.Operands[1].O32 = 1;
	BaseSet[0xBA].N.Operands[1].O64 = 1;
	BaseSet[0xBA].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBB].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBB].N.Operands[0].O16 = 1;
	BaseSet[0xBB].N.Operands[0].O32 = 1;
	BaseSet[0xBB].N.Operands[0].O64 = 1;
	BaseSet[0xBB].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0xBB].N.Operands[1].O16 = 1;
	BaseSet[0xBB].N.Operands[1].O32 = 1;
	BaseSet[0xBB].N.Operands[1].O64 = 1;
	BaseSet[0xBB].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBC].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBC].N.Operands[0].O16 = 1;
	BaseSet[0xBC].N.Operands[0].O32 = 1;
	BaseSet[0xBC].N.Operands[0].O64 = 1;
	BaseSet[0xBC].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0xBC].N.Operands[1].O16 = 1;
	BaseSet[0xBC].N.Operands[1].O32 = 1;
	BaseSet[0xBC].N.Operands[1].O64 = 1;
	BaseSet[0xBC].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBD].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBD].N.Operands[0].O16 = 1;
	BaseSet[0xBD].N.Operands[0].O32 = 1;
	BaseSet[0xBD].N.Operands[0].O64 = 1;
	BaseSet[0xBD].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xBD].N.Operands[1].O16 = 1;
	BaseSet[0xBD].N.Operands[1].O32 = 1;
	BaseSet[0xBD].N.Operands[1].O64 = 1;
	BaseSet[0xBD].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBE].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBE].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBE].N.Operands[0].O16 = 1;
	BaseSet[0xBE].N.Operands[0].O32 = 1;
	BaseSet[0xBE].N.Operands[0].O64 = 1;
	BaseSet[0xBE].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0xBE].N.Operands[1].O16 = 1;
	BaseSet[0xBE].N.Operands[1].O32 = 1;
	BaseSet[0xBE].N.Operands[1].O64 = 1;
	BaseSet[0xBE].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBF].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBF].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBF].N.Operands[0].O16 = 1;
	BaseSet[0xBF].N.Operands[0].O32 = 1;
	BaseSet[0xBF].N.Operands[0].O64 = 1;
	BaseSet[0xBF].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xBF].N.Operands[1].O16 = 1;
	BaseSet[0xBF].N.Operands[1].O32 = 1;
	BaseSet[0xBF].N.Operands[1].O64 = 1;
	BaseSet[0xBF].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC0].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xC0].R.A0 = 1;
	BaseSet[0xC0].R.A1 = 1;
	BaseSet[0xC0].R.A2 = 1;
	BaseSet[0xC0].R.A3 = 1;
	BaseSet[0xC0].R.A4 = 1;
	BaseSet[0xC0].R.A5 = 1;
	BaseSet[0xC0].R.A6 = 1;
	BaseSet[0xC0].R.A7 = 1;

	BaseSet[0xC0].R.Index = INDEX_BUFFER(&BaseSet[0xC0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC1].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xC1].R.A0 = 1;
	BaseSet[0xC1].R.A1 = 1;
	BaseSet[0xC1].R.A2 = 1;
	BaseSet[0xC1].R.A3 = 1;
	BaseSet[0xC1].R.A4 = 1;
	BaseSet[0xC1].R.A5 = 1;
	BaseSet[0xC1].R.A6 = 1;
	BaseSet[0xC1].R.A7 = 1;

	BaseSet[0xC1].R.Index = INDEX_BUFFER(&BaseSet[0xC1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC2].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xC2].N.Operands[0].O16 = 1;
	BaseSet[0xC2].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xC3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC3].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xC6].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0xC6].R.A0 = 1;

	BaseSet[0xC6].R.Index = INDEX_BUFFER(&BaseSet[0xC6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC7].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0xC7].R.A0 = 1;

	BaseSet[0xC7].R.Index = INDEX_BUFFER(&BaseSet[0xC7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC8].Behaviour = InstructionBehaviour_Enter;

	BaseSet[0xC8].N.Operands[0].IM = 1;
	BaseSet[0xC8].N.Operands[0].O16 = 1;
	BaseSet[0xC8].N.Operands[0].O64 = 1;
	BaseSet[0xC8].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xC8].N.Operands[1].O16 = 1;
	BaseSet[0xC8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC8].N.Operands[2].O8 = 1;
	BaseSet[0xC8].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0xC9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC9].Behaviour = InstructionBehaviour_Leave;

	BaseSet[0xC9].N.Operands[0].IM = 1;
	BaseSet[0xC9].N.Operands[0].O16 = 1;
	BaseSet[0xC9].N.Operands[0].O64 = 1;
	BaseSet[0xC9].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xCA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCA].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xCA].N.Operands[0].O16 = 1;
	BaseSet[0xCA].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xCB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCB].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xCC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCC].Behaviour = InstructionBehaviour_Int;

	BaseSet[0xCC].N.Operands[0].O8 = 1;
	BaseSet[0xCC].N.Operands[0].Value = 3;
	BaseSet[0xCC].N.Operands[0].Type = x86_x64OperandType_Value;

	BaseSet[0xCD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCD].Behaviour = InstructionBehaviour_Int;

	BaseSet[0xCD].N.Operands[0].O8 = 1;
	BaseSet[0xCD].N.Operands[0].Type = x86_x64OperandType_IMM;
}

static unsigned char CountBits(unsigned long Value, unsigned char From, unsigned char To)
{
	if (From >= To)
		return 0;

	unsigned char Count;

	Count = 0;

	Value = (Value >> From) & ((1 << (To - From)) - 1);
	for (; Value; Value >>= 1)
	{
		if (Value & 1)
			Count++;
	}

	return Count;
}

static void ParseCode(x86_x64Instruction* SetBuffer, void* Code, unsigned long long CodeSize, Operation* OperationBuffer, unsigned long long* OperationCount)
{
	//const x86_x64Override RegisterOverrideMap[] = { { OperandType_IR, 1 }, { OperandType_SR, 0 } };
	const OperandType RegisterTypeMap[] = { OperandType_IR, OperandType_SR };

	x86_x64Instruction* Instruction;
	x86_x64PrefixMap PrefixMap;

	unsigned char RedirectedViaOpByte;
	unsigned char MemoryToRegister;

	unsigned char OperandByte;
	unsigned char MainOperand;

	PrefixMap.Value = 0;
	MemoryToRegister = 0;
	RedirectedViaOpByte = 0;

	*OperationCount = 0;
	while (CodeSize)
	{
		Instruction = &SetBuffer[*((unsigned char*)Code)];

		CodeSize--;
		Code = ((unsigned char*)Code) + 1;

		memset(OperationBuffer, 0, sizeof(Operation));

		while (1)
		{
			if (Instruction->Type == x86_x64InstructionType_UpperRedirect)
			{
				unsigned char Portion;

				if (!RedirectedViaOpByte)
				{
					OperandByte = *((unsigned char*)Code);

					CodeSize--;
					Code = ((unsigned char*)Code) + 1;

					RedirectedViaOpByte = 1;
				}

				Portion = (OperandByte >> 3) & ((1 << 3) - 1);
				if (Instruction->R.Available & (1 << Portion))
				{
					Portion = CountBits(Instruction->R.Available, 0, Portion);
					Instruction = (Instruction + Instruction->R.Index + Portion);
				}
				else
					goto Instruction_Invalid;
			}
			else if (Instruction->Type == x86_x64InstructionType_GlobalRedirect)
			{
				unsigned char Portion;

				if (!RedirectedViaOpByte)
				{
					OperandByte = *((unsigned char*)Code);

					CodeSize--;
					Code = ((unsigned char*)Code) + 1;

					RedirectedViaOpByte = 1;
				}

				Portion = OperandByte >> 6;
				if (Instruction->R.Available & (1 << Portion))
					Portion = CountBits(Instruction->R.Available, 0, Portion);
				else
				{
					if (!((Instruction->R.Available >> 4) & (1 << Portion)))
						Portion = 0;
					else
						goto Instruction_Invalid;
				}

				Instruction = (Instruction + Instruction->R.Index + Portion);
			}
			else
				break;
		}

		if (!Instruction->Type)
			goto Instruction_Invalid;

		if (Instruction->Type == x86_x64InstructionType_Prefix)
		{
			PrefixMap.Value |= Instruction->P.Prefix.Value;

			if (!Instruction->Behaviour)
				continue;

			OperationBuffer->Behaviour = (InstructionBehaviour)Instruction->Behaviour; // Semi implemented semi prefix

			OperationBuffer++;
			(*OperationCount)++;
			continue;
		}

		OperationBuffer->Behaviour = (InstructionBehaviour)Instruction->Behaviour;

		MainOperand = 5;
		if (Instruction->N.Operands[0].Type == x86_x64OperandType_M)
			MainOperand = 0;
		else if (Instruction->N.Operands[1].Type == x86_x64OperandType_M)
			MainOperand = 1;

		if (MainOperand < 4)
		{
			if (!RedirectedViaOpByte)
			{
				OperandByte = *((unsigned char*)Code);

				CodeSize--;
				Code = ((unsigned char*)Code) + 1;
			}

			if (OperandByte >> 6 == 3) // Operation register to register
			{
				OperationBuffer->Operands[MainOperand].Type = RegisterTypeMap[Instruction->N.Operands[MainOperand].RType];
				if (PrefixMap.REX)
				{
					OperationBuffer->Operands[MainOperand].Register.HighLowPart = 0;
					OperationBuffer->Operands[MainOperand].Register.Register = (OperandByte & ((1 << 3) - 1)) + (PrefixMap.REXB && !Instruction->N.Operands[MainOperand].IM ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->Operands[MainOperand].Register.HighLowPart = (OperandByte & ((1 << 3) - 1)) > 3;
					OperationBuffer->Operands[MainOperand].Register.Register = ((OperandByte & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
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
							OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;
							OperationBuffer->Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

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
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = ~0;
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;
						OperationBuffer->Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

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

			if (Instruction->N.Operands[!MainOperand].Type == x86_x64OperandType_R)
			{
				OperationBuffer->Operands[!MainOperand].Type = RegisterTypeMap[Instruction->N.Operands[!MainOperand].RType];
				if (PrefixMap.REX)
				{
					OperationBuffer->Operands[!MainOperand].Register.HighLowPart = 0;
					OperationBuffer->Operands[!MainOperand].Register.Register = ((OperandByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXR && !Instruction->N.Operands[!MainOperand].IM ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->Operands[!MainOperand].Register.HighLowPart = ((OperandByte >> 3) & ((1 << 3) - 1)) > 3;
					OperationBuffer->Operands[!MainOperand].Register.Register = (((OperandByte >> 3) & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
				}
			}
		}

		for (unsigned char i = 0; i < 4; i++)
		{
			if (!Instruction->N.Operands[i].Type)
				break;

			if (Instruction->N.Operands[i].Type == x86_x64OperandType_M && !MemoryToRegister)
			{
				if (Instruction->N.Operands[i].O8 && !Instruction->N.Operands[i].MO8) // Establish default size
					OperationBuffer->Operands[i].OperandSize = OperandSize_8;

				else if (Instruction->N.Operands[i].O32 && !Instruction->N.Operands[i].MO32)
					OperationBuffer->Operands[i].OperandSize = OperandSize_32;

				else if (Instruction->N.Operands[i].O64 && !Instruction->N.Operands[i].MO64)
					OperationBuffer->Operands[i].OperandSize = OperandSize_64;

				else if (Instruction->N.Operands[i].O16 && !Instruction->N.Operands[i].MO16)
					OperationBuffer->Operands[i].OperandSize = OperandSize_16;

				else
					OperationBuffer->Behaviour = InstructionBehaviour_Invalid;

				if (Instruction->N.Operands[i].O64 && PrefixMap.REXW && !Instruction->N.Operands[i].MO64)
					OperationBuffer->Operands[i].OperandSize = OperandSize_64;

				else if (Instruction->N.Operands[i].O16 && PrefixMap.WORD && !Instruction->N.Operands[i].MO16)
					OperationBuffer->Operands[i].OperandSize = OperandSize_16;
			}
			else
			{
				if (Instruction->N.Operands[i].O8) // Establish default size
					OperationBuffer->Operands[i].OperandSize = OperandSize_8;

				else if (Instruction->N.Operands[i].O32)
					OperationBuffer->Operands[i].OperandSize = OperandSize_32;

				else if (Instruction->N.Operands[i].O64)
					OperationBuffer->Operands[i].OperandSize = OperandSize_64;

				else if (Instruction->N.Operands[i].O16)
					OperationBuffer->Operands[i].OperandSize = OperandSize_16;

				else
					OperationBuffer->Behaviour = InstructionBehaviour_Invalid;

				if (Instruction->N.Operands[i].O64 && PrefixMap.REXW)
					OperationBuffer->Operands[i].OperandSize = OperandSize_64;

				else if (Instruction->N.Operands[i].O16 && PrefixMap.WORD)
					OperationBuffer->Operands[i].OperandSize = OperandSize_16;
			}

			switch (Instruction->N.Operands[i].Type)
			{
			case x86_x64OperandType_IMM:
			{
				if (Instruction->N.Operands[i].DSO)
				{
					OperationBuffer->Operands[i].Type = OperandType_ML;
					OperationBuffer->Operands[i].MemoryLarge.Value = *(unsigned long long*)Code;

					CodeSize -= 8;
					Code = ((unsigned char*)Code) + 8;

					continue;
				}

				OperationBuffer->Operands[i].Type = OperandType_V;
				switch (OperationBuffer->Operands[i].OperandSize)
				{
				case OperandSize_8:
				{
					OperationBuffer->Operands[i].Value.Value = *(unsigned char*)Code;

					CodeSize--;
					Code = ((unsigned char*)Code) + 1;
				} break;
				case OperandSize_16:
				{
					OperationBuffer->Operands[i].Value.Value = *(unsigned short*)Code;

					CodeSize -= 2;
					Code = ((unsigned char*)Code) + 2;
				} break;
				case OperandSize_32:
				{
					OperationBuffer->Operands[i].Value.Value = *(unsigned long*)Code;

					CodeSize -= 4;
					Code = ((unsigned char*)Code) + 4;
				} break;
				case OperandSize_64:
				{
					OperationBuffer->Operands[i].Value.Value = *(unsigned long long*)Code;

					CodeSize -= 8;
					Code = ((unsigned char*)Code) + 8;
				} break;
				}
			} break;
			case x86_x64OperandType_Rel:
			{
				OperationBuffer->Operands[i].Type = OperandType_Rel;
				switch (OperationBuffer->Operands[i].OperandSize)
				{
				case OperandSize_8:
				{
					OperationBuffer->Operands[i].RelValue.Value = (long)*(char*)Code;

					CodeSize--;
					Code = ((unsigned char*)Code) + 1;
				} break;
				case OperandSize_16:
				{
					OperationBuffer->Operands[i].RelValue.Value = (long)*(short*)Code;

					CodeSize -= 2;
					Code = ((unsigned char*)Code) + 2;
				} break;
				case OperandSize_32:
				{
					OperationBuffer->Operands[i].RelValue.Value = *(long*)Code;

					CodeSize -= 4;
					Code = ((unsigned char*)Code) + 4;
				} break;
				}
			} break;
			case x86_x64OperandType_Value:
			{
				OperationBuffer->Operands[i].Type = OperandType_V;
				OperationBuffer->Operands[i].Value.Value = Instruction->N.Operands[i].Value;
			} break;
			default:
			{
				if (Instruction->N.Operands[i].Type >= x86_x64OperandType_AX)
				{
					if (Instruction->N.Operands[i].DSO)
					{
						OperationBuffer->Operands[i].Type = OperandType_M;
						OperationBuffer->Operands[i].Memory.FirstRegister = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + ((PrefixMap.REXB && !Instruction->N.Operands[i].IM) ? 8 : 0) + 1;
					}
					else
					{
						OperationBuffer->Operands[i].Type = OperandType_IR;

						if (PrefixMap.REX && !Instruction->N.Operands[i].IM)
						{
							OperationBuffer->Operands[i].Register.Register = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + (PrefixMap.REXB ? 8 : 0) + 1;
							OperationBuffer->Operands[i].Register.HighLowPart = 0;
						}
						else
						{
							OperationBuffer->Operands[i].Register.Register = ((Instruction->N.Operands[i].Type - x86_x64OperandType_AX) & (Instruction->N.Operands[i].IM ? ((1 << 3) - 1) : ((1 << 2) - 1))) + 1;
							OperationBuffer->Operands[i].Register.HighLowPart = !Instruction->N.Operands[i].IM && (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) > 3;
						}

					}
				}
			} break;
			}
		}

	Instruction_Invalid:

		OperationBuffer++;
		(*OperationCount)++;

		PrefixMap.Value = 0;
		MemoryToRegister = 0;
		RedirectedViaOpByte = 0;
	}
}