#pragma once
#include "InstructionSet.h"

#define BREAK_RGB(Color) (((Color) >> 16) & 0xFF), (((Color) >> 8) & 0xFF), ((Color) & 0xFF)
#define SET_DEFAULT_COLORS(ColorArray, Size) memset(ColorArray, 0xFF, Size);

typedef enum _ComponentColors
{
	ComponentColors_LowRegisters,
	ComponentColors_HighRegisters,
	ComponentColors_WordRegisters,
	ComponentColors_DwordRegisters,
	ComponentColors_QwordRegisters,
	ComponentColors_QuadRegisters,
	ComponentColors_VectorRegisters,
	ComponentColors_ControlRegisters,
	ComponentColors_DebugRegisters,
	ComponentColors_SegmentRegisters,
	ComponentColors_FloatingRegisters,
	ComponentColors_Behaviour,
	ComponentColors_PreBehaviour,
	ComponentColors_MemorySize,
	ComponentColors_Offset,
	ComponentColors_Address,
	ComponentColors_Multiplier,
	ComponentColors_ImmediateMemory,
	ComponentColors_Seperator,
	ComponentColors_Addition,
	ComponentColors_Subtraction,
	ComponentColors_Multiplication,
	ComponentColors_MemoryEnclosure,
	ComponentColors_ARRAYMAX
} ComponentColors, *PComponentColors;

typedef enum _ComponentFlags
{
	ComponentFlags_SpecifyMemorySize,
	ComponentFlags_PadOffset,
	ComponentFlags_HexOffset,
	ComponentFlags_PadAddress,
	ComponentFlags_HexAddress,
	ComponentFlags_PadImmediateMemory,
	ComponentFlags_HexImmediateMemory,
	ComponentFlags_DisplayAddressRelative,
	ComponentFlags_ARRAYMAX
} ComponentFlags, *PComponentFlags;

typedef struct _VisualComponents
{
	void* DisasemblyBase;
	const unsigned char* InstructionSizes;

	const char* const* LowRegisters;
	const char* const* HighRegisters;

	const char* const* WordRegisters;
	const char* const* DwordRegisters;
	const char* const* QwordRegisters;

	const char* const* QuadRegisters;
	const char* const* DebugRegisters;
	const char* const* VectorRegisters;
	const char* const* ControlRegisters;
	const char* const* SegmentRegisters;
	const char* const* FloatingRegisters;

	unsigned char Flags[ComponentFlags_ARRAYMAX];
	unsigned long Colors[ComponentColors_ARRAYMAX];
} VisualComponents, * PVisualComponents;

