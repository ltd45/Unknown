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
#include "Forwarding.h"
using namespace std;


int main()
{
Processor myProcessor;

myProcessor.PC = "0000000000000000";
myProcessor.currentPC = "0000000000000000";
myProcessor.IFID.set_size(32);
myProcessor.IDEXE.set_size(66);
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

printf("Instruction Memory\nAddress Hex Value Binary Value\n");
for(int i=0; i<54; i++){
    string instruction = myProcessor.instMem.get_instruction(int_to_string(i*2));
    printf("0x%0*i   0x%s    %s\n", 3, i,bin_to_hex(instruction).c_str() ,instruction.c_str());
}

bool keepGoing = true;
while(keepGoing){
	//output the content of the registers and memory
    printf("\nCock Cycle: %i\n", clockCycle);
	printf("\nRegisters:    Data Memory:\n");
	for(int i=0; i<8; i++){
		string hexReg, hexMem, binReg, binMem;
		int intMemAddressValue = (i + 8) * 2;
		binReg = myProcessor.regMem.get_register(int_to_three_bit(i));
		myProcessor.dataMem.memRead = "1";
		binMem = myProcessor.dataMem.get_data(int_to_string(intMemAddressValue));
		hexReg = bin_to_hex(binReg);
		hexMem = bin_to_hex(binMem);
		printf("$s%i: %s     MEM[$a0+%i]: %s\n", i, hexReg.c_str(),i*2, hexMem.c_str());
	}
	int n = 0;
	string input;
	cout << "\nPress enter to cycle through one clock cycle.\nEnter a number n to cycle through n clock cycles\nEnter \"loop\" to cycle through one program loop.\nEnter \"Exit\" to terminate the program." << endl;
	getline(cin, input);
	if((input == "Exit") || (input == "exit")){
		break;
	}
	else if(input.empty()){
		n = 1;
	}
        else if(input == "loop"){
            n = 200;
        }
	else{
		n = atoi(input.c_str());
		if(n == 0){
			cout << "Unknown Command" << endl;
		}
	}
	int count = 0;
        bool go = true;
	while(go == true){
            
                count = count + 1;
                clockCycle = clockCycle + 1;
                if((myProcessor.PC == "0000000000000000") && (clockCycle != 1)){
                    go = false;
                }
                else if(count == n){
                    go = false;
                } 
		myProcessor.IF();
                myProcessor.WB();
		myProcessor.ID();
		myProcessor.EXE();
		myProcessor.MEM();
		
		myProcessor.update_buffers();

	}
}


return 0;
}