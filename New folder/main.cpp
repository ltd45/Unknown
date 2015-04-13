#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include "Processor.h"
#include "Buffer.h"
#include "Control.h"
#include "Data_Memory.h"
#include "Instruction_Memory.h"
#include "Mux.h"
#include "Register_Memory.h"
#include "Double_Mux.h"
#include "Unknown.h"
using namespace std;


int main()
{
Processor myProcessor;

myProcessor.PC = "0000000000000000";
myProcessor.currentPC = "0000000000000000";
myProcessor.IFID.set_size(32);
myProcessor.IDEXE.set_size(63);
myProcessor.EXEMEM.set_size(39);
myProcessor.MEMWB.set_size(37);
	
myProcessor.regMem.regWrite = "1";
myProcessor.dataMem.memWrite = "1";
myProcessor.load_instructions();
myProcessor.load_registers();
myProcessor.load_memory();
myProcessor.regMem.regWrite = "0";
myProcessor.dataMem.memWrite = "0";

int clockCycle = 0;
bool keepGoing = true;
while(keepGoing){
	//output the content of the registers and memory
	printf("\nRegisters:    Data Memory:\n");
	for(int i=0; i<8; i++){
		string hexReg, hexMem, binReg, binMem;
		int intMemAddressValue = i * 2;
		binReg = myProcessor.regMem.get_register(int_to_three_bit(i));
		myProcessor.dataMem.memRead = "1";
		binMem = myProcessor.dataMem.get_data(int_to_string(intMemAddressValue));
		hexReg = bin_to_hex(binReg);
		hexMem = bin_to_hex(binMem);
		printf("$s%i: %s     0: %s\n", i, hexReg.c_str(), hexMem.c_str());
	}
	int n = 0;
	string input;
	cout << "\nPress enter to cycle through one clock cycle.\nEnter a number n to cycle through n clock cycles\nEnter \"finish\" to cycle through all instructions.\nEnter \"Exit\" to terminate the program." << endl;
	getline(cin, input);
	if((input == "Exit") || (input == "exit")){
		break;
	}
	else if(input.empty()){
		n = 1;
	}
        else if(input == "finish"){
            
            n = (myProcessor.instructionCount + 4) - clockCycle;
            cout << n << endl;
        }
        
	else{
		n = atoi(input.c_str());
		if(n == 0){
			cout << "Unknown Command" << endl;
		}
	}
	int count = 0;
	while(count < n){
		cout << myProcessor.PC << endl;
		myProcessor.IF();
		cout << myProcessor.IFID.get_oldBuff() << endl;
		myProcessor.ID();
		cout << myProcessor.IDEXE.get_oldBuff() << endl;
		myProcessor.EXE();
		cout << myProcessor.EXEMEM.get_oldBuff() << endl;
		myProcessor.MEM();
		cout << myProcessor.MEMWB.get_oldBuff() << endl;
                cout << "\n" << endl;
		myProcessor.WB();
		myProcessor.update_buffers();
		
		count = count + 1;
                clockCycle = clockCycle + 1;
	}
}


return 0;
}