static const char* MapBehaviourToString(InstructionBehaviour Behaviour)
{
	static const char* const BehaviourString[] = { "invalid", "add", "or", "adc", "sbb", "and", "sub", "xor", "cmp", "push", "pop", "movsxd", "imul", "ins", "outs", "jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg", "jmp", "test", "xchg", "mov", "lea", "nop", "wait", "pushf", "popf", "sahf", "lahf", "movs", "cmps", "stos", "lods", "scas", "rol", "ror", "rcl", "rcr", "shl", "shr", "sar", "ret", "enter", "leave", "int", "iret", "xlat", "fadd", "fmul", "fcom", "fcomp", "fsub", "fsubr", "fdiv", "fdivr", "fld", "fxch", "fst", "fstp", "fnop", "fldenv", "fchs", "fabs", "ftst", "fxam", "fldcw", "fld1", "fldl2t", "fldl2e", "fldpi", "fldlg2", "fldln2", "fldz", "cbw", "cwd", "cdq", "cqo", "fnstenv", "fstenv", "f2xm1", "fyl2x", "fptan", "fpatan", "fxtract", "fprem1", "fdecstp", "fincstp", "fnstcw", "fstcw", "fprem", "fyl2xp1", "fsqrt", "fsincos", "frandint", "fscale", "fsin", "fcos", "fiadd", "fcmovb", "fimul", "fcmove", "ficom", "fcmovbe", "ficomp", "fcmovu", "fisub", "fisubr", "fucompp", "fidiv", "fidivr", "fild", "fcmovnb", "fisttp", "fcmovne", "fist", "fcmovnbe", "fistp", "fcmovnu", "fnclex", "fclex", "fninit", "finit", "fucomi", "fcomi", "ffree", "frstor", "fucom", "fucomp", "fnsave", "fsave", "fnstsw", "fstsw", "faddp", "fmulp", "fcompp", "subrp", "subp", "divrp", "divp", "ffreep", "fbld", "fucomip", "fbstp", "fcomip", "loopnz", "loopz", "loop", "in", "out", "call", "icebp", "hlt", "cmc", "not", "neg", "mul", "div", "idiv", "clc", "stc", "cli", "sti", "cld", "std", "inc", "dec", "sldt", "str", "lldt", "ltr", "verr", "verw", "sgdt", "enclv", "vmcall", "vmlaunch", "vmresume", "vmoff", "pconfig", "sidt", "monitor", "mwait", "clac", "stac", "lgdt", "xgetbv", "xsetbv", "vmfunc", "xend", "xtest", "enclu", "lidt", "vmrun", "vmmcall", "vmload", "vmsave", "stgi", "clgi", "skinit", "invlpga", "smsw", "serialize", "rdpkru", "wrpkru", "lmsw", "invlpg", "swapgs", "rdiscp", "monitorx", "mwaitx", "clzero", "rdpru", "lar", "lsl", "syscall", "clts", "sysret", "invd", "wbinvd", "movups", "movss", "movupd", "movsd", "movhlps", "movlps", "movlpd", "movddup", "movsldup", "unpcklps", "unpcklpd", "unpckhps", "unpckhpd", "movlhps", "movhps", "movhpd", "movshdup", "prefetchnta", "prefetcht0", "prefetcht1" , "prefetcht2", "movaps", "movapd", "cvtpi2ps", "cvtsi2ss", "cvtpi2pd", "cvtsi2sd", "movntps", "movntpd", "cvttps2pi", "cvttss2si", "cvttpd2pi", "cvttsd2si", "cvtps2pi", "cvtss2si", "cvtpd2pi", "cvtsd2si", "ucomiss", "ucomisd", "comiss", "comisd", "wrmsr", "rdtsc", "rdmsr", "rdpmc", "sysenter" , "sysexit" , "getsec", "invept", "invvpid", "movbe", "crc32", "roundps", "roundpd", "roundss", "roundsd", "blendps", "blendpd", "pblendw", "palignr", "pextrb", "pextrw", "pextr", "extractps", "pinsrb", "insertps", "pinsr", "dpps", "dppd", "mpsadbw", "pcmpestrm", "pcmpestri", "pcmpistrm", "pcmpistri", "cmovo", "cmovno", "cmovb", "cmovae", "cmove", "cmovne", "cmovbe", "cmova", "cmovs", "cmovns", "cmovp", "cmovnp", "cmovl", "cmovge", "cmovle", "cmovg", "movmskps", "movmskpd", "sqrtps", "sqrtss", "sqrtpd", "sqrtsd", "rsqrtps", "rsqrtss", "rcpps", "rcpss", "andps", "andpd", "andnps", "andnpd", "orps", "orpd", "xorps", "xorpd", "addps", "addss", "addpd", "addsd", "mulps", "mulss", "mulpd", "mulsd", "cvtps2pd", "cvtpd2ps", "cvtss2sd", "cvtsd2ss", "cvtdq2ps", "cvtps2dq", "cvttps2dq", "subps", "subss", "subpd", "subsd", "minps", "minss", "minpd", "minsd", "divps", "divss", "divps", "divsd", "maxps", "maxss", "maxpd", "maxsd", "punpcklbw", "punpcklwd", "punpckldq", "packsswb", "pcmpgtb", "pcmpgtw", "pcmpgtd", "packuswb", "punpckhbw", "punpckhwd", "punpckhdq", "packssdw", "punpcklqdq", "punpckhqdq", "movq", "movdqa", "movdqu", "pshufw", "pshuflw", "pshufhw", "pshufd", "psrlw", "psraw", "psllw", "psrld", "psrad", "pslld", "psrlq", "psrldq", "psllq", "pslldq", "pcmpeqb", "pcmpeqw", "pcmpeqd", "emms", "vmread", "vmwrite", "haddpd", "haddps", "hsubpd", "hsubps", "seto", "setno", "setb", "setae", "sete", "setne", "setbe", "seta", "sets", "setns", "setp", "setnp", "setl", "setge", "setle", "setg", "cpuid", "bt", "shld", "rsm", "bts", "shrd", "fxsave", "fxrstor", "ldmxcsr", "stmxcsr", "xsave", "lfence", "xrstor", "xsaveopt", "mfence", "sfence", "clflush", "cmpxchg", "lss", "btr", "lfs", "lgs", "movzx", "popcnt", "btc", "bsf", "bsr", "movsx", "xadd", "cmpps", "cmpss", "cmppd", "cmpsd", "movnti", "pinsrw", "shufps", "shufpd", "vmptrld", "vmclear", "vmxon", "vmptrst", "bswap", "addsubpd", "addsubps", "paddq", "pmullw", "movq2dq", "movdq2q", "pmovmskb", "psubusb", "psubusw", "pminub", "pand", "paddusb", "paddusw", "pmaxub", "pandn", "pavgb", "pavgw", "pmulhuw", "pmulhw", "cvtpd2dq", "cvttpd2dq", "cvtdq2pd", "movntq", "movntdq", "psubsb", "psubsw", "pminsw", "por", "paddsb", "paddsw", "pmaxsw", "pxor", "lddqu", "pmuludq", "pmaddwd", "psadbw", "maskmovq", "maskmovdqu", "psubb", "psubw", "psubd", "psubq", "paddb", "paddw", "paddd" };
	return BehaviourString[Behaviour];
}

