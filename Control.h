/* 
 * File:   Control.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:17 AM
 */

#ifndef CONTROL_H
#define	CONTROL_H

#include <string>
using namespace std;

class Control{
	public:
		Control();
		string regDest;
		string regWrite;
		string ALUsrc;
		string Jump;
		string Branch;
		string PCsrc;
		string ALUopp;
		string memWrite;
		string memRead;
		string memToReg;
		void decodeOpp(string);
};

#endif	/* CONTROL_H */

