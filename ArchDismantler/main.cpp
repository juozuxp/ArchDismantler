#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include "x86_x64.h"
#include "x86_x64Parser.h"
#include "ConsoleVisualizer.h"

int main()
{
	unsigned long long OperationCount;

	static unsigned char Operations[0x100000];
	unsigned char Buffer[0x8000];

	VisualComponents Components;

	unsigned char Code[] = { 0x65, 0x01, 0x44, 0x00, 0x00 /*0xCD, 0x5B, 0x07*/ /*, 0xC1, 0x00, 0x00*/ };

	printf("Parsing: %llX\n\n", printf);

	ConstructInstructionSet((x86_x64Instruction*)&Buffer, &OperationCount);

	ParseCodeBySize((x86_x64Instruction*)Buffer, GetModuleHandleA, 0x2000  /*sizeof(Code)*/, (Operation*)Operations, &OperationCount, Buffer + 0x6000);

	memset(&Components, 0, sizeof(Components));
	memset(&Components.Colors, 0xFF, sizeof(Components.Colors));

	Components.DissasemblyBase = GetModuleHandleA;
	Components.DisassemblySource = GetModuleHandleA;
	Components.InstructionSizes = Buffer + 0x6000;

	Components.OpcodeBytePadding = 14;

	Components.Colors[ComponentColors_Offset] = 0xFF00FF;
	Components.Colors[ComponentColors_Address] = 0xFF00FF;
	Components.Colors[ComponentColors_Multiplier] = 0x8080FF;
	Components.Colors[ComponentColors_OperationBytes] = 0x008080;
	Components.Colors[ComponentColors_ImmediateMemory] = 0xFF00FF;

	Components.Colors[ComponentColors_Behaviour] = 0xFFFFFF;
	Components.Colors[ComponentColors_MemoryEnclosure] = 0xFFFFFF;

	Components.Colors[ComponentColors_MemorySize] = 0xADD8E6;

	Components.Colors[ComponentColors_LowRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_HighRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_WordRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_DwordRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_QwordRegisters] = 0x80FF80;

	Components.Colors[ComponentColors_DebugRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_QuadRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_VectorRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_ControlRegisters] = 0x80FF80;
	Components.Colors[ComponentColors_FloatingRegisters] = 0x80FF80;

	Components.Colors[ComponentColors_SegmentRegisters] = 0x80FF80;

	Components.Flags[ComponentFlags_HexOffset] = 1;
	Components.Flags[ComponentFlags_PadOffset] = 1;
	Components.Flags[ComponentFlags_HexAddress] = 1;
	Components.Flags[ComponentFlags_PadAddress] = 1;
	Components.Flags[ComponentFlags_HexImmediateMemory] = 1;

	Components.Flags[ComponentFlags_DisplayOperationBytes] = 1;
	Components.Flags[ComponentFlags_DisplayAddressRelative] = 1;

	Components.Flags[ComponentFlags_SpecifyMemorySize] = 1;

	x86_x64BuildRegisterSet(&Components);

	Visualize((Operation*)Operations, OperationCount, &Components);

	system("pause");
}