#include "backtrackingvm.hpp"

using namespace REGEX_VM_NAMESPACE;

int BacktrackingVM::Run(Instruction* program, char* input)
{
	int MAXTHREADS = 1000;

	Thread threadStack[MAXTHREADS];
	Instruction* pc;
	char* sp;

	threadStack[0] = Thread(program, input); 
	int stackSize = 1;
	while(stackSize > 0)
	{
		/* Pop a thread from the stack and run it */
		Thread currentThread = threadStack[stackSize - 1];
		stackSize--;
		pc = currentThread.pc;
		sp = currentThread.sp;
		bool failed = false;
		for(;;)
		{
			switch(pc->Opcode)
			{
			case LITERAL:
				{
					if(*sp != *input)
					{
						/* Literal doesn't match the character pointed at by stack pointer */	
						failed = true;
						break;
					}
					/* Literal matched. Advance to next instruction and character in input sequence */
					pc++;
					sp++;
					continue;
				}
			case MATCH:
				{
					/* Match instruction reached. The expression is a match */
					return 1;
				}
			case JMP:
				{
					/* Create a thread with branched instruction and push it in the stack */
					pc = pc->x;
					continue;
				}
			case SPLIT:
				{
					/* Create a thread with branched instruction and push it in the stack */
					if(stackSize == MAXTHREADS)
						throw "Stack overflow";
					threadStack[stackSize] = Thread(pc->y, sp);
					pc = pc->x;
					continue;
				}
			}

			if(failed)
				break;
		}
	}
}
