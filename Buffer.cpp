#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Buffer.h"
#include "Unknown.h"
using namespace std;

Buffer::Buffer(){
	oldBuff = "";
	newBuff = "";
}

void Buffer::set_size(int length){
	for(int i=0; i<length; i++){
		oldBuff = oldBuff + "0";
		newBuff = newBuff + "0";
	}
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