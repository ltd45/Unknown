#include "Buffer.h"

Buffer::Buffer() {
    oldBuff = "0000000000000000000000000";
    newBuff = "0000000000000000000000000";
}

Buffer::Buffer(const Buffer& orig) {
}

Buffer::~Buffer() {
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