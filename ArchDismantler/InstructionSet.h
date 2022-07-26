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
	InstructionBehaviour_Movsxd,
	InstructionBehaviour_Imul,
	InstructionBehaviour_Ins,
	InstructionBehaviour_Outs,
	InstructionBehaviour_Jo,
	InstructionBehaviour_Jno,
	InstructionBehaviour_Jb,
	InstructionBehaviour_Jae,
	InstructionBehaviour_Je,
	InstructionBehaviour_Jne,
	InstructionBehaviour_Jbe,
	InstructionBehaviour_Ja,
	InstructionBehaviour_Js,
	InstructionBehaviour_Jns,
	InstructionBehaviour_Jp,
	InstructionBehaviour_Jnp,
	InstructionBehaviour_Jl,
	InstructionBehaviour_Jge,
	InstructionBehaviour_Jle,
	InstructionBehaviour_Jg,
	InstructionBehaviour_Jmp,
	InstructionBehaviour_Test,
	InstructionBehaviour_Xchg,
	InstructionBehaviour_Mov,
	InstructionBehaviour_Lea,
	InstructionBehaviour_Nop,
	InstructionBehaviour_Fwait,
	InstructionBehaviour_Pushf,
	InstructionBehaviour_Popf,
	InstructionBehaviour_Sahf,
	InstructionBehaviour_Lahf,
	InstructionBehaviour_Movs,
	InstructionBehaviour_Cmps,
	InstructionBehaviour_Stos,
	InstructionBehaviour_Lods,
	InstructionBehaviour_Scas,
	InstructionBehaviour_Rol,
	InstructionBehaviour_Ror,
	InstructionBehaviour_Rcl,
	InstructionBehaviour_Rcr,
	InstructionBehaviour_Shl,
	InstructionBehaviour_Shr,
	InstructionBehaviour_Sar,
	InstructionBehaviour_Ret,
	InstructionBehaviour_Enter,
	InstructionBehaviour_Leave,
	InstructionBehaviour_Int
} InstructionBehaviour, *PInstructionBehaviour;

typedef enum _OperandType
{
	OperandType_None,
	OperandType_SR,	// Segment register
	OperandType_IR,	// Integer register
	OperandType_M,	// Memory
	OperandType_ML,	// Memory large
	OperandType_V,	// Value
	OperandType_Rel // Relative value
} OperandType, *POperandType;

typedef enum _OperandSize
{
	OperandSize_8,
	OperandSize_16,
	OperandSize_32,
	OperandSize_64
} OperandSize, *POperandSize;

