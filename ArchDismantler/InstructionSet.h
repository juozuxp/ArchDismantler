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
	InstructionBehaviour_Int,
	InstructionBehaviour_Iret,
	InstructionBehaviour_Xlat,
	InstructionBehaviour_Fadd,
	InstructionBehaviour_Fmul,
	InstructionBehaviour_Fcom,
	InstructionBehaviour_Fcomp,
	InstructionBehaviour_Fsub,
	InstructionBehaviour_Fsubr,
	InstructionBehaviour_Fdiv,
	InstructionBehaviour_Fdivr,
	InstructionBehaviour_Fld,
	InstructionBehaviour_Fxch,
	InstructionBehaviour_Fst,
	InstructionBehaviour_Fstp,
	InstructionBehaviour_Fnop,
	InstructionBehaviour_Fldenv,
	InstructionBehaviour_Fchs,
	InstructionBehaviour_Fabs,
	InstructionBehaviour_Ftst,
	InstructionBehaviour_Fxam,
	InstructionBehaviour_Fldcw,
	InstructionBehaviour_Fld1,
	InstructionBehaviour_Fldl2t,
	InstructionBehaviour_Fldl2e,
	InstructionBehaviour_Fldpi,
	InstructionBehaviour_Fldlg2,
	InstructionBehaviour_Fldln2,
	InstructionBehaviour_Fldz,
	InstructionBehaviour_Cbw,
	InstructionBehaviour_Cwd,
	InstructionBehaviour_Cdq,
	InstructionBehaviour_Cqo,
	InstructionBehaviour_Fnstenv,
	InstructionBehaviour_Fstenv,
	InstructionBehaviour_F2xm1,
	InstructionBehaviour_Fyl2x,
	InstructionBehaviour_Fptan,
	InstructionBehaviour_Fpatan,
	InstructionBehaviour_Fxtract,
	InstructionBehaviour_Fprem1,
	InstructionBehaviour_Fdecstp,
	InstructionBehaviour_Fincstp,
	InstructionBehaviour_Fnstcw,
	InstructionBehaviour_Fstcw,
	InstructionBehaviour_Fprem,
	InstructionBehaviour_Fyl2xp1,
	InstructionBehaviour_Fsqrt,
	InstructionBehaviour_Fsincos,
	InstructionBehaviour_Frndint,
	InstructionBehaviour_Fscale,
	InstructionBehaviour_Fsin,
	InstructionBehaviour_Fcos,
	InstructionBehaviour_Fiadd,
	InstructionBehaviour_Fcmovb,
	InstructionBehaviour_Fimul,
	InstructionBehaviour_Fcmove,
	InstructionBehaviour_Ficom,
	InstructionBehaviour_Fcmovbe,
	InstructionBehaviour_Ficomp,
	InstructionBehaviour_Fcmovu,
	InstructionBehaviour_Fisub,
	InstructionBehaviour_Fisubr,
	InstructionBehaviour_Fucompp,
	InstructionBehaviour_Fidiv,
	InstructionBehaviour_Fidivr,
	InstructionBehaviour_Fild,
	InstructionBehaviour_Fcmovnb,
	InstructionBehaviour_Fisttp,
	InstructionBehaviour_Fcmovne,
	InstructionBehaviour_Fist,
	InstructionBehaviour_Fcmovnbe,
	InstructionBehaviour_Fistp,
	InstructionBehaviour_Fcmovnu,
	InstructionBehaviour_Fnclex,
	InstructionBehaviour_Fclex,
	InstructionBehaviour_Fninit,
	InstructionBehaviour_Finit,
	InstructionBehaviour_Fucomi,
	InstructionBehaviour_Fcomi,
} InstructionBehaviour, *PInstructionBehaviour;

typedef enum _OperandType
{
	OperandType_None,
	OperandType_SR,	// Segment register
	OperandType_IR,	// Integer register
	OperandType_FR, // Floating register
	OperandType_M,	// Memory
	OperandType_ML,	// Memory large
	OperandType_V,	// Value
	OperandType_Rel // Relative value
} OperandType, *POperandType;

typedef enum _OperationType
{
	OperationType_Normal,
	OperationType_OperandLess
} OperationType, *POperationType;

typedef enum _OperationSize
{
	OperationSize_None,
	OperationSize_8,
	OperationSize_16,
	OperationSize_32,
	OperationSize_64,
	OperationSize_80,
	OperationSize_128,
} OperationSize, *POperationSize;

typedef enum _MemoryOffsetSize
{
	MemoryOffsetSize_0,
	MemoryOffsetSize_8,
	MemoryOffsetSize_32
};

