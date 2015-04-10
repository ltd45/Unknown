#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>

#ifndef DOUBLE_MUX_H
#define	DOUBLE_MUX_H

using std::string;
class Double_Mux {
    string control;
public:
    Double_Mux();
    Double_Mux(const Double_Mux& orig);
    virtual ~Double_Mux();
    void set_control(string);
    string get_output(string, string, string);
private:

};

#endif	/* DOUBLE_MUX_H */

