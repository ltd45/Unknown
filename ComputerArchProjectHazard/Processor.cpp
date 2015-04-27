#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Processor.h"
#include "Double_Mux.h"
#include "Buffer.h"
#include "Control.h"
#include "Data_Memory.h"
#include "Instruction_Memory.h"
#include "Mux.h"
#include "Register_Memory.h"
#include "Unknown.h"
#include "Forwarding.h"
using namespace std;
//instruction fetch.
void Processor::IF(){
	string newInstruction = instMem.get_instruction(PC);
	string writeToBuff;
	
	
	writeToBuff = PC + newInstruction;
	IFID.set_newBuff(writeToBuff);
}
//instruction decode
void Processor::ID(){
	string fromBuffer = IFID.get_oldBuff();
	string readRegOne = fromBuffer.substr(20,3);
	string readRegTwo = fromBuffer.substr(23,3);

	string readDataOne = regMem.get_register(readRegOne);
	string readDataTwo = regMem.get_register(readRegTwo);
	string Imm = fromBuffer.substr(26,6);
	string signExtendImm = sign_extend(Imm);
	string oppCode = fromBuffer.substr(16,4);
	controlUnit.decodeOpp(oppCode);
	string controlBits = (controlUnit.regWrite + controlUnit.memToReg + controlUnit.memWrite + controlUnit.memRead + controlUnit.regDest + controlUnit.ALUsrc + controlUnit.ALUopp);
	
	
        //Hazard Detection Unit
        string EXEmemRead = IDEXE.get_oldBuff().substr(3, 1);
        string EXErt = IDEXE.get_oldBuff().substr(60, 3);
        
        bool stall = false;
        if((EXEmemRead == "1") && ((EXErt == readRegOne) || (EXErt == readRegTwo))){
            //Stall the pipeline.
            stall = true;
            controlBits = "000000000";
            IFID.set_newBuff(fromBuffer);
        }
        string writeToBuff = (controlBits + readDataOne + readDataTwo + signExtendImm + readRegOne + readRegTwo + fromBuffer.substr(26,3));
        
        //End Hazard Detection Unit
        
        IDEXE.set_newBuff(writeToBuff);
	
	string PCfromBuff = currentPC;
	long int PCvalue = string_to_int(PCfromBuff);
	PCvalue = PCvalue + 2;
	string PCadd = int_to_string(PCvalue);
	
	string jump = fromBuffer.substr(20,12);
	jump = jump + "0";
	string PCjump = PCadd.substr(0,3) + jump;
	string slImm = shift_left_one(signExtendImm);
	long int slImmValue = string_to_int(slImm);
	long int PCaddValue = string_to_int(PCadd);
	string PCbranch = int_to_string(slImmValue + PCaddValue);
	if((controlUnit.PCsrc == "01") && (readDataOne != readDataTwo)){
		controlUnit.PCsrc = "00";
	}
	PCsrcMux.set_control(controlUnit.PCsrc);
        //Re-Write the PC if we need to stall.
        if(stall == false){
            PC = PCsrcMux.get_output(PCadd, PCbranch, PCjump);
        }
	currentPC = PC;
}
//instruction execute stage
void Processor::EXE(){
	string fromBuffer = IDEXE.get_oldBuff();
	string readDataOne = fromBuffer.substr(9, 16);
	string readDataTwo = fromBuffer.substr(25, 16);
	string Imm = fromBuffer.substr(41, 16);
	string function = fromBuffer.substr(54, 3);
        string rs = fromBuffer.substr(57, 3);
	string rt = fromBuffer.substr(60, 3);
	string rd = fromBuffer.substr(63, 3);
	string regWrite = fromBuffer.substr(0, 1);
	string memToReg = fromBuffer.substr(1, 1);
	string memWrite = fromBuffer.substr(2, 1);
	string memRead = fromBuffer.substr(3, 1);
	string regDest = fromBuffer.substr(4, 1);
	string ALUsrc = fromBuffer.substr(5, 1);
	string ALUopp = fromBuffer.substr(6, 3);
        
        string MEMregDest = EXEMEM.get_oldBuff().substr(36, 3);
        string MEMregWrite = EXEMEM.get_oldBuff().substr(0, 1);
        string WBregDest = MEMWB.get_oldBuff().substr(34, 3);
        string WBregWrite = MEMWB.get_oldBuff().substr(0, 1);
        
        ForwardingUnit.ExeRs = rs;
        ForwardingUnit.ExeRt = rt;
        ForwardingUnit.MemDest = MEMregDest;
        ForwardingUnit.MemRegWrite = MEMregWrite;
        ForwardingUnit.WbDest = WBregDest;
        ForwardingUnit.WbRegWrite = WBregWrite;
        ForwardingUnit.set_forwarding_control();
        MEMforwardingData = EXEMEM.get_oldBuff().substr(4, 16);
        
        ForwardA.set_control(ForwardingUnit.ForwardAControl);
        ForwardB.set_control(ForwardingUnit.ForwardBControl);
        
        string ForwardAOutput = ForwardA.get_output(readDataOne, WBforwardingData, MEMforwardingData);
        string ForwardBOutput = ForwardB.get_output(readDataTwo, WBforwardingData, MEMforwardingData);
	
	string ALUcontrolOutput = ALU_control(ALUopp, function);
	ALUsrcMux.set_control(ALUsrc);
	string muxOutput = ALUsrcMux.get_output(ForwardBOutput, Imm);
	string ALUoutput = ALU(ForwardAOutput, muxOutput, ALUcontrolOutput);
	
	regDestMux.set_control(regDest);
	string regDestMuxOutput = regDestMux.get_output(rt, rd);
	
	string controlBits = (regWrite + memToReg + memWrite + memRead);
	string writeToBuff = (controlBits + ALUoutput + ForwardBOutput + regDestMuxOutput);
	EXEMEM.set_newBuff(writeToBuff);
}
//MEM Stage
void Processor::MEM(){
	string fromBuffer = EXEMEM.get_oldBuff();
	string regWrite = fromBuffer.substr(0, 1);
	string memToReg = fromBuffer.substr(1, 1);
	string memWrite = fromBuffer.substr(2, 1);
	string memRead = fromBuffer.substr(3, 1);
	
	string ALUresult = fromBuffer.substr(4, 16);
	string readDataTwo = fromBuffer.substr(20, 16);
	string regDest = fromBuffer.substr(36, 3);
	
	dataMem.memRead = memRead;
	dataMem.memWrite = memWrite;
	
	dataMem.set_data(ALUresult, readDataTwo);
	string readData = dataMem.get_data(ALUresult);
	
	string writeToBuff = (regWrite + memToReg + readData + ALUresult + regDest);
	MEMWB.set_newBuff(writeToBuff);
}

