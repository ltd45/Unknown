#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Data_Memory.h"
#include "Unknown.h"
using namespace std;

//class to simulate Data Memory
Data_Memory::Data_Memory(){
	for(int i=0; i<200; i++){
		Memory_Array[i] = "00000000";
	}
	memRead = "0";
	memWrite = "0";
}


void Data_Memory::set_data(string address, string value){
	long int address_num = string_to_int(address);
	if((value.length() != 16) or (memWrite == "0")){
		string doNothing = "do nothing";
	}
	else if((address_num % 2 != 0) or (address_num < 0) or (address_num > 198)){
		string doNothing = "do nothing";
	}
	else{
		Memory_Array[address_num] = value.substr(0, 8);
		Memory_Array[address_num+1] = value.substr(8, 8);
	}
}

string Data_Memory::get_data(string address){
	if(memRead == "0"){
		return "0000000000000000";
	}	
	long int address_num = string_to_int(address);
	if((address_num % 2 != 0) or (address_num < 0) or (address_num > 198)){
		return "0000000000000000";
	}
	else{
		return (Memory_Array[address_num] + Memory_Array[address_num + 1]);
	}
}