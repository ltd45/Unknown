#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Control.h"
#include "Unknown.h"
using namespace std;
//class for the control signals.
Control::Control(){
	regDest = "0";
	regWrite = "0";
	ALUsrc = "0";
	PCsrc = "00";
	ALUopp = "000";
	memWrite = "0";
	memRead = "0";
	memToReg = "0";
}

void Control::decodeOpp(string oppCode){
	map<string, string> controlMap;
	controlMap["0001"] = "01100000001";
	controlMap["0010"] = "11000001001";
	controlMap["0011"] = "11000010001";
	controlMap["0100"] = "11000011001";
	controlMap["0101"] = "01100011001";
	controlMap["1111"] = "00001000000";
	controlMap["1110"] = "00010000000";
	controlMap["0110"] = "01100000010";
	controlMap["0111"] = "00100000100";
	controlMap["1000"] = "01100100001";
	controlMap["1001"] = "11000101001";
	controlMap["1010"] = "01100110001";
	controlMap["1011"] = "01100010001";
	controlMap["1100"] = "11000111001";
	controlMap["1101"] = "01100101001";
	controlMap["0000"] = "00000000000";
	
	string controlString = controlMap[oppCode];
	regDest = controlString[0];
	regWrite = controlString[1];
	ALUsrc = controlString[2];
	PCsrc = controlString.substr(3, 2);
	ALUopp = controlString.substr(5, 3);
	memWrite = controlString[8];
	memRead = controlString[9];
	memToReg = controlString[10];
}