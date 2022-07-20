#pragma once

typedef enum _InstructionBehaviour
{
	InstructionBehaviour_Invalid,
	InstructionBehaviour_Add,
	InstructionBehaviour_Or,
	InstructionBehaviour_Adc,
	InstructionBehaviour_Sbb,
	InstructionBehaviour_And,
	InstructionBehaviour_Sub,
	InstructionBehaviour_Xor,
	InstructionBehaviour_Cmp,
	InstructionBehaviour_Push,
	InstructionBehaviour_Pop,
	InstructionBehaviour_Movsxd
} InstructionBehaviour, *PInstructionBehaviour;

typedef enum _OperandType
{
	OperandType_None,
	OperandType_IR,	// Integer register
	OperandType_M,	// Memory
	OperandType_ML,	// Memory large
	OperandType_V,	// Value
} OperandType, *POperandType;

typedef enum _OperandSize
{
	OperandSize_8,
	OperandSize_16,
	OperandSize_32,
	OperandSize_64
} OperandSize, *POperandSize;

typedef struct _Operand // Registers are counted 1 ... 254, 255 reserved for relativity
{
	OperandType Type;
	OperandSize OperandSize;
	union
	{
		struct
		{
			unsigned char Register;
			unsigned char HighLowPart; // Low part 0, High part 1
		} IRegister;

		struct
		{
			unsigned char FirstRegister;
			unsigned char SecondRegister;

			struct
			{
				unsigned char Segment : 4;
				unsigned char Multiplier : 2;
				unsigned char OffsetSize : 2;
			};

			long Offset;
		} Memory;

		struct
		{
			struct
			{
				unsigned char Segment : 4;
				unsigned char ValueSize : 3;
			};

			unsigned long long Value;
		} MemoryLarge;

		struct
		{
			unsigned char ValueSize;
			unsigned long long Value;
		} Value;
	};
} Operand, *POperand;

typedef struct _Operation
{
	InstructionBehaviour Behaviour;
	Operand Operands[4];
} Operation, *POperation;

static void VizualizeOperand(Operand* Operand, char* Buffer, unsigned long* Length)
{
	const char SizeSuffix[] = { 'b', 'w', 'd', 0 };
	const char Multiplier[] = { 0, '2', '4', '8' };
	const char HighLowSuffix[] = { 'l', 'h' };

	unsigned long StringLength;

	StringLength = 0;
	switch (Operand->Type)
	{
	case OperandType_IR:
	{
		StringLength = sprintf(Buffer, "R%u%c", Operand->IRegister.Register - 1, !Operand->OperandSize ? HighLowSuffix[Operand->IRegister.HighLowPart] : SizeSuffix[Operand->OperandSize]) - (SizeSuffix[Operand->OperandSize] ? 0 : 1);
	} break;
	case OperandType_M:
	{
		StringLength = 1;
		if (Operand->Memory.Segment)
			StringLength = sprintf(Buffer, "S%u:", Operand->Memory.Segment - 1) + 1;

		*(Buffer + StringLength - 1) = '[';

		if (Operand->Memory.FirstRegister == (unsigned char)~0)
			StringLength += sprintf(Buffer + StringLength, "Rel %c %X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);
		else
			StringLength += sprintf(Buffer + StringLength, "R%u", Operand->Memory.FirstRegister - 1);

		if (Operand->Memory.SecondRegister)
			StringLength += sprintf(Buffer + StringLength, " + R%u", Operand->Memory.SecondRegister - 1);

		if (Operand->Memory.Multiplier)
			StringLength += sprintf(Buffer + StringLength, " * %c", Multiplier[Operand->Memory.Multiplier]);

		if (Operand->Memory.OffsetSize == 1)
			StringLength += sprintf(Buffer + StringLength, " %c %02X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);
		else if (Operand->Memory.OffsetSize == 2)
			StringLength += sprintf(Buffer + StringLength, " %c %08X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);

		*(Buffer + StringLength) = ']';
		*(Buffer + StringLength + 1) = '\0';

		StringLength += 2;
	} break;
	case OperandType_ML:
	{
		StringLength = 0;
		if (Operand->Memory.Segment)
			StringLength = sprintf(Buffer, "S%u:", Operand->Memory.Segment);

		switch (Operand->MemoryLarge.ValueSize)
		{
		case 1:
		{
			StringLength = sprintf(Buffer + StringLength, "[%02X]", Operand->MemoryLarge.Value);
		} break;
		case 2:
		{
			StringLength = sprintf(Buffer + StringLength, "[%04X]", Operand->MemoryLarge.Value);
		} break;
		case 3:
		{
			StringLength = sprintf(Buffer + StringLength, "[%08X]", Operand->MemoryLarge.Value);
		} break;
		case 4:
		{
			StringLength = sprintf(Buffer + StringLength, "[%016llX]", Operand->MemoryLarge.Value);
		} break;
		}
	} break;
	case OperandType_V:
	{
		StringLength = sprintf(Buffer, "%llu", Operand->Value.Value);
	} break;
	}

	if (Length)
		*Length = StringLength;
}

static void Visualize(Operation* Operations, unsigned long OperationCount)
{
	const char* BehaviourToString[] = { "Add", "Or", "Adc", "Sbb", "And", "Sub", "Xor", "Cmp", "Push", "Pop", "Movsxd" };

	char Buffer[0x100];
	char* RunBuffer;

	for (; OperationCount; OperationCount--, Operations++)
	{
		if (Operations->Behaviour == InstructionBehaviour_Invalid)
		{
			printf("Invalid\n");
			continue;
		}

		RunBuffer = Buffer;

		RunBuffer += sprintf(RunBuffer, "%s ", BehaviourToString[Operations->Behaviour - 1]);
		for (unsigned long i = 0; Operations->Operands[i].Type && i < (sizeof(Operations->Operands) / sizeof(Operations->Operands[0])); i++)
		{
			unsigned long Length;

			VizualizeOperand(&Operations->Operands[i], RunBuffer, &Length);
			RunBuffer += Length;

			if (i < ((sizeof(Operations->Operands) / sizeof(Operations->Operands[0])) - 1) && Operations->Operands[i + 1].Type)
			{
				memcpy(RunBuffer, ", ", sizeof(", "));
				RunBuffer += sizeof(", ") - 1;
			}
		}

		printf("%s\n", Buffer);
	}
}