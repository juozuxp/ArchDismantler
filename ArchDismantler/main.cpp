#include <string.h>
#include <stdio.h>
#include "x86_x64.h"
#include <Windows.h>

int main()
{
	unsigned long long OperationCount;

	unsigned char Operations[0x1000];
	unsigned char Buffer[0x4000];

	unsigned char Code[] = { 0x66, 0x6B, 0x00, 0x00 /*, 0xC1, 0x00, 0x00*/ };

	ConstructInstructionSet((x86_x64Instruction*)&Buffer);
	ParseCode((x86_x64Instruction*)Buffer, Code, sizeof(Code), (Operation*)Operations, &OperationCount);
	Visualize((Operation*)Operations, OperationCount);

	system("pause");
}