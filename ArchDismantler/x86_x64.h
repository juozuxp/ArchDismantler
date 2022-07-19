#pragma once
#include "InstructionSet.h"

typedef enum _x86_x64OperandType
{
	x86_x64OperandType_None,
	x86_x64OperandType_M,
	x86_x64OperandType_R,
	x86_x64OperandType_AX,
	x86_x64OperandType_IMM = 1 << 4,
	x86_x64OperandType_IMMN64,	// No 64
	x86_x64OperandType_IMM64,	// 64 Compatible
	x86_x64OperandType_MIMM
} x86_x64OperandType, *Px86_x64OperandType;

typedef struct _x86_x64Operand
{
	x86_x64OperandType Type;
} x86_x64Operand, *Px86_x64Operand;

typedef struct _x86_x64Instruction
{
	InstructionBehaviour Behaviour;

	struct
	{
		struct
		{
			unsigned char O8 : 1;  // Operation modes from 8 bit to 64 bit
			unsigned char O16 : 1;
			unsigned char O32 : 1;
			unsigned char O64 : 1;
		};
	} Compatability;

	x86_x64Operand Operands[4];
} x86_x64Instruction, *Px86_x64Instruction;

static void ConstructInstructionSet(x86_x64Instruction* SetBuffer)
{
	memset(SetBuffer, 0, 255 * sizeof(x86_x64Instruction));

	SetBuffer[0x00].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x00].Compatability.O8 = 1;

	SetBuffer[0x00].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x00].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x01].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x01].Compatability.O16 = 1;
	SetBuffer[0x01].Compatability.O32 = 1;
	SetBuffer[0x01].Compatability.O64 = 1;

	SetBuffer[0x01].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x01].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x02].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x02].Compatability.O8 = 1;

	SetBuffer[0x02].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x02].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x03].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x03].Compatability.O16 = 1;
	SetBuffer[0x03].Compatability.O32 = 1;
	SetBuffer[0x03].Compatability.O64 = 1;

	SetBuffer[0x03].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x03].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x04].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x04].Compatability.O8 = 1;

	SetBuffer[0x04].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x04].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x05].Behaviour = InstructionBehaviour_Add;

	SetBuffer[0x05].Compatability.O16 = 1;
	SetBuffer[0x05].Compatability.O32 = 1;
	SetBuffer[0x05].Compatability.O64 = 1;

	SetBuffer[0x05].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x05].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x08].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x08].Compatability.O8 = 1;

	SetBuffer[0x08].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x08].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x09].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x09].Compatability.O16 = 1;
	SetBuffer[0x09].Compatability.O32 = 1;
	SetBuffer[0x09].Compatability.O64 = 1;

	SetBuffer[0x09].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x09].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x0A].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0A].Compatability.O8 = 1;

	SetBuffer[0x0A].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x0A].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x0B].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0B].Compatability.O16 = 1;
	SetBuffer[0x0B].Compatability.O32 = 1;
	SetBuffer[0x0B].Compatability.O64 = 1;

	SetBuffer[0x0B].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x0B].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x0C].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0C].Compatability.O8 = 1;

	SetBuffer[0x0C].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x0C].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x0D].Behaviour = InstructionBehaviour_Or;

	SetBuffer[0x0D].Compatability.O16 = 1;
	SetBuffer[0x0D].Compatability.O32 = 1;
	SetBuffer[0x0D].Compatability.O64 = 1;

	SetBuffer[0x0D].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x0D].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x10].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x10].Compatability.O8 = 1;

	SetBuffer[0x10].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x10].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x11].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x11].Compatability.O16 = 1;
	SetBuffer[0x11].Compatability.O32 = 1;
	SetBuffer[0x11].Compatability.O64 = 1;

	SetBuffer[0x11].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x11].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x12].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x12].Compatability.O8 = 1;

	SetBuffer[0x12].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x12].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x13].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x13].Compatability.O16 = 1;
	SetBuffer[0x13].Compatability.O32 = 1;
	SetBuffer[0x13].Compatability.O64 = 1;

	SetBuffer[0x13].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x13].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x14].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x14].Compatability.O8 = 1;

	SetBuffer[0x14].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x14].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x15].Behaviour = InstructionBehaviour_Adc;

	SetBuffer[0x15].Compatability.O16 = 1;
	SetBuffer[0x15].Compatability.O32 = 1;
	SetBuffer[0x15].Compatability.O64 = 1;

	SetBuffer[0x15].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x15].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x18].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x18].Compatability.O8 = 1;

	SetBuffer[0x18].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x18].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x19].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x19].Compatability.O16 = 1;
	SetBuffer[0x19].Compatability.O32 = 1;
	SetBuffer[0x19].Compatability.O64 = 1;

	SetBuffer[0x19].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x19].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x1A].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1A].Compatability.O8 = 1;

	SetBuffer[0x1A].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x1A].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x1B].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1B].Compatability.O16 = 1;
	SetBuffer[0x1B].Compatability.O32 = 1;
	SetBuffer[0x1B].Compatability.O64 = 1;

	SetBuffer[0x1B].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x1B].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x1C].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1C].Compatability.O8 = 1;

	SetBuffer[0x1C].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x1C].Operands[1].Type = x86_x64OperandType_IMMN64;
	
	SetBuffer[0x1D].Behaviour = InstructionBehaviour_Sbb;

	SetBuffer[0x1D].Compatability.O16 = 1;
	SetBuffer[0x1D].Compatability.O32 = 1;
	SetBuffer[0x1D].Compatability.O64 = 1;

	SetBuffer[0x1D].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x1D].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x20].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x20].Compatability.O8 = 1;

	SetBuffer[0x20].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x20].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x21].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x21].Compatability.O16 = 1;
	SetBuffer[0x21].Compatability.O32 = 1;
	SetBuffer[0x21].Compatability.O64 = 1;

	SetBuffer[0x21].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x21].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x22].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x22].Compatability.O8 = 1;

	SetBuffer[0x22].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x22].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x23].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x23].Compatability.O16 = 1;
	SetBuffer[0x23].Compatability.O32 = 1;
	SetBuffer[0x23].Compatability.O64 = 1;

	SetBuffer[0x23].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x23].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x24].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x24].Compatability.O8 = 1;

	SetBuffer[0x24].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x24].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x25].Behaviour = InstructionBehaviour_And;

	SetBuffer[0x25].Compatability.O16 = 1;
	SetBuffer[0x25].Compatability.O32 = 1;
	SetBuffer[0x25].Compatability.O64 = 1;

	SetBuffer[0x25].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x25].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x28].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x28].Compatability.O8 = 1;

	SetBuffer[0x28].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x28].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x29].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x29].Compatability.O16 = 1;
	SetBuffer[0x29].Compatability.O32 = 1;
	SetBuffer[0x29].Compatability.O64 = 1;

	SetBuffer[0x29].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x29].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x2A].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2A].Compatability.O8 = 1;

	SetBuffer[0x2A].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x2A].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x2B].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2B].Compatability.O16 = 1;
	SetBuffer[0x2B].Compatability.O32 = 1;
	SetBuffer[0x2B].Compatability.O64 = 1;

	SetBuffer[0x2B].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x2B].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x2C].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2C].Compatability.O8 = 1;

	SetBuffer[0x2C].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x2C].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x2D].Behaviour = InstructionBehaviour_Sub;

	SetBuffer[0x2D].Compatability.O16 = 1;
	SetBuffer[0x2D].Compatability.O32 = 1;
	SetBuffer[0x2D].Compatability.O64 = 1;

	SetBuffer[0x2D].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x2D].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x30].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x30].Compatability.O8 = 1;

	SetBuffer[0x30].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x30].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x31].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x31].Compatability.O16 = 1;
	SetBuffer[0x31].Compatability.O32 = 1;
	SetBuffer[0x31].Compatability.O64 = 1;

	SetBuffer[0x31].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x31].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x32].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x32].Compatability.O8 = 1;

	SetBuffer[0x32].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x32].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x33].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x33].Compatability.O16 = 1;
	SetBuffer[0x33].Compatability.O32 = 1;
	SetBuffer[0x33].Compatability.O64 = 1;

	SetBuffer[0x33].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x33].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x34].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x34].Compatability.O8 = 1;

	SetBuffer[0x34].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x34].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x35].Behaviour = InstructionBehaviour_Xor;

	SetBuffer[0x35].Compatability.O16 = 1;
	SetBuffer[0x35].Compatability.O32 = 1;
	SetBuffer[0x35].Compatability.O64 = 1;

	SetBuffer[0x35].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x35].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x38].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x38].Compatability.O8 = 1;

	SetBuffer[0x38].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x38].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x39].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x39].Compatability.O16 = 1;
	SetBuffer[0x39].Compatability.O32 = 1;
	SetBuffer[0x39].Compatability.O64 = 1;

	SetBuffer[0x39].Operands[0].Type = x86_x64OperandType_M;
	SetBuffer[0x39].Operands[1].Type = x86_x64OperandType_R;

	SetBuffer[0x3A].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3A].Compatability.O8 = 1;

	SetBuffer[0x3A].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x3A].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x3B].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3B].Compatability.O16 = 1;
	SetBuffer[0x3B].Compatability.O32 = 1;
	SetBuffer[0x3B].Compatability.O64 = 1;

	SetBuffer[0x3B].Operands[0].Type = x86_x64OperandType_R;
	SetBuffer[0x3B].Operands[1].Type = x86_x64OperandType_M;

	SetBuffer[0x3C].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3C].Compatability.O8 = 1;

	SetBuffer[0x3C].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x3C].Operands[1].Type = x86_x64OperandType_IMMN64;

	SetBuffer[0x3D].Behaviour = InstructionBehaviour_Cmp;

	SetBuffer[0x3D].Compatability.O16 = 1;
	SetBuffer[0x3D].Compatability.O32 = 1;
	SetBuffer[0x3D].Compatability.O64 = 1;

	SetBuffer[0x3D].Operands[0].Type = x86_x64OperandType_AX;
	SetBuffer[0x3D].Operands[1].Type = x86_x64OperandType_IMMN64;
}

