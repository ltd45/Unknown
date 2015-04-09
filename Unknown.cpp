#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
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