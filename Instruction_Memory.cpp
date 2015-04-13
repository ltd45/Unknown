#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Instruction_Memory.h"
#include "Unknown.h"
using namespace std;

Instruction_Memory::Instruction_Memory(){
	for(int i=0; i<200; i++){
		Memory_Array[i] = "00000000";
	}
}

bool Instruction_Memory::set_instruction(string address, string value){
	if(value.length() != 16){
		return false;
	}
	long int address_num = string_to_int(address);
	if((address_num % 2 != 0) or (address_num < 0) or (address_num > 198)){
		return false;
	}
	Memory_Array[address_num] = value.substr(0, 8);
	Memory_Array[address_num+1] = value.substr(8, 8);
	return true;
}

string Instruction_Memory::get_instruction(string address){
	long int address_num = string_to_int(address);
	if((address_num % 2 != 0) or (address_num < 0) or (address_num > 198)){
		return "0000000000000000";
	}
	else{
		return (Memory_Array[address_num] + Memory_Array[address_num + 1]);
	}
}