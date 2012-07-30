#ifndef __BACKTRACKING_VM_H__
#define __BACKTRACKING_VM_H__

#include "regexvm.hpp"

REGEX_VM_NAMESPACE_BEGIN

class BacktrackingVM : public RegexVM
{
public:
	virtual int Run(Instruction* pc, char* c);	
};

REGEX_VM_NAMESPACE_END

#endif
