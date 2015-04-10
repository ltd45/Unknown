#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
#ifndef REGISTER_MEMORY_H
#define	REGISTER_MEMORY_H

using std::string;
class Register_Memory {
    string Memory_Array[8];
public:
    Register_Memory();
    Register_Memory(const Register_Memory& orig);
    virtual ~Register_Memory();
    string regWrite;
    bool set_register(string, string);
    string get_register(string);
private:

};


#endif	/* REGISTER_MEMORY_H */

