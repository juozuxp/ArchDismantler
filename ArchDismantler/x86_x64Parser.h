#pragma once
#include "x86_x64Base.h"
#include "InstructionSet.h"

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

static unsigned char CountBitsMask(unsigned long Value, unsigned char Mask)
{
	if (!Mask)
		return 0;

	unsigned char Count;

	Count = 0;

	Value = Value & Mask;
	for (; Value; Value >>= 1)
	{
		if (Value & 1)
			Count++;
	}

	return Count;
}

static void ResolveInstruction(x86_x64Instruction* SetBuffer, x86_x64IndexablePrefixes* IndexPfxMap, void* Location, x86_x64Instruction** Result, unsigned char* PrefixRedirect, unsigned char* Size)
{
	x86_x64Instruction* Instruction;

	unsigned char RedirectedViaOpByte;
	unsigned char RedirectedViaExByte;

	unsigned char OperandByte;
	unsigned char ExtraByte;

	Instruction = &SetBuffer[*((unsigned char*)Location)];

	Location = ((unsigned char*)Location) + 1;

	*Size = 1;
	*Result = 0;

	RedirectedViaExByte = 0;
	RedirectedViaOpByte = 0;

	if (PrefixRedirect)
		*PrefixRedirect = 0;

	while (1)
	{
		unsigned char BreakOut;
		unsigned char Portion;

		BreakOut = 0;
		switch (Instruction->Type)
		{
		case x86_x64InstructionType_FullRedirect:
		{
			Instruction = Instruction + Instruction->RF.Index + *((unsigned char*)Location);

			Location = ((unsigned char*)Location) + 1;
			*Size += 1;
		} break;
		case x86_x64InstructionType_ExUpperRedirect:
		{
			if (!RedirectedViaExByte)
			{
				ExtraByte = *((unsigned char*)Location);

				Location = ((unsigned char*)Location) + 1;
				*Size += 1;

				RedirectedViaExByte = 1;
			}

			Portion = (ExtraByte >> 3) & ((1 << 3) - 1);
		}
		case x86_x64InstructionType_UpperRedirect:
		{
			if (Instruction->Type != x86_x64InstructionType_ExUpperRedirect)
			{
				if (!RedirectedViaOpByte)
				{
					OperandByte = *((unsigned char*)Location);
					RedirectedViaOpByte = 1;
				}

				Portion = (OperandByte >> 3) & ((1 << 3) - 1);
			}

			if (Instruction->R.Available & (1 << Portion))
			{
				Portion = CountBits(Instruction->R.Available, 0, Portion);
				Instruction = Instruction + Instruction->R.Index + Portion;
			}
			else
				return;
		} break;
		case x86_x64InstructionType_ExLowerRedirect:
		{
			if (!RedirectedViaExByte)
			{
				ExtraByte = *((unsigned char*)Location);

				Location = ((unsigned char*)Location) + 1;
				*Size += 1;

				RedirectedViaExByte = 1;
			}

			Portion = ExtraByte & ((1 << 3) - 1);
		}
		case x86_x64InstructionType_LowerRedirect:
		{
			if (Instruction->Type != x86_x64InstructionType_ExLowerRedirect)
			{
				if (!RedirectedViaOpByte)
				{
					OperandByte = *((unsigned char*)Location);
					RedirectedViaOpByte = 1;
				}

				Portion = OperandByte & ((1 << 3) - 1);
			}

			if (Instruction->R.Available & (1 << Portion))
			{
				Portion = CountBits(Instruction->R.Available, 0, Portion);
				Instruction = Instruction + Instruction->R.Index + Portion;
			}
			else
				return;
		} break;
		case x86_x64InstructionType_ExGlobalRedirect:
		{
			if (!RedirectedViaExByte)
			{
				ExtraByte = *((unsigned char*)Location);

				Location = ((unsigned char*)Location) + 1;
				*Size += 1;

				RedirectedViaExByte = 1;
			}

			Portion = ExtraByte >> 6;
		}
		case x86_x64InstructionType_GlobalRedirect:
		{
			if (Instruction->Type != x86_x64InstructionType_ExGlobalRedirect)
			{
				if (!RedirectedViaOpByte)
				{
					OperandByte = *((unsigned char*)Location);
					RedirectedViaOpByte = 1;
				}

				Portion = OperandByte >> 6;
			}

			if (Instruction->R.Available & (1 << Portion))
				Portion = CountBits(Instruction->R.Available, 0, Portion);
			else
			{
				if (!((Instruction->R.Available >> 4) & (1 << Portion)))
					Portion = 0;
				else
					return;
			}

			Instruction = Instruction + Instruction->R.Index + Portion;
		} break;
		case x86_x64InstructionType_PrefixRedirect:
		{
			Portion = Instruction->RP.Available & (IndexPfxMap->Value & ((1 << 7) - 1));
			if (Portion)
			{
				if (PrefixRedirect)
					*PrefixRedirect = 1;

				Portion = CountBitsMask(Instruction->RP.Available, Portion - 1);
			}
			else if (Instruction->RP.DC)
				Portion = CountBitsMask(Instruction->RP.Available, (1 << 7) - 1);
			else
				return;

			Instruction = Instruction + Instruction->RP.Index + Portion;
		} break;
		default:
		{
			BreakOut = 1;
		} break;
		}

		if (BreakOut)
			break;
	}

	*Result = Instruction;
}