typedef enum _MemoryOffsetSize
{
	MemoryOffsetSize_0,
	MemoryOffsetSize_8,
	MemoryOffsetSize_32
};

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
		} Register;

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
			unsigned long long Value;
		} MemoryLarge;

		struct
		{
			unsigned long long Value;
		} Value;

		struct
		{
			long Value;
		} RelValue;
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
		StringLength = sprintf(Buffer, "R%u%c", Operand->Register.Register - 1, !Operand->OperandSize ? HighLowSuffix[Operand->Register.HighLowPart] : SizeSuffix[Operand->OperandSize]) - (SizeSuffix[Operand->OperandSize] ? 0 : 1);
	} break;
	case OperandType_SR:
	{
		StringLength = sprintf(Buffer, "S%u", Operand->Register.Register - 1);
	} break;
	case OperandType_M:
	{
		StringLength = 0;

		switch (Operand->OperandSize)
		{
		case OperandSize_8:
		{
			StringLength = sprintf(Buffer, "byte ptr ");
		} break;
		case OperandSize_16:
		{
			StringLength = sprintf(Buffer, "word ptr ");
		} break;
		case OperandSize_32:
		{
			StringLength = sprintf(Buffer, "dword ptr ");
		} break;
		case OperandSize_64:
		{
			StringLength = sprintf(Buffer, "qword ptr ");
		} break;
		} 

		if (Operand->Memory.Segment)
			StringLength += sprintf(Buffer + StringLength, "S%u:", Operand->Memory.Segment - 1);

		*(Buffer + StringLength) = '[';
		StringLength++;

		if (Operand->Memory.FirstRegister)
		{
			if (Operand->Memory.FirstRegister == (unsigned char)~0)
				StringLength += sprintf(Buffer + StringLength, "Rel %c %X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);
			else
				StringLength += sprintf(Buffer + StringLength, "R%u", Operand->Memory.FirstRegister - 1);
		}

		if (Operand->Memory.SecondRegister)
			StringLength += sprintf(Buffer + StringLength, " + R%u", Operand->Memory.SecondRegister - 1);

		if (Operand->Memory.Multiplier)
			StringLength += sprintf(Buffer + StringLength, " * %c", Multiplier[Operand->Memory.Multiplier]);

		if (Operand->Memory.OffsetSize == MemoryOffsetSize_8)
		{
			if (!Operand->Memory.FirstRegister && !Operand->Memory.SecondRegister)
				StringLength += sprintf(Buffer + StringLength, "%02X", Operand->Memory.Offset);

			StringLength += sprintf(Buffer + StringLength, " %c %02X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);
		}
		else if (Operand->Memory.OffsetSize == MemoryOffsetSize_32)
		{
			if (!Operand->Memory.FirstRegister && !Operand->Memory.SecondRegister)
				StringLength += sprintf(Buffer + StringLength, "%08X", Operand->Memory.Offset);

			StringLength += sprintf(Buffer + StringLength, " %c %08X", Operand->Memory.Offset < 0 ? '-' : '+', Operand->Memory.Offset < 0 ? -Operand->Memory.Offset : Operand->Memory.Offset);
		}

		*(Buffer + StringLength) = ']';
		*(Buffer + StringLength + 1) = '\0';

		StringLength++;
	} break;
	case OperandType_ML:
	{
		StringLength = 0;

		switch (Operand->OperandSize)
		{
		case OperandSize_8:
		{
			StringLength = sprintf(Buffer, "byte ptr ");
		} break;
		case OperandSize_16:
		{
			StringLength = sprintf(Buffer, "word ptr ");
		} break;
		case OperandSize_32:
		{
			StringLength = sprintf(Buffer, "dword ptr ");
		} break;
		case OperandSize_64:
		{
			StringLength = sprintf(Buffer, "qword ptr ");
		} break;
		}

		StringLength += sprintf(Buffer + StringLength, "[%016llX]", Operand->MemoryLarge.Value);
	} break;
	case OperandType_Rel:
	{
		StringLength = 0;
		switch (Operand->OperandSize)
		{
		case OperandSize_8:
		{
			StringLength = sprintf(Buffer + StringLength, "Rel %c %02X", Operand->RelValue.Value < 0 ? '-' : '+', Operand->RelValue.Value < 0 ? -Operand->RelValue.Value : Operand->RelValue.Value);
		} break;
		case OperandSize_16:
		{
			StringLength = sprintf(Buffer + StringLength, "Rel %c %04X", Operand->RelValue.Value < 0 ? '-' : '+', Operand->RelValue.Value < 0 ? -Operand->RelValue.Value : Operand->RelValue.Value);
		} break;
		case OperandSize_32:
		{
			StringLength = sprintf(Buffer + StringLength, "Rel %c %08X", Operand->RelValue.Value < 0 ? '-' : '+', Operand->RelValue.Value < 0 ? -Operand->RelValue.Value : Operand->RelValue.Value);
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
	const char* BehaviourToString[] = { "add", "or", "adc", "sbb", "and", "sub", "xor", "cmp", "push", "pop", "movsxd", "imul", "ins", "outs", "jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg", "jmp", "test", "xchg", "mov", "lea", "nop", "wait", "pushf", "popf", "sahf", "lahf", "movs", "cmps", "stos", "lods", "scas", "rol", "ror", "rcl", "rcr", "shl", "shr", "sar", "ret", "enter", "leave", "int" };

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