/* 
 * File:   Double_Mux.h
 * Author: Peter
 *
 * Created on April 13, 2015, 2:19 AM
 */

#ifndef DOUBLE_MUX_H
#define	DOUBLE_MUX_H

#include <string>
using namespace std;

class Double_Mux{
		string control;
	public:
		Double_Mux();
		void set_control(string);
		string get_output(string, string, string);
};

#endif	/* DOUBLE_MUX_H */

