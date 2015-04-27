#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Double_Mux.h"
#include "Unknown.h"
using namespace std;
//double mux class since different from normal mux
Double_Mux::Double_Mux(){
	control = "00";
}

void Double_Mux::set_control(string controlBits){
	control = controlBits;
}

string Double_Mux::get_output(string A, string B, string C){
	if(control == "00"){
		return A;
	}
	else if(control == "01"){
		return B;
	}
	else{
		return C;
	}
}