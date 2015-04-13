/* 
 * File:   Data_Memory.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:19 AM
 */

#ifndef DATA_MEMORY_H
#define	DATA_MEMORY_H

#include <string>
using namespace std;

class Data_Memory{
		string Memory_Array[200];
	public:
		Data_Memory();
		string memRead;
		string memWrite;
		void set_data(string, string);
		string get_data(string);
};

#endif	/* DATA_MEMORY_H */