static void ParseCode(x86_x64Instruction* SetBuffer, void* Code, unsigned long long CodeSize, Operation* OperationBuffer, unsigned long long* OperationCount)
{
	x86_x64Instruction* Instruction;

	unsigned char OperandByte;
	unsigned char MainOperand;

	*OperationCount = 0;
	for (; CodeSize; OperationBuffer++, (*OperationCount)++)
	{
		Instruction = &SetBuffer[*((unsigned char*)Code)];

		CodeSize--;
		Code = ((unsigned char*)Code) + 1;

		memset(OperationBuffer, 0, sizeof(Operation));

		OperationBuffer->Behaviour = Instruction->Behaviour;

		if (Instruction->Compatability.O8)
			OperationBuffer->OperationSize = OperationSize_8;

		if (Instruction->Compatability.O32)
			OperationBuffer->OperationSize = OperationSize_32;

		MainOperand = 0;
		if (Instruction->Operands[0].Type == x86_x64OperandType_AX)
		{
			OperationBuffer->Operands[0].Type = OperandType_IR;
			OperationBuffer->Operands[0].IRegister.Register = 1;

			MainOperand = 1;
		}
		else if (Instruction->Operands[1].Type == x86_x64OperandType_AX)
		{
			OperationBuffer->Operands[1].Type = OperandType_IR;
			OperationBuffer->Operands[1].IRegister.Register = 1;

			MainOperand = 0;
		}
		else
		{
			if (Instruction->Operands[0].Type == x86_x64OperandType_M)
				MainOperand = 0;
			else if (Instruction->Operands[1].Type == x86_x64OperandType_M)
				MainOperand = 1;
		}
		
		if (Instruction->Operands[MainOperand].Type == x86_x64OperandType_M)
		{
			OperandByte = *((unsigned char*)Code);

			CodeSize--;
			Code = ((unsigned char*)Code) + 1;

			if (OperandByte >> 6 == 3) // Operation register to register
			{
				OperationBuffer->Operands[MainOperand].Type = OperandType_IR;
				OperationBuffer->Operands[MainOperand].IRegister.Register = (OperandByte & ((1 << 3) - 1)) + 1;
			}
			else
			{
				OperationBuffer->Operands[MainOperand].Type = OperandType_M;
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
							OperationBuffer->Operands[MainOperand].MemoryLarge.Value = *(unsigned long*)Code;

							CodeSize -= 4;
							Code = ((unsigned char*)Code) + 4;

							break;
						}

						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + 1;
					}
					else if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0)
					{
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + 1;
						OperationBuffer->Operands[MainOperand].Memory.Offset = *(long*)Code;

						CodeSize -= 4;
						Code = ((unsigned char*)Code) + 4;
					}
					else
					{
						OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + 1;
						OperationBuffer->Operands[MainOperand].Memory.SecondRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + 1;
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
					OperationBuffer->Operands[MainOperand].Memory.FirstRegister = (OperandByte & ((1 << 3) - 1)) + 1;

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

			if (Instruction->Operands[!MainOperand].Type == x86_x64OperandType_R)
			{
				OperationBuffer->Operands[!MainOperand].Type = OperandType_IR;
				OperationBuffer->Operands[!MainOperand].IRegister.Register = ((OperandByte >> 3) & ((1 << 3) - 1)) + 1;
			}
		}
		else if (Instruction->Operands[MainOperand].Type & x86_x64OperandType_IMM)
		{
			OperationBuffer->Operands[MainOperand].Type = OperandType_V;
			switch (OperationBuffer->OperationSize)
			{
			case OperationSize_8:
			{
				OperationBuffer->Operands[MainOperand].Value.ValueSize = 1;
				OperationBuffer->Operands[MainOperand].Value.Value = *(unsigned char*)Code;

				CodeSize--;
				Code = ((unsigned char*)Code) + 1;
			} break;
			case OperationSize_16:
			{
				OperationBuffer->Operands[MainOperand].Value.ValueSize = 2;
				OperationBuffer->Operands[MainOperand].Value.Value = *(unsigned short*)Code;

				CodeSize -= 2;
				Code = ((unsigned char*)Code) + 2;
			} break;
			case OperationSize_32:
			{
				OperationBuffer->Operands[MainOperand].Value.ValueSize = 3;
				OperationBuffer->Operands[MainOperand].Value.Value = *(unsigned long*)Code;

				CodeSize -= 4;
				Code = ((unsigned char*)Code) + 4;
			} break;
			case OperationSize_64:
			{
				OperationBuffer->Operands[MainOperand].Value.ValueSize = 4;
				OperationBuffer->Operands[MainOperand].Value.Value = *(unsigned long long*)Code;

				CodeSize -= 8;
				Code = ((unsigned char*)Code) + 8;
			} break;
			}
		}
	}
}