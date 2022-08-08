#pragma once

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
	x86_x64RegisterType_StackTop,
	x86_x64RegisterType_Extended,
	x86_x64RegisterType_Control,
	x86_x64RegisterType_Xmm,
	x86_x64RegisterType_Debug,
	x86_x64RegisterType_Mm,
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
	x86_x64InstructionType_OperandLess,
	x86_x64InstructionType_FullRedirect,
	x86_x64InstructionType_PrefixRedirect,

	x86_x64InstructionType_LowerRedirect,
	x86_x64InstructionType_UpperRedirect,
	x86_x64InstructionType_GlobalRedirect,

	x86_x64InstructionType_ExLowerRedirect,
	x86_x64InstructionType_ExUpperRedirect,
	x86_x64InstructionType_ExGlobalRedirect,
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
		unsigned char O80 : 1;
		unsigned char O128 : 1;

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

typedef union _x86_x64IndexablePrefixes
{
	unsigned char Value;
	struct
	{
		unsigned char REXW : 1;
		unsigned char WAIT : 1;
		unsigned char WORD : 1;
		unsigned char REPE : 1;
		unsigned char REPNE : 1;
	};
} x86_x64IndexablePrefixes, * Px86_x64IndexablePrefixes;

typedef union _x86_x64PrefixMap
{
	unsigned short Value;
	struct
	{
		unsigned short REXW : 1;
		unsigned short WAIT : 1;
		unsigned short WORD : 1;
		unsigned short REPZ : 1;
		unsigned short REPNZ : 1;

		unsigned short REX : 1;
		unsigned short REXB : 1;
		unsigned short REXX : 1;
		unsigned short REXR : 1;
		unsigned short GS : 1;
		unsigned short FS : 1;
		unsigned short LOCK : 1;
	};
} x86_x64PrefixMap, * Px86_x64PrefixMap;

typedef struct _x86_x64Instruction
{
	struct
	{
		unsigned short Type : 4;
		unsigned short Behaviour : 10;

		unsigned short Lockable : 1; // #LOCK can be asserted
		unsigned short Repeatable : 1; // REP Prefix will not fail
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

		struct
		{
			unsigned short Index;
			union
			{
				struct
				{
					unsigned char A0 : 1; // RexW
					unsigned char A1 : 1; // Wait
					unsigned char A2 : 1; // Word
					unsigned char A3 : 1; // Repe
					unsigned char A4 : 1; // Repne
					unsigned char U5 : 1; // undefined 5
					unsigned char U6 : 1; // undefined 6
					unsigned char DC : 1; // Default case
				};
				unsigned char Available;
			};
		} RP;

		struct
		{
			unsigned short Index;
		} RF;

		struct
		{
			unsigned char O8 : 1;  // Operation modes from 8 bit to 64 bit
			unsigned char O16 : 1;
			unsigned char O32 : 1;
			unsigned char O64 : 1;
		} OL;
	};
} x86_x64Instruction, * Px86_x64Instruction;