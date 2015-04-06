#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


long int string_to_int(string binString){
	const char * c = binString.c_str();
	char * pEnd;
	long int myNum = strtol(c, &pEnd, 2);
	return myNum;
}

class Instruction_Memory{
		string Memory_Array[200];
	public:
		Instruction_Memory();
		bool set_instruction(string, string);
		string get_instruction(string);
};

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
		return "1110000000000000";
	}
	else{
		return (Memory_Array[address_num] + Memory_Array[address_num + 1]);
	}
}



int main()
{
Instruction_Memory myMemory;
cout << myMemory.get_instruction("0000000000000010") << endl;
bool testSet = myMemory.set_instruction("0000000000000010", "1111000011110000");
cout << myMemory.get_instruction("0000000000000010") << endl;

	
return 0;
}