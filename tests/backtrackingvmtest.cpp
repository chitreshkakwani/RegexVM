#include "regexvm.hpp"
#include "backtrackingvm.hpp"
#include <cassert>
#include <iostream>

using namespace std;
using namespace REGEX_VM_NAMESPACE;

void testbacktrackingvm()
{
	IRegexVM* vm = new BacktrackingVM();

	/* Regular expression : ch */
	Instruction instArr[3];
	instArr[0].Opcode = LITERAL;
	instArr[0].c = 'c';
	 
	instArr[1].Opcode = LITERAL;
	instArr[1].c = 'h';

	instArr[2].Opcode = MATCH;

	char input[] = "ch";
	assert(vm->Run(instArr, input));

	/* Regular expression c+h */
	Instruction instA[4];
	instA[0].Opcode = LITERAL;
	instA[0].c = 'c';
	 
	instA[1].Opcode = SPLIT;
	instA[1].x = instA;
	instA[1].y = &instA[2];
	

	instA[2].Opcode = LITERAL;
	instA[2].c = 'h';

	instA[3].Opcode = MATCH;

	char inputA[] = "cch";
	assert(vm->Run(instA, inputA));
	char inputB[] = "cccch";
	assert(vm->Run(instA, inputB));
	char inputC[] = "h";
	assert(0 == vm->Run(instA, inputC));
	cout << "Tests passed." << endl;
}

int main()
{
	testbacktrackingvm();
	return 0;
}

