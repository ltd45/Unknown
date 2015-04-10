/* 
 * File:   Unknown.h
 * Author: ltd45_000
 *
 * Created on April 9, 2015, 6:30 PM
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>

#ifndef UNKNOWN_H
#define	UNKNOWN_H

using std::string;

long int string_to_int(string);
string int_to_string(long int);
string ALU(string, string, string);
string sign_extend(string);
string shift_left_one(string);
string ALU_control(string, string);


#endif	/* UNKNOWN_H */

