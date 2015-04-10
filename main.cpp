/* 
 * File:   main.cpp
 * Author: ltd45_000
 *
 * Created on April 9, 2015, 6:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include <cmath>
#include "Buffer.h"
#include "Control.h"
#include "Data_Memory.h"
#include "Double_Mux.h"
#include "Instruction_Memory.h"
#include "Mux.h"
#include "Register_Memory.h"
#include "Unknown.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Instruction_Memory myMemory;
    Register_Memory myReg;
    Data_Memory myData;
    Mux myMux;
    Double_Mux myDMux;
    Buffer myBuff;
    Control myControl;
    
    string A = "0000000000001000";
    string B = "0000000001000011";
    string opp = "111";
    string alu = ALU(A, B, opp);
    cout << alu << endl;
/*
myControl.decodeOpp("0010");
cout << myControl.regDest << endl;
cout << myControl.regWrite << endl;
cout << myControl.ALUsrc << endl;
cout << myControl.Jump << endl;
cout << myControl.Branch << endl;
cout << myControl.PCsrc << endl;
cout << myControl.ALUopp << endl;
cout << myControl.memWrite << endl;
cout << myControl.memRead << endl;
cout << myControl.memToReg << endl;
*/
	
return 0;
}

