#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>

#ifndef MUX_H
#define	MUX_H
using std::string;
class Mux {
    string control;
public:
    Mux();
    Mux(const Mux& orig);
    virtual ~Mux();
    void set_control(string);
    string get_output(string, string);
private:

};


#endif	/* MUX_H */

