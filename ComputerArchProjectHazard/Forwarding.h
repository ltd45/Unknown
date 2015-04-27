/* 
 * File:   Forwarding.h
 * Author: Peter
 *
 * Created on April 22, 2015, 7:57 PM
 */

#ifndef FORWARDING_H
#define	FORWARDING_H

using namespace std;

#include <string>

class Forwarding{
public:
    string ForwardAControl;
    string ForwardBControl;
    
    string MemRegWrite;
    string WbRegWrite;
    string ExeRs;
    string ExeRt;
    string MemDest;
    string WbDest;
    
    Forwarding();
    void set_forwarding_control();
    
};

#endif	/* FORWARDING_H */

