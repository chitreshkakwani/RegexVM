#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "macros.hpp"

REGEX_VM_NAMESPACE_BEGIN

typedef enum
{
	LITERAL,
	MATCH,
	JMP,
	SPLIT
}OPCODE;

class Instruction
{
public:
	OPCODE Opcode;
	int c;
	Instruction* x;
	Instruction* y;
};

REGEX_VM_NAMESPACE_END

#endif
