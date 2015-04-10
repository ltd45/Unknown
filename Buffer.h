#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>

#ifndef BUFFER_H
#define	BUFFER_H
using std::string;
class Buffer {
    string oldBuff;
    string newBuff;
public:
    Buffer();
    Buffer(const Buffer& orig);
    virtual ~Buffer();
    void set_newBuff(string);
    string get_oldBuff();
    void refreshBuff();
private:

};

#endif	/* BUFFER_H */