static const char* VisualizeFormatNumber(OperationSize Size, unsigned char Padded, unsigned char Hexidecimal)
{
	const char* const PadedNumberFormats[] = { 0, "\x1b[38;2;%u;%u;%um%02X", "\x1b[38;2;%u;%u;%um%04X", "\x1b[38;2;%u;%u;%um%08X", "\x1b[38;2;%u;%u;%um%016llX" };
	const char* const DecNumberFormats[] = { 0, "\x1b[38;2;%u;%u;%um%u", "\x1b[38;2;%u;%u;%um%u", "\x1b[38;2;%u;%u;%um%u", "\x1b[38;2;%u;%u;%um%llu" };
	const char* const HexNumberFormats[] = { 0, "\x1b[38;2;%u;%u;%um%X", "\x1b[38;2;%u;%u;%um%X", "\x1b[38;2;%u;%u;%um%X", "\x1b[38;2;%u;%u;%um%llX" };
	
	return Padded ? (Hexidecimal ? PadedNumberFormats[Size] : DecNumberFormats[Size]) : (Hexidecimal ? HexNumberFormats[Size] : DecNumberFormats[Size]);
}

static void x86_x64BuildRegisterSet(VisualComponents* Components)
{
	static const char* const QRegisters[] = { "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15" };
	static const char* const DRegisters[] = { "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi", "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d" };
	static const char* const WRegisters[] = { "ax", "cx", "dx", "bx", "sp", "bp", "si", "di", "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w" };
	static const char* const HRegisters[] = { "ah", "ch", "dh", "bh", "sph", "bph", "sih", "dih", "r8h", "r9h", "r10h", "r11h", "r12h", "r13h", "r14h", "r15h" };
	static const char* const LRegisters[] = { "al", "cl", "dl", "bl", "spl", "bpl", "sil", "dil", "r8l", "r9l", "r10l", "r11l", "r12l", "r13l", "r14l", "r15l" };

	static const char* const VRegisters[] = { "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15" };
	static const char* const CRegisters[] = { "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7", "cr8", "cr9", "cr10", "cr11", "cr12", "cr13", "cr14", "cr15" };
	static const char* const FRegisters[] = { "st(0)", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)" };
	static const char* const QURegisters[] = { "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7" };
	static const char* const DBRegisters[] = { "dr0", "dr1", "dr2", "dr3", "dr4", "dr5", "dr6", "dr7" };
	static const char* const SRegisters[] = { "cs", "ds", "ss", "es", "fs", "gs" };

	Components->LowRegisters = LRegisters;
	Components->HighRegisters = HRegisters;
	Components->WordRegisters = WRegisters;
	Components->DwordRegisters = DRegisters;
	Components->QwordRegisters = QRegisters;

	Components->QuadRegisters = QURegisters;
	Components->VectorRegisters = VRegisters;
	Components->DebugRegisters = DBRegisters;
	Components->SegmentRegisters = SRegisters;
	Components->ControlRegisters = CRegisters;
	Components->FloatingRegisters = FRegisters;
}

