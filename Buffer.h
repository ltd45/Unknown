/* 
 * File:   Buffer.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:11 AM
 */

#ifndef BUFFER_H
#define	BUFFER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

class Buffer{
		string oldBuff;
		string newBuff;
	public:
		Buffer();
		void set_size(int);
		void set_newBuff(string);
		string get_oldBuff();
		void refreshBuff();
};

#endif	/* BUFFER_H */

