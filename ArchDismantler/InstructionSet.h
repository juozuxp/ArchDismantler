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
	InstructionBehaviour_Cmp
} InstructionBehaviour, *PInstructionBehaviour;

typedef enum _OperandType
{
	OperandType_None,
	OperandType_IR,	// Integer register
	OperandType_M,	// Memory
	OperandType_ML,	// Memory large
	OperandType_V,	// Value
} OperandType, *POperandType;

typedef enum _OperationSize
{
	OperationSize_8,
	OperationSize_16,
	OperationSize_32,
	OperationSize_64
} OperationSize, *POperationSize;

typedef struct _Operand // Registers are counted 1 ... 254, 255 rezerved for relativity
{
	OperandType Type;
	union
	{
		struct
		{
			unsigned char Register;
		} IRegister;

		struct
		{
			unsigned char FirstRegister;
			unsigned char SecondRegister;

			struct
			{
				unsigned char Multiplier : 2;
				unsigned char OffsetSize : 2;
			};

			long Offset;
		} Memory;

		struct
		{
			unsigned char ValueSize;
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
	OperationSize OperationSize;
	Operand Operands[4];
} Operation, *POperation;

void VizualizeOperand(Operation* Operation, Operand* Operand, char* Buffer, unsigned long* Length)
{
	const char SizeSuffix[] = { 'b', 'w', 'd', 0 };
	const char Multiplier[] = { 0, '2', '4', '8' };

	unsigned long StringLength;

	StringLength = 0;
	switch (Operand->Type)
	{
	case OperandType_IR:
	{
		StringLength = sprintf(Buffer, "R%u%c", Operand->IRegister.Register - 1, SizeSuffix[Operation->OperationSize]) - (SizeSuffix[Operation->OperationSize] ? 0 : 1);
	} break;
	case OperandType_M:
	{
		StringLength = 1;

		*Buffer = '[';

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

		StringLength++;
	} break;
	case OperandType_ML:
	{
		switch (Operand->MemoryLarge.ValueSize)
		{
		case 1:
		{
			StringLength = sprintf(Buffer, "[%02X]", Operand->MemoryLarge.Value);
		} break;
		case 2:
		{
			StringLength = sprintf(Buffer, "[%04X]", Operand->MemoryLarge.Value);
		} break;
		case 3:
		{
			StringLength = sprintf(Buffer, "[%08X]", Operand->MemoryLarge.Value);
		} break;
		case 4:
		{
			StringLength = sprintf(Buffer, "[%016llX]", Operand->MemoryLarge.Value);
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

void Visualize(Operation* Operations, unsigned long OperationCount)
{
	const char* BehaviourToString[] = { "Add", "Or", "Adc", "Sbb", "And", "Sub", "Xor", "Cmp" };

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

			VizualizeOperand(Operations, &Operations->Operands[i], RunBuffer, &Length);
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