#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Mux.h"
#include "Unknown.h"
using namespace std;

Mux::Mux(){
	control = "0";
}

void Mux::set_control(string controlBit){
	control = controlBit;
}


string Mux::get_output(string A, string B){
	if(control == "0"){
		return A;
	}
	else{
		return B;
	}
}