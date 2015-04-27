#ifndef INSTRUCTION_MEMORY_H
#define	INSTRUCTION_MEMORY_H

#include <string>
using namespace std;

class Instruction_Memory{
		string Memory_Array[200];
	public:
		Instruction_Memory();
		bool set_instruction(string, string);
		string get_instruction(string);
};

#endif	/* INSTRUCTION_MEMORY_H */

