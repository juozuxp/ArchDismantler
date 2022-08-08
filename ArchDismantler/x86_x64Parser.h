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

static void ParseCode(x86_x64Instruction* SetBuffer, void* Code, unsigned long long CodeSize, Operation* OperationBuffer, unsigned long long* OperationCount)
{
	//const x86_x64Override RegisterOverrideMap[] = { { OperandType_IR, 1 }, { OperandType_SR, 0 } };
	const OperandType RegisterTypeMap[] = { OperandType_IR, OperandType_SR, OperandType_FR, OperandType_IR, OperandType_CR, OperandType_VR, OperandType_DR, OperandType_QR };

	x86_x64IndexablePrefixes IndexPrefixMap;
	x86_x64Instruction* Instruction;
	x86_x64PrefixMap PrefixMap;

	unsigned char RedirectedViaOpByte;
	unsigned char RedirectedViaExByte;
	unsigned char InstructionPrefix;

	unsigned char SecondOperand;
	unsigned char MainOperand;

	unsigned char OperandByte;
	unsigned char ExtraByte;

	PrefixMap.Value = 0;
	IndexPrefixMap.Value = 0;

	InstructionPrefix = 0;
	RedirectedViaOpByte = 0;
	RedirectedViaExByte = 0;

	*OperationCount = 0;
	for (unsigned long long Index = 0; Index < CodeSize;)
	{
		Instruction = &SetBuffer[*((unsigned char*)Code)];

		Index++;
		Code = ((unsigned char*)Code) + 1;

		memset(OperationBuffer, 0, sizeof(Operation));

		while (1)
		{
			unsigned char BreakOut;
			unsigned char Portion;

			BreakOut = 0;
			switch (Instruction->Type)
			{
			case x86_x64InstructionType_FullRedirect:
			{
				Instruction = Instruction + Instruction->RF.Index + *((unsigned char*)Code);

				Index++;
				Code = ((unsigned char*)Code) + 1;
			} break;
			case x86_x64InstructionType_ExUpperRedirect:
			{
				if (!RedirectedViaExByte)
				{
					ExtraByte = *((unsigned char*)Code);

					Index++;
					Code = ((unsigned char*)Code) + 1;

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
						OperandByte = *((unsigned char*)Code);

						Index++;
						Code = ((unsigned char*)Code) + 1;

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
					goto Instruction_Invalid;
			} break;
			case x86_x64InstructionType_ExLowerRedirect:
			{
				if (!RedirectedViaExByte)
				{
					ExtraByte = *((unsigned char*)Code);

					Index++;
					Code = ((unsigned char*)Code) + 1;

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
						OperandByte = *((unsigned char*)Code);

						Index++;
						Code = ((unsigned char*)Code) + 1;

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
					goto Instruction_Invalid;
			} break;
			case x86_x64InstructionType_ExGlobalRedirect:
			{
				if (!RedirectedViaExByte)
				{
					ExtraByte = *((unsigned char*)Code);

					Index++;
					Code = ((unsigned char*)Code) + 1;

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
						OperandByte = *((unsigned char*)Code);

						Index++;
						Code = ((unsigned char*)Code) + 1;

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
						goto Instruction_Invalid;
				}

				Instruction = Instruction + Instruction->R.Index + Portion;
			} break;
			case x86_x64InstructionType_PrefixRedirect:
			{
				Portion = Instruction->RP.Available & (IndexPrefixMap.Value & ((1 << 7) - 1));
				if (Portion)
				{
					if (InstructionPrefix)
					{
						InstructionPrefix = 0;

						OperationBuffer--;
						(*OperationCount)--;
					}

					Portion = CountBitsMask(Instruction->RP.Available, Portion - 1);
				}
				else if (Instruction->RP.DC)
					Portion = CountBitsMask(Instruction->RP.Available, (1 << 7) - 1);
				else
					goto Instruction_Invalid;

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

		if (!Instruction->Type)
			goto Instruction_Invalid;

		if (Instruction->Type == x86_x64InstructionType_Prefix)
		{
			PrefixMap.Value |= Instruction->P.Prefix.Value;
			IndexPrefixMap.Value |= Instruction->P.Prefix.Value;

			if (!Instruction->Behaviour)
				continue;

			InstructionPrefix = 1;

			OperationBuffer->Behaviour = (InstructionBehaviour)Instruction->Behaviour; // Semi implemented semi prefix

			OperationBuffer++;
			(*OperationCount)++;
			continue;
		}

		OperationBuffer->Behaviour = (InstructionBehaviour)Instruction->Behaviour;

		if (Instruction->Type == x86_x64InstructionType_OperandLess)
		{
			OperationBuffer->Type = OperationType_OperandLess;

			if (Instruction->OL.O8) // Establish default size
				OperationBuffer->OL.OperationSize = OperationSize_8;

			else if (Instruction->OL.O32)
				OperationBuffer->OL.OperationSize = OperationSize_32;

			else if (Instruction->OL.O64)
				OperationBuffer->OL.OperationSize = OperationSize_64;

			else if (Instruction->OL.O16)
				OperationBuffer->OL.OperationSize = OperationSize_16;

			else
				OperationBuffer->Behaviour = InstructionBehaviour_Invalid;

			if (Instruction->OL.O64 && PrefixMap.REXW)
				OperationBuffer->OL.OperationSize = OperationSize_64;

			else if (Instruction->OL.O16 && PrefixMap.WORD)
				OperationBuffer->OL.OperationSize = OperationSize_16;

			goto Instruction_Invalid;
		}

		if ((PrefixMap.REPZ || PrefixMap.REPNZ) && Instruction->Repeatable)
			OperationBuffer->Type = PrefixMap.REPZ ? OperationType_RepeatZ : OperationType_RepeatNotZ;
		else if (PrefixMap.LOCK && Instruction->Lockable)
			OperationBuffer->Type = OperationType_Locked;
		else
			OperationBuffer->Type = OperationType_Normal;

		MainOperand = 5;
		SecondOperand = 5;
		for (unsigned char i = 0; i < 4; i++)
		{
			if (!Instruction->N.Operands[i].Type)
				break;

			if (Instruction->N.Operands[i].O8) // Establish default size
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_8;

			else if (Instruction->N.Operands[i].O32)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_32;

			else if (Instruction->N.Operands[i].O64)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_64;

			else if (Instruction->N.Operands[i].O16)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_16;

			else if (Instruction->N.Operands[i].O80)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_80;

			else if (Instruction->N.Operands[i].O128)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_128;

			if (OperationBuffer->N.Operands[i].OperandSize == OperationSize_64 && Instruction->N.Operands[i].O128 && PrefixMap.REXW)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_128;

			else if (Instruction->N.Operands[i].O64 && PrefixMap.REXW)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_64;

			else if (Instruction->N.Operands[i].O16 && PrefixMap.WORD)
				OperationBuffer->N.Operands[i].OperandSize = OperationSize_16;

			if (Instruction->N.Operands[i].Type == x86_x64OperandType_M)
				MainOperand = i;

			if (Instruction->N.Operands[i].Type == x86_x64OperandType_R)
				SecondOperand = i;
		}

		if (MainOperand < 4)
		{
			if (!RedirectedViaOpByte)
			{
				OperandByte = *((unsigned char*)Code);

				Index++;
				Code = ((unsigned char*)Code) + 1;
			}

			if (OperandByte >> 6 == 3) // Operation register to register
			{
				OperationBuffer->N.Operands[MainOperand].Type = RegisterTypeMap[Instruction->N.Operands[MainOperand].RType];
				if (PrefixMap.REX || OperationBuffer->N.Operands[MainOperand].OperandSize != OperationSize_8)
				{
					OperationBuffer->N.Operands[MainOperand].Register.HighLowPart = 0;
					OperationBuffer->N.Operands[MainOperand].Register.Register = (OperandByte & ((1 << 3) - 1)) + (PrefixMap.REXB && !Instruction->N.Operands[MainOperand].IM ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->N.Operands[MainOperand].Register.HighLowPart = (OperandByte & ((1 << 3) - 1)) > 3;
					OperationBuffer->N.Operands[MainOperand].Register.Register = ((OperandByte & ((1 << 3) - 1)) & ((1 << 2) - 1)) + 1;
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

				OperationBuffer->N.Operands[MainOperand].Type = OperandType_M;
				OperationBuffer->N.Operands[MainOperand].Memory.Segment = SegmentIndex;
				OperationBuffer->N.Operands[MainOperand].Memory.OffsetSize = OperandByte >> 6;
				switch (OperandByte & ((1 << 3) - 1))
				{
				case 4:
				{
					unsigned char ExtendedByte;

					ExtendedByte = *((unsigned char*)Code);

					Index++;
					Code = ((unsigned char*)Code) + 1;
					if (((ExtendedByte >> 3) & ((1 << 3) - 1)) == 4) // if 4 then we head into another exception case
					{
						if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0) // Another exception for segments
						{
							OperationBuffer->N.Operands[MainOperand].Memory.Offset = *(long*)Code;
							OperationBuffer->N.Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

							Index += 4;
							Code = ((unsigned char*)Code) + 4;

							break;
						}

						OperationBuffer->N.Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;
					}
					else if ((ExtendedByte & ((1 << 3) - 1)) == 5 && (OperandByte >> 6) == 0)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.FirstRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXX ? 8 : 0) + 1;
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = *(long*)Code;

						Index += 4;
						Code = ((unsigned char*)Code) + 4;
					}
					else
					{
						OperationBuffer->N.Operands[MainOperand].Memory.FirstRegister = (ExtendedByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;
						OperationBuffer->N.Operands[MainOperand].Memory.SecondRegister = ((ExtendedByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXX ? 8 : 0) + 1;
					}

					if (OperandByte >> 6 == 1)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = (long)*(char*)Code;

						Index++;
						Code = ((unsigned char*)Code) + 1;
					}
					else if (OperandByte >> 6 == 2)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = *(long*)Code;

						Index += 4;
						Code = ((unsigned char*)Code) + 4;
					}

					OperationBuffer->N.Operands[MainOperand].Memory.Multiplier = ExtendedByte >> 6;
				} break;
				case 5:
				{
					if (OperandByte >> 6 == 0)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.FirstRegister = ~0;
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = *(long*)Code;
						OperationBuffer->N.Operands[MainOperand].Memory.OffsetSize = MemoryOffsetSize_32;

						Index += 4;
						Code = ((unsigned char*)Code) + 4;

						break;
					}
				}
				default:
				{
					OperationBuffer->N.Operands[MainOperand].Memory.FirstRegister = (OperandByte & ((1 << 3) - 1)) + (PrefixMap.REXB ? 8 : 0) + 1;

					if (OperandByte >> 6 == 1)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = (long)*(char*)Code;

						Index++;
						Code = ((unsigned char*)Code) + 1;
					}
					else if (OperandByte >> 6 == 2)
					{
						OperationBuffer->N.Operands[MainOperand].Memory.Offset = *(long*)Code;

						Index += 4;
						Code = ((unsigned char*)Code) + 4;
					}
				} break;
				}
			}

			if (SecondOperand != 5)
			{
				OperationBuffer->N.Operands[SecondOperand].Type = RegisterTypeMap[Instruction->N.Operands[SecondOperand].RType];
				if (PrefixMap.REX || OperationBuffer->N.Operands[SecondOperand].OperandSize != OperationSize_8)
				{
					OperationBuffer->N.Operands[SecondOperand].Register.HighLowPart = 0;
					OperationBuffer->N.Operands[SecondOperand].Register.Register = ((OperandByte >> 3) & ((1 << 3) - 1)) + (PrefixMap.REXR && !Instruction->N.Operands[SecondOperand].IM ? 8 : 0) + 1;
				}
				else
				{
					OperationBuffer->N.Operands[SecondOperand].Register.HighLowPart = ((OperandByte >> 3) & ((1 << 3) - 1)) > 3;
					OperationBuffer->N.Operands[SecondOperand].Register.Register = ((OperandByte >> 3) & ((1 << 2) - 1)) + 1;
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
					OperationBuffer->N.Operands[i].Type = OperandType_ML;
					OperationBuffer->N.Operands[i].MemoryLarge.Value = *(unsigned long long*)Code;

					Index += 8;
					Code = ((unsigned char*)Code) + 8;

					continue;
				}

				OperationBuffer->N.Operands[i].Type = OperandType_V;
				switch (OperationBuffer->N.Operands[i].OperandSize)
				{
				case OperationSize_8:
				{
					OperationBuffer->N.Operands[i].Value.Value = *(unsigned char*)Code;

					Index++;
					Code = ((unsigned char*)Code) + 1;
				} break;
				case OperationSize_16:
				{
					OperationBuffer->N.Operands[i].Value.Value = *(unsigned short*)Code;

					Index += 2;
					Code = ((unsigned char*)Code) + 2;
				} break;
				case OperationSize_32:
				{
					OperationBuffer->N.Operands[i].Value.Value = *(unsigned long*)Code;

					Index += 4;
					Code = ((unsigned char*)Code) + 4;
				} break;
				case OperationSize_64:
				{
					OperationBuffer->N.Operands[i].Value.Value = *(unsigned long long*)Code;

					Index += 8;
					Code = ((unsigned char*)Code) + 8;
				} break;
				}
			} break;
			case x86_x64OperandType_Rel:
			{
				OperationBuffer->N.Operands[i].Type = OperandType_Rel;
				switch (OperationBuffer->N.Operands[i].OperandSize)
				{
				case OperationSize_8:
				{
					OperationBuffer->N.Operands[i].RelValue.Value = (long)*(char*)Code;

					Index++;
					Code = ((unsigned char*)Code) + 1;
				} break;
				case OperationSize_16:
				{
					OperationBuffer->N.Operands[i].RelValue.Value = (long)*(short*)Code;

					Index += 2;
					Code = ((unsigned char*)Code) + 2;
				} break;
				case OperationSize_32:
				{
					OperationBuffer->N.Operands[i].RelValue.Value = *(long*)Code;

					Index += 4;
					Code = ((unsigned char*)Code) + 4;
				} break;
				}
			} break;
			case x86_x64OperandType_Value:
			{
				OperationBuffer->N.Operands[i].Type = OperandType_V;
				OperationBuffer->N.Operands[i].Value.Value = Instruction->N.Operands[i].Value;
			} break;
			default:
			{
				if (Instruction->N.Operands[i].Type >= x86_x64OperandType_AX)
				{
					if (Instruction->N.Operands[i].DSO)
					{
						OperationBuffer->N.Operands[i].Type = OperandType_M;
						OperationBuffer->N.Operands[i].Memory.FirstRegister = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + (((PrefixMap.REXB && !Instruction->N.Operands[i].IM) || (Instruction->N.Operands[i].RType == x86_x64RegisterType_Extended)) ? 8 : 0) + 1;
					}
					else
					{
						OperationBuffer->N.Operands[i].Type = RegisterTypeMap[Instruction->N.Operands[i].RType];
						if ((PrefixMap.REX && !Instruction->N.Operands[i].IM) || OperationBuffer->N.Operands[i].OperandSize != OperationSize_8)
						{
							OperationBuffer->N.Operands[i].Register.Register = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) + (((PrefixMap.REXB && !Instruction->N.Operands[i].IM) || (Instruction->N.Operands[i].RType == x86_x64RegisterType_Extended)) ? 8 : 0) + 1;
							OperationBuffer->N.Operands[i].Register.HighLowPart = 0;
						}
						else
						{
							OperationBuffer->N.Operands[i].Register.Register = ((Instruction->N.Operands[i].Type - x86_x64OperandType_AX) & ((1 << 2) - 1)) + 1;
							OperationBuffer->N.Operands[i].Register.HighLowPart = (Instruction->N.Operands[i].Type - x86_x64OperandType_AX) > 3;
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
		IndexPrefixMap.Value = 0;

		InstructionPrefix = 0;
		RedirectedViaOpByte = 0;
		RedirectedViaExByte = 0;
	}
}