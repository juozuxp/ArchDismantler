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
	InstructionBehaviour_Ffree,
	InstructionBehaviour_Frstor,
	InstructionBehaviour_Fucom,
	InstructionBehaviour_Fucomp,
	InstructionBehaviour_Fnsave,
	InstructionBehaviour_Fsave,
	InstructionBehaviour_Fnstsw,
	InstructionBehaviour_Fstsw,
	InstructionBehaviour_Faddp,
	InstructionBehaviour_Fmulp,
	InstructionBehaviour_Ficompp,
	InstructionBehaviour_Fsubrp,
	InstructionBehaviour_Fsubp,
	InstructionBehaviour_Fdivrp,
	InstructionBehaviour_Fdivp,
	InstructionBehaviour_Ffreep,
	InstructionBehaviour_Fbld,
	InstructionBehaviour_Fucomip,
	InstructionBehaviour_Fbstp,
	InstructionBehaviour_Fcomip,
	InstructionBehaviour_Loopnz,
	InstructionBehaviour_Loopz,
	InstructionBehaviour_Loop,
	InstructionBehaviour_In,
	InstructionBehaviour_Out,
	InstructionBehaviour_Call,
	InstructionBehaviour_Icebp,
	InstructionBehaviour_Hlt,
	InstructionBehaviour_Cmc,
	InstructionBehaviour_Not,
	InstructionBehaviour_Neg,
	InstructionBehaviour_Mul,
	InstructionBehaviour_Div,
	InstructionBehaviour_Idiv,
	InstructionBehaviour_Clc,
	InstructionBehaviour_Stc,
	InstructionBehaviour_Cli,
	InstructionBehaviour_Sti,
	InstructionBehaviour_Cld,
	InstructionBehaviour_Std,
	InstructionBehaviour_Inc,
	InstructionBehaviour_Dec,
	InstructionBehaviour_Sldt,
	InstructionBehaviour_Str,
	InstructionBehaviour_Lldt,
	InstructionBehaviour_Ltr,
	InstructionBehaviour_Verr,
	InstructionBehaviour_Verw,
	InstructionBehaviour_Sgdt,
	InstructionBehaviour_Enclv,
	InstructionBehaviour_Vmcall,
	InstructionBehaviour_Vmlaunch,
	InstructionBehaviour_Vmresume,
	InstructionBehaviour_Vmxoff,
	InstructionBehaviour_Pconfig,
	InstructionBehaviour_Sidt,
	InstructionBehaviour_Monitor,
	InstructionBehaviour_Mwait,
	InstructionBehaviour_Clac,
	InstructionBehaviour_Stac,
	InstructionBehaviour_Lgdt,
	InstructionBehaviour_Xgetbv,
	InstructionBehaviour_Xsetbv,
	InstructionBehaviour_Vmfunc,
	InstructionBehaviour_Xend,
	InstructionBehaviour_Xtest,
	InstructionBehaviour_Enclu,
	InstructionBehaviour_Lidt,
	InstructionBehaviour_Vmrun,
	InstructionBehaviour_Vmmcall,
	InstructionBehaviour_Vmload,
	InstructionBehaviour_Vmsave,
	InstructionBehaviour_Stgi,
	InstructionBehaviour_Clgi,
	InstructionBehaviour_Skinit,
	InstructionBehaviour_Invlpga,
	InstructionBehaviour_Smsw,
	InstructionBehaviour_Serialize,
	InstructionBehaviour_Rdpkru,
	InstructionBehaviour_Wrpkru,
	InstructionBehaviour_Lmsw,
	InstructionBehaviour_Invlpg,
	InstructionBehaviour_Swapgs,
	InstructionBehaviour_Rdiscp,
	InstructionBehaviour_Monitorx,
	InstructionBehaviour_Mwaitx,
	InstructionBehaviour_Clzero,
	InstructionBehaviour_Rdpru,
	InstructionBehaviour_Lar,
	InstructionBehaviour_Lsl,
	InstructionBehaviour_Syscall,
	InstructionBehaviour_Clts,
	InstructionBehaviour_Sysret,
	InstructionBehaviour_Invd,
	InstructionBehaviour_Wbinvd,
	InstructionBehaviour_Movups,
	InstructionBehaviour_Movss,
	InstructionBehaviour_Movupd,
	InstructionBehaviour_Movsd,
	InstructionBehaviour_Movhlps,
	InstructionBehaviour_Movlps,
	InstructionBehaviour_Movlpd,
	InstructionBehaviour_Movddup,
	InstructionBehaviour_Movsldup,
	InstructionBehaviour_Unpcklps,
	InstructionBehaviour_Unpcklpd,
	InstructionBehaviour_Unpckhps,
	InstructionBehaviour_Unpckhpd,
	InstructionBehaviour_Movlhps,
	InstructionBehaviour_Movhps,
	InstructionBehaviour_Movhpd,
	InstructionBehaviour_Movshdup,
	InstructionBehaviour_Prefetchnta,
	InstructionBehaviour_Prefetcht0,
	InstructionBehaviour_Prefetcht1,
	InstructionBehaviour_Prefetcht2,
	InstructionBehaviour_Movaps,
	InstructionBehaviour_Movapd,
	InstructionBehaviour_Cvtpi2ps,
	InstructionBehaviour_Cvtsi2ss,
	InstructionBehaviour_Cvtpi2pd,
	InstructionBehaviour_Cvtsi2sd,
	InstructionBehaviour_Movntps,
	InstructionBehaviour_Movntpd,
	InstructionBehaviour_Cvttps2pi,
	InstructionBehaviour_Cvttss2si,
	InstructionBehaviour_Cvttpd2pi,
	InstructionBehaviour_Cvttsd2si,
	InstructionBehaviour_Cvtps2pi,
	InstructionBehaviour_Cvtss2si,
	InstructionBehaviour_Cvtpd2pi,
	InstructionBehaviour_Cvtsd2si,
	InstructionBehaviour_Ucomiss,
	InstructionBehaviour_Ucomisd,
	InstructionBehaviour_Comiss,
	InstructionBehaviour_Comisd,
	InstructionBehaviour_Wrmsr,
	InstructionBehaviour_Rdtsc,
	InstructionBehaviour_Rdmsr,
	InstructionBehaviour_Rdpmc,
	InstructionBehaviour_Sysenter,
	InstructionBehaviour_Sysexit,
	InstructionBehaviour_Getsec,
	InstructionBehaviour_Invept,
	InstructionBehaviour_Invvpid,
	InstructionBehaviour_Movbe,
	InstructionBehaviour_Crc32,
	InstructionBehaviour_Roundps,
	InstructionBehaviour_Roundpd,
	InstructionBehaviour_Roundss,
	InstructionBehaviour_Roundsd,
	InstructionBehaviour_Blendps,
	InstructionBehaviour_Blendpd,
	InstructionBehaviour_Pblendw,
	InstructionBehaviour_Palignr,
	InstructionBehaviour_Pextrb,
	InstructionBehaviour_Pextrw,
	InstructionBehaviour_Pextr,
	InstructionBehaviour_Extractps,
	InstructionBehaviour_Pinsrb,
	InstructionBehaviour_Insertps,
	InstructionBehaviour_Pinsr,
	InstructionBehaviour_Dpps,
	InstructionBehaviour_Dppd,
	InstructionBehaviour_Mpsadbw,
	InstructionBehaviour_Pcmpestrm,
	InstructionBehaviour_Pcmpestri,
	InstructionBehaviour_Pcmpistrm,
	InstructionBehaviour_Pcmpistri,
	InstructionBehaviour_Cmovo,
	InstructionBehaviour_Cmovno,
	InstructionBehaviour_Cmovb,
	InstructionBehaviour_Cmovae,
	InstructionBehaviour_Cmove,
	InstructionBehaviour_Cmovne,
	InstructionBehaviour_Cmovbe,
	InstructionBehaviour_Cmova,
	InstructionBehaviour_Cmovs,
	InstructionBehaviour_Cmovns,
	InstructionBehaviour_Cmovp,
	InstructionBehaviour_Cmovnp,
	InstructionBehaviour_Cmovl,
	InstructionBehaviour_Cmovge,
	InstructionBehaviour_Cmovle,
	InstructionBehaviour_Cmovg,
	InstructionBehaviour_Movmskps,
	InstructionBehaviour_Movmskpd,
	InstructionBehaviour_Sqrtps,
	InstructionBehaviour_Sqrtss,
	InstructionBehaviour_Sqrtpd,
	InstructionBehaviour_Sqrtsd,
	InstructionBehaviour_Rsqrtps,
	InstructionBehaviour_Rsqrtss,
	InstructionBehaviour_Rcpps,
	InstructionBehaviour_Rcpss,
	InstructionBehaviour_Andps,
	InstructionBehaviour_Andpd,
	InstructionBehaviour_Andnps,
	InstructionBehaviour_Andnpd,
	InstructionBehaviour_Orps,
	InstructionBehaviour_Orpd,
	InstructionBehaviour_Xorps,
	InstructionBehaviour_Xorpd,
	InstructionBehaviour_Addps,
	InstructionBehaviour_Addss,
	InstructionBehaviour_Addpd,
	InstructionBehaviour_Addsd,
	InstructionBehaviour_Mulps,
	InstructionBehaviour_Mulss,
	InstructionBehaviour_Mulpd,
	InstructionBehaviour_Mulsd,
	InstructionBehaviour_Cvtps2pd,
	InstructionBehaviour_Cvtpd2ps,
	InstructionBehaviour_Cvtss2sd,
	InstructionBehaviour_Cvtsd2ss,
	InstructionBehaviour_Cvtdq2ps,
	InstructionBehaviour_Cvtps2dq,
	InstructionBehaviour_Cvttps2dq,
	InstructionBehaviour_Subps,
	InstructionBehaviour_Subss,
	InstructionBehaviour_Subpd,
	InstructionBehaviour_Subsd,
	InstructionBehaviour_Minps,
	InstructionBehaviour_Minss,
	InstructionBehaviour_Minpd,
	InstructionBehaviour_Minsd,
	InstructionBehaviour_Divps,
	InstructionBehaviour_Divss,
	InstructionBehaviour_Divpd,
	InstructionBehaviour_Divsd,
	InstructionBehaviour_Maxps,
	InstructionBehaviour_Maxss,
	InstructionBehaviour_Maxpd,
	InstructionBehaviour_Maxsd,
	InstructionBehaviour_Punpcklbw,
	InstructionBehaviour_Punpcklwd,
	InstructionBehaviour_Punpckldq,
	InstructionBehaviour_Packsswb,
	InstructionBehaviour_Pcmpgtb,
	InstructionBehaviour_Pcmpgtw,
	InstructionBehaviour_Pcmpgtd,
	InstructionBehaviour_Packuswb,
	InstructionBehaviour_Punpckhbw,
	InstructionBehaviour_Punpckhwd,
	InstructionBehaviour_Punpckhdq,
	InstructionBehaviour_Packssdw,
	InstructionBehaviour_Punpcklqdq,
	InstructionBehaviour_Punpckhqdq,
	InstructionBehaviour_Movq,
	InstructionBehaviour_Movdqa,
	InstructionBehaviour_Movdqu,
	InstructionBehaviour_Pshufw,
	InstructionBehaviour_Pshuflw,
	InstructionBehaviour_Pshufhw,
	InstructionBehaviour_Pshufd,
	InstructionBehaviour_Psrlw,
	InstructionBehaviour_Psraw,
	InstructionBehaviour_Psliw,
	InstructionBehaviour_Psrld,
	InstructionBehaviour_Psrad,
	InstructionBehaviour_Pslld,
	InstructionBehaviour_Psrlq,
	InstructionBehaviour_Psrldq,
	InstructionBehaviour_Psllq,
	InstructionBehaviour_Pslldq,
} InstructionBehaviour, * PInstructionBehaviour;

