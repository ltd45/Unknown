#include "Mux.h"

Mux::Mux() {
    control = "0";
}

Mux::Mux(const Mux& orig) {
}

Mux::~Mux() {
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
