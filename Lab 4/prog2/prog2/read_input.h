/* read_input.h 
 * ENSF 337 Lab 4 Exercise  E
 */

#ifndef INPUTC
#define INPUTC

#include <stdio.h>

int get_string(char* digits, int n);
/* REQUIRES
 *   n > 0.
 *   Array elements digits[0], ...,  digits[n-1] exist. * 
 * PROMISES
 *   Trys to fill some or all elements of array using fgets(digits, n, stdin).
 *   Returns EOF if fgets couldn't read any characters at all.
 *   Otherwise, trims leading and trailing spaces from the string, replaces
 *   the final '\n' (if there is one) and returns 1.
 */

int read_integer(char* digits, int n, int* num);
/* REQUIRES
 *   n > 0, n is large enough to handle longest expected line of input. 
 *   Array elements digits[0], ...,  digits[n-1] exist.
 *   num points to a variable.
 *
 * PROMISES: 
 *   A line of user input is copied into the array, possibly after some
 *   editing.
 *   If an int is successfully read from the input, that int is copied
 *   into *num and 1 is returned.
 *   EOF is returned if user enters end-of-file (Ctrl-D on a Unix-like 
 *   system, and Ctrl-Z on Windows).  
 *   0 is returned if the user's input can't be read as an int.
 */

int is_valid_integer(const char* digits);
/* REQUIRES: digits points to the beginning of a valid C string.
 *
 * PROMISES: Returns 1 if all characters in digits are 
 *           acceptable as characters in an integer number.
 *           Otherwise returns zero.
 */


int convert_to_integer(const char* digits);
/* REQUIRES: digits points to a valid C string
 *           and is_valid_integer(digits) is true.
 * PROMISES: computes and returns the equivalent integer value of the string 
 *           digits.
 */

/* THE FOLLOWING FUNCTIONS MUST BE DEFINED BY STUDENTS, 
 * IN A FILE CALLED read_real.c */ 

int read_real(char* digits, int n, double * num);
/* REQUIRES
 *   n > 0, n is large enough to handle longest expected line of input. 
 *   Array elements digits[0], ...,  digits[n-1] exist.
 *   num points to a variable.
 *
 * PROMISES: 
 *   A line of user input is copied into the array, possibly after some
 *   editing.
 *   If a double is successfully read from the input, that double is copied
 *   into *num and 1 is returned.
 *   EOF is returned if user enters end-of-file (Ctrl-D on a Unix-like 
 *   system, and Ctrl-Z on Windows).  
 *   0 is returned if the user's input can't be read as a double.
 */


int is_valid_double(const char* digits);
/* REQUIRES: digits points to the beginning of a valid C string.
 *
 * PROMISES: Returns 1 if all characters in digits are 
 *           acceptable as characters in a real number.
 *           Otherwise returns zero.
 */


double convert_to_double(const char *digits);
/* REQUIRES: digits points to a valid C string
 *           and is_valid_double(digits) is true.
 * PROMISES: computes and returns the equivalent double value of the string 
 *           characters.
 */


#endif
