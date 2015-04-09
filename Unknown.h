/* 
 * File:   Unknown.h
 * Author: ltd45_000
 *
 * Created on April 9, 2015, 6:30 PM
 */

#ifndef UNKNOWN_H
#define	UNKNOWN_H

long int string_to_int(string binString);
string int_to_string(long int myNum);
string ALU(string string1, string string2, string control);
string sign_extend(string binString);
string shift_left_one(string binString);
string ALU_control(string ALUopp, string function);


#endif	/* UNKNOWN_H */

