#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
#include "Data_Memory.h"
#include "Unknown.h"

Data_Memory::Data_Memory() {
    for(int i=0; i<200; i++){
        Memory_Array[i] = "00000000";
    }
    memRead = "1";
    memWrite = "1";
}

Data_Memory::Data_Memory(const Data_Memory& orig) {
}

Data_Memory::~Data_Memory() {
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
