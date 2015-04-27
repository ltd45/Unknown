#include <string>

using namespace std;
#ifndef UNKNOWN_H
#define	UNKNOWN_H


long int string_to_unsigned(string);
string bin_to_hex(string);
string int_to_three_bit(int);
long int string_to_int(string);
string int_to_string(long int);
string ALU(string, string, string);
string sign_extend(string);
string shift_left_one(string);
string ALU_control(string, string);


#endif	/* UNKNOWN_H */

