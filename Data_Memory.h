#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
#ifndef DATA_MEMORY_H
#define	DATA_MEMORY_H

using std::string;
class Data_Memory {
    string Memory_Array[200];
public:
    Data_Memory();
    Data_Memory(const Data_Memory& orig);
    virtual ~Data_Memory();		
    string memRead;
    string memWrite;
    bool set_data(string, string);
    string get_data(string);
private:

};

#endif	/* DATA_MEMORY_H */

