#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Register_Memory.h"
#include "Unknown.h"
using namespace std;


Register_Memory::Register_Memory(){
	for(int i=0; i<8; i++){
		Memory_Array[i] = "0000000000000000";
	}
	regWrite = "0";
}

void Register_Memory::set_register(string address, string value){
	long int address_num = string_to_unsigned(address);
	if(regWrite == "0"){
		string doNothing = "do nothing";
	}
	else if((address_num < 0) or (address_num > 7)){
		string doNothing = "do nothing";
	}
	else{
		Memory_Array[address_num] = value;
	}
}

string Register_Memory::get_register(string address){
	long int address_num = string_to_unsigned(address);
	if((address_num < 0) or (address_num > 7)){
		return "0000000000000000";
	}
	else{
		return (Memory_Array[address_num]);
	}
}
