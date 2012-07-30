#ifndef __BACKTRACKING_VM_H__
#define __BACKTRACKING_VM_H__

#include "regexvm.hpp"

REGEX_VM_NAMESPACE_BEGIN

class BacktrackingVM : public IRegexVM
{
public:
	virtual int Run(Instruction* program, char* input);	
};

class Thread
{
public:
	Thread(){}

	~Thread(){}

	Thread(Instruction* prog, char* stackPointer)
	{
		pc = prog;
		sp = stackPointer;
	}
	Instruction* pc;
	char* sp;
};

REGEX_VM_NAMESPACE_END

#endif