static void ResolveOperands(x86_x64Instruction* Instruction, x86_x64PrefixMap* PfxMap, void* Location, Operation* Result, unsigned char* Size)
{
	const OperandType RegisterTypeMap[] = { OperandType_IR, OperandType_SR, OperandType_FR, OperandType_IR, OperandType_CR, OperandType_VR, OperandType_DR, OperandType_QR };

	unsigned char SecondOperand;
	unsigned char MainOperand;

	unsigned char OperandByte;

	*Size = 0;

	MainOperand = 5;
	SecondOperand = 5;
	for (unsigned char i = 0; i < 4; i++)
	{
		if (!Instruction->N.Operands[i].Type)
			break;

		if (Instruction->N.Operands[i].O8) // Establish default size
			Result->N.Operands[i].OperandSize = OperationSize_8;

		else if (Instruction->N.Operands[i].O32)
			Result->N.Operands[i].OperandSize = OperationSize_32;

		else if (Instruction->N.Operands[i].O64)
			Result->N.Operands[i].OperandSize = OperationSize_64;

		else if (Instruction->N.Operands[i].O16)
			Result->N.Operands[i].OperandSize = OperationSize_16;

		else if (Instruction->N.Operands[i].O80)
			Result->N.Operands[i].OperandSize = OperationSize_80;

		else if (Instruction->N.Operands[i].O128)
			Result->N.Operands[i].OperandSize = OperationSize_128;

		if (Result->N.Operands[i].OperandSize == OperationSize_64 && Instruction->N.Operands[i].O128 && PfxMap->REXW)
			Result->N.Operands[i].OperandSize = OperationSize_128;

		else if (Instruction->N.Operands[i].O64 && PfxMap->REXW)
			Result->N.Operands[i].OperandSize = OperationSize_64;

		else if (Instruction->N.Operands[i].O16 && PfxMap->WORD)
			Result->N.Operands[i].OperandSize = OperationSize_16;

		if (Instruction->N.Operands[i].Type == x86_x64OperandType_M)
			MainOperand = i;

		if (Instruction->N.Operands[i].Type == x86_x64OperandType_R)
			SecondOperand = i;
	}

	if (MainOperand < 4)
	{
		OperandByte = *((unsigned char*)Location);

		*Size += 1;
		Location = ((unsigned char*)Location) + 1;

		if (OperandByte >> 6 == 3) // Operation register to register
		{
			Result->N.Operands[MainOperand].Type = RegisterTypeMap[Instruction->N.Operands[MainOperand].RType];
			if (PfxMap->REX || Result->N.Operands[MainOperand].OperandSize != OperationSize_8)
			{
				Result->N.Operands[MainOperand].Register.HighLowPart = 0;
				Result->N.Operands[MainOperand].Register.Register = (OperandByte & ((1 << 3) - 1)) + (PfxMap->REXB && !Instruction->N.Operands[MainOperand].IM ? 8 : 0) + 1;
			}
			else
			{
				Result->N.Operands[MainOperand].Register.HighLowPart = (OperandByte & ((1 << 3) - 1)) > 3;
				Result->N.Operands[MainOperand].Register.Register = ((OperandByte & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
			}
		}
		else
		{
			unsigned char SegmentIndex;

			SegmentIndex = 0;
			if (PfxMap->GS)
				SegmentIndex = x86_x64Segments_GS;
			else if (PfxMap->FS)
				SegmentIndex = x86_x64Segments_FS;

			Result->N.Operands[MainOperand].Type = OperandType_M;
			Result->N.Operands[MainOperand].Memory.Segment = SegmentIndex;
			Result->N.Operands[MainOperand].Memory.OffsetSize = OperandByte >> 6;
			switch (OperandByte & ((1 << 3) - 1))
			{
			case 4:
			{
				unsigned char ExtendedByte;

				ExtendedByte = *((unsigned char*)Location);

				*Size += 1;
				Location = ((unsigned char*)Location) + 1;

				if (((ExtendedByte >> 3) & ((1 << 3) - 1)) == 4) // if 4 then we head into another exception case
				{
					if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0) // Another exception for segments
					{
						Result->N.Operands[MainOperand].Memory.Offset = *(long*)Location;
						Result->N.Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

						*Size += 4;
						Location = ((unsigned char*)Location) + 4;

						break;
					}

					Result->N.Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PfxMap->REXB ? 8 : 0) + 1;
				}
				else if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0)
				{
					Result->N.Operands[MainOperand].Memory.FirstRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PfxMap->REXX ? 8 : 0) + 1;
					Result->N.Operands[MainOperand].Memory.Offset = *(long*)Location;

					*Size += 4;
					Location = ((unsigned char*)Location) + 4;
				}
				else
				{
					Result->N.Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PfxMap->REXB ? 8 : 0) + 1;
					Result->N.Operands[MainOperand].Memory.SecondRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PfxMap->REXX ? 8 : 0) + 1;
				}

				if (OperandByte >> 6 == 1)
				{
					Result->N.Operands[MainOperand].Memory.Offset = (long)*(char*)Location;

					*Size += 1;
					Location = ((unsigned char*)Location) + 1;
				}
				else if (OperandByte >> 6 == 2)
				{
					Result->N.Operands[MainOperand].Memory.Offset = *(long*)Location;

					*Size += 4;
					Location = ((unsigned char*)Location) + 4;
				}

				Result->N.Operands[MainOperand].Memory.Multiplier = ExtendedByte >> 6;
			} break;
			case 5:
			{
				if (OperandByte >> 6 == 0)
				{
					Result->N.Operands[MainOperand].Memory.FirstRegister = ~0;
					Result->N.Operands[MainOperand].Memory.Offset = *(long*)Location;
					Result->N.Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

					*Size += 4;
					Location = ((unsigned char*)Location) + 4;

					break;
				}
			}
			default:
			{
				Result->N.Operands[MainOperand].Memory.FirstRegister = (OperandByte & ((1 << 3) - 1)) + (PfxMap->REXB ? 8 : 0) + 1;

				if (OperandByte >> 6 == 1)
				{
					Result->N.Operands[MainOperand].Memory.Offset = (long)*(char*)Location;

					*Size += 1;
					Location = ((unsigned char*)Location) + 1;
				}
				else if (OperandByte >> 6 == 2)
				{
					Result->N.Operands[MainOperand].Memory.Offset = *(long*)Location;

					*Size += 4;
					Location = ((unsigned char*)Location) + 4;
				}
			} break;
			}
		}

		if (SecondOperand != 5)
		{
			Result->N.Operands[SecondOperand].Type = RegisterTypeMap[Instruction->N.Operands[SecondOperand].RType];
			if (PfxMap->REX || Result->N.Operands[SecondOperand].OperandSize != OperationSize_8)
			{
				Result->N.Operands[SecondOperand].Register.HighLowPart = 0;
				Result->N.Operands[SecondOperand].Register.Register = ((OperandByte >> 3) & ((1 << 3) - 1)) + (PfxMap->REXR && !Instruction->N.Operands[SecondOperand].IM ? 8 : 0) + 1;
			}
			else
			{
				Result->N.Operands[SecondOperand].Register.HighLowPart = ((OperandByte >> 3) & ((1 << 3) - 1)) > 3;
				Result->N.Operands[SecondOperand].Register.Register = ((OperandByte >> 3) & ((1 << 2) - 1)) + 1;
			}
		}
	}

	for (unsigned char i = 0; i < 4; i++)
	{
		if (!Instruction->N.Operands[i].Type)
			break;

		switch (Instruction->N.Operands[i].Type)
		{
		case x86_x64OperandType_IMM:
		{
			if (Instruction->N.Operands[i].DSO)
			{
				Result->N.Operands[i].Type = OperandType_ML;
				Result->N.Operands[i].MemoryLarge.Value = *(unsigned long long*)Location;

				*Size += 8;
				Location = ((unsigned char*)Location) + 8;

				continue;
			}

			Result->N.Operands[i].Type = OperandType_V;
			switch (Result->N.Operands[i].OperandSize)
			{
			case OperationSize_8:
			{
				Result->N.Operands[i].Value.Value = *(unsigned char*)Location;

				*Size += 1;
				Location = ((unsigned char*)Location) + 1;
			} break;
			case OperationSize_16:
			{
				Result->N.Operands[i].Value.Value = *(unsigned short*)Location;

				*Size += 2;
				Location = ((unsigned char*)Location) + 2;
			} break;
			case OperationSize_32:
			{
				Result->N.Operands[i].Value.Value = *(unsigned long*)Location;

				*Size += 4;
				Location = ((unsigned char*)Location) + 4;
			} break;
			case OperationSize_64:
			{
				Result->N.Operands[i].Value.Value = *(unsigned long long*)Location;

				*Size += 8;
				Location = ((unsigned char*)Location) + 8;
			} break;
			}
		} break;
		case x86_x64OperandType_Rel:
		{
			Result->N.Operands[i].Type = OperandType_Rel;
			switch (Result->N.Operands[i].OperandSize)
			{
			case OperationSize_8:
			{
				Result->N.Operands[i].RelValue.Value = (long)*(char*)Location;

				*Size += 1;
				Location = ((unsigned char*)Location) + 1;
			} break;
			case OperationSize_16:
			{
				Result->N.Operands[i].RelValue.Value = (long)*(short*)Location;

				*Size += 2;
				Location = ((unsigned char*)Location) + 2;
			} break;
			case OperationSize_32:
			{
				Result->N.Operands[i].RelValue.Value = *(long*)Location;

				*Size += 4;
				Location = ((unsigned char*)Location) + 4;
			} break;
			}
		} break;
		case x86_x64OperandType_Value:
		{
			Result->N.Operands[i].Type = OperandType_V;
			Result->N.Operands[i].Value.Value = Instruction->N.Operands[i].Value;
		} break;
		default:
		{
			if (Instruction->N.Operands[i].Type >= x86_x64OperandType_AX)
			{
				if (Instruction->N.Operands[i].DSO)
				{
					Result->N.Operands[i].Type = OperandType_M;
					Result->N.Operands[i].Memory.FirstRegister = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + (((PfxMap->REXB && !Instruction->N.Operands[i].IM) || (Instruction->N.Operands[i].RType == x86_x64RegisterType_Extended)) ? 8 : 0) + 1;
				}
				else
				{
					Result->N.Operands[i].Type = RegisterTypeMap[Instruction->N.Operands[i].RType];
					if ((PfxMap->REX && !Instruction->N.Operands[i].IM) || Result->N.Operands[i].OperandSize != OperationSize_8)
					{
						Result->N.Operands[i].Register.Register = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + (((PfxMap->REXB && !Instruction->N.Operands[i].IM) || (Instruction->N.Operands[i].RType == x86_x64RegisterType_Extended)) ? 8 : 0) + 1;
						Result->N.Operands[i].Register.HighLowPart = 0;
					}
					else
					{
						Result->N.Operands[i].Register.Register = ((Instruction->N.Operands[i].Type - x86_x64OperandType_AX) & ((1 << 2) - 1)) + 1;
						Result->N.Operands[i].Register.HighLowPart = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) > 3;
					}

				}
			}
		} break;
		}
	}
}

