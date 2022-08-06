#include <string.h>
#include <stdio.h>
#include "x86_x64.h"
#include <Windows.h>

int main()
{
	unsigned long long OperationCount;

	unsigned char Operations[0x8000];
	unsigned char Buffer[0x4000];

	unsigned char Code[] = { 0x66, 0x0F, 0x6F, 0x00 /*0xCD, 0x5B, 0x07*/ /*, 0xC1, 0x00, 0x00*/ };

	printf("Parsing: %llX\n\n", ConstructInstructionSet);

	ConstructInstructionSet((x86_x64Instruction*)&Buffer);
	ParseCode((x86_x64Instruction*)Buffer, Code,  sizeof(Code), (Operation*)Operations, &OperationCount);
	// ParseCode((x86_x64Instruction*)Buffer, ParseCode, 0x100, (Operation*)Operations, &OperationCount);
	Visualize((Operation*)Operations, OperationCount);

	system("pause");
}