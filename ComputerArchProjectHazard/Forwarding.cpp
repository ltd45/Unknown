#include <iostream>
#include <cstdlib>
#include <string>
#include "Forwarding.h"

using namespace std;

Forwarding::Forwarding(){
    ForwardAControl = "00";
    ForwardBControl = "00";
    MemRegWrite = "0";
    WbRegWrite = "0";
    
    ExeRs = "000";
    ExeRt = "000";
    MemDest = "000";
    WbDest = "000";
}

void Forwarding::set_forwarding_control(){
    //Forwarding control for the RS double mux.
    if((MemRegWrite == "1") && (MemDest == ExeRs)){
        ForwardAControl = "10";
    }
    else if((WbRegWrite == "1") && (WbDest == ExeRs)){
        ForwardAControl = "01";
    }
    else{
        ForwardAControl = "00";
    }
    
    //Forwarding control for the RT double mux.
    if((MemRegWrite == "1") && (MemDest == ExeRt)){
        ForwardBControl = "10";
    }
    else if((WbRegWrite == "1") && (WbDest == ExeRt)){
        ForwardBControl = "01";
    }
    else{
        ForwardBControl = "00";
    }
    
}