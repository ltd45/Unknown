/* 
 * File:   main.cpp
 * Author: ltd45_000
 *
 * Created on April 9, 2015, 6:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include <cmath>
#include "Buffer.h"
#include "Control.h"
#include "Data_Memory.h"
#include "Double_Mux.h"
#include "Instruction_Memory.h"
#include "Mux.h"
#include "Register_Memory.h"
#include "Unknown.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Instruction_Memory myMemory;
    Register_Memory myReg;
    Data_Memory myData;
    Mux myMux;
    Double_Mux myDMux;
    Buffer myBuff;
    Control myControl;
// <editor-fold defaultstate="collapsed" desc="Loading Instructions into memory">    
    myMemory.set_instruction("0000000000000000", "0111101110001010"); //0
    myMemory.set_instruction("0000000000000010", "0101101101000000"); //2
    myMemory.set_instruction("0000000000000100", "1100000101111111"); //4
    myMemory.set_instruction("0000000000000110", "0101101101000001"); //6
    myMemory.set_instruction("0000000000001000", "1111000101001100"); //8
    myMemory.set_instruction("0000000000001010", "0000000001010100"); //10
    myMemory.set_instruction("0000000000001100", "0110101110001010"); //12
    myMemory.set_instruction("0000000000001110", "1011111111000001"); //14
    myMemory.set_instruction("0000000000010000", "0110101110000000"); //16
    myMemory.set_instruction("0000000000010010", "0111111110001100"); //18
    myMemory.set_instruction("0000000000010100", "0101111111000000"); //20
    myMemory.set_instruction("0000000000010110", "0001111111100000"); //22
    myMemory.set_instruction("0000000000011000", "1000111111000011"); //24
    myMemory.set_instruction("0000000000011010", "1100000111101111"); //26
    myMemory.set_instruction("0000000000011100", "0101111111000000"); //28
    myMemory.set_instruction("0000000000011110", "1111111000110000"); //30
    myMemory.set_instruction("0000000000100000", "1010001001000011"); //32
    myMemory.set_instruction("0000000000100010", "1001010010001101"); //34
    myMemory.set_instruction("0000000000100100", "0101000000000000"); //36
    myMemory.set_instruction("0000000000100110", "0001000000111111"); //38
    myMemory.set_instruction("0000000000101000", "1000000000000110"); //40
    myMemory.set_instruction("0000000000101010", "0001000000110000"); //42
    myMemory.set_instruction("0000000000101100", "1000000000000100"); //44
    myMemory.set_instruction("0000000000101110", "0111000110000000"); //46
    myMemory.set_instruction("0000000000110000", "0000000001001100"); //48
    myMemory.set_instruction("0000000000110010", "1000011011000010"); //50
    myMemory.set_instruction("0000000000110100", "0111101110001010"); //52
    myMemory.set_instruction("0000000000110110", "0101101101000000"); //54
    myMemory.set_instruction("0000000000111000", "0010000100101001"); //56
    myMemory.set_instruction("0000000000111010", "0010111011101001"); //58 
    myMemory.set_instruction("0000000000111100", "0100000000100011"); //60
    myMemory.set_instruction("0000000000111110", "0100111111011011"); //62
    myMemory.set_instruction("0000000001000000", "1001100000111101"); //64
    myMemory.set_instruction("0000000001000010", "0101000000000000"); //66
    myMemory.set_instruction("0000000001000100", "0001000000111111"); //68
    myMemory.set_instruction("0000000001000110", "1000000000000010"); //70
    myMemory.set_instruction("0000000001001000", "0001000000000011"); //72
    myMemory.set_instruction("0000000001001010", "0111000110000000"); //74
    myMemory.set_instruction("0000000001001100", "0001110110000010"); //76
    myMemory.set_instruction("0000000001001110", "0110111110001100"); //78
    myMemory.set_instruction("0000000001010000", "0110101110001010"); //80
    myMemory.set_instruction("0000000001010010", "0000000000000000"); //82
    myMemory.set_instruction("0000000001010100", "0110101110001010"); //84
// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="Loading Initial Data Memory"> 
    myData.set_data("0000000000010000","0000000100000001");
    myData.set_data("0000000000010010","0000000100010000");
    myData.set_data("0000000000010100","0000000000010001");
    myData.set_data("0000000000010110","0000000011110000");
    myData.set_data("0000000000011000","0000000011111111");
//</editor-fold>
//<editor-fold defaultstate="collapsed" desc="Loading Intial Register Memory">
    myReg.set_register("000","0000000000000000"); //s0 = 0
    myReg.set_register("001","0000000001000000"); //s1=0040 hex
    myReg.set_register("010","0001000000010000"); //s2=1010 hex
    myReg.set_register("011","0000000000001111"); //s3=000F hex
    myReg.set_register("100","0000000011110000"); //s4=00F0 hex
    myReg.set_register("101","0000000000000000"); //s5=0000 hex
    myReg.set_register("110","0000000000010000"); //s6=0010 hex
    myReg.set_register("111","0000000000000101"); //s7=0005 hex
//</editor-fold>
return 0;
}

