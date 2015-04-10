#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include <cmath>
#include "Unknown.h"
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
	cout << valueB << endl;
	
	if(control == "000"){
		result = valueA + valueB;
		return int_to_string(result);
	}
	else if(control == "001"){
		string binResult = "1111111111111111";
		for(int i=0; i<16; i++){
			if((A.substr(i, 1) == "1") || (B.substr(i, 1) == "1")){
				binResult.replace(i, 1, "0");
			}
		}
		return binResult;
	}
	else if(control == "010"){
		result = valueA - valueB;
		return int_to_string(result);
	}
	else if(control == "011"){
		string binResult = "0000000000000000";
		for(int i=0; i<16; i++){
			if((A.substr(i, 1) == "1") && (B.substr(i, 1) == "1")){
				binResult.replace(i, 1, "1");
			}
		}
		return binResult;
	}
	else if(control == "100"){
		string binResult = "0000000000000000";
		for(int j=0; j<valueB; j++){
			for(int i=0; i<15; i++){
				binResult[i] = A[i+1];
			}
			binResult.replace(15, 1, "0");
			A = binResult;
		}
		return A;
	}
	else if(control == "101"){
		string binResult = "0000000000000000";
		for(int i=0; i<16; i++){
			if((A.substr(i, 1) == "1") || (B.substr(i, 1) == "1")){
				binResult.replace(i, 1, "1");
			}
		}
		return binResult;
	}
	else if(control == "110"){
		string binResult = "0000000000000000";
		for(int j=0; j<valueB; j++){
			for(int i=1; i<16; i++){
				binResult[i] = A[i-1]; 
			}
			binResult.replace(0, 1, "0");
			A = binResult;
		}
		return A;
	}
	else if(control == "111"){
		if(valueA < valueB){
			return "0000000000000001";
		}
		else{
			return "0000000000000000";
		}
	}
}

string sign_extend(string binString){
	if(binString.substr(0,1) == "0"){
		binString = "0000000000" + binString;
	}
	else{
		binString = "1111111111" + binString;
	}
	return binString;
}

string shift_left_one(string binString){
	string binResult = "0000000000000000";
	for(int i=0; i<15; i++){
		binResult[i] = binString[i+1];
	}
	binResult.replace(15, 1, "0");
	return binResult;
}

string ALU_control(string ALUopp, string function){
	return ALUopp;
}