static void VisualizeOperand(Operand* Operand, void* Location, const VisualComponents* Components)
{
	const char* const MemorySizes[] = { "byte ptr", "word ptr", "dword ptr", "qword ptr", "tword ptr", "oword ptr" };

	const char SizeSuffix[] = { 'b', 'w', 'd', 0, 't', 'o' };
	const char Multiplier[] = { 0, '2', '4', '8' };
	const char HighLowSuffix[] = { 'l', 'h' };

	switch (Operand->Type)
	{
	case OperandType_M:
	{
		if (Components->Flags[ComponentFlags_SpecifyMemorySize])
			printf("\x1b[38;2;%u;%u;%um%s ", BREAK_RGB(Components->Colors[ComponentColors_MemorySize]), MemorySizes[Operand->OperandSize - 1]);

		if (Operand->Memory.Segment)
		{
			if (Components->SegmentRegisters)
				printf("\x1b[38;2;%u;%u;%um%s:", BREAK_RGB(Components->Colors[ComponentColors_SegmentRegisters]), Components->SegmentRegisters[Operand->Memory.Segment - 1]);
			else
				printf("\x1b[38;2;%u;%u;%umS%u:", BREAK_RGB(Components->Colors[ComponentColors_SegmentRegisters]), Operand->Memory.Segment - 1);
		}

		printf("\x1b[38;2;%u;%u;%um[", BREAK_RGB(Components->Colors[ComponentColors_MemoryEnclosure]));
		if (Operand->Memory.FirstRegister)
		{
			if (Operand->Memory.FirstRegister == (unsigned char)~0)
			{
				if (!Components->Flags[ComponentFlags_DisplayAddressRelative])
					printf("\x1b[38;2;%u;%u;%umRel", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]));
			}
			else
			{
				if (Components->QwordRegisters)
					printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Components->QwordRegisters[Operand->Memory.FirstRegister - 1]);
				else
					printf("\x1b[38;2;%u;%u;%umR%u", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Operand->Memory.FirstRegister - 1);
			}
		}

		if (Operand->Memory.SecondRegister)
		{
			printf("\x1b[38;2;%u;%u;%um + ", BREAK_RGB(Components->Colors[ComponentColors_Addition]));

			if (Components->QwordRegisters)
				printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Components->QwordRegisters[Operand->Memory.SecondRegister - 1]);
			else
				printf("\x1b[38;2;%u;%u;%umR%u", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Operand->Memory.SecondRegister - 1);
		}

		if (Operand->Memory.Multiplier)
		{
			printf("\x1b[38;2;%u;%u;%um * ", BREAK_RGB(Components->Colors[ComponentColors_Multiplication]));
			printf("\x1b[38;2;%u;%u;%um%c", BREAK_RGB(Components->Colors[ComponentColors_Multiplier]), Multiplier[Operand->Memory.Multiplier]);
		}

			if (Operand->Memory.OffsetSize == MemoryOffsetSize_8)
			{
				if (!Operand->Memory.FirstRegister && !Operand->Memory.SecondRegister)
					printf(VisualizeFormatNumber(OperationSize_8, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), Operand->Memory.Offset);
				else
				{
					if (Operand->Memory.FirstRegister != (unsigned char)~0 || !Components->Flags[ComponentFlags_DisplayAddressRelative])
					{
						if (Operand->Memory.Offset < 0)
						{
							printf("\x1b[38;2;%u;%u;%um - ", BREAK_RGB(Components->Colors[ComponentColors_Subtraction]));
							printf(VisualizeFormatNumber(OperationSize_8, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), -Operand->Memory.Offset);
						}
						else
						{
							printf("\x1b[38;2;%u;%u;%um + ", BREAK_RGB(Components->Colors[ComponentColors_Addition]));
							printf(VisualizeFormatNumber(OperationSize_8, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), Operand->Memory.Offset);
						}
					}
					else
						printf(VisualizeFormatNumber(OperationSize_64, Components->Flags[ComponentFlags_PadAddress], Components->Flags[ComponentFlags_HexAddress]), BREAK_RGB(Components->Colors[ComponentColors_Address]), ((unsigned char*)Location) + Operand->Memory.Offset);
				}
			}
			else if (Operand->Memory.OffsetSize == MemoryOffsetSize_32)
			{
				if (!Operand->Memory.FirstRegister && !Operand->Memory.SecondRegister)
					printf(VisualizeFormatNumber(OperationSize_32, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), Operand->Memory.Offset);
				else
				{
					if (Operand->Memory.FirstRegister != (unsigned char)~0 || !Components->Flags[ComponentFlags_DisplayAddressRelative])
					{
						if (Operand->Memory.Offset < 0)
						{
							printf("\x1b[38;2;%u;%u;%um - ", BREAK_RGB(Components->Colors[ComponentColors_Subtraction]));
							printf(VisualizeFormatNumber(OperationSize_32, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), -Operand->Memory.Offset);
						}
						else
						{
							printf("\x1b[38;2;%u;%u;%um + ", BREAK_RGB(Components->Colors[ComponentColors_Addition]));
							printf(VisualizeFormatNumber(OperationSize_32, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_Offset]), Operand->Memory.Offset);
						}
					}
					else
						printf(VisualizeFormatNumber(OperationSize_64, Components->Flags[ComponentFlags_PadAddress], Components->Flags[ComponentFlags_HexAddress]), BREAK_RGB(Components->Colors[ComponentColors_Address]), ((unsigned char*)Location) + Operand->Memory.Offset);
				}
		}

		printf("\x1b[38;2;%u;%u;%um]", BREAK_RGB(Components->Colors[ComponentColors_MemoryEnclosure]));
	} break;
	case OperandType_ML:
	{
		if (Components->Flags[ComponentFlags_SpecifyMemorySize])
			printf("\x1b[38;2;%u;%u;%um%s ", BREAK_RGB(Components->Colors[ComponentColors_MemorySize]), MemorySizes[Operand->OperandSize - 1]);

		printf(VisualizeFormatNumber(OperationSize_64, Components->Flags[ComponentFlags_PadAddress], Components->Flags[ComponentFlags_HexAddress]), BREAK_RGB(Components->Colors[ComponentColors_Address]), Operand->MemoryLarge.Value);
	} break;
	case OperandType_V:
	{
		printf(VisualizeFormatNumber((OperationSize)Operand->OperandSize, Components->Flags[ComponentFlags_PadImmediateMemory], Components->Flags[ComponentFlags_HexImmediateMemory]), BREAK_RGB(Components->Colors[ComponentColors_ImmediateMemory]), Operand->Value.Value);
	} break;
	case OperandType_Rel:
	{
		if (!Components->Flags[ComponentFlags_DisplayAddressRelative])
		{
			printf("\x1b[38;2;%u;%u;%umRel", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]));

			if (Operand->RelValue.Value < 0)
			{
				printf("\x1b[38;2;%u;%u;%um - ", BREAK_RGB(Components->Colors[ComponentColors_Subtraction]));
				printf(VisualizeFormatNumber((OperationSize)Operand->OperandSize, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_ImmediateMemory]), -Operand->RelValue.Value);
			}
			else
			{
				printf("\x1b[38;2;%u;%u;%um + ", BREAK_RGB(Components->Colors[ComponentColors_Addition]));
				printf(VisualizeFormatNumber((OperationSize)Operand->OperandSize, Components->Flags[ComponentFlags_PadOffset], Components->Flags[ComponentFlags_HexOffset]), BREAK_RGB(Components->Colors[ComponentColors_ImmediateMemory]), Operand->RelValue.Value);
			}
		}
		else
			printf(VisualizeFormatNumber(OperationSize_64, Components->Flags[ComponentFlags_PadAddress], Components->Flags[ComponentFlags_HexAddress]), BREAK_RGB(Components->Colors[ComponentColors_Address]), ((unsigned char*)Location) + Operand->RelValue.Value);
	} break;
	case OperandType_IR:
	{
		switch (Operand->OperandSize)
		{
		case OperationSize_8:
		{
			if (Operand->Register.HighLowPart)
			{
				if (Components->HighRegisters)
					printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_HighRegisters]), Components->HighRegisters[Operand->Register.Register - 1]);
				else
					printf("\x1b[38;2;%u;%u;%umR%uh", BREAK_RGB(Components->Colors[ComponentColors_HighRegisters]), Operand->Register.Register - 1);
			}
			else
			{
				if (Components->LowRegisters)
					printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_LowRegisters]), Components->HighRegisters[Operand->Register.Register - 1]);
				else
					printf("\x1b[38;2;%u;%u;%umR%ul", BREAK_RGB(Components->Colors[ComponentColors_LowRegisters]), Operand->Register.Register - 1);
			}
		} break;
		case OperationSize_16:
		{
			if (Components->WordRegisters)
				printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_WordRegisters]), Components->WordRegisters[Operand->Register.Register - 1]);
			else
				printf("\x1b[38;2;%u;%u;%umR%uw", BREAK_RGB(Components->Colors[ComponentColors_WordRegisters]), Operand->Register.Register - 1);
		} break;
		case OperationSize_32:
		{
			if (Components->DwordRegisters)
				printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_DwordRegisters]), Components->DwordRegisters[Operand->Register.Register - 1]);
			else
				printf("\x1b[38;2;%u;%u;%umR%ud", BREAK_RGB(Components->Colors[ComponentColors_DwordRegisters]), Operand->Register.Register - 1);
		} break;
		case OperationSize_64:
		{
			if (Components->QwordRegisters)
				printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Components->QwordRegisters[Operand->Register.Register - 1]);
			else
				printf("\x1b[38;2;%u;%u;%umR%u", BREAK_RGB(Components->Colors[ComponentColors_QwordRegisters]), Operand->Register.Register - 1);
		} break;
		}
	} break;
	case OperandType_SR:
	{
		if (Components->SegmentRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_SegmentRegisters]), Components->SegmentRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umS%u", BREAK_RGB(Components->Colors[ComponentColors_SegmentRegisters]), Operand->Register.Register - 1);
	} break;
	case OperandType_FR:
	{
		if (Components->FloatingRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_FloatingRegisters]), Components->FloatingRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umFR%u", BREAK_RGB(Components->Colors[ComponentColors_FloatingRegisters]), Operand->Register.Register - 1);
	} break;
	case OperandType_CR:
	{
		if (Components->ControlRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_ControlRegisters]), Components->ControlRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umCR%u", BREAK_RGB(Components->Colors[ComponentColors_ControlRegisters]), Operand->Register.Register - 1);
	} break;
	case OperandType_VR:
	{
		if (Components->VectorRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_VectorRegisters]), Components->VectorRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umVR%u", BREAK_RGB(Components->Colors[ComponentColors_VectorRegisters]), Operand->Register.Register - 1);
	} break;
	case OperandType_DR:
	{
		if (Components->DebugRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_DebugRegisters]), Components->DebugRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umDR%u", BREAK_RGB(Components->Colors[ComponentColors_DebugRegisters]), Operand->Register.Register - 1);
	} break;
	case OperandType_QR:
	{
		if (Components->QuadRegisters)
			printf("\x1b[38;2;%u;%u;%um%s", BREAK_RGB(Components->Colors[ComponentColors_QuadRegisters]), Components->QuadRegisters[Operand->Register.Register - 1]);
		else
			printf("\x1b[38;2;%u;%u;%umQR%u", BREAK_RGB(Components->Colors[ComponentColors_QuadRegisters]), Operand->Register.Register - 1);
	} break;
	}
}