static void ParseInstruction(x86_x64Instruction* SetBuffer, void* Location, Operation* Result, unsigned char* Size)
{
	x86_x64PrefixMap PrefixMap;
	Operation Operation;

	unsigned char ResultSize;

	PrefixMap.Value = 0;

	ResultSize = 0;
	memset(&Operation, 0, sizeof(Operation));
	while (1)
	{
		x86_x64Instruction* Instruction;

		unsigned char RunSize;

		ResolveInstruction(SetBuffer, (x86_x64IndexablePrefixes*)&PrefixMap, Location, &Instruction, 0, &RunSize);
		if (!Instruction || !Instruction->Type)
			return;

		ResultSize += RunSize;
		Location = ((unsigned char*)Location) + RunSize;
		if (Instruction->Type == x86_x64InstructionType_Prefix)
		{
			unsigned char PrefixRedirect;

			PrefixMap.Value |= Instruction->P.Prefix.Value;
			if (!Instruction->Behaviour)
				continue;

			ResolveInstruction(SetBuffer, (x86_x64IndexablePrefixes*)&Instruction->P.Prefix.Value, Location, &Instruction, &PrefixRedirect, &RunSize);
			if (!PrefixRedirect)
			{
				Operation.Behaviour = (InstructionBehaviour)Instruction->Behaviour; // Semi implemented semi prefix
				break;
			}

			ResultSize += RunSize;
			Location = ((unsigned char*)Location) + RunSize;
		}

		Operation.Behaviour = (InstructionBehaviour)Instruction->Behaviour;
		if (Instruction->Type == x86_x64InstructionType_OperandLess)
		{
			Operation.Type = OperationType_OperandLess;

			if (Instruction->OL.O8) // Establish default size
				Operation.OL.OperationSize = OperationSize_8;

			else if (Instruction->OL.O32)
				Operation.OL.OperationSize = OperationSize_32;

			else if (Instruction->OL.O64)
				Operation.OL.OperationSize = OperationSize_64;

			else if (Instruction->OL.O16)
				Operation.OL.OperationSize = OperationSize_16;

			else
				Operation.Behaviour = InstructionBehaviour_Invalid;

			if (Instruction->OL.O64 && PrefixMap.REXW)
				Operation.OL.OperationSize = OperationSize_64;

			else if (Instruction->OL.O16 && PrefixMap.WORD)
				Operation.OL.OperationSize = OperationSize_16;

			break;
		}

		if ((PrefixMap.REPZ || PrefixMap.REPNZ) && Instruction->Repeatable)
			Operation.Type = PrefixMap.REPZ ? OperationType_RepeatZ : OperationType_RepeatNotZ;
		else if (PrefixMap.LOCK && Instruction->Lockable)
			Operation.Type = OperationType_Locked;
		else
			Operation.Type = OperationType_Normal;

		ResolveOperands(Instruction, &PrefixMap, Location, &Operation, &RunSize);

		ResultSize += RunSize;
		break;
	}

	if (Result)
		memcpy(Result, &Operation, sizeof(Operation));

	if (Size)
		*Size = ResultSize;
}

static void ParseCodeBySize(x86_x64Instruction* SetBuffer, void* Location, unsigned long long CodeSize, Operation* Operations, unsigned long long* OperationCount, unsigned char* InstructionSizes)
{
	unsigned char Size;

	if (OperationCount)
		*OperationCount = 0;

	for (unsigned long long Index = 0; Index < CodeSize; Index += Size, Location = ((unsigned char*)Location) + Size)
	{
		ParseInstruction(SetBuffer, Location, Operations, &Size);

		if (Operations)
			Operations++;

		if (OperationCount)
			(*OperationCount)++;

		if (InstructionSizes)
		{
			*InstructionSizes = Size;
			InstructionSizes++;
		}
	}
}

static void ParseCodeByCount(x86_x64Instruction* SetBuffer, void* Location, unsigned long long Count, Operation* Operations, unsigned char* InstructionSizes)
{
	unsigned char Size;

	for (unsigned long long Index = 0; Index < Count; Index++, Location = ((unsigned char*)Location) + Size)
	{
		ParseInstruction(SetBuffer, Location, Operations, &Size);

		if (Operations)
			Operations++;

		if (InstructionSizes)
		{
			*InstructionSizes = Size;
			InstructionSizes++;
		}
	}
}