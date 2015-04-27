/* 
 * File:   Register_Memory.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:21 AM
 */

#ifndef REGISTER_MEMORY_H
#define	REGISTER_MEMORY_H

#include <string>
using namespace std;

class Register_Memory{
		string Memory_Array[8];
	public:
		Register_Memory();
		string regWrite;
		void set_register(string, string);
		string get_register(string);
};

#endif	/* REGISTER_MEMORY_H */