typedef struct _Operand // Registers are counted 1 ... 254, 255 reserved for relativity
{
	OperandType Type;
	OperationSize OperandSize;
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
	OperationType Type;
	InstructionBehaviour Behaviour;
	union
	{
		struct
		{
			Operand Operands[4];
		} N;

		struct
		{
			OperationSize OperationSize;
		} OL;
	};
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
		StringLength = sprintf(Buffer, "R%u%c", Operand->Register.Register - 1, (Operand->OperandSize == OperationSize_8) ? HighLowSuffix[Operand->Register.HighLowPart] : SizeSuffix[Operand->OperandSize - 1]) - (SizeSuffix[Operand->OperandSize - 1] ? 0 : 1);
	} break;
	case OperandType_SR:
	{
		StringLength = sprintf(Buffer, "S%u", Operand->Register.Register - 1);
	} break;
	case OperandType_FR:
	{
		StringLength = sprintf(Buffer, "F%u", Operand->Register.Register - 1);
	} break;
	case OperandType_M:
	{
		StringLength = 0;

		switch (Operand->OperandSize)
		{
		case OperationSize_8:
		{
			StringLength = sprintf(Buffer, "byte ptr ");
		} break;
		case OperationSize_16:
		{
			StringLength = sprintf(Buffer, "word ptr ");
		} break;
		case OperationSize_32:
		{
			StringLength = sprintf(Buffer, "dword ptr ");
		} break;
		case OperationSize_64:
		{
			StringLength = sprintf(Buffer, "qword ptr ");
		} break;
		case OperationSize_80:
		{
			StringLength = sprintf(Buffer, "tword ptr ");
		} break;
		case OperationSize_128:
		{
			StringLength = sprintf(Buffer, "oword ptr ");
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
		case OperationSize_8:
		{
			StringLength = sprintf(Buffer, "byte ptr ");
		} break;
		case OperationSize_16:
		{
			StringLength = sprintf(Buffer, "word ptr ");
		} break;
		case OperationSize_32:
		{
			StringLength = sprintf(Buffer, "dword ptr ");
		} break;
		case OperationSize_64:
		{
			StringLength = sprintf(Buffer, "qword ptr ");
		} break;
		case OperationSize_80:
		{
			StringLength = sprintf(Buffer, "tword ptr ");
		} break;
		case OperationSize_128:
		{
			StringLength = sprintf(Buffer, "oword ptr ");
		} break;
		}

		StringLength += sprintf(Buffer + StringLength, "[%016llX]", Operand->MemoryLarge.Value);
	} break;
	case OperandType_Rel:
	{
		StringLength = 0;
		switch (Operand->OperandSize)
		{
		case OperationSize_8:
		{
			StringLength = sprintf(Buffer + StringLength, "Rel %c %02X", Operand->RelValue.Value < 0 ? '-' : '+', Operand->RelValue.Value < 0 ? -Operand->RelValue.Value : Operand->RelValue.Value);
		} break;
		case OperationSize_16:
		{
			StringLength = sprintf(Buffer + StringLength, "Rel %c %04X", Operand->RelValue.Value < 0 ? '-' : '+', Operand->RelValue.Value < 0 ? -Operand->RelValue.Value : Operand->RelValue.Value);
		} break;
		case OperationSize_32:
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
	const char* const BehaviourToString[] = { "add", "or", "adc", "sbb", "and", "sub", "xor", "cmp", "push", "pop", "movsxd", "imul", "ins", "outs", "jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg", "jmp", "test", "xchg", "mov", "lea", "nop", "wait", "pushf", "popf", "sahf", "lahf", "movs", "cmps", "stos", "lods", "scas", "rol", "ror", "rcl", "rcr", "shl", "shr", "sar", "ret", "enter", "leave", "int", "iret", "xlat", "fadd", "fmul", "fcom", "fcomp", "fsub", "fsubr", "fdiv", "fdivr", "fld", "fxch", "fst", "fstp", "fnop", "fldenv", "fchs", "fabs", "ftst", "fxam", "fldcw", "fld1", "fldl2t", "fldl2e", "fldpi", "fldlg2", "fldln2", "fldz", "cbw", "cwd", "cdq", "cqo", "fnstenv", "fstenv", "f2xm1", "fyl2x", "fptan", "fpatan", "fxtract", "fprem1", "fdecstp", "fincstp", "fnstcw", "fstcw", "fprem", "fyl2xp1", "fsqrt", "fsincos", "frandint", "fscale", "fsin", "fcos", "fiadd", "fcmovb", "fimul", "fcmove", "ficom", "fcmovbe", "ficomp", "fcmovu", "fisub", "fisubr", "fucompp", "fidiv", "fidivr", "fild", "fcmovnb", "fisttp", "fcmovne", "fist", "fcmovnbe", "fistp", "fcmovnu", "fnclex", "fclex", "fninit", "finit", "fucomi", "fcomi" };
	const char OperationSizeToChar[] = { 'b', 'w', 'd', 'q' };

	char Buffer[0x100];
	char* RunBuffer;

	for (; OperationCount; OperationCount--, Operations++)
	{
		if (Operations->Behaviour == InstructionBehaviour_Invalid)
		{
			printf("Invalid\n");
			continue;
		}

		if (Operations->Type == OperationType_OperandLess)
		{
			printf("%s%c\n", BehaviourToString[Operations->Behaviour - 1], OperationSizeToChar[Operations->OL.OperationSize]);
			continue;
		}

		RunBuffer = Buffer;

		RunBuffer += sprintf(RunBuffer, "%s ", BehaviourToString[Operations->Behaviour - 1]);
		for (unsigned long i = 0; Operations->N.Operands[i].Type && i < (sizeof(Operations->N.Operands) / sizeof(Operations->N.Operands[0])); i++)
		{
			unsigned long Length;

			VizualizeOperand(&Operations->N.Operands[i], RunBuffer, &Length);
			RunBuffer += Length;

			if (i < ((sizeof(Operations->N.Operands) / sizeof(Operations->N.Operands[0])) - 1) && Operations->N.Operands[i + 1].Type)
			{
				memcpy(RunBuffer, ", ", sizeof(", "));
				RunBuffer += sizeof(", ") - 1;
			}
		}

		printf("%s\n", Buffer);
	}
}