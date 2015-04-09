#include "Double_Mux.h"

Double_Mux::Double_Mux() {
    control = "00";
}

Double_Mux::Double_Mux(const Double_Mux& orig) {
}

Double_Mux::~Double_Mux() {
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