static void Visualize(Operation* Operations, unsigned long OperationCount, const VisualComponents* Components)
{
	const char OperationSizeToChar[] = { 'b', 'w', 'd', 'q' };
	const char* PrefixBehaviour[] = { "lock", "repz", "repnz" };

	unsigned long ConsoleMode;

	void* Location;

	HANDLE ConsoleHandle;

	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ConsoleHandle == INVALID_HANDLE_VALUE)
		return;

	if (!GetConsoleMode(ConsoleHandle, &ConsoleMode))
		return;

	if (!SetConsoleMode(ConsoleHandle, ConsoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		return;

	Location = Components->DisasemblyBase;
	for (unsigned long long i = 0; i < OperationCount; Operations++, i++)
	{
		if (Components->InstructionSizes)
			Location = ((unsigned char*)Location) + Components->InstructionSizes[i];

		if (!Operations->Behaviour)
		{
			printf("\x1b[38;2;%u;%u;%umInvalid\n", BREAK_RGB(Components->Colors[ComponentColors_Behaviour]));
			continue;
		}

		if (Operations->Type == OperationType_OperandLess)
		{
			printf("\x1b[38;2;%u;%u;%um%s%c\n", BREAK_RGB(Components->Colors[ComponentColors_Behaviour]), MapBehaviourToString((InstructionBehaviour)Operations->Behaviour), OperationSizeToChar[Operations->OL.OperationSize]);
			continue;
		}

		if (Operations->Type)
			printf("\x1b[38;2;%u;%u;%um%s ", BREAK_RGB(Components->Colors[ComponentColors_PreBehaviour]), PrefixBehaviour[Operations->Type - 1]);

		printf("\x1b[38;2;%u;%u;%um%s ", BREAK_RGB(Components->Colors[ComponentColors_Behaviour]), MapBehaviourToString((InstructionBehaviour)Operations->Behaviour));
		for (unsigned long i = 0; Operations->N.Operands[i].Type && i < (sizeof(Operations->N.Operands) / sizeof(Operations->N.Operands[0])); i++)
		{
			VisualizeOperand(&Operations->N.Operands[i], Location, Components);
			if (i < ((sizeof(Operations->N.Operands) / sizeof(Operations->N.Operands[0])) - 1) && Operations->N.Operands[i + 1].Type)
				printf("\x1b[38;2;%u;%u;%um, ", BREAK_RGB(Components->Colors[ComponentColors_Seperator]));
		}

		printf("\x1b[38;2;255;255;255m\n");
	}

	SetConsoleMode(ConsoleHandle, ConsoleMode);
}