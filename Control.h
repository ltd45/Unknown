/* 
 * File:   Control.h
 * Author: ltd45_000
 *
 * Created on April 9, 2015, 6:09 PM
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>

#ifndef CONTROL_H
#define	CONTROL_H

using std::string;
using std::map;
class Control {
    string regDest;
    string regWrite;
    string ALUsrc;
    string Jump;
    string Branch;
    string PCsrc;
    string ALUopp;
    string memWrite;
    string memRead;
    string memToReg;
public:
    Control();
    Control(const Control& orig);
    virtual ~Control();
    void decodeOpp(string);
private:

};

#endif	/* CONTROL_H */