typedef enum _OperandType
{
	OperandType_None,

	OperandType_SR,	// Segment register
	OperandType_IR,	// Integer register
	OperandType_FR, // Floating register
	OperandType_CR, // Control register
	OperandType_VR, // Vector register
	OperandType_DR, // Debug register
	OperandType_QR, // Quad register

	OperandType_M,	// Memory
	OperandType_ML,	// Memory large
	OperandType_V,	// Value
	OperandType_Rel // Relative value
} OperandType, * POperandType;

typedef enum _OperationType
{
	OperationType_Normal,
	OperationType_Locked,
	OperationType_RepeatZ,
	OperationType_RepeatNotZ,
	OperationType_OperandLess
} OperationType, * POperationType;

typedef enum _OperationSize
{
	OperationSize_None,
	OperationSize_8,
	OperationSize_16,
	OperationSize_32,
	OperationSize_64,
	OperationSize_80,
	OperationSize_128,
} OperationSize, * POperationSize;

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
} Operand, * POperand;

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
} Operation, * POperation;

static void VizualizeOperand(Operand* Operand, char* Buffer, unsigned long* Length)
{
	const char SizeSuffix[] = { 'b', 'w', 'd', 0, 't', 'o' };
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
		StringLength = sprintf(Buffer, "FR%u", Operand->Register.Register - 1);
	} break;
	case OperandType_CR:
	{
		StringLength = sprintf(Buffer, "CR%u", Operand->Register.Register - 1);
	} break;
	case OperandType_VR:
	{
		StringLength = sprintf(Buffer, "VR%u", Operand->Register.Register - 1);
	} break;
	case OperandType_DR:
	{
		StringLength = sprintf(Buffer, "DR%u", Operand->Register.Register - 1);
	} break;
	case OperandType_QR:
	{
		StringLength = sprintf(Buffer, "QR%u", Operand->Register.Register - 1);
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
				StringLength += sprintf(Buffer + StringLength, "Rel");
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
		StringLength = sprintf(Buffer, "%llX", Operand->Value.Value);
	} break;
	}

	if (Length)
		*Length = StringLength;
}

