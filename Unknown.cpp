#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

/*Function to change 16 bit 2's complement binary string to a signed integer*/
long int string_to_int(string binString){
	string test;
	test = binString[0];
	binString = binString.substr(1, 15);
	const char * c = binString.c_str();
	char * pEnd;
	long int myNum = strtol(c, &pEnd, 2);
	
	if(test == "0"){
		return myNum;
	}
	else{
		return (myNum - 32768);
	}
}

/*Function to change a signed integer to a 16 bit 2's complement binary string*/
string int_to_string(long int myNum){
	string binNum = "";
	if(myNum >= 0){
		while(myNum > 0){
			if((myNum % 2) == 1){
				binNum = "1" + binNum;
			}
			else{
				binNum = "0" + binNum;
			}
			myNum = floor(myNum / 2);
		}
		int fillCount = 16 - binNum.length();
	
		for(int i=0; i < fillCount; i++){
			binNum = "0" + binNum;
		}
		return binNum;
	}
	else{
		myNum = myNum + 32768;
		while(myNum > 0){
			if((myNum % 2) == 1){
				binNum = "1" + binNum;
			}
			else{
				binNum = "0" + binNum;
			}
			myNum = floor(myNum / 2);
		}
		int fillCount = 15 - binNum.length();
	
		for(int i=0; i < fillCount; i++){
			binNum = "0" + binNum;
		}
		binNum = "1" + binNum;
		return binNum;
	}
	
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

class Register_Memory{
		string Memory_Array[8];
	public:
		Register_Memory();
		string regWrite;
		bool set_register(string, string);
		string get_register(string);
};

Register_Memory::Register_Memory(){
	for(int i=0; i<8; i++){
		Memory_Array[i] = "0000000000000000";
	}
	regWrite = "1";
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

class Data_Memory{
		string Memory_Array[200];
	public:
		Data_Memory();
		string memRead;
		string memWrite;
		bool set_data(string, string);
		string get_data(string);
};

Data_Memory::Data_Memory(){
	for(int i=0; i<200; i++){
		Memory_Array[i] = "00000000";
	}
	memRead = "1";
	memWrite = "1";
}

bool Data_Memory::set_data(string address, string value){
	if((value.length() != 16) or (memWrite == "0")){
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

string Data_Memory::get_data(string address){
	if(memRead == "0"){
		return "1110000000000000";
	}	
	long int address_num = string_to_int(address);
	if((address_num % 2 != 0) or (address_num < 0) or (address_num > 198)){
		return "1110000000000000";
	}
	else{
		return (Memory_Array[address_num] + Memory_Array[address_num + 1]);
	}
}

class Mux{
		string control;
	public:
		Mux();
		void set_control(string);
		string get_output(string, string);
};

Mux::Mux(){
	control = "0";
}

void Mux::set_control(string controlBit){
	control = controlBit;
}


string Mux::get_output(string A, string B){
	if(control == "0"){
		return A;
	}
	else{
		return B;
	}
}

class Double_Mux{
		string control;
	public:
		Double_Mux();
		void set_control(string);
		string get_output(string, string, string);
};

Double_Mux::Double_Mux(){
	control = "00";
}

void Double_Mux::set_control(string controlBits){
	control = controlBits;
}

string Double_Mux::get_output(string A, string B, string C){
	if(control == "00"){
		return A;
	}
	else if(control == "01"){
		return B;
	}
	else{
		return C;
	}
}

class Buffer{
		string oldBuff;
		string newBuff;
	public:
		Buffer();
		void set_newBuff(string);
		string get_oldBuff();
		void refreshBuff();
};

Buffer::Buffer(){
	oldBuff = "0000000000000000000000000";
	newBuff = "0000000000000000000000000";
}

void Buffer::set_newBuff(string newString){
	newBuff = newString;
}

string Buffer::get_oldBuff(){
	return oldBuff;
}

void Buffer::refreshBuff(){
	oldBuff = newBuff;
}

class Control{
	public:
		Control();
		string regDest;
		string regWrite;
		string ALUsrc;
		string Jump;
		string Branch;
		string PCsrc;
		string ALUopp;
		string memWrite;
		string memRead;
		string memToReg;
		void decodeOpp(string);
};

Control::Control(){
	regDest = "0";
	regWrite = "0";
	ALUsrc = "0";
	Jump = "0";
	Branch = "0";
	PCsrc = "00";
	ALUopp = "000";
	memWrite = "0";
	memRead = "0";
	memToReg = "0";
}

void Control::decodeOpp(string oppCode){
	map<string, string> controlMap;
	controlMap["0001"] = "0110000000001";
	controlMap["0010"] = "1100000001001";
	controlMap["0011"] = "1100000010001";
	controlMap["0100"] = "1100000011001";
	controlMap["0101"] = "0110000011001";
	controlMap["1111"] = "0000101000000";
	controlMap["0000"] = "0001010000000";
	controlMap["0110"] = "0110000000010";
	controlMap["0111"] = "0010000000100";
	controlMap["1000"] = "0110000100001";
	controlMap["1001"] = "1100000101001";
	controlMap["1010"] = "0110000110001";
	controlMap["1011"] = "0110000010001";
	controlMap["1100"] = "1100000111001";
	controlMap["1101"] = "0110000111001";
	controlMap["1110"] = "0000000000000";
	
	string controlString = controlMap[oppCode];
	regDest = controlString[0];
	regWrite = controlString[1];
	ALUsrc = controlString[2];
	Jump = controlString[3];
	Branch = controlString[4];
	PCsrc = controlString.substr(5, 2);
	ALUopp = controlString.substr(7, 3);
	memWrite = controlString[10];
	memRead = controlString[11];
	memToReg = controlString[12];
}

string ALU(string A, string B, string control){
	long int valueA, valueB, result;
	valueA = string_to_int(A);
	valueB = string_to_int(B);
	
	switch(control){
		case "000":
			result = valueA + valueB;
			return int_to_string(result);
		case "001": /*nor*/
			string binResult = "1111111111111111";
			for(int i=0; i<16; i++){
				if((A[i] == "1") || (B[i] == "1")){
					binResult[i] = "0";
				}
			}
			return binResult;
		case "010":
			result = valueA - valueB;
			return int_to_string(result);
		case "011": /*and*/
			string binResult = "0000000000000000";
			for(int i=0; i<16; i++){
				if((A[i] == "1") && (B[i] == "1")){
					binResult[i] = "1";
				}
			}
			return binResult;
		case "100": /*sll*/
			string binResult = "0000000000000000";
			for(int j=0; j<valueB; j++){
				for(int i=0; i<15; i++){
					binResult[i] = A[i+1];
				}
				binResult[15] = "0";
			}
			return binResult;
		case "101": /*or*/
			string binResult = "0000000000000000";
			for(int i=0; i<16; i++){
				if((A[i] == "1") || (B[i] == "1")){
					binResult[i] = "0";
				}
			}
			return binResult;
		case "110": /*srl*/
			
		case "111":
			if(valueA < valueB){
				return "0000000000000001";
			}
			else{
				return "0000000000000000";
			}
	}
	
}

int main()
{
Instruction_Memory myMemory;
Register_Memory myReg;
Data_Memory myData;
Mux myMux;
Double_Mux myDMux;
Buffer myBuff;
Control myControl;

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