void Processor::WB(){
	string fromBuffer = MEMWB.get_oldBuff();
	string regWrite = fromBuffer.substr(0, 1);
	string memToReg = fromBuffer.substr(1, 1);
	
	string readData = fromBuffer.substr(2, 16);
	string ALUresult = fromBuffer.substr(18, 16);
	string regDest = fromBuffer.substr(34, 3);
	
	memToRegMux.set_control(memToReg);
	regMem.regWrite = regWrite;
	
	string memToRegMuxOutput = memToRegMux.get_output(readData, ALUresult);
        WBforwardingData = memToRegMuxOutput;
	regMem.set_register(regDest, memToRegMuxOutput);
}

void Processor::update_buffers(){
	IFID.refreshBuff();
	IDEXE.refreshBuff();
	EXEMEM.refreshBuff();
	MEMWB.refreshBuff();
}

void Processor::load_instructions(){
        instructionCount = 0;
	string line;
	ifstream myFile ("UnknownInstructions.txt");
	int address = 0;
	if(myFile.is_open()){
		while(getline(myFile, line)){
			line = line.substr(0, 16);
			string binAddress = int_to_string(address);
			instMem.set_instruction(binAddress, line);
			address = address + 2;
                        instructionCount += 1;
		}
		myFile.close();
	}
	else{
		cout << "unable to open instruction file" << endl;
	}
}

void Processor::load_registers(){
	string line;
	ifstream myFile("UnknownRegisters.txt");
	int address = 0;
	if(myFile.is_open()){
		while(getline(myFile, line)){
			line = line.substr(0, 16);
			string binAddress = int_to_three_bit(address);
			regMem.set_register(binAddress, line);
			address = address + 1;
		}
		myFile.close();
	}
	else{
		cout << "unable to open register file" << endl;
	}
}

void Processor::load_memory(){

	string line;
	ifstream myFile ("UnknownMemory.txt");
	int address = 0;
	if(myFile.is_open()){
		while(getline(myFile, line)){
			line = line.substr(0, 16);
			string binAddress = int_to_string(address);
			dataMem.set_data(binAddress, line);
			address = address + 2;
                        
		}
		myFile.close();
	}
	else{
		cout << "unable to open memory file" << endl;
	}
}