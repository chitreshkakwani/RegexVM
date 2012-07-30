#ifndef __REGEX_VM_H__
#define __REGEX_VM_H__

#include "instruction.hpp"

REGEX_VM_NAMESPACE_BEGIN

class IRegexVM
{
public:

	virtual int Run(Instruction* program, char* input) = 0;
};

REGEX_VM_NAMESPACE_END

#endif
