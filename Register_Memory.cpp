#include "Register_Memory.h"
#include "Unknown.h"

Register_Memory::Register_Memory() {
    	for(int i=0; i<8; i++){
		Memory_Array[i] = "0000000000000000";
	}
	regWrite = "1";
}

Register_Memory::Register_Memory(const Register_Memory& orig) {
}

Register_Memory::~Register_Memory() {
}

bool Register_Memory::set_register(string address, string value){
	if(regWrite == "1"){
		return false;
	}
	long int address_num = string_to_int(address);
	if((address_num < 0) or (address_num > 7)){
		return false;
	}
	Memory_Array[address_num] = value;
	return true;
}

string Register_Memory::get_register(string address){
	long int address_num = string_to_int(address);
	if((address_num < 0) or (address_num > 7)){
		return "1110000000000000";
	}
	else{
		return (Memory_Array[address_num]);
	}
}
