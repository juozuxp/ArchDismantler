#include <string.h>
#include <stdio.h>
#include "x86_x64.h"

int main()
{
	unsigned long long OperationCount;

	unsigned char Operations[0x1000];
	unsigned char Buffer[0x2000];

	unsigned char Code[] = { 0x30, 0x44, 0xD0, 0x00 /*, 0xC1, 0x00, 0x00*/ };

	ConstructInstructionSet((x86_x64Instruction*)&Buffer);
	ParseCode((x86_x64Instruction*)Buffer, Code, sizeof(Code), (Operation*)Operations, &OperationCount);
	Visualize((Operation*)Operations, OperationCount);
}