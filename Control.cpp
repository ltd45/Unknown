/* 
 * File:   Control.cpp
 * Author: ltd45_000
 * 
 * Created on April 9, 2015, 6:09 PM
 */

#include "Control.h"

Control::Control() {
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

Control::Control(const Control& orig) {
}

Control::~Control() {
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
