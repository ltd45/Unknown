#ifndef MUX_H
#define	MUX_H

#include <string>
using namespace std;

class Mux{
		string control;
	public:
		Mux();
		void set_control(string);
		string get_output(string, string);
};

#endif	/* MUX_H */

