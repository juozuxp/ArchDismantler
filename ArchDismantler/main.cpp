#include <string.h>
#include <stdio.h>
#include "x86_x64.h"
#include "x86_x64Parser.h"
#include <Windows.h>

int main()
{
	unsigned long long OperationCount;

	static unsigned char Operations[0x100000];
	unsigned char Buffer[0x8000];

	//unsigned char Code[] = { 0x4F, 0xF2, 0x0F, 0xF7, 0xC0 /*0xCD, 0x5B, 0x07*/ /*, 0xC1, 0x00, 0x00*/ };

	printf("Parsing: %llX\n\n", main);

	ConstructInstructionSet((x86_x64Instruction*)&Buffer, &OperationCount);

	ParseCode((x86_x64Instruction*)Buffer, main, 0x9000  /*sizeof(Code)*/, (Operation*)Operations, &OperationCount);
	Visualize((Operation*)Operations, OperationCount);

	system("pause");
}