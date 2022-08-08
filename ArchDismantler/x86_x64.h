#pragma once
#include "x86_x64Base.h"
#include "InstructionSet.h"

#define ALLOCATE_BUFFER(AllocationArrow, Buffer, Size) ((Buffer) ? (((x86_x64Instruction*)(Buffer)) + (AllocationArrow)) : (x86_x64Instruction*)(DefaultBuffer)); memset(((x86_x64Instruction*)(Buffer)) + (AllocationArrow), 0, (Size) * sizeof(x86_x64Instruction)); (AllocationArrow) += (Size)
#define INDEX_BUFFER(From, To) ((((unsigned char*)(To)) - ((unsigned char*)(From))) / sizeof(x86_x64Instruction))

static void ConstructInstructionSet(x86_x64Instruction* SetBuffer, unsigned long long* SetSize)
{
	unsigned char DefaultBuffer[0x1000];
	unsigned long AllocationArrow;

	x86_x64Instruction* L5SubSet; // Impossible shit, radioactive zone
	x86_x64Instruction* L4SubSet; // dreadful stuff, basically everything gets redirected
	x86_x64Instruction* L3SubSet;
	x86_x64Instruction* L2SubSet;
	x86_x64Instruction* BaseSet;
	x86_x64Instruction* SubSet;
	x86_x64Instruction* ExSet;

	AllocationArrow = 0;

	BaseSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 255);

	BaseSet[0x00].Type = x86_x64InstructionType_Normal;
	BaseSet[0x00].Behaviour = InstructionBehaviour_Add;
	BaseSet[0x00].Lockable = 1;

	BaseSet[0x00].N.Operands[0].O8 = 1;
	BaseSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x00].N.Operands[1].O8 = 1;
	BaseSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x01].Type = x86_x64InstructionType_Normal;
	BaseSet[0x01].Behaviour = InstructionBehaviour_Add;
	BaseSet[0x01].Lockable = 1;

	BaseSet[0x01].N.Operands[0].O16 = 1;
	BaseSet[0x01].N.Operands[0].O32 = 1;
	BaseSet[0x01].N.Operands[0].O64 = 1;
	BaseSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x01].N.Operands[1].O16 = 1;
	BaseSet[0x01].N.Operands[1].O32 = 1;
	BaseSet[0x01].N.Operands[1].O64 = 1;
	BaseSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x02].Type = x86_x64InstructionType_Normal;
	BaseSet[0x02].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x02].N.Operands[0].O8 = 1;
	BaseSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x02].N.Operands[1].O8 = 1;
	BaseSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x03].Type = x86_x64InstructionType_Normal;
	BaseSet[0x03].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x03].N.Operands[0].O16 = 1;
	BaseSet[0x03].N.Operands[0].O32 = 1;
	BaseSet[0x03].N.Operands[0].O64 = 1;
	BaseSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x03].N.Operands[1].O16 = 1;
	BaseSet[0x03].N.Operands[1].O32 = 1;
	BaseSet[0x03].N.Operands[1].O64 = 1;
	BaseSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x04].Type = x86_x64InstructionType_Normal;
	BaseSet[0x04].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x04].N.Operands[0].IM = 1;
	BaseSet[0x04].N.Operands[0].O8 = 1;
	BaseSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x04].N.Operands[1].O8 = 1;
	BaseSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x05].Type = x86_x64InstructionType_Normal;
	BaseSet[0x05].Behaviour = InstructionBehaviour_Add;

	BaseSet[0x05].N.Operands[0].IM = 1;
	BaseSet[0x05].N.Operands[0].O16 = 1;
	BaseSet[0x05].N.Operands[0].O32 = 1;
	BaseSet[0x05].N.Operands[0].O64 = 1;
	BaseSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x05].N.Operands[1].O16 = 1;
	BaseSet[0x05].N.Operands[1].O32 = 1;
	BaseSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x08].Type = x86_x64InstructionType_Normal;
	BaseSet[0x08].Behaviour = InstructionBehaviour_Or;
	BaseSet[0x08].Lockable = 1;

	BaseSet[0x08].N.Operands[0].O8 = 1;
	BaseSet[0x08].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x08].N.Operands[1].O8 = 1;
	BaseSet[0x08].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x09].Type = x86_x64InstructionType_Normal;
	BaseSet[0x09].Behaviour = InstructionBehaviour_Or;
	BaseSet[0x09].Lockable = 1;

	BaseSet[0x09].N.Operands[0].O16 = 1;
	BaseSet[0x09].N.Operands[0].O32 = 1;
	BaseSet[0x09].N.Operands[0].O64 = 1;
	BaseSet[0x09].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x09].N.Operands[1].O16 = 1;
	BaseSet[0x09].N.Operands[1].O32 = 1;
	BaseSet[0x09].N.Operands[1].O64 = 1;
	BaseSet[0x09].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x0A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0A].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0A].N.Operands[0].O8 = 1;
	BaseSet[0x0A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x0A].N.Operands[1].O8 = 1;
	BaseSet[0x0A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x0B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0B].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0B].N.Operands[0].O16 = 1;
	BaseSet[0x0B].N.Operands[0].O32 = 1;
	BaseSet[0x0B].N.Operands[0].O64 = 1;
	BaseSet[0x0B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x0B].N.Operands[1].O16 = 1;
	BaseSet[0x0B].N.Operands[1].O32 = 1;
	BaseSet[0x0B].N.Operands[1].O64 = 1;
	BaseSet[0x0B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x0C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0C].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0C].N.Operands[0].IM = 1;
	BaseSet[0x0C].N.Operands[0].O8 = 1;
	BaseSet[0x0C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x0C].N.Operands[1].O8 = 1;
	BaseSet[0x0C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x0D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x0D].Behaviour = InstructionBehaviour_Or;

	BaseSet[0x0D].N.Operands[0].IM = 1;
	BaseSet[0x0D].N.Operands[0].O16 = 1;
	BaseSet[0x0D].N.Operands[0].O32 = 1;
	BaseSet[0x0D].N.Operands[0].O64 = 1;
	BaseSet[0x0D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x0D].N.Operands[1].O16 = 1;
	BaseSet[0x0D].N.Operands[1].O32 = 1;
	BaseSet[0x0D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x10].Type = x86_x64InstructionType_Normal;
	BaseSet[0x10].Behaviour = InstructionBehaviour_Adc;
	BaseSet[0x10].Lockable = 1;

	BaseSet[0x10].N.Operands[0].O8 = 1;
	BaseSet[0x10].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x10].N.Operands[1].O8 = 1;
	BaseSet[0x10].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x11].Type = x86_x64InstructionType_Normal;
	BaseSet[0x11].Behaviour = InstructionBehaviour_Adc;
	BaseSet[0x11].Lockable = 1;

	BaseSet[0x11].N.Operands[0].O16 = 1;
	BaseSet[0x11].N.Operands[0].O32 = 1;
	BaseSet[0x11].N.Operands[0].O64 = 1;
	BaseSet[0x11].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x11].N.Operands[1].O16 = 1;
	BaseSet[0x11].N.Operands[1].O32 = 1;
	BaseSet[0x11].N.Operands[1].O64 = 1;
	BaseSet[0x11].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x12].Type = x86_x64InstructionType_Normal;
	BaseSet[0x12].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x12].N.Operands[0].O8 = 1;
	BaseSet[0x12].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x12].N.Operands[1].O8 = 1;
	BaseSet[0x12].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x13].Type = x86_x64InstructionType_Normal;
	BaseSet[0x13].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x13].N.Operands[0].O16 = 1;
	BaseSet[0x13].N.Operands[0].O32 = 1;
	BaseSet[0x13].N.Operands[0].O64 = 1;
	BaseSet[0x13].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x13].N.Operands[1].O16 = 1;
	BaseSet[0x13].N.Operands[1].O32 = 1;
	BaseSet[0x13].N.Operands[1].O64 = 1;
	BaseSet[0x13].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x14].Type = x86_x64InstructionType_Normal;
	BaseSet[0x14].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x14].N.Operands[0].IM = 1;
	BaseSet[0x14].N.Operands[0].O8 = 1;
	BaseSet[0x14].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x14].N.Operands[1].O8 = 1;
	BaseSet[0x14].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x15].Type = x86_x64InstructionType_Normal;
	BaseSet[0x15].Behaviour = InstructionBehaviour_Adc;

	BaseSet[0x15].N.Operands[0].IM = 1;
	BaseSet[0x15].N.Operands[0].O16 = 1;
	BaseSet[0x15].N.Operands[0].O32 = 1;
	BaseSet[0x15].N.Operands[0].O64 = 1;
	BaseSet[0x15].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x15].N.Operands[1].O16 = 1;
	BaseSet[0x15].N.Operands[1].O32 = 1;
	BaseSet[0x15].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x18].Type = x86_x64InstructionType_Normal;
	BaseSet[0x18].Behaviour = InstructionBehaviour_Sbb;
	BaseSet[0x18].Lockable = 1;

	BaseSet[0x18].N.Operands[0].O8 = 1;
	BaseSet[0x18].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x18].N.Operands[1].O8 = 1;
	BaseSet[0x18].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x19].Type = x86_x64InstructionType_Normal;
	BaseSet[0x19].Behaviour = InstructionBehaviour_Sbb;
	BaseSet[0x19].Lockable = 1;

	BaseSet[0x19].N.Operands[0].O16 = 1;
	BaseSet[0x19].N.Operands[0].O32 = 1;
	BaseSet[0x19].N.Operands[0].O64 = 1;
	BaseSet[0x19].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x19].N.Operands[1].O16 = 1;
	BaseSet[0x19].N.Operands[1].O32 = 1;
	BaseSet[0x19].N.Operands[1].O64 = 1;
	BaseSet[0x19].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x1A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1A].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1A].N.Operands[0].O8 = 1;
	BaseSet[0x1A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x1A].N.Operands[1].O8 = 1;
	BaseSet[0x1A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x1B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1B].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1B].N.Operands[0].O16 = 1;
	BaseSet[0x1B].N.Operands[0].O32 = 1;
	BaseSet[0x1B].N.Operands[0].O64 = 1;
	BaseSet[0x1B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x1B].N.Operands[1].O16 = 1;
	BaseSet[0x1B].N.Operands[1].O32 = 1;
	BaseSet[0x1B].N.Operands[1].O64 = 1;
	BaseSet[0x1B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x1C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1C].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1C].N.Operands[0].IM = 1;
	BaseSet[0x1C].N.Operands[0].O8 = 1;
	BaseSet[0x1C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x1C].N.Operands[1].O8 = 1;
	BaseSet[0x1C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x1D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x1D].Behaviour = InstructionBehaviour_Sbb;

	BaseSet[0x1D].N.Operands[0].IM = 1;
	BaseSet[0x1D].N.Operands[0].O16 = 1;
	BaseSet[0x1D].N.Operands[0].O32 = 1;
	BaseSet[0x1D].N.Operands[0].O64 = 1;
	BaseSet[0x1D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x1D].N.Operands[1].O16 = 1;
	BaseSet[0x1D].N.Operands[1].O32 = 1;
	BaseSet[0x1D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x20].Type = x86_x64InstructionType_Normal;
	BaseSet[0x20].Behaviour = InstructionBehaviour_And;
	BaseSet[0x20].Lockable = 1;

	BaseSet[0x20].N.Operands[0].O8 = 1;
	BaseSet[0x20].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x20].N.Operands[1].O8 = 1;
	BaseSet[0x20].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x21].Type = x86_x64InstructionType_Normal;
	BaseSet[0x21].Behaviour = InstructionBehaviour_And;
	BaseSet[0x21].Lockable = 1;

	BaseSet[0x21].N.Operands[0].O16 = 1;
	BaseSet[0x21].N.Operands[0].O32 = 1;
	BaseSet[0x21].N.Operands[0].O64 = 1;
	BaseSet[0x21].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x21].N.Operands[1].O16 = 1;
	BaseSet[0x21].N.Operands[1].O32 = 1;
	BaseSet[0x21].N.Operands[1].O64 = 1;
	BaseSet[0x21].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x22].Type = x86_x64InstructionType_Normal;
	BaseSet[0x22].Behaviour = InstructionBehaviour_And;

	BaseSet[0x22].N.Operands[0].O8 = 1;
	BaseSet[0x22].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x22].N.Operands[1].O8 = 1;
	BaseSet[0x22].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x23].Type = x86_x64InstructionType_Normal;
	BaseSet[0x23].Behaviour = InstructionBehaviour_And;

	BaseSet[0x23].N.Operands[0].O16 = 1;
	BaseSet[0x23].N.Operands[0].O32 = 1;
	BaseSet[0x23].N.Operands[0].O64 = 1;
	BaseSet[0x23].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x23].N.Operands[1].O16 = 1;
	BaseSet[0x23].N.Operands[1].O32 = 1;
	BaseSet[0x23].N.Operands[1].O64 = 1;
	BaseSet[0x23].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x24].Type = x86_x64InstructionType_Normal;
	BaseSet[0x24].Behaviour = InstructionBehaviour_And;

	BaseSet[0x24].N.Operands[0].IM = 1;
	BaseSet[0x24].N.Operands[0].O8 = 1;
	BaseSet[0x24].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x24].N.Operands[1].O8 = 1;
	BaseSet[0x24].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x25].Type = x86_x64InstructionType_Normal;
	BaseSet[0x25].Behaviour = InstructionBehaviour_And;

	BaseSet[0x25].N.Operands[0].IM = 1;
	BaseSet[0x25].N.Operands[0].O16 = 1;
	BaseSet[0x25].N.Operands[0].O32 = 1;
	BaseSet[0x25].N.Operands[0].O64 = 1;
	BaseSet[0x25].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x25].N.Operands[1].O16 = 1;
	BaseSet[0x25].N.Operands[1].O32 = 1;
	BaseSet[0x25].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x26].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x26].P.Prefix.Value = 0;

	BaseSet[0x28].Type = x86_x64InstructionType_Normal;
	BaseSet[0x28].Behaviour = InstructionBehaviour_Sub;
	BaseSet[0x28].Lockable = 1;

	BaseSet[0x28].N.Operands[0].O8 = 1;
	BaseSet[0x28].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x28].N.Operands[1].O8 = 1;
	BaseSet[0x28].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x29].Type = x86_x64InstructionType_Normal;
	BaseSet[0x29].Behaviour = InstructionBehaviour_Sub;
	BaseSet[0x29].Lockable = 1;

	BaseSet[0x29].N.Operands[0].O16 = 1;
	BaseSet[0x29].N.Operands[0].O32 = 1;
	BaseSet[0x29].N.Operands[0].O64 = 1;
	BaseSet[0x29].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x29].N.Operands[1].O16 = 1;
	BaseSet[0x29].N.Operands[1].O32 = 1;
	BaseSet[0x29].N.Operands[1].O64 = 1;
	BaseSet[0x29].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x2A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2A].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2A].N.Operands[0].O8 = 1;
	BaseSet[0x2A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x2A].N.Operands[1].O8 = 1;
	BaseSet[0x2A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x2B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2B].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2B].N.Operands[0].O16 = 1;
	BaseSet[0x2B].N.Operands[0].O32 = 1;
	BaseSet[0x2B].N.Operands[0].O64 = 1;
	BaseSet[0x2B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x2B].N.Operands[1].O16 = 1;
	BaseSet[0x2B].N.Operands[1].O32 = 1;
	BaseSet[0x2B].N.Operands[1].O64 = 1;
	BaseSet[0x2B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x2C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2C].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2C].N.Operands[0].IM = 1;
	BaseSet[0x2C].N.Operands[0].O8 = 1;
	BaseSet[0x2C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x2C].N.Operands[1].O8 = 1;
	BaseSet[0x2C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x2D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x2D].Behaviour = InstructionBehaviour_Sub;

	BaseSet[0x2D].N.Operands[0].IM = 1;
	BaseSet[0x2D].N.Operands[0].O16 = 1;
	BaseSet[0x2D].N.Operands[0].O32 = 1;
	BaseSet[0x2D].N.Operands[0].O64 = 1;
	BaseSet[0x2D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x2D].N.Operands[1].O16 = 1;
	BaseSet[0x2D].N.Operands[1].O32 = 1;
	BaseSet[0x2D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x2E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x2E].P.Prefix.Value = 0;

	BaseSet[0x30].Type = x86_x64InstructionType_Normal;
	BaseSet[0x30].Behaviour = InstructionBehaviour_Xor;
	BaseSet[0x30].Lockable = 1;

	BaseSet[0x30].N.Operands[0].O8 = 1;
	BaseSet[0x30].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x30].N.Operands[1].O8 = 1;
	BaseSet[0x30].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x31].Type = x86_x64InstructionType_Normal;
	BaseSet[0x31].Behaviour = InstructionBehaviour_Xor;
	BaseSet[0x31].Lockable = 1;

	BaseSet[0x31].N.Operands[0].O16 = 1;
	BaseSet[0x31].N.Operands[0].O32 = 1;
	BaseSet[0x31].N.Operands[0].O64 = 1;
	BaseSet[0x31].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x31].N.Operands[1].O16 = 1;
	BaseSet[0x31].N.Operands[1].O32 = 1;
	BaseSet[0x31].N.Operands[1].O64 = 1;
	BaseSet[0x31].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x32].Type = x86_x64InstructionType_Normal;
	BaseSet[0x32].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x32].N.Operands[0].O8 = 1;
	BaseSet[0x32].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x32].N.Operands[1].O8 = 1;
	BaseSet[0x32].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x33].Type = x86_x64InstructionType_Normal;
	BaseSet[0x33].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x33].N.Operands[0].O16 = 1;
	BaseSet[0x33].N.Operands[0].O32 = 1;
	BaseSet[0x33].N.Operands[0].O64 = 1;
	BaseSet[0x33].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x33].N.Operands[1].O16 = 1;
	BaseSet[0x33].N.Operands[1].O32 = 1;
	BaseSet[0x33].N.Operands[1].O64 = 1;
	BaseSet[0x33].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x34].Type = x86_x64InstructionType_Normal;
	BaseSet[0x34].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x34].N.Operands[0].IM = 1;
	BaseSet[0x34].N.Operands[0].O8 = 1;
	BaseSet[0x34].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x34].N.Operands[1].O8 = 1;
	BaseSet[0x34].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x35].Type = x86_x64InstructionType_Normal;
	BaseSet[0x35].Behaviour = InstructionBehaviour_Xor;

	BaseSet[0x35].N.Operands[0].IM = 1;
	BaseSet[0x35].N.Operands[0].O16 = 1;
	BaseSet[0x35].N.Operands[0].O32 = 1;
	BaseSet[0x35].N.Operands[0].O64 = 1;
	BaseSet[0x35].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x35].N.Operands[1].O16 = 1;
	BaseSet[0x35].N.Operands[1].O32 = 1;
	BaseSet[0x35].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x36].Type = x86_x64InstructionType_Normal;
	BaseSet[0x36].P.Prefix.Value = 0;

	BaseSet[0x38].Type = x86_x64InstructionType_Normal;
	BaseSet[0x38].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x38].N.Operands[0].O8 = 1;
	BaseSet[0x38].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x38].N.Operands[1].O8 = 1;
	BaseSet[0x38].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x39].Type = x86_x64InstructionType_Normal;
	BaseSet[0x39].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x39].N.Operands[0].O16 = 1;
	BaseSet[0x39].N.Operands[0].O32 = 1;
	BaseSet[0x39].N.Operands[0].O64 = 1;
	BaseSet[0x39].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x39].N.Operands[1].O16 = 1;
	BaseSet[0x39].N.Operands[1].O32 = 1;
	BaseSet[0x39].N.Operands[1].O64 = 1;
	BaseSet[0x39].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x3A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3A].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3A].N.Operands[0].O8 = 1;
	BaseSet[0x3A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x3A].N.Operands[1].O8 = 1;
	BaseSet[0x3A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x3B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3B].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3B].N.Operands[0].O16 = 1;
	BaseSet[0x3B].N.Operands[0].O32 = 1;
	BaseSet[0x3B].N.Operands[0].O64 = 1;
	BaseSet[0x3B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x3B].N.Operands[1].O16 = 1;
	BaseSet[0x3B].N.Operands[1].O32 = 1;
	BaseSet[0x3B].N.Operands[1].O64 = 1;
	BaseSet[0x3B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x3C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3C].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3C].N.Operands[0].IM = 1;
	BaseSet[0x3C].N.Operands[0].O8 = 1;
	BaseSet[0x3C].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x3C].N.Operands[1].O8 = 1;
	BaseSet[0x3C].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x3D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x3D].Behaviour = InstructionBehaviour_Cmp;

	BaseSet[0x3D].N.Operands[0].IM = 1;
	BaseSet[0x3D].N.Operands[0].O16 = 1;
	BaseSet[0x3D].N.Operands[0].O32 = 1;
	BaseSet[0x3D].N.Operands[0].O64 = 1;
	BaseSet[0x3D].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x3D].N.Operands[1].O16 = 1;
	BaseSet[0x3D].N.Operands[1].O32 = 1;
	BaseSet[0x3D].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x3E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x3E].P.Prefix.Value = 0;

	BaseSet[0x40].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x40].P.Prefix.REX = 1;

	BaseSet[0x41].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x41].P.Prefix.REX = 1;
	BaseSet[0x41].P.Prefix.REXB = 1;

	BaseSet[0x42].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x42].P.Prefix.REX = 1;
	BaseSet[0x42].P.Prefix.REXX = 1;

	BaseSet[0x43].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x43].P.Prefix.REX = 1;
	BaseSet[0x43].P.Prefix.REXB = 1;
	BaseSet[0x43].P.Prefix.REXX = 1;

	BaseSet[0x44].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x44].P.Prefix.REX = 1;
	BaseSet[0x44].P.Prefix.REXR = 1;

	BaseSet[0x45].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x45].P.Prefix.REX = 1;
	BaseSet[0x45].P.Prefix.REXR = 1;
	BaseSet[0x45].P.Prefix.REXB = 1;

	BaseSet[0x46].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x46].P.Prefix.REX = 1;
	BaseSet[0x46].P.Prefix.REXR = 1;
	BaseSet[0x46].P.Prefix.REXX = 1;

	BaseSet[0x47].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x47].P.Prefix.REX = 1;
	BaseSet[0x47].P.Prefix.REXR = 1;
	BaseSet[0x47].P.Prefix.REXX = 1;
	BaseSet[0x47].P.Prefix.REXB = 1;

	BaseSet[0x48].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x48].P.Prefix.REX = 1;
	BaseSet[0x48].P.Prefix.REXW = 1;

	BaseSet[0x49].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x49].P.Prefix.REX = 1;
	BaseSet[0x49].P.Prefix.REXW = 1;
	BaseSet[0x49].P.Prefix.REXB = 1;

	BaseSet[0x4A].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4A].P.Prefix.REX = 1;
	BaseSet[0x4A].P.Prefix.REXW = 1;
	BaseSet[0x4A].P.Prefix.REXX = 1;

	BaseSet[0x4B].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4B].P.Prefix.REX = 1;
	BaseSet[0x4B].P.Prefix.REXW = 1;
	BaseSet[0x4B].P.Prefix.REXX = 1;
	BaseSet[0x4B].P.Prefix.REXB = 1;

	BaseSet[0x4C].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4C].P.Prefix.REX = 1;
	BaseSet[0x4C].P.Prefix.REXW = 1;
	BaseSet[0x4C].P.Prefix.REXR = 1;

	BaseSet[0x4D].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4D].P.Prefix.REX = 1;
	BaseSet[0x4D].P.Prefix.REXW = 1;
	BaseSet[0x4D].P.Prefix.REXR = 1;
	BaseSet[0x4D].P.Prefix.REXB = 1;

	BaseSet[0x4E].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4E].P.Prefix.REX = 1;
	BaseSet[0x4E].P.Prefix.REXW = 1;
	BaseSet[0x4E].P.Prefix.REXR = 1;
	BaseSet[0x4E].P.Prefix.REXX = 1;

	BaseSet[0x4F].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x4F].P.Prefix.REX = 1;
	BaseSet[0x4F].P.Prefix.REXW = 1;
	BaseSet[0x4F].P.Prefix.REXR = 1;
	BaseSet[0x4F].P.Prefix.REXX = 1;
	BaseSet[0x4F].P.Prefix.REXB = 1;

	BaseSet[0x50].Type = x86_x64InstructionType_Normal;
	BaseSet[0x50].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x50].N.Operands[0].O16 = 1;
	BaseSet[0x50].N.Operands[0].O64 = 1;
	BaseSet[0x50].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x51].Type = x86_x64InstructionType_Normal;
	BaseSet[0x51].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x51].N.Operands[0].O16 = 1;
	BaseSet[0x51].N.Operands[0].O64 = 1;
	BaseSet[0x51].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x52].Type = x86_x64InstructionType_Normal;
	BaseSet[0x52].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x52].N.Operands[0].O16 = 1;
	BaseSet[0x52].N.Operands[0].O64 = 1;
	BaseSet[0x52].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x53].Type = x86_x64InstructionType_Normal;
	BaseSet[0x53].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x53].N.Operands[0].O16 = 1;
	BaseSet[0x53].N.Operands[0].O64 = 1;
	BaseSet[0x53].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x54].Type = x86_x64InstructionType_Normal;
	BaseSet[0x54].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x54].N.Operands[0].O16 = 1;
	BaseSet[0x54].N.Operands[0].O64 = 1;
	BaseSet[0x54].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x55].Type = x86_x64InstructionType_Normal;
	BaseSet[0x55].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x55].N.Operands[0].O16 = 1;
	BaseSet[0x55].N.Operands[0].O64 = 1;
	BaseSet[0x55].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x56].Type = x86_x64InstructionType_Normal;
	BaseSet[0x56].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x56].N.Operands[0].O16 = 1;
	BaseSet[0x56].N.Operands[0].O64 = 1;
	BaseSet[0x56].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x57].Type = x86_x64InstructionType_Normal;
	BaseSet[0x57].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x57].N.Operands[0].O16 = 1;
	BaseSet[0x57].N.Operands[0].O64 = 1;
	BaseSet[0x57].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x58].Type = x86_x64InstructionType_Normal;
	BaseSet[0x58].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x58].N.Operands[0].O16 = 1;
	BaseSet[0x58].N.Operands[0].O64 = 1;
	BaseSet[0x58].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0x59].Type = x86_x64InstructionType_Normal;
	BaseSet[0x59].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x59].N.Operands[0].O16 = 1;
	BaseSet[0x59].N.Operands[0].O64 = 1;
	BaseSet[0x59].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x5A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5A].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5A].N.Operands[0].O16 = 1;
	BaseSet[0x5A].N.Operands[0].O64 = 1;
	BaseSet[0x5A].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x5B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5B].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5B].N.Operands[0].O16 = 1;
	BaseSet[0x5B].N.Operands[0].O64 = 1;
	BaseSet[0x5B].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x5C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5C].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5C].N.Operands[0].O16 = 1;
	BaseSet[0x5C].N.Operands[0].O64 = 1;
	BaseSet[0x5C].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x5D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5D].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5D].N.Operands[0].O16 = 1;
	BaseSet[0x5D].N.Operands[0].O64 = 1;
	BaseSet[0x5D].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x5E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5E].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5E].N.Operands[0].O16 = 1;
	BaseSet[0x5E].N.Operands[0].O64 = 1;
	BaseSet[0x5E].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x5F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x5F].Behaviour = InstructionBehaviour_Pop;

	BaseSet[0x5F].N.Operands[0].O16 = 1;
	BaseSet[0x5F].N.Operands[0].O64 = 1;
	BaseSet[0x5F].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x63].Type = x86_x64InstructionType_Normal;
	BaseSet[0x63].Behaviour = InstructionBehaviour_Movsxd;

	BaseSet[0x63].N.Operands[0].O32 = 1;
	BaseSet[0x63].N.Operands[0].O64 = 1;
	BaseSet[0x63].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x63].N.Operands[1].O32 = 1;
	BaseSet[0x63].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x64].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x64].P.Prefix.FS = 1;

	BaseSet[0x65].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x65].P.Prefix.GS = 1;

	BaseSet[0x66].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x66].P.Prefix.WORD = 1;

	BaseSet[0x67].Type = x86_x64InstructionType_Prefix; // not yet implemented
	BaseSet[0x67].P.Prefix.Value = 0;

	BaseSet[0x68].Type = x86_x64InstructionType_Normal;
	BaseSet[0x68].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x68].N.Operands[0].O16 = 1;
	BaseSet[0x68].N.Operands[0].O32 = 1;
	BaseSet[0x68].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0x69].Type = x86_x64InstructionType_Normal;
	BaseSet[0x69].Behaviour = InstructionBehaviour_Imul;

	BaseSet[0x69].N.Operands[0].O16 = 1;
	BaseSet[0x69].N.Operands[0].O32 = 1;
	BaseSet[0x69].N.Operands[0].O64 = 1;
	BaseSet[0x69].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x69].N.Operands[1].O16 = 1;
	BaseSet[0x69].N.Operands[1].O32 = 1;
	BaseSet[0x69].N.Operands[1].O64 = 1;
	BaseSet[0x69].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x69].N.Operands[2].O16 = 1;
	BaseSet[0x69].N.Operands[2].O32 = 1;
	BaseSet[0x69].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0x6A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6A].Behaviour = InstructionBehaviour_Push;

	BaseSet[0x6A].N.Operands[0].O8 = 1;
	BaseSet[0x6A].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0x6B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x6B].Behaviour = InstructionBehaviour_Imul;

	BaseSet[0x6B].N.Operands[0].O16 = 1;
	BaseSet[0x6B].N.Operands[0].O32 = 1;
	BaseSet[0x6B].N.Operands[0].O64 = 1;
	BaseSet[0x6B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x6B].N.Operands[1].O16 = 1;
	BaseSet[0x6B].N.Operands[1].O32 = 1;
	BaseSet[0x6B].N.Operands[1].O64 = 1;
	BaseSet[0x6B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x6B].N.Operands[2].O8 = 1;
	BaseSet[0x6B].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0x6C].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x6C].RP.A3 = 1;
	BaseSet[0x6C].RP.A4 = 1;
	BaseSet[0x6C].RP.DC = 1;

	BaseSet[0x6C].RP.Index = INDEX_BUFFER(&BaseSet[0x6C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DX;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DX;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0x6D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x6D].RP.A3 = 1;
	BaseSet[0x6D].RP.A4 = 1;
	BaseSet[0x6D].RP.DC = 1;

	BaseSet[0x6D].RP.Index = INDEX_BUFFER(&BaseSet[0x6D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DX;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DX;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Ins;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0x6E].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x6E].RP.A3 = 1;
	BaseSet[0x6E].RP.A4 = 1;
	BaseSet[0x6E].RP.DC = 1;

	BaseSet[0x6E].RP.Index = INDEX_BUFFER(&BaseSet[0x6E], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0x6D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x6F].RP.A3 = 1;
	BaseSet[0x6F].RP.A4 = 1;
	BaseSet[0x6F].RP.DC = 1;

	BaseSet[0x6F].RP.Index = INDEX_BUFFER(&BaseSet[0x6F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Outs;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0x70].Type = x86_x64InstructionType_Normal;
	BaseSet[0x70].Behaviour = InstructionBehaviour_Jo;

	BaseSet[0x70].N.Operands[0].O8 = 1;
	BaseSet[0x70].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x71].Type = x86_x64InstructionType_Normal;
	BaseSet[0x71].Behaviour = InstructionBehaviour_Jno;

	BaseSet[0x71].N.Operands[0].O8 = 1;
	BaseSet[0x71].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x72].Type = x86_x64InstructionType_Normal;
	BaseSet[0x72].Behaviour = InstructionBehaviour_Jb;

	BaseSet[0x72].N.Operands[0].O8 = 1;
	BaseSet[0x72].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x73].Type = x86_x64InstructionType_Normal;
	BaseSet[0x73].Behaviour = InstructionBehaviour_Jae;

	BaseSet[0x73].N.Operands[0].O8 = 1;
	BaseSet[0x73].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x74].Type = x86_x64InstructionType_Normal;
	BaseSet[0x74].Behaviour = InstructionBehaviour_Je;

	BaseSet[0x74].N.Operands[0].O8 = 1;
	BaseSet[0x74].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x75].Type = x86_x64InstructionType_Normal;
	BaseSet[0x75].Behaviour = InstructionBehaviour_Jne;

	BaseSet[0x75].N.Operands[0].O8 = 1;
	BaseSet[0x75].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x76].Type = x86_x64InstructionType_Normal;
	BaseSet[0x76].Behaviour = InstructionBehaviour_Jbe;

	BaseSet[0x76].N.Operands[0].O8 = 1;
	BaseSet[0x76].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x77].Type = x86_x64InstructionType_Normal;
	BaseSet[0x77].Behaviour = InstructionBehaviour_Ja;

	BaseSet[0x77].N.Operands[0].O8 = 1;
	BaseSet[0x77].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x78].Type = x86_x64InstructionType_Normal;
	BaseSet[0x78].Behaviour = InstructionBehaviour_Js;

	BaseSet[0x78].N.Operands[0].O8 = 1;
	BaseSet[0x78].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x79].Type = x86_x64InstructionType_Normal;
	BaseSet[0x79].Behaviour = InstructionBehaviour_Jns;

	BaseSet[0x79].N.Operands[0].O8 = 1;
	BaseSet[0x79].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7A].Behaviour = InstructionBehaviour_Jp;

	BaseSet[0x7A].N.Operands[0].O8 = 1;
	BaseSet[0x7A].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7B].Behaviour = InstructionBehaviour_Jnp;

	BaseSet[0x7B].N.Operands[0].O8 = 1;
	BaseSet[0x7B].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7C].Behaviour = InstructionBehaviour_Jl;

	BaseSet[0x7C].N.Operands[0].O8 = 1;
	BaseSet[0x7C].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7D].Behaviour = InstructionBehaviour_Jge;

	BaseSet[0x7D].N.Operands[0].O8 = 1;
	BaseSet[0x7D].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7E].Behaviour = InstructionBehaviour_Jle;

	BaseSet[0x7E].N.Operands[0].O8 = 1;
	BaseSet[0x7E].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x7F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x7F].Behaviour = InstructionBehaviour_Jg;

	BaseSet[0x7F].N.Operands[0].O8 = 1;
	BaseSet[0x7F].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0x80].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x80].R.A0 = 1;
	BaseSet[0x80].R.A1 = 1;
	BaseSet[0x80].R.A2 = 1;
	BaseSet[0x80].R.A3 = 1;
	BaseSet[0x80].R.A4 = 1;
	BaseSet[0x80].R.A5 = 1;
	BaseSet[0x80].R.A6 = 1;
	BaseSet[0x80].R.A7 = 1;

	BaseSet[0x80].R.Index = INDEX_BUFFER(&BaseSet[0x80], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;
	SubSet[0x00].Lockable = 1;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;
	SubSet[0x01].Lockable = 1;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;
	SubSet[0x02].Lockable = 1;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;
	SubSet[0x03].Lockable = 1;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;
	SubSet[0x04].Lockable = 1;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;
	SubSet[0x05].Lockable = 1;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;
	SubSet[0x06].Lockable = 1;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x81].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x81].R.A0 = 1;
	BaseSet[0x81].R.A1 = 1;
	BaseSet[0x81].R.A2 = 1;
	BaseSet[0x81].R.A3 = 1;
	BaseSet[0x81].R.A4 = 1;
	BaseSet[0x81].R.A5 = 1;
	BaseSet[0x81].R.A6 = 1;
	BaseSet[0x81].R.A7 = 1;

	BaseSet[0x81].R.Index = INDEX_BUFFER(&BaseSet[0x81], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;
	SubSet[0x00].Lockable = 1;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;
	SubSet[0x01].Lockable = 1;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;
	SubSet[0x02].Lockable = 1;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;
	SubSet[0x03].Lockable = 1;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O16 = 1;
	SubSet[0x03].N.Operands[1].O32 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;
	SubSet[0x04].Lockable = 1;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O16 = 1;
	SubSet[0x04].N.Operands[1].O32 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;
	SubSet[0x05].Lockable = 1;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O16 = 1;
	SubSet[0x05].N.Operands[1].O32 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;
	SubSet[0x06].Lockable = 1;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O16 = 1;
	SubSet[0x06].N.Operands[1].O32 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O16 = 1;
	SubSet[0x07].N.Operands[1].O32 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x83].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0x83].R.A0 = 1;
	BaseSet[0x83].R.A1 = 1;
	BaseSet[0x83].R.A2 = 1;
	BaseSet[0x83].R.A3 = 1;
	BaseSet[0x83].R.A4 = 1;
	BaseSet[0x83].R.A5 = 1;
	BaseSet[0x83].R.A6 = 1;
	BaseSet[0x83].R.A7 = 1;

	BaseSet[0x83].R.Index = INDEX_BUFFER(&BaseSet[0x83], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Add;
	SubSet[0x00].Lockable = 1;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Or;
	SubSet[0x01].Lockable = 1;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Adc;
	SubSet[0x02].Lockable = 1;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sbb;
	SubSet[0x03].Lockable = 1;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_And;
	SubSet[0x04].Lockable = 1;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Sub;
	SubSet[0x05].Lockable = 1;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Xor;
	SubSet[0x06].Lockable = 1;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Cmp;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0x84].Type = x86_x64InstructionType_Normal;
	BaseSet[0x84].Behaviour = InstructionBehaviour_Test;

	BaseSet[0x84].N.Operands[0].O8 = 1;
	BaseSet[0x84].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x84].N.Operands[1].O8 = 1;
	BaseSet[0x84].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x85].Type = x86_x64InstructionType_Normal;
	BaseSet[0x85].Behaviour = InstructionBehaviour_Test;

	BaseSet[0x85].N.Operands[0].O16 = 1;
	BaseSet[0x85].N.Operands[0].O32 = 1;
	BaseSet[0x85].N.Operands[0].O64 = 1;
	BaseSet[0x85].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x85].N.Operands[1].O16 = 1;
	BaseSet[0x85].N.Operands[1].O32 = 1;
	BaseSet[0x85].N.Operands[1].O64 = 1;
	BaseSet[0x85].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x86].Type = x86_x64InstructionType_Normal;
	BaseSet[0x86].Behaviour = InstructionBehaviour_Xchg;
	BaseSet[0x86].Lockable = 1;

	BaseSet[0x86].N.Operands[0].O8 = 1;
	BaseSet[0x86].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x86].N.Operands[1].O8 = 1;
	BaseSet[0x86].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x87].Type = x86_x64InstructionType_Normal;
	BaseSet[0x87].Behaviour = InstructionBehaviour_Xchg;
	BaseSet[0x87].Lockable = 1;

	BaseSet[0x87].N.Operands[0].O16 = 1;
	BaseSet[0x87].N.Operands[0].O32 = 1;
	BaseSet[0x87].N.Operands[0].O64 = 1;
	BaseSet[0x87].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x87].N.Operands[1].O16 = 1;
	BaseSet[0x87].N.Operands[1].O32 = 1;
	BaseSet[0x87].N.Operands[1].O64 = 1;
	BaseSet[0x87].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x88].Type = x86_x64InstructionType_Normal;
	BaseSet[0x88].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x88].N.Operands[0].O8 = 1;
	BaseSet[0x88].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x88].N.Operands[1].O8 = 1;
	BaseSet[0x88].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x89].Type = x86_x64InstructionType_Normal;
	BaseSet[0x89].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x89].N.Operands[0].O16 = 1;
	BaseSet[0x89].N.Operands[0].O32 = 1;
	BaseSet[0x89].N.Operands[0].O64 = 1;
	BaseSet[0x89].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x89].N.Operands[1].O16 = 1;
	BaseSet[0x89].N.Operands[1].O32 = 1;
	BaseSet[0x89].N.Operands[1].O64 = 1;
	BaseSet[0x89].N.Operands[1].Type = x86_x64OperandType_R;

	BaseSet[0x8A].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8A].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8A].N.Operands[0].O8 = 1;
	BaseSet[0x8A].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x8A].N.Operands[1].O8 = 1;
	BaseSet[0x8A].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8B].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8B].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8B].N.Operands[0].O16 = 1;
	BaseSet[0x8B].N.Operands[0].O32 = 1;
	BaseSet[0x8B].N.Operands[0].O64 = 1;
	BaseSet[0x8B].N.Operands[0].Type = x86_x64OperandType_R;

	BaseSet[0x8B].N.Operands[1].O16 = 1;
	BaseSet[0x8B].N.Operands[1].O32 = 1;
	BaseSet[0x8B].N.Operands[1].O64 = 1;
	BaseSet[0x8B].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8C].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	BaseSet[0x8C].RG.A0 = 1;
	BaseSet[0x8C].RG.A3 = 1;

	BaseSet[0x8C].RG.H0 = 1;
	BaseSet[0x8C].RG.H3 = 1;

	BaseSet[0x8C].R.Index = INDEX_BUFFER(&BaseSet[0x8C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Segment;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Segment;

	BaseSet[0x8D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8D].Behaviour = InstructionBehaviour_Lea;

	BaseSet[0x8D].N.Operands[0].O16 = 1;
	BaseSet[0x8D].N.Operands[0].O32 = 1;
	BaseSet[0x8D].N.Operands[0].O64 = 1;

	BaseSet[0x8D].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0x8D].RG.A0 = 1;

	BaseSet[0x8D].RG.H0 = 1;
	BaseSet[0x8D].RG.H3 = 1;

	BaseSet[0x8D].RG.Index = INDEX_BUFFER(&BaseSet[0x8D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lea;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x8E].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0x8E].N.Operands[0].IM = 1;
	BaseSet[0x8E].N.Operands[0].O16 = 1;
	BaseSet[0x8E].N.Operands[0].Type = x86_x64OperandType_R;
	BaseSet[0x8E].N.Operands[0].RType = x86_x64RegisterType_Segment;

	BaseSet[0x8E].N.Operands[1].O16 = 1;
	BaseSet[0x8E].N.Operands[1].Type = x86_x64OperandType_M;

	BaseSet[0x8F].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0x8F].R.A0 = 1;

	BaseSet[0x8F].R.Index = INDEX_BUFFER(&BaseSet[0x8F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pop;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x90].Type = x86_x64InstructionType_Normal;
	BaseSet[0x90].Behaviour = InstructionBehaviour_Nop;

	BaseSet[0x91].Type = x86_x64InstructionType_Normal;
	BaseSet[0x91].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x91].N.Operands[0].O16 = 1;
	BaseSet[0x91].N.Operands[0].O32 = 1;
	BaseSet[0x91].N.Operands[0].O64 = 1;
	BaseSet[0x91].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0x91].N.Operands[1].IM = 1;
	BaseSet[0x91].N.Operands[1].O16 = 1;
	BaseSet[0x91].N.Operands[1].O32 = 1;
	BaseSet[0x91].N.Operands[1].O64 = 1;
	BaseSet[0x91].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x92].Type = x86_x64InstructionType_Normal;
	BaseSet[0x92].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x92].N.Operands[0].O16 = 1;
	BaseSet[0x92].N.Operands[0].O32 = 1;
	BaseSet[0x92].N.Operands[0].O64 = 1;
	BaseSet[0x92].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0x92].N.Operands[1].IM = 1;
	BaseSet[0x92].N.Operands[1].O16 = 1;
	BaseSet[0x92].N.Operands[1].O32 = 1;
	BaseSet[0x92].N.Operands[1].O64 = 1;
	BaseSet[0x92].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x93].Type = x86_x64InstructionType_Normal;
	BaseSet[0x93].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x93].N.Operands[0].O16 = 1;
	BaseSet[0x93].N.Operands[0].O32 = 1;
	BaseSet[0x93].N.Operands[0].O64 = 1;
	BaseSet[0x93].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0x93].N.Operands[1].IM = 1;
	BaseSet[0x93].N.Operands[1].O16 = 1;
	BaseSet[0x93].N.Operands[1].O32 = 1;
	BaseSet[0x93].N.Operands[1].O64 = 1;
	BaseSet[0x93].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x94].Type = x86_x64InstructionType_Normal;
	BaseSet[0x94].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x94].N.Operands[0].O16 = 1;
	BaseSet[0x94].N.Operands[0].O32 = 1;
	BaseSet[0x94].N.Operands[0].O64 = 1;
	BaseSet[0x94].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0x94].N.Operands[1].IM = 1;
	BaseSet[0x94].N.Operands[1].O16 = 1;
	BaseSet[0x94].N.Operands[1].O32 = 1;
	BaseSet[0x94].N.Operands[1].O64 = 1;
	BaseSet[0x94].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x95].Type = x86_x64InstructionType_Normal;
	BaseSet[0x95].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x95].N.Operands[0].O16 = 1;
	BaseSet[0x95].N.Operands[0].O32 = 1;
	BaseSet[0x95].N.Operands[0].O64 = 1;
	BaseSet[0x95].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0x95].N.Operands[1].IM = 1;
	BaseSet[0x95].N.Operands[1].O16 = 1;
	BaseSet[0x95].N.Operands[1].O32 = 1;
	BaseSet[0x95].N.Operands[1].O64 = 1;
	BaseSet[0x95].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x96].Type = x86_x64InstructionType_Normal;
	BaseSet[0x96].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x96].N.Operands[0].O16 = 1;
	BaseSet[0x96].N.Operands[0].O32 = 1;
	BaseSet[0x96].N.Operands[0].O64 = 1;
	BaseSet[0x96].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0x96].N.Operands[1].IM = 1;
	BaseSet[0x96].N.Operands[1].O16 = 1;
	BaseSet[0x96].N.Operands[1].O32 = 1;
	BaseSet[0x96].N.Operands[1].O64 = 1;
	BaseSet[0x96].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x97].Type = x86_x64InstructionType_Normal;
	BaseSet[0x97].Behaviour = InstructionBehaviour_Xchg;

	BaseSet[0x97].N.Operands[0].O16 = 1;
	BaseSet[0x97].N.Operands[0].O32 = 1;
	BaseSet[0x97].N.Operands[0].O64 = 1;
	BaseSet[0x97].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0x97].N.Operands[1].IM = 1;
	BaseSet[0x97].N.Operands[1].O16 = 1;
	BaseSet[0x97].N.Operands[1].O32 = 1;
	BaseSet[0x97].N.Operands[1].O64 = 1;
	BaseSet[0x97].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x98].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x98].RP.A0 = 1;
	BaseSet[0x98].RP.A2 = 1;
	BaseSet[0x98].RP.DC = 1;

	BaseSet[0x98].RP.Index = INDEX_BUFFER(&BaseSet[0x98], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cdq;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cbw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cwd;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x99].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0x99].RP.A0 = 1;
	BaseSet[0x99].RP.A2 = 1;
	BaseSet[0x99].RP.DC = 1;

	BaseSet[0x99].RP.Index = INDEX_BUFFER(&BaseSet[0x99], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cqo;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cbw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cwd;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0x9B].Type = x86_x64InstructionType_Prefix;
	BaseSet[0x9B].Behaviour = InstructionBehaviour_Fwait;

	BaseSet[0x9B].P.Prefix.WAIT = 1;

	BaseSet[0x9C].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9C].Behaviour = InstructionBehaviour_Pushf;

	BaseSet[0x9D].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9D].Behaviour = InstructionBehaviour_Popf;

	BaseSet[0x9E].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9E].Behaviour = InstructionBehaviour_Sahf;

	BaseSet[0x9F].Type = x86_x64InstructionType_Normal;
	BaseSet[0x9F].Behaviour = InstructionBehaviour_Lahf;

	BaseSet[0xA0].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA0].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA0].N.Operands[0].IM = 1;
	BaseSet[0xA0].N.Operands[0].O8 = 1;
	BaseSet[0xA0].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA0].N.Operands[1].O8 = 1;
	BaseSet[0xA0].N.Operands[1].DSO = 1;
	BaseSet[0xA0].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA1].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA1].N.Operands[0].IM = 1;
	BaseSet[0xA1].N.Operands[0].O16 = 1;
	BaseSet[0xA1].N.Operands[0].O32 = 1;
	BaseSet[0xA1].N.Operands[0].O64 = 1;
	BaseSet[0xA1].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA1].N.Operands[1].O16 = 1;
	BaseSet[0xA1].N.Operands[1].O32 = 1;
	BaseSet[0xA1].N.Operands[1].O64 = 1;
	BaseSet[0xA1].N.Operands[1].DSO = 1;
	BaseSet[0xA1].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA2].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA2].N.Operands[0].O8 = 1;
	BaseSet[0xA2].N.Operands[0].DSO = 1;
	BaseSet[0xA2].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xA2].N.Operands[1].IM = 1;
	BaseSet[0xA2].N.Operands[1].O8 = 1;
	BaseSet[0xA2].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xA3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA3].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xA3].N.Operands[0].O16 = 1;
	BaseSet[0xA3].N.Operands[0].O32 = 1;
	BaseSet[0xA3].N.Operands[0].O64 = 1;
	BaseSet[0xA3].N.Operands[0].DSO = 1;
	BaseSet[0xA3].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xA3].N.Operands[1].IM = 1;
	BaseSet[0xA3].N.Operands[1].O16 = 1;
	BaseSet[0xA3].N.Operands[1].O32 = 1;
	BaseSet[0xA3].N.Operands[1].O64 = 1;
	BaseSet[0xA3].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xA4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xA4].RP.A3 = 1;
	BaseSet[0xA4].RP.A4 = 1;
	BaseSet[0xA4].RP.DC = 1;

	BaseSet[0xA4].RP.Index = INDEX_BUFFER(&BaseSet[0xA4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_SI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_SI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA5].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xA5].RP.A3 = 1;
	BaseSet[0xA5].RP.A4 = 1;
	BaseSet[0xA5].RP.DC = 1;

	BaseSet[0xA5].RG.Index = INDEX_BUFFER(&BaseSet[0xA5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_SI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_SI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movs;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA6].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA6].Behaviour = InstructionBehaviour_Cmps;
	BaseSet[0xA6].Repeatable = 1;

	BaseSet[0xA6].N.Operands[0].IM = 1;
	BaseSet[0xA6].N.Operands[0].O8 = 1;
	BaseSet[0xA6].N.Operands[0].DSO = 1;
	BaseSet[0xA6].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA6].N.Operands[1].IM = 1;
	BaseSet[0xA6].N.Operands[1].O8 = 1;
	BaseSet[0xA6].N.Operands[1].DSO = 1;
	BaseSet[0xA6].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA7].Behaviour = InstructionBehaviour_Cmps;
	BaseSet[0xA7].Repeatable = 1;

	BaseSet[0xA7].N.Operands[0].IM = 1;
	BaseSet[0xA7].N.Operands[0].O16 = 1;
	BaseSet[0xA7].N.Operands[0].O32 = 1;
	BaseSet[0xA7].N.Operands[0].O64 = 1;
	BaseSet[0xA7].N.Operands[0].DSO = 1;
	BaseSet[0xA7].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xA7].N.Operands[1].IM = 1;
	BaseSet[0xA7].N.Operands[1].O16 = 1;
	BaseSet[0xA7].N.Operands[1].O32 = 1;
	BaseSet[0xA7].N.Operands[1].O64 = 1;
	BaseSet[0xA7].N.Operands[1].DSO = 1;
	BaseSet[0xA7].N.Operands[1].Type = x86_x64OperandType_SI;

	BaseSet[0xA8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA8].Behaviour = InstructionBehaviour_Test;

	BaseSet[0xA8].N.Operands[0].IM = 1;
	BaseSet[0xA8].N.Operands[0].O8 = 1;
	BaseSet[0xA8].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA8].N.Operands[1].O8 = 1;
	BaseSet[0xA8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xA9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xA9].Behaviour = InstructionBehaviour_Test;

	BaseSet[0xA9].N.Operands[0].IM = 1;
	BaseSet[0xA9].N.Operands[0].O16 = 1;
	BaseSet[0xA9].N.Operands[0].O32 = 1;
	BaseSet[0xA9].N.Operands[0].O64 = 1;
	BaseSet[0xA9].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xA9].N.Operands[1].O16 = 1;
	BaseSet[0xA9].N.Operands[1].O32 = 1;
	BaseSet[0xA9].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xAA].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xAA].RP.A3 = 1;
	BaseSet[0xAA].RP.A4 = 1;
	BaseSet[0xAA].RP.DC = 1;

	BaseSet[0xAA].RG.Index = INDEX_BUFFER(&BaseSet[0xAA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAB].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xAB].RP.A3 = 1;
	BaseSet[0xAB].RP.A4 = 1;
	BaseSet[0xAB].RP.DC = 1;

	BaseSet[0xAB].RG.Index = INDEX_BUFFER(&BaseSet[0xAB], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].DSO = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].DSO = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Stos;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].DSO = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_DI;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAC].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xAC].RP.A3 = 1;
	BaseSet[0xAC].RP.A4 = 1;
	BaseSet[0xAC].RP.DC = 1;

	BaseSet[0xAC].RG.Index = INDEX_BUFFER(&BaseSet[0xAC], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0xAD].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	BaseSet[0xAD].RP.A3 = 1;
	BaseSet[0xAD].RP.A4 = 1;
	BaseSet[0xAD].RP.DC = 1;

	BaseSet[0xAD].RG.Index = INDEX_BUFFER(&BaseSet[0xAD], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x00].Repeatable = 1;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].DSO = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x01].Repeatable = 1;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].DSO = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DI;

	SubSet[0x01].N.Operands[2].IM = 1;
	SubSet[0x01].N.Operands[2].O32 = 1;
	SubSet[0x01].N.Operands[2].O64 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Lods;
	SubSet[0x02].Repeatable = 1;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O16 = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].DSO = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_DI;

	BaseSet[0xAE].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAE].Behaviour = InstructionBehaviour_Scas;
	BaseSet[0xAE].Repeatable = 1;

	BaseSet[0xAE].N.Operands[0].IM = 1;
	BaseSet[0xAE].N.Operands[0].O8 = 1;
	BaseSet[0xAE].N.Operands[0].DSO = 1;
	BaseSet[0xAE].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAE].N.Operands[1].IM = 1;
	BaseSet[0xAE].N.Operands[1].O8 = 1;
	BaseSet[0xAE].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xAF].Type = x86_x64InstructionType_Normal;
	BaseSet[0xAF].Behaviour = InstructionBehaviour_Scas;
	BaseSet[0xAF].Repeatable = 1;

	BaseSet[0xAF].N.Operands[0].IM = 1;
	BaseSet[0xAF].N.Operands[0].O16 = 1;
	BaseSet[0xAF].N.Operands[0].O32 = 1;
	BaseSet[0xAF].N.Operands[0].O64 = 1;
	BaseSet[0xAF].N.Operands[0].DSO = 1;
	BaseSet[0xAF].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xAF].N.Operands[1].IM = 1;
	BaseSet[0xAF].N.Operands[1].O16 = 1;
	BaseSet[0xAF].N.Operands[1].O32 = 1;
	BaseSet[0xAF].N.Operands[1].O64 = 1;
	BaseSet[0xAF].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xB0].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB0].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB0].N.Operands[0].O8 = 1;
	BaseSet[0xB0].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xB0].N.Operands[1].O8 = 1;
	BaseSet[0xB0].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB1].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB1].N.Operands[0].O8 = 1;
	BaseSet[0xB1].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xB1].N.Operands[1].O8 = 1;
	BaseSet[0xB1].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB2].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB2].N.Operands[0].O8 = 1;
	BaseSet[0xB2].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xB2].N.Operands[1].O8 = 1;
	BaseSet[0xB2].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB3].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB3].N.Operands[0].O8 = 1;
	BaseSet[0xB3].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0xB3].N.Operands[1].O8 = 1;
	BaseSet[0xB3].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB4].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB4].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB4].N.Operands[0].O8 = 1;
	BaseSet[0xB4].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0xB4].N.Operands[1].O8 = 1;
	BaseSet[0xB4].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB5].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB5].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB5].N.Operands[0].O8 = 1;
	BaseSet[0xB5].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xB5].N.Operands[1].O8 = 1;
	BaseSet[0xB5].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB6].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB6].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB6].N.Operands[0].O8 = 1;
	BaseSet[0xB6].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0xB6].N.Operands[1].O8 = 1;
	BaseSet[0xB6].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB7].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB7].N.Operands[0].O8 = 1;
	BaseSet[0xB7].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xB7].N.Operands[1].O8 = 1;
	BaseSet[0xB7].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB8].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB8].N.Operands[0].O16 = 1;
	BaseSet[0xB8].N.Operands[0].O32 = 1;
	BaseSet[0xB8].N.Operands[0].O64 = 1;
	BaseSet[0xB8].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xB8].N.Operands[1].O16 = 1;
	BaseSet[0xB8].N.Operands[1].O32 = 1;
	BaseSet[0xB8].N.Operands[1].O64 = 1;
	BaseSet[0xB8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xB9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xB9].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xB9].N.Operands[0].O16 = 1;
	BaseSet[0xB9].N.Operands[0].O32 = 1;
	BaseSet[0xB9].N.Operands[0].O64 = 1;
	BaseSet[0xB9].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xB9].N.Operands[1].O16 = 1;
	BaseSet[0xB9].N.Operands[1].O32 = 1;
	BaseSet[0xB9].N.Operands[1].O64 = 1;
	BaseSet[0xB9].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBA].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBA].N.Operands[0].O16 = 1;
	BaseSet[0xBA].N.Operands[0].O32 = 1;
	BaseSet[0xBA].N.Operands[0].O64 = 1;
	BaseSet[0xBA].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xBA].N.Operands[1].O16 = 1;
	BaseSet[0xBA].N.Operands[1].O32 = 1;
	BaseSet[0xBA].N.Operands[1].O64 = 1;
	BaseSet[0xBA].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBB].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBB].N.Operands[0].O16 = 1;
	BaseSet[0xBB].N.Operands[0].O32 = 1;
	BaseSet[0xBB].N.Operands[0].O64 = 1;
	BaseSet[0xBB].N.Operands[0].Type = x86_x64OperandType_BX;

	BaseSet[0xBB].N.Operands[1].O16 = 1;
	BaseSet[0xBB].N.Operands[1].O32 = 1;
	BaseSet[0xBB].N.Operands[1].O64 = 1;
	BaseSet[0xBB].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBC].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBC].N.Operands[0].O16 = 1;
	BaseSet[0xBC].N.Operands[0].O32 = 1;
	BaseSet[0xBC].N.Operands[0].O64 = 1;
	BaseSet[0xBC].N.Operands[0].Type = x86_x64OperandType_SP;

	BaseSet[0xBC].N.Operands[1].O16 = 1;
	BaseSet[0xBC].N.Operands[1].O32 = 1;
	BaseSet[0xBC].N.Operands[1].O64 = 1;
	BaseSet[0xBC].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBD].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBD].N.Operands[0].O16 = 1;
	BaseSet[0xBD].N.Operands[0].O32 = 1;
	BaseSet[0xBD].N.Operands[0].O64 = 1;
	BaseSet[0xBD].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xBD].N.Operands[1].O16 = 1;
	BaseSet[0xBD].N.Operands[1].O32 = 1;
	BaseSet[0xBD].N.Operands[1].O64 = 1;
	BaseSet[0xBD].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBE].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBE].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBE].N.Operands[0].O16 = 1;
	BaseSet[0xBE].N.Operands[0].O32 = 1;
	BaseSet[0xBE].N.Operands[0].O64 = 1;
	BaseSet[0xBE].N.Operands[0].Type = x86_x64OperandType_SI;

	BaseSet[0xBE].N.Operands[1].O16 = 1;
	BaseSet[0xBE].N.Operands[1].O32 = 1;
	BaseSet[0xBE].N.Operands[1].O64 = 1;
	BaseSet[0xBE].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xBF].Type = x86_x64InstructionType_Normal;
	BaseSet[0xBF].Behaviour = InstructionBehaviour_Mov;

	BaseSet[0xBF].N.Operands[0].O16 = 1;
	BaseSet[0xBF].N.Operands[0].O32 = 1;
	BaseSet[0xBF].N.Operands[0].O64 = 1;
	BaseSet[0xBF].N.Operands[0].Type = x86_x64OperandType_DI;

	BaseSet[0xBF].N.Operands[1].O16 = 1;
	BaseSet[0xBF].N.Operands[1].O32 = 1;
	BaseSet[0xBF].N.Operands[1].O64 = 1;
	BaseSet[0xBF].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC0].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xC0].R.A0 = 1;
	BaseSet[0xC0].R.A1 = 1;
	BaseSet[0xC0].R.A2 = 1;
	BaseSet[0xC0].R.A3 = 1;
	BaseSet[0xC0].R.A4 = 1;
	BaseSet[0xC0].R.A5 = 1;
	BaseSet[0xC0].R.A6 = 1;
	BaseSet[0xC0].R.A7 = 1;

	BaseSet[0xC0].R.Index = INDEX_BUFFER(&BaseSet[0xC0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC1].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xC1].R.A0 = 1;
	BaseSet[0xC1].R.A1 = 1;
	BaseSet[0xC1].R.A2 = 1;
	BaseSet[0xC1].R.A3 = 1;
	BaseSet[0xC1].R.A4 = 1;
	BaseSet[0xC1].R.A5 = 1;
	BaseSet[0xC1].R.A6 = 1;
	BaseSet[0xC1].R.A7 = 1;

	BaseSet[0xC1].R.Index = INDEX_BUFFER(&BaseSet[0xC1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC2].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xC2].N.Operands[0].O16 = 1;
	BaseSet[0xC2].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xC3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC3].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xC6].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0xC6].R.A0 = 1;

	BaseSet[0xC6].R.Index = INDEX_BUFFER(&BaseSet[0xC6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC7].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	BaseSet[0xC7].R.A0 = 1;

	BaseSet[0xC7].R.Index = INDEX_BUFFER(&BaseSet[0xC7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC8].Behaviour = InstructionBehaviour_Enter;

	BaseSet[0xC8].N.Operands[0].IM = 1;
	BaseSet[0xC8].N.Operands[0].O16 = 1;
	BaseSet[0xC8].N.Operands[0].O64 = 1;
	BaseSet[0xC8].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xC8].N.Operands[1].O16 = 1;
	BaseSet[0xC8].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xC8].N.Operands[2].O8 = 1;
	BaseSet[0xC8].N.Operands[2].Type = x86_x64OperandType_IMM;

	BaseSet[0xC9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xC9].Behaviour = InstructionBehaviour_Leave;

	BaseSet[0xC9].N.Operands[0].IM = 1;
	BaseSet[0xC9].N.Operands[0].O16 = 1;
	BaseSet[0xC9].N.Operands[0].O64 = 1;
	BaseSet[0xC9].N.Operands[0].Type = x86_x64OperandType_BP;

	BaseSet[0xCA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCA].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xCA].N.Operands[0].O16 = 1;
	BaseSet[0xCA].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xCB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCB].Behaviour = InstructionBehaviour_Ret;

	BaseSet[0xCC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCC].Behaviour = InstructionBehaviour_Int;

	BaseSet[0xCC].N.Operands[0].O8 = 1;
	BaseSet[0xCC].N.Operands[0].Value = 3;
	BaseSet[0xCC].N.Operands[0].Type = x86_x64OperandType_Value;

	BaseSet[0xCD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xCD].Behaviour = InstructionBehaviour_Int;

	BaseSet[0xCD].N.Operands[0].O8 = 1;
	BaseSet[0xCD].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xCF].Type = x86_x64InstructionType_OperandLess;
	BaseSet[0xCF].Behaviour = InstructionBehaviour_Iret;

	BaseSet[0xCF].OL.O16 = 1;
	BaseSet[0xCF].OL.O32 = 1;
	BaseSet[0xCF].OL.O64 = 1;

	BaseSet[0xD0].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD0].R.A0 = 1;
	BaseSet[0xD0].R.A1 = 1;
	BaseSet[0xD0].R.A2 = 1;
	BaseSet[0xD0].R.A3 = 1;
	BaseSet[0xD0].R.A4 = 1;
	BaseSet[0xD0].R.A5 = 1;
	BaseSet[0xD0].R.A6 = 1;
	BaseSet[0xD0].R.A7 = 1;

	BaseSet[0xD0].R.Index = INDEX_BUFFER(&BaseSet[0xD0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Value = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Value = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Value = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Value = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Value = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Value = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Value = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Value = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_Value;

	BaseSet[0xD1].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD1].R.A0 = 1;
	BaseSet[0xD1].R.A1 = 1;
	BaseSet[0xD1].R.A2 = 1;
	BaseSet[0xD1].R.A3 = 1;
	BaseSet[0xD1].R.A4 = 1;
	BaseSet[0xD1].R.A5 = 1;
	BaseSet[0xD1].R.A6 = 1;
	BaseSet[0xD1].R.A7 = 1;

	BaseSet[0xD1].R.Index = INDEX_BUFFER(&BaseSet[0xD1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Value = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Value = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Value = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Value = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Value = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Value = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Value = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_Value;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Value = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_Value;

	BaseSet[0xD2].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD2].R.A0 = 1;
	BaseSet[0xD2].R.A1 = 1;
	BaseSet[0xD2].R.A2 = 1;
	BaseSet[0xD2].R.A3 = 1;
	BaseSet[0xD2].R.A4 = 1;
	BaseSet[0xD2].R.A5 = 1;
	BaseSet[0xD2].R.A6 = 1;
	BaseSet[0xD2].R.A7 = 1;

	BaseSet[0xD2].R.Index = INDEX_BUFFER(&BaseSet[0xD2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O8 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].IM = 1;
	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O8 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].IM = 1;
	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].IM = 1;
	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].IM = 1;
	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_CX;

	BaseSet[0xD3].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD3].R.A0 = 1;
	BaseSet[0xD3].R.A1 = 1;
	BaseSet[0xD3].R.A2 = 1;
	BaseSet[0xD3].R.A3 = 1;
	BaseSet[0xD3].R.A4 = 1;
	BaseSet[0xD3].R.A5 = 1;
	BaseSet[0xD3].R.A6 = 1;
	BaseSet[0xD3].R.A7 = 1;

	BaseSet[0xD3].R.Index = INDEX_BUFFER(&BaseSet[0xD3], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rol;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ror;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Rcl;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O8 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Rcr;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O8 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].N.Operands[1].IM = 1;
	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Shr;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].N.Operands[1].IM = 1;
	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Shl;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].N.Operands[1].IM = 1;
	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_CX;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Sar;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].N.Operands[1].IM = 1;
	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_CX;

	BaseSet[0xD7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xD7].Behaviour = InstructionBehaviour_Xlat;

	BaseSet[0xD7].N.Operands[0].IM = 1;
	BaseSet[0xD7].N.Operands[0].O8 = 1;
	BaseSet[0xD7].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xD7].N.Operands[1].IM = 1;
	BaseSet[0xD7].N.Operands[1].O8 = 1;
	BaseSet[0xD7].N.Operands[1].DSO = 1;
	BaseSet[0xD7].N.Operands[1].Type = x86_x64OperandType_BX;

	BaseSet[0xD8].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD8].R.A0 = 1;
	BaseSet[0xD8].R.A1 = 1;
	BaseSet[0xD8].R.A2 = 1;
	BaseSet[0xD8].R.A3 = 1;
	BaseSet[0xD8].R.A4 = 1;
	BaseSet[0xD8].R.A5 = 1;
	BaseSet[0xD8].R.A6 = 1;
	BaseSet[0xD8].R.A7 = 1;

	BaseSet[0xD8].R.Index = INDEX_BUFFER(&BaseSet[0xD8], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Fadd;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Fmul;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Fcom;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Fcomp;

	SubSet[0x03].N.Operands[0].IM = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O32 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Fsub;

	SubSet[0x04].N.Operands[0].IM = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x04].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].N.Operands[1].IM = 1;
	SubSet[0x04].N.Operands[1].O32 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x04].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Fsubr;

	SubSet[0x05].N.Operands[0].IM = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x05].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].N.Operands[1].IM = 1;
	SubSet[0x05].N.Operands[1].O32 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x05].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Fdiv;

	SubSet[0x06].N.Operands[0].IM = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x06].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].N.Operands[1].IM = 1;
	SubSet[0x06].N.Operands[1].O32 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x06].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Fdivr;

	SubSet[0x07].N.Operands[0].IM = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x07].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].N.Operands[1].IM = 1;
	SubSet[0x07].N.Operands[1].O32 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x07].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xD9].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xD9].R.A0 = 1;
	BaseSet[0xD9].R.A1 = 1;
	BaseSet[0xD9].R.A2 = 1;
	BaseSet[0xD9].R.A3 = 1;
	BaseSet[0xD9].R.A4 = 1;
	BaseSet[0xD9].R.A5 = 1;
	BaseSet[0xD9].R.A6 = 1;
	BaseSet[0xD9].R.A7 = 1;

	BaseSet[0xD9].R.Index = INDEX_BUFFER(&BaseSet[0xD9], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Fld;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fxch;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fst;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x01].R.A0 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fnop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A0 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fstp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fldenv;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fchs;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fabs;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Ftst;

	L3SubSet[0x02].N.Operands[0].IM = 1;
	L3SubSet[0x02].N.Operands[0].O32 = 1;
	L3SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Fxam;

	L3SubSet[0x03].N.Operands[0].IM = 1;
	L3SubSet[0x03].N.Operands[0].O32 = 1;
	L3SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fldcw;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 7);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fld1;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fldl2t;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Fldl2e;

	L3SubSet[0x02].N.Operands[0].IM = 1;
	L3SubSet[0x02].N.Operands[0].O32 = 1;
	L3SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Fldpi;

	L3SubSet[0x03].N.Operands[0].IM = 1;
	L3SubSet[0x03].N.Operands[0].O32 = 1;
	L3SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Fldlg2;

	L3SubSet[0x04].N.Operands[0].IM = 1;
	L3SubSet[0x04].N.Operands[0].O32 = 1;
	L3SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x04].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Fldln2;

	L3SubSet[0x05].N.Operands[0].IM = 1;
	L3SubSet[0x05].N.Operands[0].O32 = 1;
	L3SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x05].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x06].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x06].Behaviour = InstructionBehaviour_Fldz;

	L3SubSet[0x06].N.Operands[0].IM = 1;
	L3SubSet[0x06].N.Operands[0].O32 = 1;
	L3SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x06].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x06].RG.A0 = 1;
	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A1 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fstenv;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fnstenv;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;
	L2SubSet[0x01].R.A7 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_F2xm1;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fyl2x;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_CX;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].N.Operands[1].IM = 1;
	L3SubSet[0x01].N.Operands[1].O32 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L3SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Fptan;

	L3SubSet[0x02].N.Operands[0].IM = 1;
	L3SubSet[0x02].N.Operands[0].O32 = 1;
	L3SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Fpatan;

	L3SubSet[0x03].N.Operands[0].IM = 1;
	L3SubSet[0x03].N.Operands[0].O32 = 1;
	L3SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_CX;
	L3SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x03].N.Operands[1].IM = 1;
	L3SubSet[0x03].N.Operands[1].O32 = 1;
	L3SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_AX;
	L3SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Fxtract;

	L3SubSet[0x04].N.Operands[0].IM = 1;
	L3SubSet[0x04].N.Operands[0].O32 = 1;
	L3SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x04].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Fprem1;

	L3SubSet[0x05].N.Operands[0].IM = 1;
	L3SubSet[0x05].N.Operands[0].O32 = 1;
	L3SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x05].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x05].N.Operands[1].IM = 1;
	L3SubSet[0x05].N.Operands[1].O32 = 1;
	L3SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_CX;
	L3SubSet[0x05].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x06].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x06].Behaviour = InstructionBehaviour_Fdecstp;

	L3SubSet[0x07].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x07].Behaviour = InstructionBehaviour_Fincstp;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x07].RG.A0 = 1;
	SubSet[0x07].RG.A3 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A1 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fstcw;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fnstcw;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;
	L2SubSet[0x01].R.A7 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fprem;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x00].N.Operands[1].IM = 1;
	L3SubSet[0x00].N.Operands[1].O32 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_CX;
	L3SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fyl2xp1;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_CX;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].N.Operands[1].IM = 1;
	L3SubSet[0x01].N.Operands[1].O32 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L3SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Fsqrt;

	L3SubSet[0x02].N.Operands[0].IM = 1;
	L3SubSet[0x02].N.Operands[0].O32 = 1;
	L3SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Fsincos;

	L3SubSet[0x03].N.Operands[0].IM = 1;
	L3SubSet[0x03].N.Operands[0].O32 = 1;
	L3SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Frndint;

	L3SubSet[0x04].N.Operands[0].IM = 1;
	L3SubSet[0x04].N.Operands[0].O32 = 1;
	L3SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x04].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Fscale;

	L3SubSet[0x05].N.Operands[0].IM = 1;
	L3SubSet[0x05].N.Operands[0].O32 = 1;
	L3SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x05].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x05].N.Operands[1].IM = 1;
	L3SubSet[0x05].N.Operands[1].O32 = 1;
	L3SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_CX;
	L3SubSet[0x05].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x06].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x06].Behaviour = InstructionBehaviour_Fsin;

	L3SubSet[0x06].N.Operands[0].IM = 1;
	L3SubSet[0x06].N.Operands[0].O32 = 1;
	L3SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x06].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x07].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x07].Behaviour = InstructionBehaviour_Fcos;

	L3SubSet[0x07].N.Operands[0].IM = 1;
	L3SubSet[0x07].N.Operands[0].O32 = 1;
	L3SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x07].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDA].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDA].R.A0 = 1;
	BaseSet[0xDA].R.A1 = 1;
	BaseSet[0xDA].R.A2 = 1;
	BaseSet[0xDA].R.A3 = 1;
	BaseSet[0xDA].R.A4 = 1;
	BaseSet[0xDA].R.A5 = 1;
	BaseSet[0xDA].R.A6 = 1;
	BaseSet[0xDA].R.A7 = 1;

	BaseSet[0xDA].R.Index = INDEX_BUFFER(&BaseSet[0xDA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fiadd;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovb;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fimul;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmove;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Ficom;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovbe;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Ficomp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovu;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x04].RG.A0 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisub;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisubr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x01].R.A1 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fucompp;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x00].N.Operands[1].IM = 1;
	L3SubSet[0x00].N.Operands[1].O32 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_CX;
	L3SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x06].RG.A0 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fidiv;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x07].RG.A0 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fidivr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDB].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDB].R.A0 = 1;
	BaseSet[0xDB].R.A1 = 1;
	BaseSet[0xDB].R.A2 = 1;
	BaseSet[0xDB].R.A3 = 1;
	BaseSet[0xDB].R.A4 = 1;
	BaseSet[0xDB].R.A5 = 1;
	BaseSet[0xDB].R.A6 = 1;
	BaseSet[0xDB].R.A7 = 1;

	BaseSet[0xDB].R.Index = INDEX_BUFFER(&BaseSet[0xDB], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fild;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovnb;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisttp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovne;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fist;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovnbe;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fistp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcmovnu;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H1 = 1;
	SubSet[0x04].RG.H2 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].R.A2 = 1;
	L2SubSet[0x00].R.A3 = 1;

	L2SubSet[0x00].RG.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x00].RP.A1 = 1;
	L3SubSet[0x00].RP.DC = 1;

	L3SubSet[0x00].RG.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Fclex;

	L4SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x01].Behaviour = InstructionBehaviour_Fnclex;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x01].RP.A1 = 1;
	L3SubSet[0x01].RP.DC = 1;

	L3SubSet[0x01].RG.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Finit;

	L4SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x01].Behaviour = InstructionBehaviour_Fninit;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fld;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O80 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fucomi;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H1 = 1;
	SubSet[0x06].RG.H2 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fcomi;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x07].RG.A0 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fstp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O80 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O80 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDC].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDC].R.A0 = 1;
	BaseSet[0xDC].R.A1 = 1;
	BaseSet[0xDC].R.A2 = 1;
	BaseSet[0xDC].R.A3 = 1;
	BaseSet[0xDC].R.A4 = 1;
	BaseSet[0xDC].R.A5 = 1;
	BaseSet[0xDC].R.A6 = 1;
	BaseSet[0xDC].R.A7 = 1;

	BaseSet[0xDC].R.Index = INDEX_BUFFER(&BaseSet[0xDC], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fadd;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fadd;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fmul;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fmul;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Fcom;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Fcomp;

	SubSet[0x03].N.Operands[0].IM = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_AX;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O64 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fsub;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fsubr;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fsubr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fsub;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x06].RG.A0 = 1;
	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fdiv;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fdivr;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x07].RG.A0 = 1;
	SubSet[0x07].RG.A3 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fdivr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fdiv;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDD].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDD].R.A0 = 1;
	BaseSet[0xDD].R.A1 = 1;
	BaseSet[0xDD].R.A2 = 1;
	BaseSet[0xDD].R.A3 = 1;
	BaseSet[0xDD].R.A4 = 1;
	BaseSet[0xDD].R.A5 = 1;
	BaseSet[0xDD].R.A6 = 1;
	BaseSet[0xDD].R.A7 = 1;

	BaseSet[0xDD].R.Index = INDEX_BUFFER(&BaseSet[0xDD], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fld;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Ffree;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisttp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fst;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fst;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fstp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fstp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Frstor;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fucom;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H1 = 1;
	SubSet[0x05].RG.H2 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fucomp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x06].RG.A0 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A1 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fsave;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fnsave;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x07].RG.A0 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A1 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Fstsw;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O16 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Fnstsw;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O16 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDE].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDE].R.A0 = 1;
	BaseSet[0xDE].R.A1 = 1;
	BaseSet[0xDE].R.A2 = 1;
	BaseSet[0xDE].R.A3 = 1;
	BaseSet[0xDE].R.A4 = 1;
	BaseSet[0xDE].R.A5 = 1;
	BaseSet[0xDE].R.A6 = 1;
	BaseSet[0xDE].R.A7 = 1;

	BaseSet[0xDE].R.Index = INDEX_BUFFER(&BaseSet[0xDE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fiadd;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Faddp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A0 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Ficom;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Ficomp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x01].R.A1 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Ficompp;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O16 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L3SubSet[0x00].N.Operands[1].IM = 1;
	L3SubSet[0x00].N.Operands[1].O16 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_DX;
	L3SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisub;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fsubrp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisubr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fsubp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x06].RG.A0 = 1;
	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fidiv;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fdivrp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x07].RG.A0 = 1;
	SubSet[0x07].RG.A3 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fidivr;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fdivp;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xDF].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xDF].R.A0 = 1;
	BaseSet[0xDF].R.A1 = 1;
	BaseSet[0xDF].R.A2 = 1;
	BaseSet[0xDF].R.A3 = 1;
	BaseSet[0xDF].R.A4 = 1;
	BaseSet[0xDF].R.A5 = 1;
	BaseSet[0xDF].R.A6 = 1;
	BaseSet[0xDF].R.A7 = 1;

	BaseSet[0xDF].R.Index = INDEX_BUFFER(&BaseSet[0xDF], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fild;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Ffreep;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fisttp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A0 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fist;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A0 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fistp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fbld;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O80 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O80 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x01].R.A0 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x00].RP.A1 = 1;
	L3SubSet[0x00].RP.DC = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Fstsw;

	L4SubSet[0x00].N.Operands[0].IM = 1;
	L4SubSet[0x00].N.Operands[0].O16 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;

	L4SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x01].Behaviour = InstructionBehaviour_Fnstsw;

	L4SubSet[0x01].N.Operands[0].IM = 1;
	L4SubSet[0x01].N.Operands[0].O16 = 1;
	L4SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fild;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fucomip;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O80 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O80 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x06].RG.A0 = 1;
	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fbstp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O80 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O80 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Fcomip;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O80 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x01].N.Operands[1].IM = 1;
	L2SubSet[0x01].N.Operands[1].O80 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x07].RG.A0 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fistp;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_StackTop;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O32 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_StackTop;

	BaseSet[0xE0].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE0].Behaviour = InstructionBehaviour_Loopnz;

	BaseSet[0xE0].N.Operands[0].IM = 1;
	BaseSet[0xE0].N.Operands[0].O16 = 1;
	BaseSet[0xE0].N.Operands[0].O32 = 1;
	BaseSet[0xE0].N.Operands[0].O64 = 1;
	BaseSet[0xE0].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xE0].N.Operands[1].O8 = 1;
	BaseSet[0xE0].N.Operands[1].Type = x86_x64OperandType_Rel;

	BaseSet[0xE1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE1].Behaviour = InstructionBehaviour_Loopz;

	BaseSet[0xE1].N.Operands[0].IM = 1;
	BaseSet[0xE1].N.Operands[0].O16 = 1;
	BaseSet[0xE1].N.Operands[0].O32 = 1;
	BaseSet[0xE1].N.Operands[0].O64 = 1;
	BaseSet[0xE1].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xE1].N.Operands[1].O8 = 1;
	BaseSet[0xE1].N.Operands[1].Type = x86_x64OperandType_Rel;

	BaseSet[0xE2].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE2].Behaviour = InstructionBehaviour_Loop;

	BaseSet[0xE2].N.Operands[0].IM = 1;
	BaseSet[0xE2].N.Operands[0].O16 = 1;
	BaseSet[0xE2].N.Operands[0].O32 = 1;
	BaseSet[0xE2].N.Operands[0].O64 = 1;
	BaseSet[0xE2].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xE2].N.Operands[1].O8 = 1;
	BaseSet[0xE2].N.Operands[1].Type = x86_x64OperandType_Rel;

	BaseSet[0xE3].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE3].Behaviour = InstructionBehaviour_Je;

	BaseSet[0xE3].N.Operands[0].IM = 1;
	BaseSet[0xE3].N.Operands[0].O64 = 1;
	BaseSet[0xE3].N.Operands[0].Type = x86_x64OperandType_CX;

	BaseSet[0xE3].N.Operands[1].O8 = 1;
	BaseSet[0xE3].N.Operands[1].Type = x86_x64OperandType_Rel;

	BaseSet[0xE4].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE4].Behaviour = InstructionBehaviour_In;

	BaseSet[0xE4].N.Operands[0].IM = 1;
	BaseSet[0xE4].N.Operands[0].O8 = 1;
	BaseSet[0xE4].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xE4].N.Operands[1].O8 = 1;
	BaseSet[0xE4].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xE7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE7].Behaviour = InstructionBehaviour_In;

	BaseSet[0xE7].N.Operands[0].IM = 1;
	BaseSet[0xE7].N.Operands[0].O16 = 1;
	BaseSet[0xE7].N.Operands[0].O32 = 1;
	BaseSet[0xE7].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xE7].N.Operands[1].O8 = 1;
	BaseSet[0xE7].N.Operands[1].Type = x86_x64OperandType_IMM;

	BaseSet[0xE6].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE6].Behaviour = InstructionBehaviour_Out;

	BaseSet[0xE6].N.Operands[0].O8 = 1;
	BaseSet[0xE6].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xE6].N.Operands[1].IM = 1;
	BaseSet[0xE6].N.Operands[1].O8 = 1;
	BaseSet[0xE6].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xE7].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE7].Behaviour = InstructionBehaviour_Out;

	BaseSet[0xE7].N.Operands[0].O8 = 1;
	BaseSet[0xE7].N.Operands[0].Type = x86_x64OperandType_IMM;

	BaseSet[0xE7].N.Operands[1].IM = 1;
	BaseSet[0xE7].N.Operands[1].O16 = 1;
	BaseSet[0xE7].N.Operands[1].O32 = 1;
	BaseSet[0xE7].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xE8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE8].Behaviour = InstructionBehaviour_Call;

	BaseSet[0xE8].N.Operands[0].O16 = 1;
	BaseSet[0xE8].N.Operands[0].O32 = 1;
	BaseSet[0xE8].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0xE9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xE9].Behaviour = InstructionBehaviour_Jmp;

	BaseSet[0xE9].N.Operands[0].O16 = 1;
	BaseSet[0xE9].N.Operands[0].O32 = 1;
	BaseSet[0xE9].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0xEB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xEB].Behaviour = InstructionBehaviour_Jmp;

	BaseSet[0xEB].N.Operands[0].O8 = 1;
	BaseSet[0xEB].N.Operands[0].Type = x86_x64OperandType_Rel;

	BaseSet[0xEC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xEC].Behaviour = InstructionBehaviour_In;

	BaseSet[0xEC].N.Operands[0].IM = 1;
	BaseSet[0xEC].N.Operands[0].O8 = 1;
	BaseSet[0xEC].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xEC].N.Operands[1].IM = 1;
	BaseSet[0xEC].N.Operands[1].O16 = 1;
	BaseSet[0xEC].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0xED].Type = x86_x64InstructionType_Normal;
	BaseSet[0xED].Behaviour = InstructionBehaviour_In;

	BaseSet[0xED].N.Operands[0].IM = 1;
	BaseSet[0xED].N.Operands[0].O16 = 1;
	BaseSet[0xED].N.Operands[0].O32 = 1;
	BaseSet[0xED].N.Operands[0].Type = x86_x64OperandType_AX;

	BaseSet[0xED].N.Operands[1].IM = 1;
	BaseSet[0xED].N.Operands[1].O16 = 1;
	BaseSet[0xED].N.Operands[1].Type = x86_x64OperandType_DX;

	BaseSet[0xEE].Type = x86_x64InstructionType_Normal;
	BaseSet[0xEE].Behaviour = InstructionBehaviour_Out;

	BaseSet[0xEE].N.Operands[0].IM = 1;
	BaseSet[0xEE].N.Operands[0].O16 = 1;
	BaseSet[0xEE].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xEE].N.Operands[1].IM = 1;
	BaseSet[0xEE].N.Operands[1].O8 = 1;
	BaseSet[0xEE].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xEF].Type = x86_x64InstructionType_Normal;
	BaseSet[0xEF].Behaviour = InstructionBehaviour_Out;

	BaseSet[0xEF].N.Operands[0].IM = 1;
	BaseSet[0xEF].N.Operands[0].O16 = 1;
	BaseSet[0xEF].N.Operands[0].Type = x86_x64OperandType_DX;

	BaseSet[0xEF].N.Operands[1].IM = 1;
	BaseSet[0xEF].N.Operands[1].O16 = 1;
	BaseSet[0xEF].N.Operands[1].O32 = 1;
	BaseSet[0xEF].N.Operands[1].Type = x86_x64OperandType_AX;

	BaseSet[0xF0].Type = x86_x64InstructionType_Prefix;
	BaseSet[0xF0].P.Prefix.LOCK = 1;

	BaseSet[0xF1].Type = x86_x64InstructionType_Normal;
	BaseSet[0xF1].Behaviour = InstructionBehaviour_Icebp;

	BaseSet[0xF2].Type = x86_x64InstructionType_Prefix;
	BaseSet[0xF2].P.Prefix.REPNZ = 1;

	BaseSet[0xF3].Type = x86_x64InstructionType_Prefix;
	BaseSet[0xF3].P.Prefix.REPZ = 1;

	BaseSet[0xF4].Type = x86_x64InstructionType_Normal;
	BaseSet[0xF4].Behaviour = InstructionBehaviour_Hlt;

	BaseSet[0xF5].Type = x86_x64InstructionType_Normal;
	BaseSet[0xF5].Behaviour = InstructionBehaviour_Cmc;

	BaseSet[0xF6].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xF6].R.A0 = 1;
	BaseSet[0xF6].R.A1 = 1;
	BaseSet[0xF6].R.A2 = 1;
	BaseSet[0xF6].R.A3 = 1;
	BaseSet[0xF6].R.A4 = 1;
	BaseSet[0xF6].R.A5 = 1;
	BaseSet[0xF6].R.A6 = 1;
	BaseSet[0xF6].R.A7 = 1;

	BaseSet[0xF6].R.Index = INDEX_BUFFER(&BaseSet[0xF6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Test;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O8 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Test;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O8 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Not;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Neg;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Mul;

	SubSet[0x04].N.Operands[0].IM = 1;
	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x04].N.Operands[0].IM = 1;
	SubSet[0x04].N.Operands[1].O8 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x04].N.Operands[2].O8 = 1;
	SubSet[0x04].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Imul;

	SubSet[0x05].N.Operands[0].IM = 1;
	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x05].N.Operands[1].IM = 1;
	SubSet[0x05].N.Operands[1].O8 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x05].N.Operands[2].O8 = 1;
	SubSet[0x05].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Div;

	SubSet[0x06].N.Operands[0].IM = 1;
	SubSet[0x06].N.Operands[0].O8 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x06].N.Operands[0].IM = 1;
	SubSet[0x06].N.Operands[1].O8 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_SP;

	SubSet[0x06].N.Operands[0].IM = 1;
	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x06].N.Operands[2].O8 = 1;
	SubSet[0x06].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Idiv;

	SubSet[0x07].N.Operands[0].IM = 1;
	SubSet[0x07].N.Operands[0].O8 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x07].N.Operands[0].IM = 1;
	SubSet[0x07].N.Operands[1].O8 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_SP;

	SubSet[0x07].N.Operands[0].IM = 1;
	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_AX;

	SubSet[0x07].N.Operands[2].O8 = 1;
	SubSet[0x07].N.Operands[2].Type = x86_x64OperandType_M;

	BaseSet[0xF7].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	BaseSet[0xF7].R.A0 = 1;
	BaseSet[0xF7].R.A1 = 1;
	BaseSet[0xF7].R.A2 = 1;
	BaseSet[0xF7].R.A3 = 1;
	BaseSet[0xF7].R.A4 = 1;
	BaseSet[0xF7].R.A5 = 1;
	BaseSet[0xF7].R.A6 = 1;
	BaseSet[0xF7].R.A7 = 1;

	BaseSet[0xF7].R.Index = INDEX_BUFFER(&BaseSet[0xF7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Test;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Test;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[1].O16 = 1;
	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Not;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Neg;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Mul;

	SubSet[0x04].N.Operands[0].IM = 1;
	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x04].N.Operands[1].IM = 1;
	SubSet[0x04].N.Operands[1].O16 = 1;
	SubSet[0x04].N.Operands[1].O32 = 1;
	SubSet[0x04].N.Operands[1].O64 = 1;
	SubSet[0x04].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x04].N.Operands[2].O16 = 1;
	SubSet[0x04].N.Operands[2].O32 = 1;
	SubSet[0x04].N.Operands[2].O64 = 1;
	SubSet[0x04].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Imul;

	SubSet[0x05].N.Operands[0].IM = 1;
	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].O64 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x05].N.Operands[1].IM = 1;
	SubSet[0x05].N.Operands[1].O16 = 1;
	SubSet[0x05].N.Operands[1].O32 = 1;
	SubSet[0x05].N.Operands[1].O64 = 1;
	SubSet[0x05].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x05].N.Operands[2].O16 = 1;
	SubSet[0x05].N.Operands[2].O32 = 1;
	SubSet[0x05].N.Operands[2].O64 = 1;
	SubSet[0x05].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Div;

	SubSet[0x06].N.Operands[0].IM = 1;
	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x06].N.Operands[1].IM = 1;
	SubSet[0x06].N.Operands[1].O16 = 1;
	SubSet[0x06].N.Operands[1].O32 = 1;
	SubSet[0x06].N.Operands[1].O64 = 1;
	SubSet[0x06].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x06].N.Operands[2].O16 = 1;
	SubSet[0x06].N.Operands[2].O32 = 1;
	SubSet[0x06].N.Operands[2].O64 = 1;
	SubSet[0x06].N.Operands[2].Type = x86_x64OperandType_M;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Idiv;

	SubSet[0x07].N.Operands[0].IM = 1;
	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].O64 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_DX;

	SubSet[0x07].N.Operands[1].IM = 1;
	SubSet[0x07].N.Operands[1].O16 = 1;
	SubSet[0x07].N.Operands[1].O32 = 1;
	SubSet[0x07].N.Operands[1].O64 = 1;
	SubSet[0x07].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x07].N.Operands[2].O16 = 1;
	SubSet[0x07].N.Operands[2].O32 = 1;
	SubSet[0x07].N.Operands[2].O64 = 1;
	SubSet[0x07].N.Operands[2].Type = x86_x64OperandType_M;

	BaseSet[0xF8].Type = x86_x64InstructionType_Normal;
	BaseSet[0xF8].Behaviour = InstructionBehaviour_Clc;

	BaseSet[0xF9].Type = x86_x64InstructionType_Normal;
	BaseSet[0xF9].Behaviour = InstructionBehaviour_Stc;

	BaseSet[0xFA].Type = x86_x64InstructionType_Normal;
	BaseSet[0xFA].Behaviour = InstructionBehaviour_Cli;

	BaseSet[0xFB].Type = x86_x64InstructionType_Normal;
	BaseSet[0xFB].Behaviour = InstructionBehaviour_Sti;

	BaseSet[0xFC].Type = x86_x64InstructionType_Normal;
	BaseSet[0xFC].Behaviour = InstructionBehaviour_Cld;

	BaseSet[0xFD].Type = x86_x64InstructionType_Normal;
	BaseSet[0xFD].Behaviour = InstructionBehaviour_Std;

	BaseSet[0xFE].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	BaseSet[0xFE].R.A0 = 1;
	BaseSet[0xFE].R.A1 = 1;

	BaseSet[0xFE].R.Index = INDEX_BUFFER(&BaseSet[0xFE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Inc;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Dec;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0xFF].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 7);

	BaseSet[0xFF].R.A0 = 1;
	BaseSet[0xFF].R.A1 = 1;
	BaseSet[0xFF].R.A2 = 1;
	BaseSet[0xFF].R.A3 = 1;
	BaseSet[0xFF].R.A4 = 1;
	BaseSet[0xFF].R.A5 = 1;
	BaseSet[0xFF].R.A6 = 1;

	BaseSet[0xFF].R.Index = INDEX_BUFFER(&BaseSet[0xFF], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Inc;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Dec;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Call;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A0 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].R.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Call;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Jmp;

	SubSet[0x04].N.Operands[0].O64 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x05].RG.A0 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].R.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Jmp;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Push;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O64 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	BaseSet[0x0F].Type = x86_x64InstructionType_FullRedirect;

	ExSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 255);

	BaseSet[0x0F].RF.Index = INDEX_BUFFER(&BaseSet[0x0F], ExSet);

	ExSet[0x00].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 6);

	ExSet[0x00].R.A0 = 1;
	ExSet[0x00].R.A1 = 1;
	ExSet[0x00].R.A2 = 1;
	ExSet[0x00].R.A3 = 1;
	ExSet[0x00].R.A4 = 1;
	ExSet[0x00].R.A5 = 1;

	ExSet[0x00].R.Index = INDEX_BUFFER(&ExSet[0x00], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].R.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Sldt;

	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Sldt;

	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].R.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Str;

	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Str;

	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Lldt;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Ltr;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Verr;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Verw;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x01].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	ExSet[0x01].R.A0 = 1;
	ExSet[0x01].R.A1 = 1;
	ExSet[0x01].R.A2 = 1;
	ExSet[0x01].R.A3 = 1;
	ExSet[0x01].R.A4 = 1;
	ExSet[0x01].R.A5 = 1;
	ExSet[0x01].R.A6 = 1;
	ExSet[0x01].R.A7 = 1;

	ExSet[0x01].R.Index = INDEX_BUFFER(&ExSet[0x01], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].R.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Sgdt;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 6);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Enclv;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Vmcall;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Vmlaunch;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Vmresume;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Vmxoff;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Pconfig;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].R.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Sidt;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Monitor;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Mwait;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Clac;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Stac;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].R.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Lgdt;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 6);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;
	L2SubSet[0x01].R.A7 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Xgetbv;

	L3SubSet[0x00].N.Operands[0].IM = 1;
	L3SubSet[0x00].N.Operands[0].O32 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DX;

	L3SubSet[0x00].N.Operands[1].IM = 1;
	L3SubSet[0x00].N.Operands[1].O32 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	L3SubSet[0x00].N.Operands[2].IM = 1;
	L3SubSet[0x00].N.Operands[2].O32 = 1;
	L3SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_CX;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Xsetbv;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_CX;

	L3SubSet[0x01].N.Operands[1].IM = 1;
	L3SubSet[0x01].N.Operands[1].O32 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DX;

	L3SubSet[0x01].N.Operands[2].IM = 1;
	L3SubSet[0x01].N.Operands[2].O32 = 1;
	L3SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_AX;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Vmfunc;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Xend;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Xtest;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Enclu;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].R.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Lidt;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;
	L2SubSet[0x01].R.A7 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Vmrun;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Vmmcall;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Vmload;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Vmsave;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Stgi;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Clgi;

	L3SubSet[0x06].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x06].Behaviour = InstructionBehaviour_Skinit;

	L3SubSet[0x07].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x07].Behaviour = InstructionBehaviour_Invlpga;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x04].RG.A0 = 1;
	SubSet[0x04].RG.A3 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].R.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Smsw;

	L2SubSet[0x00].N.Operands[0].O16 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Smsw;

	L2SubSet[0x01].N.Operands[0].O16 = 1;
	L2SubSet[0x01].N.Operands[0].O32 = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H1 = 1;
	SubSet[0x05].RG.H2 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].R.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	L2SubSet[0x00].R.A0 = 1;
	L2SubSet[0x00].R.A6 = 1;
	L2SubSet[0x00].R.A7 = 1;

	L2SubSet[0x00].R.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Serialize;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Rdpkru;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Wrpkru;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Lmsw;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x07].RG.A0 = 1;
	SubSet[0x07].RG.A3 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].R.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Invlpg;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_LowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 6);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;
	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Swapgs;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Rdiscp;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O32 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_AX;

	L3SubSet[0x01].N.Operands[1].IM = 1;
	L3SubSet[0x01].N.Operands[1].O32 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_DX;

	L3SubSet[0x01].N.Operands[2].IM = 1;
	L3SubSet[0x01].N.Operands[2].O32 = 1;
	L3SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_CX;

	L3SubSet[0x02].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x02].Behaviour = InstructionBehaviour_Monitorx;

	L3SubSet[0x03].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x03].Behaviour = InstructionBehaviour_Mwaitx;

	L3SubSet[0x04].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x04].Behaviour = InstructionBehaviour_Clzero;

	L3SubSet[0x05].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x05].Behaviour = InstructionBehaviour_Rdpru;

	ExSet[0x02].Type = x86_x64InstructionType_Normal;
	ExSet[0x02].Behaviour = InstructionBehaviour_Lar;

	ExSet[0x02].N.Operands[0].O16 = 1;
	ExSet[0x02].N.Operands[0].O32 = 1;
	ExSet[0x02].N.Operands[0].O64 = 1;
	ExSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x02].N.Operands[1].O16 = 1;
	ExSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x03].Type = x86_x64InstructionType_Normal;
	ExSet[0x03].Behaviour = InstructionBehaviour_Lsl;

	ExSet[0x03].N.Operands[0].O16 = 1;
	ExSet[0x03].N.Operands[0].O32 = 1;
	ExSet[0x03].N.Operands[0].O64 = 1;
	ExSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x03].N.Operands[1].O16 = 1;
	ExSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x05].Type = x86_x64InstructionType_Normal;
	ExSet[0x05].Behaviour = InstructionBehaviour_Syscall;

	ExSet[0x05].N.Operands[0].IM = 1;
	ExSet[0x05].N.Operands[0].O64 = 1;
	ExSet[0x05].N.Operands[0].Type = x86_x64OperandType_CX;

	ExSet[0x05].N.Operands[1].IM = 1;
	ExSet[0x05].N.Operands[1].O64 = 1;
	ExSet[0x05].N.Operands[1].Type = x86_x64OperandType_BX;
	ExSet[0x05].N.Operands[1].RType = x86_x64RegisterType_Extended;

	ExSet[0x06].Type = x86_x64InstructionType_Normal;
	ExSet[0x06].Behaviour = InstructionBehaviour_Clts;

	ExSet[0x06].N.Operands[0].IM = 1;
	ExSet[0x06].N.Operands[0].O64 = 1;
	ExSet[0x06].N.Operands[0].Type = x86_x64OperandType_AX;
	ExSet[0x06].N.Operands[0].RType = x86_x64RegisterType_Control;

	ExSet[0x07].Type = x86_x64InstructionType_Normal;
	ExSet[0x07].Behaviour = InstructionBehaviour_Sysret;

	ExSet[0x07].N.Operands[0].IM = 1;
	ExSet[0x07].N.Operands[0].O32 = 1;
	ExSet[0x07].N.Operands[0].O64 = 1;
	ExSet[0x07].N.Operands[0].Type = x86_x64OperandType_CX;

	ExSet[0x07].N.Operands[1].IM = 1;
	ExSet[0x07].N.Operands[1].O64 = 1;
	ExSet[0x07].N.Operands[1].Type = x86_x64OperandType_BX;
	ExSet[0x07].N.Operands[1].RType = x86_x64RegisterType_Extended;

	ExSet[0x08].Type = x86_x64InstructionType_Normal;
	ExSet[0x08].Behaviour = InstructionBehaviour_Invd;

	ExSet[0x09].Type = x86_x64InstructionType_Normal;
	ExSet[0x09].Behaviour = InstructionBehaviour_Wbinvd;

	ExSet[0x0D].Type = x86_x64InstructionType_Normal;
	ExSet[0x0D].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x0D].N.Operands[0].O16 = 1;
	ExSet[0x0D].N.Operands[0].O32 = 1;
	ExSet[0x0D].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x10].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x10].RP.A2 = 1;
	ExSet[0x10].RP.A3 = 1;
	ExSet[0x10].RP.A4 = 1;
	ExSet[0x10].RP.DC = 1;

	ExSet[0x10].R.Index = INDEX_BUFFER(&ExSet[0x10], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movupd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Movups;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x11].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x11].RP.A2 = 1;
	ExSet[0x11].RP.A3 = 1;
	ExSet[0x11].RP.A4 = 1;
	ExSet[0x11].RP.DC = 1;

	ExSet[0x11].R.Index = INDEX_BUFFER(&ExSet[0x11], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movupd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Movups;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x12].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x12].RP.A2 = 1;
	ExSet[0x12].RP.A3 = 1;
	ExSet[0x12].RP.A4 = 1;
	ExSet[0x12].RP.DC = 1;

	ExSet[0x12].R.Index = INDEX_BUFFER(&ExSet[0x12], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movlpd;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movsldup;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movddup;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x03].RG.A0 = 1;
	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movlps;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Movhlps;

	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x13].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x13].RP.A2 = 1;
	ExSet[0x13].RP.DC = 1;

	ExSet[0x13].RP.Index = INDEX_BUFFER(&ExSet[0x13], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movlpd;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movlps;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x14].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x14].RP.A2 = 1;
	ExSet[0x14].RP.DC = 1;

	ExSet[0x14].RP.Index = INDEX_BUFFER(&ExSet[0x14], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Unpcklpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Unpcklps;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x15].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x15].RP.A2 = 1;
	ExSet[0x15].RP.DC = 1;

	ExSet[0x15].RP.Index = INDEX_BUFFER(&ExSet[0x15], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Unpckhpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Unpckhps;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x16].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x16].RP.A2 = 1;
	ExSet[0x16].RP.A3 = 1;
	ExSet[0x16].RP.DC = 1;

	ExSet[0x16].RP.Index = INDEX_BUFFER(&ExSet[0x16], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movhpd;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movshdup;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x02].RG.A0 = 1;
	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movhps;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Movlhps;

	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x17].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x17].RP.A2 = 1;
	ExSet[0x17].RP.DC = 1;

	ExSet[0x17].RP.Index = INDEX_BUFFER(&ExSet[0x17], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movhpd;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movhps;

	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x18].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	ExSet[0x18].R.A0 = 1;
	ExSet[0x18].R.A1 = 1;
	ExSet[0x18].R.A2 = 1;
	ExSet[0x18].R.A3 = 1;
	ExSet[0x18].R.A4 = 1;
	ExSet[0x18].R.A5 = 1;
	ExSet[0x18].R.A6 = 1;
	ExSet[0x18].R.A7 = 1;

	ExSet[0x18].R.Index = INDEX_BUFFER(&ExSet[0x18], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Prefetchnta;

	L2SubSet[0x00].N.Operands[0].O8 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Prefetcht0;

	L2SubSet[0x00].N.Operands[0].O8 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A0 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Prefetcht1;

	L2SubSet[0x00].N.Operands[0].O8 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A0 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Prefetcht2;

	L2SubSet[0x00].N.Operands[0].O8 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_Normal;
	SubSet[0x04].Behaviour = InstructionBehaviour_Nop;

	SubSet[0x04].N.Operands[0].O16 = 1;
	SubSet[0x04].N.Operands[0].O32 = 1;
	SubSet[0x04].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_Normal;
	SubSet[0x05].Behaviour = InstructionBehaviour_Nop;

	SubSet[0x05].N.Operands[0].O16 = 1;
	SubSet[0x05].N.Operands[0].O32 = 1;
	SubSet[0x05].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x06].Type = x86_x64InstructionType_Normal;
	SubSet[0x06].Behaviour = InstructionBehaviour_Nop;

	SubSet[0x06].N.Operands[0].O16 = 1;
	SubSet[0x06].N.Operands[0].O32 = 1;
	SubSet[0x06].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x07].Type = x86_x64InstructionType_Normal;
	SubSet[0x07].Behaviour = InstructionBehaviour_Nop;

	SubSet[0x07].N.Operands[0].O16 = 1;
	SubSet[0x07].N.Operands[0].O32 = 1;
	SubSet[0x07].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x19].Type = x86_x64InstructionType_Normal;
	ExSet[0x19].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x19].N.Operands[0].O16 = 1;
	ExSet[0x19].N.Operands[0].O32 = 1;
	ExSet[0x19].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1A].Type = x86_x64InstructionType_Normal;
	ExSet[0x1A].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1A].N.Operands[0].O16 = 1;
	ExSet[0x1A].N.Operands[0].O32 = 1;
	ExSet[0x1A].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1B].Type = x86_x64InstructionType_Normal;
	ExSet[0x1B].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1B].N.Operands[0].O16 = 1;
	ExSet[0x1B].N.Operands[0].O32 = 1;
	ExSet[0x1B].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1C].Type = x86_x64InstructionType_Normal;
	ExSet[0x1C].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1C].N.Operands[0].O16 = 1;
	ExSet[0x1C].N.Operands[0].O32 = 1;
	ExSet[0x1C].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1D].Type = x86_x64InstructionType_Normal;
	ExSet[0x1D].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1D].N.Operands[0].O16 = 1;
	ExSet[0x1D].N.Operands[0].O32 = 1;
	ExSet[0x1D].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1E].Type = x86_x64InstructionType_Normal;
	ExSet[0x1E].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1E].N.Operands[0].O16 = 1;
	ExSet[0x1E].N.Operands[0].O32 = 1;
	ExSet[0x1E].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x1F].Type = x86_x64InstructionType_Normal;
	ExSet[0x1F].Behaviour = InstructionBehaviour_Nop;

	ExSet[0x1F].N.Operands[0].O16 = 1;
	ExSet[0x1F].N.Operands[0].O32 = 1;
	ExSet[0x1F].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x20].Type = x86_x64InstructionType_Normal;
	ExSet[0x20].Behaviour = InstructionBehaviour_Mov;

	ExSet[0x20].N.Operands[0].O64 = 1;
	ExSet[0x20].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x20].N.Operands[1].O64 = 1;
	ExSet[0x20].N.Operands[1].Type = x86_x64OperandType_R;
	ExSet[0x20].N.Operands[1].RType = x86_x64RegisterType_Control;

	ExSet[0x21].Type = x86_x64InstructionType_Normal;
	ExSet[0x21].Behaviour = InstructionBehaviour_Mov;

	ExSet[0x21].N.Operands[0].O64 = 1;
	ExSet[0x21].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x21].N.Operands[1].IM = 1;
	ExSet[0x21].N.Operands[1].O64 = 1;
	ExSet[0x21].N.Operands[1].Type = x86_x64OperandType_R;
	ExSet[0x21].N.Operands[1].RType = x86_x64RegisterType_Debug;

	ExSet[0x22].Type = x86_x64InstructionType_Normal;
	ExSet[0x22].Behaviour = InstructionBehaviour_Mov;

	ExSet[0x22].N.Operands[0].O64 = 1;
	ExSet[0x22].N.Operands[0].Type = x86_x64OperandType_R;
	ExSet[0x22].N.Operands[0].RType = x86_x64RegisterType_Control;

	ExSet[0x22].N.Operands[1].O64 = 1;
	ExSet[0x22].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x23].Type = x86_x64InstructionType_Normal;
	ExSet[0x23].Behaviour = InstructionBehaviour_Mov;

	ExSet[0x23].N.Operands[0].IM = 1;
	ExSet[0x23].N.Operands[0].O64 = 1;
	ExSet[0x23].N.Operands[0].Type = x86_x64OperandType_R;
	ExSet[0x23].N.Operands[0].RType = x86_x64RegisterType_Debug;

	ExSet[0x23].N.Operands[1].O64 = 1;
	ExSet[0x23].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x28].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x28].RP.A2 = 1;
	ExSet[0x28].RP.DC = 1;

	ExSet[0x28].RP.Index = INDEX_BUFFER(&ExSet[0x28], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movapd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movaps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x29].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x29].RP.A2 = 1;
	ExSet[0x29].RP.DC = 1;

	ExSet[0x29].RP.Index = INDEX_BUFFER(&ExSet[0x29], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movapd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movaps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x2A].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x2A].RP.A2 = 1;
	ExSet[0x2A].RP.A3 = 1;
	ExSet[0x2A].RP.A4 = 1;
	ExSet[0x2A].RP.DC = 1;

	ExSet[0x2A].RP.Index = INDEX_BUFFER(&ExSet[0x2A], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvtpi2pd;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvtsi2ss;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvtsi2sd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Cvtpi2ps;

	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O64 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x2B].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x2B].RP.A2 = 1;
	ExSet[0x2B].RP.DC = 1;

	ExSet[0x2B].RP.Index = INDEX_BUFFER(&ExSet[0x2B], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movntpd;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movntps;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x2C].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x2C].RP.A2 = 1;
	ExSet[0x2C].RP.A3 = 1;
	ExSet[0x2C].RP.A4 = 1;
	ExSet[0x2C].RP.DC = 1;

	ExSet[0x2C].RP.Index = INDEX_BUFFER(&ExSet[0x2C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvttpd2pi;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvttss2si;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvttsd2si;

	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Cvtpi2ps;

	SubSet[0x03].N.Operands[0].IM = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x03].N.Operands[1].O64 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x2D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x2D].RP.A2 = 1;
	ExSet[0x2D].RP.A3 = 1;
	ExSet[0x2D].RP.A4 = 1;
	ExSet[0x2D].RP.DC = 1;

	ExSet[0x2D].RP.Index = INDEX_BUFFER(&ExSet[0x2D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvtpd2pi;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvtss2si;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvtsd2si;

	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Cvtps2pi;

	SubSet[0x03].N.Operands[0].IM = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x03].N.Operands[1].O64 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x2E].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x2E].RP.A2 = 1;
	ExSet[0x2E].RP.DC = 1;

	ExSet[0x2E].RP.Index = INDEX_BUFFER(&ExSet[0x2E], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Ucomisd;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Ucomiss;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x2F].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x2F].RP.A2 = 1;
	ExSet[0x2F].RP.DC = 1;

	ExSet[0x2F].RP.Index = INDEX_BUFFER(&ExSet[0x2F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Comisd;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Comiss;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x30].Type = x86_x64InstructionType_Normal;
	ExSet[0x30].Behaviour = InstructionBehaviour_Wrmsr;

	ExSet[0x30].N.Operands[0].IM = 1;
	ExSet[0x30].N.Operands[0].O32 = 1;
	ExSet[0x30].N.Operands[0].Type = x86_x64OperandType_CX;

	ExSet[0x30].N.Operands[1].IM = 1;
	ExSet[0x30].N.Operands[1].O32 = 1;
	ExSet[0x30].N.Operands[1].Type = x86_x64OperandType_AX;

	ExSet[0x30].N.Operands[2].IM = 1;
	ExSet[0x30].N.Operands[2].O32 = 1;
	ExSet[0x30].N.Operands[2].Type = x86_x64OperandType_DX;

	ExSet[0x31].Type = x86_x64InstructionType_Normal;
	ExSet[0x31].Behaviour = InstructionBehaviour_Rdtsc;

	ExSet[0x31].N.Operands[0].IM = 1;
	ExSet[0x31].N.Operands[0].O32 = 1;
	ExSet[0x31].N.Operands[0].Type = x86_x64OperandType_CX;

	ExSet[0x31].N.Operands[1].IM = 1;
	ExSet[0x31].N.Operands[1].O32 = 1;
	ExSet[0x31].N.Operands[1].Type = x86_x64OperandType_AX;

	ExSet[0x32].Type = x86_x64InstructionType_Normal;
	ExSet[0x32].Behaviour = InstructionBehaviour_Rdmsr;

	ExSet[0x32].N.Operands[0].IM = 1;
	ExSet[0x32].N.Operands[0].O32 = 1;
	ExSet[0x32].N.Operands[0].Type = x86_x64OperandType_AX;

	ExSet[0x32].N.Operands[1].IM = 1;
	ExSet[0x32].N.Operands[1].O32 = 1;
	ExSet[0x32].N.Operands[1].Type = x86_x64OperandType_DX;

	ExSet[0x32].N.Operands[2].IM = 1;
	ExSet[0x32].N.Operands[2].O32 = 1;
	ExSet[0x32].N.Operands[2].Type = x86_x64OperandType_CX;

	ExSet[0x33].Type = x86_x64InstructionType_Normal;
	ExSet[0x33].Behaviour = InstructionBehaviour_Rdpmc;

	ExSet[0x33].N.Operands[0].IM = 1;
	ExSet[0x33].N.Operands[0].O32 = 1;
	ExSet[0x33].N.Operands[0].Type = x86_x64OperandType_AX;

	ExSet[0x33].N.Operands[1].IM = 1;
	ExSet[0x33].N.Operands[1].O32 = 1;
	ExSet[0x33].N.Operands[1].Type = x86_x64OperandType_DX;

	ExSet[0x34].Type = x86_x64InstructionType_Normal;
	ExSet[0x34].Behaviour = InstructionBehaviour_Sysenter;

	ExSet[0x34].N.Operands[0].IM = 1;
	ExSet[0x34].N.Operands[0].O64 = 1;
	ExSet[0x34].N.Operands[0].Type = x86_x64OperandType_SP;

	ExSet[0x35].Type = x86_x64InstructionType_Normal;
	ExSet[0x35].Behaviour = InstructionBehaviour_Sysexit;

	ExSet[0x35].N.Operands[0].IM = 1;
	ExSet[0x35].N.Operands[0].O64 = 1;
	ExSet[0x35].N.Operands[0].Type = x86_x64OperandType_DX;

	ExSet[0x35].N.Operands[1].IM = 1;
	ExSet[0x35].N.Operands[1].O64 = 1;
	ExSet[0x35].N.Operands[1].Type = x86_x64OperandType_SP;

	ExSet[0x35].N.Operands[2].IM = 1;
	ExSet[0x35].N.Operands[2].O64 = 1;
	ExSet[0x35].N.Operands[2].Type = x86_x64OperandType_CX;

	ExSet[0x37].Type = x86_x64InstructionType_Normal;
	ExSet[0x37].Behaviour = InstructionBehaviour_Getsec;

	ExSet[0x37].N.Operands[0].IM = 1;
	ExSet[0x37].N.Operands[0].O32 = 1;
	ExSet[0x37].N.Operands[0].Type = x86_x64OperandType_AX;

	ExSet[0x38].Type = x86_x64InstructionType_ExGlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x38].RG.A2 = 1;
	ExSet[0x38].RG.A3 = 1;

	ExSet[0x38].RG.Index = INDEX_BUFFER(&ExSet[0x38], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_ExUpperRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].R.A0 = 1;

	SubSet[0x00].R.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].R.A0 = 1;
	L2SubSet[0x00].R.A1 = 1;

	L2SubSet[0x00].R.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L4SubSet[0x00].RG.A0 = 1;

	L4SubSet[0x00].RG.H0 = 1;
	L4SubSet[0x00].RG.H3 = 1;

	L4SubSet[0x00].RG.Index = INDEX_BUFFER(&L4SubSet[0x00], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Invept;

	L5SubSet[0x00].N.Operands[0].O64 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L5SubSet[0x00].N.Operands[1].O128 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L4SubSet[0x00].RG.A0 = 1;

	L4SubSet[0x00].RG.H0 = 1;
	L4SubSet[0x00].RG.H3 = 1;

	L4SubSet[0x00].RG.Index = INDEX_BUFFER(&L4SubSet[0x00], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Invvpid;

	L5SubSet[0x00].N.Operands[0].O64 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L5SubSet[0x00].N.Operands[1].O128 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_ExUpperRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].R.A6 = 1;

	SubSet[0x01].R.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].R.A0 = 1;
	L2SubSet[0x00].R.A1 = 1;

	L2SubSet[0x00].R.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x00].RP.A4 = 1;
	L3SubSet[0x00].RP.DC = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Crc32;

	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].O64 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L4SubSet[0x00].N.Operands[1].O8 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L4SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L4SubSet[0x01].RG.A0 = 1;

	L4SubSet[0x01].RG.H0 = 1;
	L4SubSet[0x01].RG.H3 = 1;

	L4SubSet[0x01].RG.Index = INDEX_BUFFER(&L4SubSet[0x01], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Movbe;

	L5SubSet[0x00].N.Operands[0].O16 = 1;
	L5SubSet[0x00].N.Operands[0].O32 = 1;
	L5SubSet[0x00].N.Operands[0].O64 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L5SubSet[0x00].N.Operands[1].O16 = 1;
	L5SubSet[0x00].N.Operands[1].O32 = 1;
	L5SubSet[0x00].N.Operands[1].O64 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x01].RP.A4 = 1;
	L3SubSet[0x01].RP.DC = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Crc32;

	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].O64 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L4SubSet[0x00].N.Operands[1].O16 = 1;
	L4SubSet[0x00].N.Operands[1].O32 = 1;
	L4SubSet[0x00].N.Operands[1].O64 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L4SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L4SubSet[0x01].RG.A0 = 1;

	L4SubSet[0x01].RG.H0 = 1;
	L4SubSet[0x01].RG.H3 = 1;

	L4SubSet[0x01].RG.Index = INDEX_BUFFER(&L4SubSet[0x01], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Movbe;

	L5SubSet[0x00].N.Operands[0].O16 = 1;
	L5SubSet[0x00].N.Operands[0].O32 = 1;
	L5SubSet[0x00].N.Operands[0].O64 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L5SubSet[0x00].N.Operands[1].O16 = 1;
	L5SubSet[0x00].N.Operands[1].O32 = 1;
	L5SubSet[0x00].N.Operands[1].O64 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0x3A].Type = x86_x64InstructionType_ExGlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x3A].RG.A0 = 1;
	ExSet[0x3A].RG.A1 = 1;

	ExSet[0x3A].RG.Index = INDEX_BUFFER(&ExSet[0x3A], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_ExUpperRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	SubSet[0x00].R.A1 = 1;
	SubSet[0x00].R.A2 = 1;
	SubSet[0x00].R.A4 = 1;

	SubSet[0x00].R.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	L2SubSet[0x00].R.A0 = 1;
	L2SubSet[0x00].R.A1 = 1;
	L2SubSet[0x00].R.A2 = 1;
	L2SubSet[0x00].R.A3 = 1;
	L2SubSet[0x00].R.A4 = 1;
	L2SubSet[0x00].R.A5 = 1;
	L2SubSet[0x00].R.A6 = 1;
	L2SubSet[0x00].R.A7 = 1;

	L2SubSet[0x00].R.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Roundps;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Roundpd;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x02].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x02].RP.A2 = 1;

	L3SubSet[0x02].RP.Index = INDEX_BUFFER(&L3SubSet[0x02], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Roundss;

	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O32 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x03].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x03].RP.A2 = 1;

	L3SubSet[0x03].RP.Index = INDEX_BUFFER(&L3SubSet[0x03], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Roundsd;

	L4SubSet[0x00].N.Operands[0].O64 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O64 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x04].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x04].RP.A2 = 1;

	L3SubSet[0x04].RP.Index = INDEX_BUFFER(&L3SubSet[0x04], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Blendps;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x05].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x05].RP.A2 = 1;

	L3SubSet[0x05].RP.Index = INDEX_BUFFER(&L3SubSet[0x05], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Blendpd;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x06].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x06].RP.A2 = 1;

	L3SubSet[0x06].RP.Index = INDEX_BUFFER(&L3SubSet[0x06], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pblendw;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x07].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L3SubSet[0x07].RP.A2 = 1;
	L3SubSet[0x07].RP.DC = 1;

	L3SubSet[0x07].RP.Index = INDEX_BUFFER(&L3SubSet[0x07], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Palignr;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L4SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x01].Behaviour = InstructionBehaviour_Palignr;

	L4SubSet[0x01].N.Operands[0].IM = 1;
	L4SubSet[0x01].N.Operands[0].O64 = 1;
	L4SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L4SubSet[0x01].N.Operands[1].IM = 1;
	L4SubSet[0x01].N.Operands[1].O64 = 1;
	L4SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	L4SubSet[0x01].N.Operands[2].O8 = 1;
	L4SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x01].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	L2SubSet[0x01].R.A4 = 1;
	L2SubSet[0x01].R.A5 = 1;
	L2SubSet[0x01].R.A6 = 1;
	L2SubSet[0x01].R.A7 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L4SubSet[0x00].RG.A0 = 1;
	L4SubSet[0x00].RG.A3 = 1;

	L4SubSet[0x00].RG.H0 = 1;
	L4SubSet[0x00].RG.H3 = 1;

	L4SubSet[0x00].RG.Index = INDEX_BUFFER(&L4SubSet[0x00], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Pextrb;

	L5SubSet[0x00].N.Operands[0].O8 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L5SubSet[0x00].N.Operands[1].O128 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L5SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x00].N.Operands[2].O8 = 1;
	L5SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L5SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x01].Behaviour = InstructionBehaviour_Pextrb;

	L5SubSet[0x01].N.Operands[0].O32 = 1;
	L5SubSet[0x01].N.Operands[0].O64 = 1;
	L5SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	L5SubSet[0x01].N.Operands[1].O128 = 1;
	L5SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	L5SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x01].N.Operands[2].O8 = 1;
	L5SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L4SubSet[0x00].RG.A0 = 1;
	L4SubSet[0x00].RG.A3 = 1;

	L4SubSet[0x00].RG.H0 = 1;
	L4SubSet[0x00].RG.H3 = 1;

	L4SubSet[0x00].RG.Index = INDEX_BUFFER(&L4SubSet[0x00], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Pextrw;

	L5SubSet[0x00].N.Operands[0].O16 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L5SubSet[0x00].N.Operands[1].O128 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L5SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x00].N.Operands[2].O8 = 1;
	L5SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L5SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x01].Behaviour = InstructionBehaviour_Pextrw;

	L5SubSet[0x01].N.Operands[0].O32 = 1;
	L5SubSet[0x01].N.Operands[0].O64 = 1;
	L5SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	L5SubSet[0x01].N.Operands[1].O128 = 1;
	L5SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	L5SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x01].N.Operands[2].O8 = 1;
	L5SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x02].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x02].RP.A2 = 1;

	L3SubSet[0x02].RP.Index = INDEX_BUFFER(&L3SubSet[0x02], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pextr;

	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].O64 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x03].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x03].RP.A2 = 1;

	L3SubSet[0x03].RP.Index = INDEX_BUFFER(&L3SubSet[0x03], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Extractps;

	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x02].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	L2SubSet[0x02].R.A0 = 1;
	L2SubSet[0x02].R.A1 = 1;
	L2SubSet[0x02].R.A2 = 1;

	L2SubSet[0x02].R.Index = INDEX_BUFFER(&L2SubSet[0x02], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L5SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L4SubSet[0x00].RG.A0 = 1;
	L4SubSet[0x00].RG.A3 = 1;

	L4SubSet[0x00].RG.H0 = 1;
	L4SubSet[0x00].RG.H3 = 1;

	L4SubSet[0x00].RG.Index = INDEX_BUFFER(&L4SubSet[0x00], L5SubSet);

	L5SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x00].Behaviour = InstructionBehaviour_Pinsrb;

	L5SubSet[0x00].N.Operands[0].O128 = 1;
	L5SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L5SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x00].N.Operands[1].O8 = 1;
	L5SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L5SubSet[0x00].N.Operands[2].O8 = 1;
	L5SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L5SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L5SubSet[0x01].Behaviour = InstructionBehaviour_Pinsrb;

	L5SubSet[0x01].N.Operands[0].O128 = 1;
	L5SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L5SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L5SubSet[0x01].N.Operands[1].O32 = 1;
	L5SubSet[0x01].N.Operands[1].O64 = 1;
	L5SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;

	L5SubSet[0x01].N.Operands[2].O8 = 1;
	L5SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Insertps;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O8 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L3SubSet[0x02].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x02].RP.A2 = 1;

	L3SubSet[0x02].RP.Index = INDEX_BUFFER(&L3SubSet[0x02], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pinsr;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O32 = 1;
	L4SubSet[0x00].N.Operands[1].O64 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_ExUpperRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].R.A0 = 1;
	SubSet[0x01].R.A4 = 1;

	SubSet[0x01].R.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	L2SubSet[0x00].R.A0 = 1;
	L2SubSet[0x00].R.A1 = 1;
	L2SubSet[0x00].R.A2 = 1;

	L2SubSet[0x00].R.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Dpps;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Dppd;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x02].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x02].RP.A2 = 1;

	L3SubSet[0x02].RP.Index = INDEX_BUFFER(&L3SubSet[0x02], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Mpsadbw;

	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O8 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x01].Type = x86_x64InstructionType_ExLowerRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	L2SubSet[0x01].R.A0 = 1;
	L2SubSet[0x01].R.A1 = 1;
	L2SubSet[0x01].R.A2 = 1;
	L2SubSet[0x01].R.A3 = 1;

	L2SubSet[0x01].R.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x00].RP.A2 = 1;

	L3SubSet[0x00].RP.Index = INDEX_BUFFER(&L3SubSet[0x00], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpestrm;

	L4SubSet[0x00].N.Operands[0].IM = 1;
	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O128 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[3].O8 = 1;
	L4SubSet[0x00].N.Operands[3].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Behaviour = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x01].RP.A2 = 1;

	L3SubSet[0x01].RP.Index = INDEX_BUFFER(&L3SubSet[0x01], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpestri;

	L4SubSet[0x00].N.Operands[0].IM = 1;
	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_CX;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O128 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[3].O8 = 1;
	L4SubSet[0x00].N.Operands[3].Type = x86_x64OperandType_IMM;

	L3SubSet[0x02].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x02].RP.A2 = 1;

	L3SubSet[0x02].RP.Index = INDEX_BUFFER(&L3SubSet[0x02], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpistrm;

	L4SubSet[0x00].N.Operands[0].IM = 1;
	L4SubSet[0x00].N.Operands[0].O128 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_AX;
	L4SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O128 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[3].O8 = 1;
	L4SubSet[0x00].N.Operands[3].Type = x86_x64OperandType_IMM;

	L3SubSet[0x03].Type = x86_x64InstructionType_PrefixRedirect;

	L4SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L3SubSet[0x03].RP.A2 = 1;

	L3SubSet[0x03].RP.Index = INDEX_BUFFER(&L3SubSet[0x03], L4SubSet);

	L4SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L4SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpistri;

	L4SubSet[0x00].N.Operands[0].IM = 1;
	L4SubSet[0x00].N.Operands[0].O32 = 1;
	L4SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_CX;

	L4SubSet[0x00].N.Operands[1].O128 = 1;
	L4SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L4SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[2].O128 = 1;
	L4SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L4SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Xmm;

	L4SubSet[0x00].N.Operands[3].O8 = 1;
	L4SubSet[0x00].N.Operands[3].Type = x86_x64OperandType_IMM;

	ExSet[0x40].Type = x86_x64InstructionType_Normal;
	ExSet[0x40].Behaviour = InstructionBehaviour_Cmovo;

	ExSet[0x40].N.Operands[0].O16 = 1;
	ExSet[0x40].N.Operands[0].O32 = 1;
	ExSet[0x40].N.Operands[0].O64 = 1;
	ExSet[0x40].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x40].N.Operands[1].O16 = 1;
	ExSet[0x40].N.Operands[1].O32 = 1;
	ExSet[0x40].N.Operands[1].O64 = 1;
	ExSet[0x40].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x41].Type = x86_x64InstructionType_Normal;
	ExSet[0x41].Behaviour = InstructionBehaviour_Cmovno;

	ExSet[0x41].N.Operands[0].O16 = 1;
	ExSet[0x41].N.Operands[0].O32 = 1;
	ExSet[0x41].N.Operands[0].O64 = 1;
	ExSet[0x41].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x41].N.Operands[1].O16 = 1;
	ExSet[0x41].N.Operands[1].O32 = 1;
	ExSet[0x41].N.Operands[1].O64 = 1;
	ExSet[0x41].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x42].Type = x86_x64InstructionType_Normal;
	ExSet[0x42].Behaviour = InstructionBehaviour_Cmovb;

	ExSet[0x42].N.Operands[0].O16 = 1;
	ExSet[0x42].N.Operands[0].O32 = 1;
	ExSet[0x42].N.Operands[0].O64 = 1;
	ExSet[0x42].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x42].N.Operands[1].O16 = 1;
	ExSet[0x42].N.Operands[1].O32 = 1;
	ExSet[0x42].N.Operands[1].O64 = 1;
	ExSet[0x42].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x43].Type = x86_x64InstructionType_Normal;
	ExSet[0x43].Behaviour = InstructionBehaviour_Cmovae;

	ExSet[0x43].N.Operands[0].O16 = 1;
	ExSet[0x43].N.Operands[0].O32 = 1;
	ExSet[0x43].N.Operands[0].O64 = 1;
	ExSet[0x43].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x43].N.Operands[1].O16 = 1;
	ExSet[0x43].N.Operands[1].O32 = 1;
	ExSet[0x43].N.Operands[1].O64 = 1;
	ExSet[0x43].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x44].Type = x86_x64InstructionType_Normal;
	ExSet[0x44].Behaviour = InstructionBehaviour_Cmove;

	ExSet[0x44].N.Operands[0].O16 = 1;
	ExSet[0x44].N.Operands[0].O32 = 1;
	ExSet[0x44].N.Operands[0].O64 = 1;
	ExSet[0x44].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x44].N.Operands[1].O16 = 1;
	ExSet[0x44].N.Operands[1].O32 = 1;
	ExSet[0x44].N.Operands[1].O64 = 1;
	ExSet[0x44].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x45].Type = x86_x64InstructionType_Normal;
	ExSet[0x45].Behaviour = InstructionBehaviour_Cmovne;

	ExSet[0x45].N.Operands[0].O16 = 1;
	ExSet[0x45].N.Operands[0].O32 = 1;
	ExSet[0x45].N.Operands[0].O64 = 1;
	ExSet[0x45].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x45].N.Operands[1].O16 = 1;
	ExSet[0x45].N.Operands[1].O32 = 1;
	ExSet[0x45].N.Operands[1].O64 = 1;
	ExSet[0x45].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x46].Type = x86_x64InstructionType_Normal;
	ExSet[0x46].Behaviour = InstructionBehaviour_Cmovbe;

	ExSet[0x46].N.Operands[0].O16 = 1;
	ExSet[0x46].N.Operands[0].O32 = 1;
	ExSet[0x46].N.Operands[0].O64 = 1;
	ExSet[0x46].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x46].N.Operands[1].O16 = 1;
	ExSet[0x46].N.Operands[1].O32 = 1;
	ExSet[0x46].N.Operands[1].O64 = 1;
	ExSet[0x46].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x47].Type = x86_x64InstructionType_Normal;
	ExSet[0x47].Behaviour = InstructionBehaviour_Cmova;

	ExSet[0x47].N.Operands[0].O16 = 1;
	ExSet[0x47].N.Operands[0].O32 = 1;
	ExSet[0x47].N.Operands[0].O64 = 1;
	ExSet[0x47].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x47].N.Operands[1].O16 = 1;
	ExSet[0x47].N.Operands[1].O32 = 1;
	ExSet[0x47].N.Operands[1].O64 = 1;
	ExSet[0x47].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x48].Type = x86_x64InstructionType_Normal;
	ExSet[0x48].Behaviour = InstructionBehaviour_Cmovs;

	ExSet[0x48].N.Operands[0].O16 = 1;
	ExSet[0x48].N.Operands[0].O32 = 1;
	ExSet[0x48].N.Operands[0].O64 = 1;
	ExSet[0x48].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x48].N.Operands[1].O16 = 1;
	ExSet[0x48].N.Operands[1].O32 = 1;
	ExSet[0x48].N.Operands[1].O64 = 1;
	ExSet[0x48].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x49].Type = x86_x64InstructionType_Normal;
	ExSet[0x49].Behaviour = InstructionBehaviour_Cmovns;

	ExSet[0x49].N.Operands[0].O16 = 1;
	ExSet[0x49].N.Operands[0].O32 = 1;
	ExSet[0x49].N.Operands[0].O64 = 1;
	ExSet[0x49].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x49].N.Operands[1].O16 = 1;
	ExSet[0x49].N.Operands[1].O32 = 1;
	ExSet[0x49].N.Operands[1].O64 = 1;
	ExSet[0x49].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4A].Type = x86_x64InstructionType_Normal;
	ExSet[0x4A].Behaviour = InstructionBehaviour_Cmovp;

	ExSet[0x4A].N.Operands[0].O16 = 1;
	ExSet[0x4A].N.Operands[0].O32 = 1;
	ExSet[0x4A].N.Operands[0].O64 = 1;
	ExSet[0x4A].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4A].N.Operands[1].O16 = 1;
	ExSet[0x4A].N.Operands[1].O32 = 1;
	ExSet[0x4A].N.Operands[1].O64 = 1;
	ExSet[0x4A].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4B].Type = x86_x64InstructionType_Normal;
	ExSet[0x4B].Behaviour = InstructionBehaviour_Cmovnp;

	ExSet[0x4B].N.Operands[0].O16 = 1;
	ExSet[0x4B].N.Operands[0].O32 = 1;
	ExSet[0x4B].N.Operands[0].O64 = 1;
	ExSet[0x4B].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4B].N.Operands[1].O16 = 1;
	ExSet[0x4B].N.Operands[1].O32 = 1;
	ExSet[0x4B].N.Operands[1].O64 = 1;
	ExSet[0x4B].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4C].Type = x86_x64InstructionType_Normal;
	ExSet[0x4C].Behaviour = InstructionBehaviour_Cmovl;

	ExSet[0x4C].N.Operands[0].O16 = 1;
	ExSet[0x4C].N.Operands[0].O32 = 1;
	ExSet[0x4C].N.Operands[0].O64 = 1;
	ExSet[0x4C].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4C].N.Operands[1].O16 = 1;
	ExSet[0x4C].N.Operands[1].O32 = 1;
	ExSet[0x4C].N.Operands[1].O64 = 1;
	ExSet[0x4C].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4D].Type = x86_x64InstructionType_Normal;
	ExSet[0x4D].Behaviour = InstructionBehaviour_Cmovge;

	ExSet[0x4D].N.Operands[0].O16 = 1;
	ExSet[0x4D].N.Operands[0].O32 = 1;
	ExSet[0x4D].N.Operands[0].O64 = 1;
	ExSet[0x4D].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4D].N.Operands[1].O16 = 1;
	ExSet[0x4D].N.Operands[1].O32 = 1;
	ExSet[0x4D].N.Operands[1].O64 = 1;
	ExSet[0x4D].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4E].Type = x86_x64InstructionType_Normal;
	ExSet[0x4E].Behaviour = InstructionBehaviour_Cmovle;

	ExSet[0x4E].N.Operands[0].O16 = 1;
	ExSet[0x4E].N.Operands[0].O32 = 1;
	ExSet[0x4E].N.Operands[0].O64 = 1;
	ExSet[0x4E].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4E].N.Operands[1].O16 = 1;
	ExSet[0x4E].N.Operands[1].O32 = 1;
	ExSet[0x4E].N.Operands[1].O64 = 1;
	ExSet[0x4E].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x4F].Type = x86_x64InstructionType_Normal;
	ExSet[0x4F].Behaviour = InstructionBehaviour_Cmovg;

	ExSet[0x4F].N.Operands[0].O16 = 1;
	ExSet[0x4F].N.Operands[0].O32 = 1;
	ExSet[0x4F].N.Operands[0].O64 = 1;
	ExSet[0x4F].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x4F].N.Operands[1].O16 = 1;
	ExSet[0x4F].N.Operands[1].O32 = 1;
	ExSet[0x4F].N.Operands[1].O64 = 1;
	ExSet[0x4F].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x50].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x50].RP.A2 = 1;
	ExSet[0x50].RP.DC = 1;

	ExSet[0x50].RP.Index = INDEX_BUFFER(&ExSet[0x50], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movmskpd;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movmskps;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x51].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x51].RP.A2 = 1;
	ExSet[0x51].RP.A3 = 1;
	ExSet[0x51].RP.A4 = 1;
	ExSet[0x51].RP.DC = 1;

	ExSet[0x51].RP.Index = INDEX_BUFFER(&ExSet[0x51], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Sqrtpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Sqrtss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Sqrtsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Sqrtps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x52].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x52].RP.A3 = 1;
	ExSet[0x52].RP.DC = 1;

	ExSet[0x52].RP.Index = INDEX_BUFFER(&ExSet[0x52], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rsqrtss;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Rsqrtps;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x53].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x53].RP.A3 = 1;
	ExSet[0x53].RP.DC = 1;

	ExSet[0x53].RP.Index = INDEX_BUFFER(&ExSet[0x53], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Rcpss;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Rcpps;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x54].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x54].RP.A2 = 1;
	ExSet[0x54].RP.DC = 1;

	ExSet[0x54].RP.Index = INDEX_BUFFER(&ExSet[0x54], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Andpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Andps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x55].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x55].RP.A2 = 1;
	ExSet[0x55].RP.DC = 1;

	ExSet[0x55].RP.Index = INDEX_BUFFER(&ExSet[0x55], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Andnpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Andnps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x56].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x56].RP.A2 = 1;
	ExSet[0x56].RP.DC = 1;

	ExSet[0x56].RP.Index = INDEX_BUFFER(&ExSet[0x56], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Orpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Orps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x57].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x57].RP.A2 = 1;
	ExSet[0x57].RP.DC = 1;

	ExSet[0x57].RP.Index = INDEX_BUFFER(&ExSet[0x57], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Xorpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Xorps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x58].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x58].RP.A2 = 1;
	ExSet[0x58].RP.A3 = 1;
	ExSet[0x58].RP.A4 = 1;
	ExSet[0x58].RP.DC = 1;

	ExSet[0x58].RP.Index = INDEX_BUFFER(&ExSet[0x58], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Addpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Addss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Addsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Addps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x59].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x59].RP.A2 = 1;
	ExSet[0x59].RP.A3 = 1;
	ExSet[0x59].RP.A4 = 1;
	ExSet[0x59].RP.DC = 1;

	ExSet[0x59].RP.Index = INDEX_BUFFER(&ExSet[0x59], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mulpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Mulss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Mulsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Mulps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x5A].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x5A].RP.A2 = 1;
	ExSet[0x5A].RP.A3 = 1;
	ExSet[0x5A].RP.A4 = 1;
	ExSet[0x5A].RP.DC = 1;

	ExSet[0x5A].RP.Index = INDEX_BUFFER(&ExSet[0x5A], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvtpd2ps;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvtss2sd;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvtsd2ss;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Cvtps2pd;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x5B].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x5B].RP.A2 = 1;
	ExSet[0x5B].RP.A3 = 1;
	ExSet[0x5B].RP.DC = 1;

	ExSet[0x5B].RP.Index = INDEX_BUFFER(&ExSet[0x5B], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvtps2dq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvttps2dq;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvtdq2ps;

	SubSet[0x02].N.Operands[0].O128 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O128 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x5C].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x5C].RP.A2 = 1;
	ExSet[0x5C].RP.A3 = 1;
	ExSet[0x5C].RP.A4 = 1;
	ExSet[0x5C].RP.DC = 1;

	ExSet[0x5C].RP.Index = INDEX_BUFFER(&ExSet[0x5C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Subpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Subss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Subsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Subps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x5D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x5D].RP.A2 = 1;
	ExSet[0x5D].RP.A3 = 1;
	ExSet[0x5D].RP.A4 = 1;
	ExSet[0x5D].RP.DC = 1;

	ExSet[0x5D].RP.Index = INDEX_BUFFER(&ExSet[0x5D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Minpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Minss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Minsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Minps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x5E].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x5E].RP.A2 = 1;
	ExSet[0x5E].RP.A3 = 1;
	ExSet[0x5E].RP.A4 = 1;
	ExSet[0x5E].RP.DC = 1;

	ExSet[0x5E].RP.Index = INDEX_BUFFER(&ExSet[0x5E], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Maxpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Maxss;

	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Maxsd;

	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Maxps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x60].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x60].RP.A2 = 1;
	ExSet[0x60].RP.DC = 1;

	ExSet[0x60].RP.Index = INDEX_BUFFER(&ExSet[0x60], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpcklbw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpcklbw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x61].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x61].RP.A2 = 1;
	ExSet[0x61].RP.DC = 1;

	ExSet[0x61].RP.Index = INDEX_BUFFER(&ExSet[0x61], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpcklwd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpcklwd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x62].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x62].RP.A2 = 1;
	ExSet[0x62].RP.DC = 1;

	ExSet[0x62].RP.Index = INDEX_BUFFER(&ExSet[0x62], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpckldq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpckldq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x63].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x63].RP.A2 = 1;
	ExSet[0x63].RP.DC = 1;

	ExSet[0x63].RP.Index = INDEX_BUFFER(&ExSet[0x63], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Packsswb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Packsswb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x64].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x64].RP.A2 = 1;
	ExSet[0x64].RP.DC = 1;

	ExSet[0x64].RP.Index = INDEX_BUFFER(&ExSet[0x64], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpgtb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpgtb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x65].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x65].RP.A2 = 1;
	ExSet[0x65].RP.DC = 1;

	ExSet[0x65].RP.Index = INDEX_BUFFER(&ExSet[0x65], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpgtw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpgtw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x66].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x66].RP.A2 = 1;
	ExSet[0x66].RP.DC = 1;

	ExSet[0x66].RP.Index = INDEX_BUFFER(&ExSet[0x66], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpgtd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpgtd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x67].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x67].RP.A2 = 1;
	ExSet[0x67].RP.DC = 1;

	ExSet[0x67].RP.Index = INDEX_BUFFER(&ExSet[0x67], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Packuswb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Packuswb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x68].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x68].RP.A2 = 1;
	ExSet[0x68].RP.DC = 1;

	ExSet[0x68].RP.Index = INDEX_BUFFER(&ExSet[0x68], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpckhbw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpckhbw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x69].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x69].RP.A2 = 1;
	ExSet[0x69].RP.DC = 1;

	ExSet[0x69].RP.Index = INDEX_BUFFER(&ExSet[0x69], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpckhwd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpckhwd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x6A].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x6A].RP.A2 = 1;
	ExSet[0x6A].RP.DC = 1;

	ExSet[0x6A].RP.Index = INDEX_BUFFER(&ExSet[0x6A], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpckhdq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Punpckhdq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x6B].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x6B].RP.A2 = 1;
	ExSet[0x6B].RP.DC = 1;

	ExSet[0x6B].RP.Index = INDEX_BUFFER(&ExSet[0x6B], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Packssdw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Packssdw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x6C].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0x6C].RP.A2 = 1;

	ExSet[0x6C].RP.Index = INDEX_BUFFER(&ExSet[0x6C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpcklqdq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x6D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0x6D].RP.A2 = 1;

	ExSet[0x6D].RP.Index = INDEX_BUFFER(&ExSet[0x6D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Punpckhqdq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x6E].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x6E].RP.A2 = 1;
	ExSet[0x6E].RP.A3 = 1;
	ExSet[0x6E].RP.DC = 1;

	ExSet[0x6E].RP.Index = INDEX_BUFFER(&ExSet[0x6E], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movq;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O128 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x6F].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x6F].RP.A2 = 1;
	ExSet[0x6F].RP.A3 = 1;
	ExSet[0x6F].RP.DC = 1;

	ExSet[0x6F].RP.Index = INDEX_BUFFER(&ExSet[0x6F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movdqa;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movdqu;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x70].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x70].RP.A2 = 1;
	ExSet[0x70].RP.A3 = 1;
	ExSet[0x70].RP.A4 = 1;
	ExSet[0x70].RP.DC = 1;

	ExSet[0x70].RP.Index = INDEX_BUFFER(&ExSet[0x70], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pshufd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[2].O8 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pshufhw;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[2].O8 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Pshuflw;

	SubSet[0x02].N.Operands[0].O128 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O128 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[2].O8 = 1;
	SubSet[0x02].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Pshufw;

	SubSet[0x03].N.Operands[0].IM = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x03].N.Operands[1].IM = 1;
	SubSet[0x03].N.Operands[1].O64 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Mm;

	SubSet[0x03].N.Operands[2].O8 = 1;
	SubSet[0x03].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0x71].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x71].R.A2 = 1;
	ExSet[0x71].R.A4 = 1;
	ExSet[0x71].R.A6 = 1;

	ExSet[0x71].RP.Index = INDEX_BUFFER(&ExSet[0x71], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrlw;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psrlw;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrlw;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psrlw;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H1 = 1;
	SubSet[0x02].RG.H2 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psllw;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psllw;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	ExSet[0x72].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x72].R.A2 = 1;
	ExSet[0x72].R.A4 = 1;
	ExSet[0x72].R.A6 = 1;

	ExSet[0x72].RP.Index = INDEX_BUFFER(&ExSet[0x72], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrld;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psrld;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrad;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psrad;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H1 = 1;
	SubSet[0x02].RG.H2 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Pslld;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Pslld;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	ExSet[0x73].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0x73].R.A2 = 1;
	ExSet[0x73].R.A3 = 1;
	ExSet[0x73].R.A6 = 1;
	ExSet[0x73].R.A7 = 1;

	ExSet[0x73].RP.Index = INDEX_BUFFER(&ExSet[0x73], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrlq;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psrlq;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x00].RP.A2 = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psrldq;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H1 = 1;
	SubSet[0x02].RG.H2 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	L2SubSet[0x00].RP.A2 = 1;
	L2SubSet[0x00].RP.DC = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Psllq;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	L3SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x01].Behaviour = InstructionBehaviour_Psllq;

	L3SubSet[0x01].N.Operands[0].IM = 1;
	L3SubSet[0x01].N.Operands[0].O64 = 1;
	L3SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L3SubSet[0x01].N.Operands[1].O8 = 1;
	L3SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A3 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H1 = 1;
	SubSet[0x03].RG.H2 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_PrefixRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x00].RP.A2 = 1;

	L2SubSet[0x00].RP.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Pslldq;

	L3SubSet[0x00].N.Operands[0].O128 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L3SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L3SubSet[0x00].N.Operands[1].O8 = 1;
	L3SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_IMM;

	ExSet[0x74].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x74].RP.A2 = 1;
	ExSet[0x74].RP.DC = 1;

	ExSet[0x74].RP.Index = INDEX_BUFFER(&ExSet[0x74], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpeqb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpeqb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x75].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x75].RP.A2 = 1;
	ExSet[0x75].RP.DC = 1;

	ExSet[0x75].RP.Index = INDEX_BUFFER(&ExSet[0x75], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpeqw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpeqw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x76].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x76].RP.A2 = 1;
	ExSet[0x76].RP.DC = 1;

	ExSet[0x76].RP.Index = INDEX_BUFFER(&ExSet[0x76], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pcmpeqd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pcmpeqd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x77].Type = x86_x64InstructionType_Normal;
	ExSet[0x77].Behaviour = InstructionBehaviour_Emms;

	ExSet[0x78].Type = x86_x64InstructionType_Normal;
	ExSet[0x78].Behaviour = InstructionBehaviour_Vmread;

	ExSet[0x78].N.Operands[0].O64 = 1;
	ExSet[0x78].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x78].N.Operands[1].O64 = 1;
	ExSet[0x78].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0x79].Type = x86_x64InstructionType_Normal;
	ExSet[0x79].Behaviour = InstructionBehaviour_Vmwrite;

	ExSet[0x79].N.Operands[0].O64 = 1;
	ExSet[0x79].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0x79].N.Operands[1].O64 = 1;
	ExSet[0x79].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0x7C].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x7C].RP.A2 = 1;
	ExSet[0x7C].RP.A4 = 1;

	ExSet[0x7C].RP.Index = INDEX_BUFFER(&ExSet[0x7C], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Haddpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Haddps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x7D].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0x7D].RP.A2 = 1;
	ExSet[0x7D].RP.A4 = 1;

	ExSet[0x7D].RP.Index = INDEX_BUFFER(&ExSet[0x7D], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Hsubpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Hsubps;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0x7E].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x7E].RP.A2 = 1;
	ExSet[0x7E].RP.A3 = 1;
	ExSet[0x7E].RP.DC = 1;

	ExSet[0x7E].RP.Index = INDEX_BUFFER(&ExSet[0x7E], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Mov;

	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movq;

	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movq;

	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x7F].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0x7F].RP.A2 = 1;
	ExSet[0x7F].RP.A3 = 1;
	ExSet[0x7F].RP.DC = 1;

	ExSet[0x7F].RP.Index = INDEX_BUFFER(&ExSet[0x7F], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movdqa;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Movdqu;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Movq;

	SubSet[0x02].N.Operands[0].IM = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x02].N.Operands[1].IM = 1;
	SubSet[0x02].N.Operands[1].O64 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0x80].Type = x86_x64InstructionType_Normal;
	ExSet[0x80].Behaviour = InstructionBehaviour_Jo;

	ExSet[0x80].N.Operands[0].O16 = 1;
	ExSet[0x80].N.Operands[0].O32 = 1;
	ExSet[0x80].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x81].Type = x86_x64InstructionType_Normal;
	ExSet[0x81].Behaviour = InstructionBehaviour_Jno;

	ExSet[0x81].N.Operands[0].O16 = 1;
	ExSet[0x81].N.Operands[0].O32 = 1;
	ExSet[0x81].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x82].Type = x86_x64InstructionType_Normal;
	ExSet[0x82].Behaviour = InstructionBehaviour_Jb;

	ExSet[0x82].N.Operands[0].O16 = 1;
	ExSet[0x82].N.Operands[0].O32 = 1;
	ExSet[0x82].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x83].Type = x86_x64InstructionType_Normal;
	ExSet[0x83].Behaviour = InstructionBehaviour_Jae;

	ExSet[0x83].N.Operands[0].O16 = 1;
	ExSet[0x83].N.Operands[0].O32 = 1;
	ExSet[0x83].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x84].Type = x86_x64InstructionType_Normal;
	ExSet[0x84].Behaviour = InstructionBehaviour_Je;

	ExSet[0x84].N.Operands[0].O16 = 1;
	ExSet[0x84].N.Operands[0].O32 = 1;
	ExSet[0x84].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x85].Type = x86_x64InstructionType_Normal;
	ExSet[0x85].Behaviour = InstructionBehaviour_Jne;

	ExSet[0x85].N.Operands[0].O16 = 1;
	ExSet[0x85].N.Operands[0].O32 = 1;
	ExSet[0x85].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x86].Type = x86_x64InstructionType_Normal;
	ExSet[0x86].Behaviour = InstructionBehaviour_Jbe;

	ExSet[0x86].N.Operands[0].O16 = 1;
	ExSet[0x86].N.Operands[0].O32 = 1;
	ExSet[0x86].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x87].Type = x86_x64InstructionType_Normal;
	ExSet[0x87].Behaviour = InstructionBehaviour_Ja;

	ExSet[0x87].N.Operands[0].O16 = 1;
	ExSet[0x87].N.Operands[0].O32 = 1;
	ExSet[0x87].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x88].Type = x86_x64InstructionType_Normal;
	ExSet[0x88].Behaviour = InstructionBehaviour_Js;

	ExSet[0x88].N.Operands[0].O16 = 1;
	ExSet[0x88].N.Operands[0].O32 = 1;
	ExSet[0x88].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x89].Type = x86_x64InstructionType_Normal;
	ExSet[0x89].Behaviour = InstructionBehaviour_Jns;

	ExSet[0x89].N.Operands[0].O16 = 1;
	ExSet[0x89].N.Operands[0].O32 = 1;
	ExSet[0x89].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8A].Type = x86_x64InstructionType_Normal;
	ExSet[0x8A].Behaviour = InstructionBehaviour_Jp;

	ExSet[0x8A].N.Operands[0].O16 = 1;
	ExSet[0x8A].N.Operands[0].O32 = 1;
	ExSet[0x8A].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8B].Type = x86_x64InstructionType_Normal;
	ExSet[0x8B].Behaviour = InstructionBehaviour_Jnp;

	ExSet[0x8B].N.Operands[0].O16 = 1;
	ExSet[0x8B].N.Operands[0].O32 = 1;
	ExSet[0x8B].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8C].Type = x86_x64InstructionType_Normal;
	ExSet[0x8C].Behaviour = InstructionBehaviour_Jl;

	ExSet[0x8C].N.Operands[0].O16 = 1;
	ExSet[0x8C].N.Operands[0].O32 = 1;
	ExSet[0x8C].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8D].Type = x86_x64InstructionType_Normal;
	ExSet[0x8D].Behaviour = InstructionBehaviour_Jge;

	ExSet[0x8D].N.Operands[0].O16 = 1;
	ExSet[0x8D].N.Operands[0].O32 = 1;
	ExSet[0x8D].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8E].Type = x86_x64InstructionType_Normal;
	ExSet[0x8E].Behaviour = InstructionBehaviour_Jle;

	ExSet[0x8E].N.Operands[0].O16 = 1;
	ExSet[0x8E].N.Operands[0].O32 = 1;
	ExSet[0x8E].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x8F].Type = x86_x64InstructionType_Normal;
	ExSet[0x8F].Behaviour = InstructionBehaviour_Jg;

	ExSet[0x8F].N.Operands[0].O16 = 1;
	ExSet[0x8F].N.Operands[0].O32 = 1;
	ExSet[0x8F].N.Operands[0].Type = x86_x64OperandType_Rel;

	ExSet[0x90].Type = x86_x64InstructionType_Normal;
	ExSet[0x90].Behaviour = InstructionBehaviour_Seto;

	ExSet[0x90].N.Operands[0].O8 = 1;
	ExSet[0x90].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x91].Type = x86_x64InstructionType_Normal;
	ExSet[0x91].Behaviour = InstructionBehaviour_Setno;

	ExSet[0x91].N.Operands[0].O8 = 1;
	ExSet[0x91].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x92].Type = x86_x64InstructionType_Normal;
	ExSet[0x92].Behaviour = InstructionBehaviour_Setb;

	ExSet[0x92].N.Operands[0].O8 = 1;
	ExSet[0x92].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x93].Type = x86_x64InstructionType_Normal;
	ExSet[0x93].Behaviour = InstructionBehaviour_Setae;

	ExSet[0x93].N.Operands[0].O8 = 1;
	ExSet[0x93].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x94].Type = x86_x64InstructionType_Normal;
	ExSet[0x94].Behaviour = InstructionBehaviour_Sete;

	ExSet[0x94].N.Operands[0].O8 = 1;
	ExSet[0x94].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x95].Type = x86_x64InstructionType_Normal;
	ExSet[0x95].Behaviour = InstructionBehaviour_Setne;

	ExSet[0x95].N.Operands[0].O8 = 1;
	ExSet[0x95].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x96].Type = x86_x64InstructionType_Normal;
	ExSet[0x96].Behaviour = InstructionBehaviour_Setbe;

	ExSet[0x96].N.Operands[0].O8 = 1;
	ExSet[0x96].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x97].Type = x86_x64InstructionType_Normal;
	ExSet[0x97].Behaviour = InstructionBehaviour_Seta;

	ExSet[0x97].N.Operands[0].O8 = 1;
	ExSet[0x97].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x98].Type = x86_x64InstructionType_Normal;
	ExSet[0x98].Behaviour = InstructionBehaviour_Sets;

	ExSet[0x98].N.Operands[0].O8 = 1;
	ExSet[0x98].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x99].Type = x86_x64InstructionType_Normal;
	ExSet[0x99].Behaviour = InstructionBehaviour_Setns;

	ExSet[0x99].N.Operands[0].O8 = 1;
	ExSet[0x99].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9A].Type = x86_x64InstructionType_Normal;
	ExSet[0x9A].Behaviour = InstructionBehaviour_Setp;

	ExSet[0x9A].N.Operands[0].O8 = 1;
	ExSet[0x9A].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9B].Type = x86_x64InstructionType_Normal;
	ExSet[0x9B].Behaviour = InstructionBehaviour_Setnp;

	ExSet[0x9B].N.Operands[0].O8 = 1;
	ExSet[0x9B].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9C].Type = x86_x64InstructionType_Normal;
	ExSet[0x9C].Behaviour = InstructionBehaviour_Setl;

	ExSet[0x9C].N.Operands[0].O8 = 1;
	ExSet[0x9C].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9D].Type = x86_x64InstructionType_Normal;
	ExSet[0x9D].Behaviour = InstructionBehaviour_Setge;

	ExSet[0x9D].N.Operands[0].O8 = 1;
	ExSet[0x9D].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9E].Type = x86_x64InstructionType_Normal;
	ExSet[0x9E].Behaviour = InstructionBehaviour_Setle;

	ExSet[0x9E].N.Operands[0].O8 = 1;
	ExSet[0x9E].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0x9F].Type = x86_x64InstructionType_Normal;
	ExSet[0x9F].Behaviour = InstructionBehaviour_Setg;

	ExSet[0x9F].N.Operands[0].O8 = 1;
	ExSet[0x9F].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xA0].Type = x86_x64InstructionType_Normal;
	ExSet[0xA0].Behaviour = InstructionBehaviour_Push;

	ExSet[0xA0].N.Operands[0].IM = 1;
	ExSet[0xA0].N.Operands[0].O64 = 1;
	ExSet[0xA0].N.Operands[0].Type = x86_x64OperandType_SP;
	ExSet[0xA0].N.Operands[0].RType = x86_x64RegisterType_Segment;

	ExSet[0xA1].Type = x86_x64InstructionType_Normal;
	ExSet[0xA1].Behaviour = InstructionBehaviour_Pop;

	ExSet[0xA1].N.Operands[0].IM = 1;
	ExSet[0xA1].N.Operands[0].O64 = 1;
	ExSet[0xA1].N.Operands[0].Type = x86_x64OperandType_SP;
	ExSet[0xA1].N.Operands[0].RType = x86_x64RegisterType_Segment;

	ExSet[0xA2].Type = x86_x64InstructionType_Normal;
	ExSet[0xA2].Behaviour = InstructionBehaviour_Cpuid;

	ExSet[0xA2].N.Operands[0].IM = 1;
	ExSet[0xA2].N.Operands[0].O32 = 1;
	ExSet[0xA2].N.Operands[0].Type = x86_x64OperandType_AX;

	ExSet[0xA2].N.Operands[1].IM = 1;
	ExSet[0xA2].N.Operands[1].O32 = 1;
	ExSet[0xA2].N.Operands[1].Type = x86_x64OperandType_BX;

	ExSet[0xA2].N.Operands[2].IM = 1;
	ExSet[0xA2].N.Operands[2].O32 = 1;
	ExSet[0xA2].N.Operands[2].Type = x86_x64OperandType_CX;

	ExSet[0xA2].N.Operands[3].IM = 1;
	ExSet[0xA2].N.Operands[3].O32 = 1;
	ExSet[0xA2].N.Operands[3].Type = x86_x64OperandType_DX;

	ExSet[0xA3].Type = x86_x64InstructionType_Normal;
	ExSet[0xA3].Behaviour = InstructionBehaviour_Bt;

	ExSet[0xA3].N.Operands[0].O16 = 1;
	ExSet[0xA3].N.Operands[0].O32 = 1;
	ExSet[0xA3].N.Operands[0].O64 = 1;
	ExSet[0xA3].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xA3].N.Operands[1].O16 = 1;
	ExSet[0xA3].N.Operands[1].O32 = 1;
	ExSet[0xA3].N.Operands[1].O64 = 1;
	ExSet[0xA3].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xA4].Type = x86_x64InstructionType_Normal;
	ExSet[0xA4].Behaviour = InstructionBehaviour_Shld;

	ExSet[0xA4].N.Operands[0].O16 = 1;
	ExSet[0xA4].N.Operands[0].O32 = 1;
	ExSet[0xA4].N.Operands[0].O64 = 1;
	ExSet[0xA4].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xA4].N.Operands[1].O16 = 1;
	ExSet[0xA4].N.Operands[1].O32 = 1;
	ExSet[0xA4].N.Operands[1].O64 = 1;
	ExSet[0xA4].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xA4].N.Operands[2].O8 = 1;
	ExSet[0xA4].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xA5].Type = x86_x64InstructionType_Normal;
	ExSet[0xA5].Behaviour = InstructionBehaviour_Shld;

	ExSet[0xA5].N.Operands[0].O16 = 1;
	ExSet[0xA5].N.Operands[0].O32 = 1;
	ExSet[0xA5].N.Operands[0].O64 = 1;
	ExSet[0xA5].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xA5].N.Operands[1].O16 = 1;
	ExSet[0xA5].N.Operands[1].O32 = 1;
	ExSet[0xA5].N.Operands[1].O64 = 1;
	ExSet[0xA5].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xA5].N.Operands[2].O8 = 1;
	ExSet[0xA5].N.Operands[2].Type = x86_x64OperandType_CX;

	ExSet[0xA8].Type = x86_x64InstructionType_Normal;
	ExSet[0xA8].Behaviour = InstructionBehaviour_Push;

	ExSet[0xA8].N.Operands[0].IM = 1;
	ExSet[0xA8].N.Operands[0].O64 = 1;
	ExSet[0xA8].N.Operands[0].Type = x86_x64OperandType_BP;
	ExSet[0xA8].N.Operands[0].RType = x86_x64RegisterType_Segment;

	ExSet[0xA9].Type = x86_x64InstructionType_Normal;
	ExSet[0xA9].Behaviour = InstructionBehaviour_Pop;

	ExSet[0xA9].N.Operands[0].IM = 1;
	ExSet[0xA9].N.Operands[0].O64 = 1;
	ExSet[0xA9].N.Operands[0].Type = x86_x64OperandType_BP;
	ExSet[0xA9].N.Operands[0].RType = x86_x64RegisterType_Segment;

	ExSet[0xAA].Type = x86_x64InstructionType_Normal;
	ExSet[0xAA].Behaviour = InstructionBehaviour_Rsm;

	ExSet[0xAB].Type = x86_x64InstructionType_Normal;
	ExSet[0xAB].Behaviour = InstructionBehaviour_Bts;

	ExSet[0xAB].N.Operands[0].O16 = 1;
	ExSet[0xAB].N.Operands[0].O32 = 1;
	ExSet[0xAB].N.Operands[0].O64 = 1;
	ExSet[0xAB].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xAB].N.Operands[1].O16 = 1;
	ExSet[0xAB].N.Operands[1].O32 = 1;
	ExSet[0xAB].N.Operands[1].O64 = 1;
	ExSet[0xAB].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xAC].Type = x86_x64InstructionType_Normal;
	ExSet[0xAC].Behaviour = InstructionBehaviour_Shrd;

	ExSet[0xAC].N.Operands[0].O16 = 1;
	ExSet[0xAC].N.Operands[0].O32 = 1;
	ExSet[0xAC].N.Operands[0].O64 = 1;
	ExSet[0xAC].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xAC].N.Operands[1].O16 = 1;
	ExSet[0xAC].N.Operands[1].O32 = 1;
	ExSet[0xAC].N.Operands[1].O64 = 1;
	ExSet[0xAC].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xAC].N.Operands[2].O8 = 1;
	ExSet[0xAC].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xAD].Type = x86_x64InstructionType_Normal;
	ExSet[0xAD].Behaviour = InstructionBehaviour_Shrd;

	ExSet[0xAD].N.Operands[0].O16 = 1;
	ExSet[0xAD].N.Operands[0].O32 = 1;
	ExSet[0xAD].N.Operands[0].O64 = 1;
	ExSet[0xAD].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xAD].N.Operands[1].O16 = 1;
	ExSet[0xAD].N.Operands[1].O32 = 1;
	ExSet[0xAD].N.Operands[1].O64 = 1;
	ExSet[0xAD].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xAD].N.Operands[2].O8 = 1;
	ExSet[0xAD].N.Operands[2].Type = x86_x64OperandType_CX;

	ExSet[0xAE].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 8);

	ExSet[0xAE].R.A0 = 1;
	ExSet[0xAE].R.A1 = 1;
	ExSet[0xAE].R.A2 = 1;
	ExSet[0xAE].R.A3 = 1;
	ExSet[0xAE].R.A4 = 1;
	ExSet[0xAE].R.A5 = 1;
	ExSet[0xAE].R.A6 = 1;
	ExSet[0xAE].R.A7 = 1;

	ExSet[0xAE].R.Index = INDEX_BUFFER(&ExSet[0xAE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fxsave;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Fxrstor;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A0 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Ldmxcsr;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x03].RG.A0 = 1;

	SubSet[0x03].RG.H0 = 1;
	SubSet[0x03].RG.H3 = 1;

	SubSet[0x03].RG.Index = INDEX_BUFFER(&SubSet[0x03], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Stmxcsr;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x04].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x04].RG.A0 = 1;

	SubSet[0x04].RG.H0 = 1;
	SubSet[0x04].RG.H3 = 1;

	SubSet[0x04].RG.Index = INDEX_BUFFER(&SubSet[0x04], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Xsave;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Xrstor;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Lfence;

	SubSet[0x05].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x05].RG.A0 = 1;
	SubSet[0x05].RG.A3 = 1;

	SubSet[0x05].RG.H0 = 1;
	SubSet[0x05].RG.H3 = 1;

	SubSet[0x05].RG.Index = INDEX_BUFFER(&SubSet[0x05], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Xrstor;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Lfence;

	SubSet[0x06].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x06].RG.A0 = 1;
	SubSet[0x06].RG.A3 = 1;

	SubSet[0x06].RG.H0 = 1;
	SubSet[0x06].RG.H3 = 1;

	SubSet[0x06].RG.Index = INDEX_BUFFER(&SubSet[0x06], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Xsaveopt;

	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Mfence;

	SubSet[0x07].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x07].RG.A0 = 1;
	SubSet[0x07].RG.A3 = 1;

	SubSet[0x07].RG.H0 = 1;
	SubSet[0x07].RG.H3 = 1;

	SubSet[0x07].RG.Index = INDEX_BUFFER(&SubSet[0x07], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Clflush;

	L2SubSet[0x00].N.Operands[0].O8 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Sfence;

	ExSet[0xAF].Type = x86_x64InstructionType_Normal;
	ExSet[0xAF].Behaviour = InstructionBehaviour_Imul;

	ExSet[0xAF].N.Operands[0].O16 = 1;
	ExSet[0xAF].N.Operands[0].O32 = 1;
	ExSet[0xAF].N.Operands[0].O64 = 1;
	ExSet[0xAF].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xAF].N.Operands[1].O16 = 1;
	ExSet[0xAF].N.Operands[1].O32 = 1;
	ExSet[0xAF].N.Operands[1].O64 = 1;
	ExSet[0xAF].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xB0].Lockable = 1;
	ExSet[0xB0].Type = x86_x64InstructionType_Normal;
	ExSet[0xB0].Behaviour = InstructionBehaviour_Cmpxchg;

	ExSet[0xB0].N.Operands[0].O8 = 1;
	ExSet[0xB0].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xB0].N.Operands[1].IM = 1;
	ExSet[0xB0].N.Operands[1].O8 = 1;
	ExSet[0xB0].N.Operands[1].Type = x86_x64OperandType_AX;

	ExSet[0xB0].N.Operands[2].O8 = 1;
	ExSet[0xB0].N.Operands[2].Type = x86_x64OperandType_R;

	ExSet[0xB1].Lockable = 1;
	ExSet[0xB1].Type = x86_x64InstructionType_Normal;
	ExSet[0xB1].Behaviour = InstructionBehaviour_Cmpxchg;

	ExSet[0xB1].N.Operands[0].O16 = 1;
	ExSet[0xB1].N.Operands[0].O32 = 1;
	ExSet[0xB1].N.Operands[0].O64 = 1;
	ExSet[0xB1].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xB1].N.Operands[1].IM = 1;
	ExSet[0xB1].N.Operands[1].O16 = 1;
	ExSet[0xB1].N.Operands[1].O32 = 1;
	ExSet[0xB1].N.Operands[1].O64 = 1;
	ExSet[0xB1].N.Operands[1].Type = x86_x64OperandType_AX;

	ExSet[0xB1].N.Operands[2].O16 = 1;
	ExSet[0xB1].N.Operands[2].O32 = 1;
	ExSet[0xB1].N.Operands[2].O64 = 1;
	ExSet[0xB1].N.Operands[2].Type = x86_x64OperandType_R;

	ExSet[0xB2].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xB2].RG.A0 = 1;

	ExSet[0xB2].RG.H0 = 1;
	ExSet[0xB2].RG.H3 = 1;

	ExSet[0xB2].RG.Index = INDEX_BUFFER(&ExSet[0xB2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lss;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DX;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Segment;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;

	ExSet[0xB3].Type = x86_x64InstructionType_Normal;
	ExSet[0xB3].Behaviour = InstructionBehaviour_Btr;

	ExSet[0xB3].N.Operands[0].O16 = 1;
	ExSet[0xB3].N.Operands[0].O32 = 1;
	ExSet[0xB3].N.Operands[0].O64 = 1;
	ExSet[0xB3].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xB3].N.Operands[1].O16 = 1;
	ExSet[0xB3].N.Operands[1].O32 = 1;
	ExSet[0xB3].N.Operands[1].O64 = 1;
	ExSet[0xB3].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xB4].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xB4].RG.A0 = 1;

	ExSet[0xB4].RG.H0 = 1;
	ExSet[0xB4].RG.H3 = 1;

	ExSet[0xB4].RG.Index = INDEX_BUFFER(&ExSet[0xB4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lfs;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_SP;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Segment;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;

	ExSet[0xB5].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xB5].RG.A0 = 1;

	ExSet[0xB5].RG.H0 = 1;
	ExSet[0xB5].RG.H3 = 1;

	ExSet[0xB5].RG.Index = INDEX_BUFFER(&ExSet[0xB5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Lgs;

	SubSet[0x00].N.Operands[0].IM = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_BP;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Segment;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;

	ExSet[0xB6].Type = x86_x64InstructionType_Normal;
	ExSet[0xB6].Behaviour = InstructionBehaviour_Movzx;

	ExSet[0xB6].N.Operands[0].O16 = 1;
	ExSet[0xB6].N.Operands[0].O32 = 1;
	ExSet[0xB6].N.Operands[0].O64 = 1;
	ExSet[0xB6].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xB6].N.Operands[1].O8 = 1;
	ExSet[0xB6].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xB7].Type = x86_x64InstructionType_Normal;
	ExSet[0xB7].Behaviour = InstructionBehaviour_Movzx;

	ExSet[0xB7].N.Operands[0].O16 = 1;
	ExSet[0xB7].N.Operands[0].O32 = 1;
	ExSet[0xB7].N.Operands[0].O64 = 1;
	ExSet[0xB7].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xB7].N.Operands[1].O16 = 1;
	ExSet[0xB7].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xB8].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xB8].RP.A3 = 1;

	ExSet[0xB8].RP.Index = INDEX_BUFFER(&ExSet[0xB8], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Popcnt;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	SubSet[0x00].N.Operands[1].O16 = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xBA].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0xBA].R.A4 = 1;
	ExSet[0xBA].R.A5 = 1;
	ExSet[0xBA].R.A6 = 1;
	ExSet[0xBA].R.A7 = 1;

	ExSet[0xBA].R.Index = INDEX_BUFFER(&ExSet[0xBA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Bt;

	SubSet[0x00].N.Operands[0].O16 = 1;
	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[0].O8 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Bts;

	SubSet[0x01].N.Operands[0].O16 = 1;
	SubSet[0x01].N.Operands[0].O32 = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x01].N.Operands[0].O8 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Btr;

	SubSet[0x02].N.Operands[0].O16 = 1;
	SubSet[0x02].N.Operands[0].O32 = 1;
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].N.Operands[0].O8 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Btc;

	SubSet[0x03].N.Operands[0].O16 = 1;
	SubSet[0x03].N.Operands[0].O32 = 1;
	SubSet[0x03].N.Operands[0].O64 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x03].N.Operands[0].O8 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_IMM;

	ExSet[0xBB].Type = x86_x64InstructionType_Normal;
	ExSet[0xBB].Behaviour = InstructionBehaviour_Btc;

	ExSet[0xBB].N.Operands[0].O16 = 1;
	ExSet[0xBB].N.Operands[0].O32 = 1;
	ExSet[0xBB].N.Operands[0].O64 = 1;
	ExSet[0xBB].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xBB].N.Operands[1].O16 = 1;
	ExSet[0xBB].N.Operands[1].O32 = 1;
	ExSet[0xBB].N.Operands[1].O64 = 1;
	ExSet[0xBB].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xBC].Type = x86_x64InstructionType_Normal;
	ExSet[0xBC].Behaviour = InstructionBehaviour_Bsf;

	ExSet[0xBC].N.Operands[0].O16 = 1;
	ExSet[0xBC].N.Operands[0].O32 = 1;
	ExSet[0xBC].N.Operands[0].O64 = 1;
	ExSet[0xBC].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xBC].N.Operands[1].O16 = 1;
	ExSet[0xBC].N.Operands[1].O32 = 1;
	ExSet[0xBC].N.Operands[1].O64 = 1;
	ExSet[0xBC].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xBD].Type = x86_x64InstructionType_Normal;
	ExSet[0xBD].Behaviour = InstructionBehaviour_Bsr;

	ExSet[0xBD].N.Operands[0].O16 = 1;
	ExSet[0xBD].N.Operands[0].O32 = 1;
	ExSet[0xBD].N.Operands[0].O64 = 1;
	ExSet[0xBD].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xBD].N.Operands[1].O16 = 1;
	ExSet[0xBD].N.Operands[1].O32 = 1;
	ExSet[0xBD].N.Operands[1].O64 = 1;
	ExSet[0xBD].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xBE].Type = x86_x64InstructionType_Normal;
	ExSet[0xBE].Behaviour = InstructionBehaviour_Movsx;

	ExSet[0xBE].N.Operands[0].O16 = 1;
	ExSet[0xBE].N.Operands[0].O32 = 1;
	ExSet[0xBE].N.Operands[0].O64 = 1;
	ExSet[0xBE].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xBE].N.Operands[1].O8 = 1;
	ExSet[0xBE].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xBF].Type = x86_x64InstructionType_Normal;
	ExSet[0xBF].Behaviour = InstructionBehaviour_Movsx;

	ExSet[0xBF].N.Operands[0].O16 = 1;
	ExSet[0xBF].N.Operands[0].O32 = 1;
	ExSet[0xBF].N.Operands[0].O64 = 1;
	ExSet[0xBF].N.Operands[0].Type = x86_x64OperandType_R;

	ExSet[0xBF].N.Operands[1].O16 = 1;
	ExSet[0xBF].N.Operands[1].Type = x86_x64OperandType_M;

	ExSet[0xC0].Type = x86_x64InstructionType_Normal;
	ExSet[0xC0].Behaviour = InstructionBehaviour_Xadd;

	ExSet[0xC0].N.Operands[0].O8 = 1;
	ExSet[0xC0].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xC0].N.Operands[1].O8 = 1;
	ExSet[0xC0].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xC1].Type = x86_x64InstructionType_Normal;
	ExSet[0xC1].Behaviour = InstructionBehaviour_Xadd;

	ExSet[0xC1].N.Operands[0].O16 = 1;
	ExSet[0xC1].N.Operands[0].O32 = 1;
	ExSet[0xC1].N.Operands[0].O64 = 1;
	ExSet[0xC1].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xC1].N.Operands[1].O16 = 1;
	ExSet[0xC1].N.Operands[1].O32 = 1;
	ExSet[0xC1].N.Operands[1].O64 = 1;
	ExSet[0xC1].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xC2].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 4);

	ExSet[0xC2].RP.A2 = 1;
	ExSet[0xC2].RP.A3 = 1;
	ExSet[0xC2].RP.A4 = 1;
	ExSet[0xC2].RP.DC = 1;

	ExSet[0xC2].RP.Index = INDEX_BUFFER(&ExSet[0xC2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cmppd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[2].O8 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cmpss;

	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[1].O32 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].N.Operands[2].O8 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cmpsd;

	SubSet[0x02].N.Operands[0].O128 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[1].O32 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].N.Operands[2].O8 = 1;
	SubSet[0x02].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x03].Type = x86_x64InstructionType_Normal;
	SubSet[0x03].Behaviour = InstructionBehaviour_Cmpps;

	SubSet[0x03].N.Operands[0].O128 = 1;
	SubSet[0x03].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x03].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[1].O128 = 1;
	SubSet[0x03].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x03].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x03].N.Operands[2].O8 = 1;
	SubSet[0x03].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xC3].Type = x86_x64InstructionType_GlobalRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xC3].RG.A0 = 1;

	ExSet[0xC3].RG.H0 = 1;
	ExSet[0xC3].RG.H3 = 1;

	ExSet[0xC3].RG.Index = INDEX_BUFFER(&ExSet[0xC3], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movnti;

	SubSet[0x00].N.Operands[0].O32 = 1;
	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;

	ExSet[0xC4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xC4].RP.A2 = 1;
	ExSet[0xC4].RP.DC = 1;

	ExSet[0xC4].RP.Index = INDEX_BUFFER(&ExSet[0xC4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[2].O8 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x01].N.Operands[0].O128 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].N.Operands[1].O16 = 1;
	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].N.Operands[2].O8 = 1;
	L2SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xC4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xC4].RP.A2 = 1;
	ExSet[0xC4].RP.DC = 1;

	ExSet[0xC4].RP.Index = INDEX_BUFFER(&ExSet[0xC4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x00].RG.A0 = 1;
	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L2SubSet[0x00].N.Operands[2].O8 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x01].N.Operands[0].O128 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;

	L2SubSet[0x01].N.Operands[2].O8 = 1;
	L2SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	SubSet[0x01].RG.A0 = 1;
	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L2SubSet[0x00].N.Operands[1].O16 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;

	L2SubSet[0x00].N.Operands[2].O8 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	L2SubSet[0x01].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x01].Behaviour = InstructionBehaviour_Pinsrw;

	L2SubSet[0x01].N.Operands[0].IM = 1;
	L2SubSet[0x01].N.Operands[0].O64 = 1;
	L2SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L2SubSet[0x01].N.Operands[1].O32 = 1;
	L2SubSet[0x01].N.Operands[1].O64 = 1;
	L2SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;

	L2SubSet[0x01].N.Operands[2].O8 = 1;
	L2SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xC5].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xC5].RP.A2 = 1;
	ExSet[0xC5].RP.DC = 1;

	ExSet[0xC5].RP.Index = INDEX_BUFFER(&ExSet[0xC5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pextrw;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[2].O8 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;
			  
	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pextrw;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	L2SubSet[0x00].N.Operands[2].O8 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xC6].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xC6].RP.A2 = 1;
	ExSet[0xC6].RP.DC = 1;

	ExSet[0xC6].RP.Index = INDEX_BUFFER(&ExSet[0xC6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Shufpd;
	
	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;
	
	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;
	
	SubSet[0x00].N.Operands[2].O8 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_IMM;
	
	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Shufps;
			  
	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;
			  
	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;
			  
	SubSet[0x01].N.Operands[2].O8 = 1;
	SubSet[0x01].N.Operands[2].Type = x86_x64OperandType_IMM;

	ExSet[0xC7].Type = x86_x64InstructionType_UpperRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0xC7].R.A1 = 1;
	ExSet[0xC7].R.A6 = 1;
	ExSet[0xC7].R.A7 = 1;

	ExSet[0xC7].R.Index = INDEX_BUFFER(&ExSet[0xC7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cmpxchg;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x00].N.Operands[1].IM = 1;
	SubSet[0x00].N.Operands[1].O32 = 1;
	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_AX;

	SubSet[0x00].N.Operands[2].IM = 1;
	SubSet[0x00].N.Operands[2].O32 = 1;
	SubSet[0x00].N.Operands[2].O64 = 1;
	SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_DX;

	SubSet[0x01].Type = x86_x64InstructionType_PrefixRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	SubSet[0x01].RP.A2 = 1;
	SubSet[0x01].RP.A3 = 1;
	SubSet[0x01].RP.DC = 1;

	SubSet[0x01].RP.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x00].RG.A0 = 1;

	L2SubSet[0x00].RG.H0 = 1;
	L2SubSet[0x00].RG.H3 = 1;

	L2SubSet[0x00].RG.Index = INDEX_BUFFER(&L2SubSet[0x00], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Vmclear;

	L3SubSet[0x00].N.Operands[0].O64 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x01].RG.A0 = 1;

	L2SubSet[0x01].RG.H0 = 1;
	L2SubSet[0x01].RG.H3 = 1;

	L2SubSet[0x01].RG.Index = INDEX_BUFFER(&L2SubSet[0x01], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Vmxon;

	L3SubSet[0x00].N.Operands[0].O64 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	L2SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L3SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	L2SubSet[0x02].RG.A0 = 1;

	L2SubSet[0x02].RG.H0 = 1;
	L2SubSet[0x02].RG.H3 = 1;

	L2SubSet[0x02].RG.Index = INDEX_BUFFER(&L2SubSet[0x02], L3SubSet);

	L3SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L3SubSet[0x00].Behaviour = InstructionBehaviour_Vmptrld;

	L3SubSet[0x00].N.Operands[0].O64 = 1;
	L3SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Vmptrst;
			  
	SubSet[0x02].N.Operands[0].O64 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_M;

	ExSet[0xC8].Type = x86_x64InstructionType_Normal;
	ExSet[0xC8].Behaviour = InstructionBehaviour_Bswap;

	ExSet[0xC8].N.Operands[0].O16 = 1;
	ExSet[0xC8].N.Operands[0].O32 = 1;
	ExSet[0xC8].N.Operands[0].O64 = 1;
	ExSet[0xC8].N.Operands[0].Type = x86_x64OperandType_AX;

	ExSet[0xC9].Type = x86_x64InstructionType_Normal;
	ExSet[0xC9].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xC9].N.Operands[0].O16 = 1;
	ExSet[0xC9].N.Operands[0].O32 = 1;
	ExSet[0xC9].N.Operands[0].O64 = 1;
	ExSet[0xC9].N.Operands[0].Type = x86_x64OperandType_CX;

	ExSet[0xCA].Type = x86_x64InstructionType_Normal;
	ExSet[0xCA].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCA].N.Operands[0].O16 = 1;
	ExSet[0xCA].N.Operands[0].O32 = 1;
	ExSet[0xCA].N.Operands[0].O64 = 1;
	ExSet[0xCA].N.Operands[0].Type = x86_x64OperandType_DX;

	ExSet[0xCB].Type = x86_x64InstructionType_Normal;
	ExSet[0xCB].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCB].N.Operands[0].O16 = 1;
	ExSet[0xCB].N.Operands[0].O32 = 1;
	ExSet[0xCB].N.Operands[0].O64 = 1;
	ExSet[0xCB].N.Operands[0].Type = x86_x64OperandType_BX;

	ExSet[0xCC].Type = x86_x64InstructionType_Normal;
	ExSet[0xCC].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCC].N.Operands[0].O16 = 1;
	ExSet[0xCC].N.Operands[0].O32 = 1;
	ExSet[0xCC].N.Operands[0].O64 = 1;
	ExSet[0xCC].N.Operands[0].Type = x86_x64OperandType_SP;

	ExSet[0xCD].Type = x86_x64InstructionType_Normal;
	ExSet[0xCD].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCD].N.Operands[0].O16 = 1;
	ExSet[0xCD].N.Operands[0].O32 = 1;
	ExSet[0xCD].N.Operands[0].O64 = 1;
	ExSet[0xCD].N.Operands[0].Type = x86_x64OperandType_BP;

	ExSet[0xCE].Type = x86_x64InstructionType_Normal;
	ExSet[0xCE].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCE].N.Operands[0].O16 = 1;
	ExSet[0xCE].N.Operands[0].O32 = 1;
	ExSet[0xCE].N.Operands[0].O64 = 1;
	ExSet[0xCE].N.Operands[0].Type = x86_x64OperandType_SI;

	ExSet[0xCF].Type = x86_x64InstructionType_Normal;
	ExSet[0xCF].Behaviour = InstructionBehaviour_Bswap;
			 
	ExSet[0xCF].N.Operands[0].O16 = 1;
	ExSet[0xCF].N.Operands[0].O32 = 1;
	ExSet[0xCF].N.Operands[0].O64 = 1;
	ExSet[0xCF].N.Operands[0].Type = x86_x64OperandType_DI;

	ExSet[0xD0].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD0].RP.A2 = 1;
	ExSet[0xD0].RP.A4 = 1;

	ExSet[0xD0].RP.Index = INDEX_BUFFER(&ExSet[0xD0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Addsubpd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Addsubps;
			  
	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;
			  
	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0xD1].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD1].RP.A2 = 1;
	ExSet[0xD1].RP.DC = 1;

	ExSet[0xD1].RP.Index = INDEX_BUFFER(&ExSet[0xD1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psrlw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psrlw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD2].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD2].RP.A2 = 1;
	ExSet[0xD2].RP.DC = 1;

	ExSet[0xD2].RP.Index = INDEX_BUFFER(&ExSet[0xD2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psrld;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psrld;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD3].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD3].RP.A2 = 1;
	ExSet[0xD3].RP.DC = 1;

	ExSet[0xD3].RP.Index = INDEX_BUFFER(&ExSet[0xD3], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psrlq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psrlq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD4].RP.A2 = 1;
	ExSet[0xD4].RP.DC = 1;

	ExSet[0xD4].RP.Index = INDEX_BUFFER(&ExSet[0xD4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD5].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD5].RP.A2 = 1;
	ExSet[0xD5].RP.DC = 1;

	ExSet[0xD5].RP.Index = INDEX_BUFFER(&ExSet[0xD5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmullw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmullw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD6].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0xD6].RP.A2 = 1;
	ExSet[0xD6].RP.A3 = 1;
	ExSet[0xD6].RP.A4 = 1;

	ExSet[0xD6].RP.Index = INDEX_BUFFER(&ExSet[0xD6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Movq;

	SubSet[0x00].N.Operands[0].O64 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O64 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movq2dq;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	SubSet[0x02].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x02].RG.A3 = 1;

	SubSet[0x02].RG.H0 = 1;
	SubSet[0x02].RG.H1 = 1;
	SubSet[0x02].RG.H2 = 1;
	SubSet[0x02].RG.H3 = 1;

	SubSet[0x02].RG.Index = INDEX_BUFFER(&SubSet[0x02], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movdq2q;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Mm;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0xD7].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD7].RP.A2 = 1;
	ExSet[0xD7].RP.DC = 1;

	ExSet[0xD7].RP.Index = INDEX_BUFFER(&ExSet[0xD7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pmovmskb;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Pmovmskb;

	L2SubSet[0x00].N.Operands[0].O32 = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD8].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD8].RP.A2 = 1;
	ExSet[0xD8].RP.DC = 1;

	ExSet[0xD8].RP.Index = INDEX_BUFFER(&ExSet[0xD8], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubusb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubusb;
	
	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;
	
	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xD9].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xD9].RP.A2 = 1;
	ExSet[0xD9].RP.DC = 1;

	ExSet[0xD9].RP.Index = INDEX_BUFFER(&ExSet[0xD9], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubusw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubusw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDA].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDA].RP.A2 = 1;
	ExSet[0xDA].RP.DC = 1;

	ExSet[0xDA].RP.Index = INDEX_BUFFER(&ExSet[0xDA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pminub;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pminub;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDB].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDB].RP.A2 = 1;
	ExSet[0xDB].RP.DC = 1;

	ExSet[0xDB].RP.Index = INDEX_BUFFER(&ExSet[0xDB], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pand;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pand;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDC].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDC].RP.A2 = 1;
	ExSet[0xDC].RP.DC = 1;

	ExSet[0xDC].RP.Index = INDEX_BUFFER(&ExSet[0xDC], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddusb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddusb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDD].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDD].RP.A2 = 1;
	ExSet[0xDD].RP.DC = 1;

	ExSet[0xDD].RP.Index = INDEX_BUFFER(&ExSet[0xDD], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddusw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddusw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDE].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDE].RP.A2 = 1;
	ExSet[0xDE].RP.DC = 1;

	ExSet[0xDE].RP.Index = INDEX_BUFFER(&ExSet[0xDE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmaxub;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmaxub;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xDF].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xDF].RP.A2 = 1;
	ExSet[0xDF].RP.DC = 1;

	ExSet[0xDF].RP.Index = INDEX_BUFFER(&ExSet[0xDF], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pandn;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pandn;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE0].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE0].RP.A2 = 1;
	ExSet[0xE0].RP.DC = 1;

	ExSet[0xE0].RP.Index = INDEX_BUFFER(&ExSet[0xE0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pavgb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pavgb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE1].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE1].RP.A2 = 1;
	ExSet[0xE1].RP.DC = 1;

	ExSet[0xE1].RP.Index = INDEX_BUFFER(&ExSet[0xE1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psraw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psraw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE2].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE2].RP.A2 = 1;
	ExSet[0xE2].RP.DC = 1;

	ExSet[0xE2].RP.Index = INDEX_BUFFER(&ExSet[0xE2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psrad;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psrad;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE3].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE3].RP.A2 = 1;
	ExSet[0xE3].RP.DC = 1;

	ExSet[0xE3].RP.Index = INDEX_BUFFER(&ExSet[0xE3], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pavgw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pavgw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE4].RP.A2 = 1;
	ExSet[0xE4].RP.DC = 1;

	ExSet[0xE4].RP.Index = INDEX_BUFFER(&ExSet[0xE4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmulhuw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmulhuw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE5].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE5].RP.A2 = 1;
	ExSet[0xE5].RP.DC = 1;

	ExSet[0xE5].RP.Index = INDEX_BUFFER(&ExSet[0xE5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmulhw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmulhw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE6].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 3);

	ExSet[0xE6].RP.A2 = 1;
	ExSet[0xE6].RP.A3 = 1;
	ExSet[0xE6].RP.A4 = 1;

	ExSet[0xE6].RP.Index = INDEX_BUFFER(&ExSet[0xE6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Cvttpd2dq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Cvtdq2pd;
			  
	SubSet[0x01].N.Operands[0].O128 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Xmm;
			  
	SubSet[0x01].N.Operands[1].O128 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x02].Type = x86_x64InstructionType_Normal;
	SubSet[0x02].Behaviour = InstructionBehaviour_Cvtpd2dq;
			 
	SubSet[0x02].N.Operands[0].O128 = 1;
	SubSet[0x02].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x02].N.Operands[0].RType = x86_x64RegisterType_Xmm;
			 
	SubSet[0x02].N.Operands[1].O128 = 1;
	SubSet[0x02].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x02].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0xE7].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE7].RP.A2 = 1;
	ExSet[0xE7].RP.DC = 1;

	ExSet[0xE7].RP.Index = INDEX_BUFFER(&ExSet[0xE7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movntdq;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A0 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Movntq;
				
	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].O64 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Mm;
				
	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE8].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE8].RP.A2 = 1;
	ExSet[0xE8].RP.DC = 1;

	ExSet[0xE8].RP.Index = INDEX_BUFFER(&ExSet[0xE8], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubsb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubsb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xE9].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xE9].RP.A2 = 1;
	ExSet[0xE9].RP.DC = 1;

	ExSet[0xE9].RP.Index = INDEX_BUFFER(&ExSet[0xE9], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubsw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubsw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xEA].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xEA].RP.A2 = 1;
	ExSet[0xEA].RP.DC = 1;

	ExSet[0xEA].RP.Index = INDEX_BUFFER(&ExSet[0xEA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pminsw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pminsw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xEB].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xEB].RP.A2 = 1;
	ExSet[0xEB].RP.DC = 1;

	ExSet[0xEB].RP.Index = INDEX_BUFFER(&ExSet[0xEB], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Por;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Por;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xEC].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xEC].RP.A2 = 1;
	ExSet[0xEC].RP.DC = 1;

	ExSet[0xEC].RP.Index = INDEX_BUFFER(&ExSet[0xEC], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddsb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddsb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xED].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xED].RP.A2 = 1;
	ExSet[0xED].RP.DC = 1;

	ExSet[0xED].RP.Index = INDEX_BUFFER(&ExSet[0xED], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddsw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddsw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xEE].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xEE].RP.A2 = 1;
	ExSet[0xEE].RP.DC = 1;

	ExSet[0xEE].RP.Index = INDEX_BUFFER(&ExSet[0xEE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmaxsw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmaxsw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xEF].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xEF].RP.A2 = 1;
	ExSet[0xEF].RP.DC = 1;

	ExSet[0xEF].RP.Index = INDEX_BUFFER(&ExSet[0xEF], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pxor;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pxor;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF0].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	ExSet[0xF0].RP.A4 = 1;

	ExSet[0xF0].RP.Index = INDEX_BUFFER(&ExSet[0xF0], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A0 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Lddqu;

	L2SubSet[0x00].N.Operands[0].O128 = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	ExSet[0xF1].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF1].RP.A2 = 1;
	ExSet[0xF1].RP.DC = 1;

	ExSet[0xF1].RP.Index = INDEX_BUFFER(&ExSet[0xF1], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psllw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psllw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF2].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF2].RP.A2 = 1;
	ExSet[0xF2].RP.DC = 1;

	ExSet[0xF2].RP.Index = INDEX_BUFFER(&ExSet[0xF2], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pslld;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pslld;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF3].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF3].RP.A2 = 1;
	ExSet[0xF3].RP.DC = 1;

	ExSet[0xF3].RP.Index = INDEX_BUFFER(&ExSet[0xF3], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psllq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psllq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF4].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF4].RP.A2 = 1;
	ExSet[0xF4].RP.DC = 1;

	ExSet[0xF4].RP.Index = INDEX_BUFFER(&ExSet[0xF4], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmuludq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmuludq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF5].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF5].RP.A2 = 1;
	ExSet[0xF5].RP.DC = 1;

	ExSet[0xF5].RP.Index = INDEX_BUFFER(&ExSet[0xF5], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Pmaddwd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Pmaddwd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF6].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF6].RP.A2 = 1;
	ExSet[0xF6].RP.DC = 1;

	ExSet[0xF6].RP.Index = INDEX_BUFFER(&ExSet[0xF6], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psadbw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psadbw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF7].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF7].RP.A2 = 1;
	ExSet[0xF7].RP.DC = 1;

	ExSet[0xF7].RP.Index = INDEX_BUFFER(&ExSet[0xF7], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x00].RG.A3 = 1;

	SubSet[0x00].RG.H0 = 1;
	SubSet[0x00].RG.H1 = 1;
	SubSet[0x00].RG.H2 = 1;
	SubSet[0x00].RG.H3 = 1;

	SubSet[0x00].RG.Index = INDEX_BUFFER(&SubSet[0x00], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Maskmovq;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].DSO = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	L2SubSet[0x00].N.Operands[1].O128 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	L2SubSet[0x00].N.Operands[2].O128 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_GlobalRedirect;

	L2SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 1);

	SubSet[0x01].RG.A3 = 1;

	SubSet[0x01].RG.H0 = 1;
	SubSet[0x01].RG.H1 = 1;
	SubSet[0x01].RG.H2 = 1;
	SubSet[0x01].RG.H3 = 1;

	SubSet[0x01].RG.Index = INDEX_BUFFER(&SubSet[0x01], L2SubSet);

	L2SubSet[0x00].Type = x86_x64InstructionType_Normal;
	L2SubSet[0x00].Behaviour = InstructionBehaviour_Maskmovdqu;

	L2SubSet[0x00].N.Operands[0].IM = 1;
	L2SubSet[0x00].N.Operands[0].DSO = 1;
	L2SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_DI;

	L2SubSet[0x00].N.Operands[1].IM = 1;
	L2SubSet[0x00].N.Operands[1].O64 = 1;
	L2SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_R;
	L2SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Mm;

	L2SubSet[0x00].N.Operands[2].IM = 1;
	L2SubSet[0x00].N.Operands[2].O64 = 1;
	L2SubSet[0x00].N.Operands[2].Type = x86_x64OperandType_M;
	L2SubSet[0x00].N.Operands[2].RType = x86_x64RegisterType_Mm;

	ExSet[0xF8].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF8].RP.A2 = 1;
	ExSet[0xF8].RP.DC = 1;

	ExSet[0xF8].RP.Index = INDEX_BUFFER(&ExSet[0xF8], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xF9].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xF9].RP.A2 = 1;
	ExSet[0xF9].RP.DC = 1;

	ExSet[0xF9].RP.Index = INDEX_BUFFER(&ExSet[0xF9], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xFA].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xFA].RP.A2 = 1;
	ExSet[0xFA].RP.DC = 1;

	ExSet[0xFA].RP.Index = INDEX_BUFFER(&ExSet[0xFA], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xFB].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xFB].RP.A2 = 1;
	ExSet[0xFB].RP.DC = 1;

	ExSet[0xFB].RP.Index = INDEX_BUFFER(&ExSet[0xFB], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Psubq;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Psubq;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xFC].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xFC].RP.A2 = 1;
	ExSet[0xFC].RP.DC = 1;

	ExSet[0xFC].RP.Index = INDEX_BUFFER(&ExSet[0xFC], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddb;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddb;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xFD].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xFD].RP.A2 = 1;
	ExSet[0xFD].RP.DC = 1;

	ExSet[0xFD].RP.Index = INDEX_BUFFER(&ExSet[0xFD], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddw;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddw;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	ExSet[0xFE].Type = x86_x64InstructionType_PrefixRedirect;

	SubSet = ALLOCATE_BUFFER(AllocationArrow, SetBuffer, 2);

	ExSet[0xFE].RP.A2 = 1;
	ExSet[0xFE].RP.DC = 1;

	ExSet[0xFE].RP.Index = INDEX_BUFFER(&ExSet[0xFE], SubSet);

	SubSet[0x00].Type = x86_x64InstructionType_Normal;
	SubSet[0x00].Behaviour = InstructionBehaviour_Paddd;

	SubSet[0x00].N.Operands[0].O128 = 1;
	SubSet[0x00].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x00].N.Operands[0].RType = x86_x64RegisterType_Xmm;

	SubSet[0x00].N.Operands[1].O128 = 1;
	SubSet[0x00].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x00].N.Operands[1].RType = x86_x64RegisterType_Xmm;

	SubSet[0x01].Type = x86_x64InstructionType_Normal;
	SubSet[0x01].Behaviour = InstructionBehaviour_Paddd;

	SubSet[0x01].N.Operands[0].IM = 1;
	SubSet[0x01].N.Operands[0].O64 = 1;
	SubSet[0x01].N.Operands[0].Type = x86_x64OperandType_R;
	SubSet[0x01].N.Operands[0].RType = x86_x64RegisterType_Mm;

	SubSet[0x01].N.Operands[1].IM = 1;
	SubSet[0x01].N.Operands[1].O64 = 1;
	SubSet[0x01].N.Operands[1].Type = x86_x64OperandType_M;
	SubSet[0x01].N.Operands[1].RType = x86_x64RegisterType_Mm;

	if (SetSize)
		*SetSize = AllocationArrow * sizeof(x86_x64Instruction);
}