static void Visualize(Operation* Operations, unsigned long OperationCount)
{
	const char* const BehaviourToString[] = { "add", "or", "adc", "sbb", "and", "sub", "xor", "cmp", "push", "pop", "movsxd", "imul", "ins", "outs", "jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg", "jmp", "test", "xchg", "mov", "lea", "nop", "wait", "pushf", "popf", "sahf", "lahf", "movs", "cmps", "stos", "lods", "scas", "rol", "ror", "rcl", "rcr", "shl", "shr", "sar", "ret", "enter", "leave", "int", "iret", "xlat", "fadd", "fmul", "fcom", "fcomp", "fsub", "fsubr", "fdiv", "fdivr", "fld", "fxch", "fst", "fstp", "fnop", "fldenv", "fchs", "fabs", "ftst", "fxam", "fldcw", "fld1", "fldl2t", "fldl2e", "fldpi", "fldlg2", "fldln2", "fldz", "cbw", "cwd", "cdq", "cqo", "fnstenv", "fstenv", "f2xm1", "fyl2x", "fptan", "fpatan", "fxtract", "fprem1", "fdecstp", "fincstp", "fnstcw", "fstcw", "fprem", "fyl2xp1", "fsqrt", "fsincos", "frandint", "fscale", "fsin", "fcos", "fiadd", "fcmovb", "fimul", "fcmove", "ficom", "fcmovbe", "ficomp", "fcmovu", "fisub", "fisubr", "fucompp", "fidiv", "fidivr", "fild", "fcmovnb", "fisttp", "fcmovne", "fist", "fcmovnbe", "fistp", "fcmovnu", "fnclex", "fclex", "fninit", "finit", "fucomi", "fcomi", "ffree", "frstor", "fucom", "fucomp", "fnsave", "fsave", "fnstsw", "fstsw", "faddp", "fmulp", "fcompp", "subrp", "subp", "divrp", "divp", "ffreep", "fbld", "fucomip", "fbstp", "fcomip", "loopnz", "loopz", "loop", "in", "out", "call", "icebp", "hlt", "cmc", "not", "neg", "mul", "div", "idiv", "clc", "stc", "cli", "sti", "cld", "std", "inc", "dec", "sldt", "str", "lldt", "ltr", "verr", "verw", "sgdt", "enclv", "vmcall", "vmlaunch", "vmresume", "vmoff", "pconfig", "sidt", "monitor", "mwait", "clac", "stac", "lgdt", "xgetbv", "xsetbv", "vmfunc", "xend", "xtest", "enclu", "lidt", "vmrun", "vmmcall", "vmload", "vmsave", "stgi", "clgi", "skinit", "invlpga", "smsw", "serialize", "rdpkru", "wrpkru", "lmsw", "invlpg", "swapgs", "rdiscp", "monitorx", "mwaitx", "clzero", "rdpru", "lar", "lsl", "syscall", "clts", "sysret", "invd", "wbinvd", "movups", "movss", "movupd", "movsd", "movhlps", "movlps", "movlpd", "movddup", "movsldup", "unpcklps", "unpcklpd", "unpckhps", "unpckhpd", "movlhps", "movhps", "movhpd", "movshdup", "prefetchnta", "prefetcht0", "prefetcht1" , "prefetcht2", "movaps", "movapd", "cvtpi2ps", "cvtsi2ss", "cvtpi2pd", "cvtsi2sd", "movntps", "movntpd", "cvttps2pi", "cvttss2si", "cvttpd2pi", "cvttsd2si", "cvtps2pi", "cvtss2si", "cvtpd2pi", "cvtsd2si", "ucomiss", "ucomisd", "comiss", "comisd", "wrmsr", "rdtsc", "rdmsr", "rdpmc", "sysenter" , "sysexit" , "getsec", "invept", "invvpid", "movbe", "crc32", "roundps", "roundpd", "roundss", "roundsd", "blendps", "blendpd", "pblendw", "palignr", "pextrb", "pextrw", "pextr", "extractps", "pinsrb", "insertps", "pinsr", "dpps", "dppd", "mpsadbw", "pcmpestrm", "pcmpestri", "pcmpistrm", "pcmpistri", "cmovo", "cmovno", "cmovb", "cmovae", "cmove", "cmovne", "cmovbe", "cmova", "cmovs", "cmovns", "cmovp", "cmovnp", "cmovl", "cmovge", "cmovle", "cmovg", "movmskps", "movmskpd", "sqrtps", "sqrtss", "sqrtpd", "sqrtsd", "rsqrtps", "rsqrtss", "rcpps", "rcpss", "andps", "andpd", "andnps", "andnpd", "orps", "orpd", "xorps", "xorpd", "addps", "addss", "addpd", "addsd", "mulps", "mulss", "mulpd", "mulsd", "cvtps2pd", "cvtpd2ps", "cvtss2sd", "cvtsd2ss", "cvtdq2ps", "cvtps2dq", "cvttps2dq", "subps", "subss", "subpd", "subsd", "minps", "minss", "minpd", "minsd", "divps", "divss", "divps", "divsd", "maxps", "maxss", "maxpd", "maxsd", "punpcklbw", "punpcklwd", "punpckldq", "packsswb", "pcmpgtb", "pcmpgtw", "pcmpgtd", "packuswb", "punpckhbw", "punpckhwd", "punpckhdq", "packssdw", "punpcklqdq", "punpckhqdq", "movq", "movdqa", "movdqu", "pshufw", "pshuflw", "pshufhw", "pshufd", "psrlw", "psraw", "psllw", "psrld", "psrad", "pslld", "psrlq", "psrldq", "psllq", "pslldq"};
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
		switch (Operations->Type)
		{
		case OperationType_RepeatZ:
		{
			RunBuffer += sprintf(RunBuffer, "repz ");
		} break;
		case OperationType_RepeatNotZ:
		{
			RunBuffer += sprintf(RunBuffer, "repnz ");
		} break;
		case OperationType_Locked:
		{
			RunBuffer += sprintf(RunBuffer, "lock ");
		} break;
		}

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