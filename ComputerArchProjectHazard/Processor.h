/* 
 * File:   Processor.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:21 AM
 */

#ifndef PROCESSOR_H
#define	PROCESSOR_H

using namespace std;

#include <string>
#include "Buffer.h"
#include "Control.h"
#include "Data_Memory.h"
#include "Instruction_Memory.h"
#include "Mux.h"
#include "Register_Memory.h"
#include "Double_Mux.h"
#include "Forwarding.h"



class Processor{
	public:
		Instruction_Memory instMem;
		Register_Memory regMem;
		Data_Memory dataMem;
		Mux regDestMux;
		Mux ALUsrcMux;
		Mux memToRegMux;
		Double_Mux PCsrcMux;
                Double_Mux ForwardA;
                Double_Mux ForwardB;
                Forwarding ForwardingUnit;
		Buffer IFID;
		Buffer IDEXE;
		Buffer EXEMEM;
		Buffer MEMWB;
		Control controlUnit;
		string PC;
		string currentPC;
                string WBforwardingData;
                string MEMforwardingData;
                int instructionCount;
                
		void IF();
		void ID();
		void EXE();
		void MEM();
		void WB();
		void update_buffers();
		
		void load_instructions();
		void load_registers();
		void load_memory();
};

#endif	/* PROCESSOR_H */

