//
//  main.c
//  prog2
//
//  Created by Gillian Habermehl on 2022-10-14.
//

#include <stdio.h>
#include <limits.h>
#include "read_input.h"

int read_real(char* digits, int n, double* num){

    if(get_string(digits, n) == EOF)
        return EOF;
    
    if(is_valid_double(digits)){
        if((digits[0] == '.' || digits[0] == '+' || digits[0] == '-') && digits[1] == '.'){
            if(digits[0] == '-')
                *num = -convert_to_double(digits + 2);
            else
                *num = convert_to_double(digits + 2);
        }
        else if((digits[0] == '.' || digits[0] == '+' || digits[0] == '-') && digits[2] == '.'){
            if(digits[0] == '-')
                *num = -convert_to_double(digits + 3);
            else
                *num = convert_to_double(digits + 3);
        }
        else if(digits[0] == '-')
            *num = -convert_to_double(digits + 1);
        else if(digits[0] == '+' || digits[0] == '.')
            *num = convert_to_double(digits + 1);
        else
            *num = convert_to_double(digits);
        
        return 1;
    }
    return 0;
    }


int is_valid_double(const char* digits){
    /* REQUIRES: digits points to the beginning of a valid C string.
     *
     * PROMISES: Returns 1 if all characters in digits are
     *           acceptable as characters in a real number.
     *           Otherwise returns zero.
     */
    int valid = 1;
    int i;
    int j = 0;
    
    // i = index where first digit is //
    if((digits[0] == '+' || digits[0] == '-') && digits[1] == '.')
      i = 2;
    if((digits[0] == '+' || digits[0] == '-') && digits[2] == '.')
      i = 3;
    else if(digits[0] == '+' || digits[0] == '-')
      i = 1;
    else
        i = 0;
    
    /* Must have at least one digit, and no non-digits. */
    if (digits[i] == '\0')
      valid = 0;
    else
      while (valid && (digits[i] != '\0')) {
        if(digits[i] < '0' ||  digits[i] > '9')
          valid = 0;
        i++;
      }
    

    
    return valid;
}


double convert_to_double(const char *digits){
    /* REQUIRES: digits points to a valid C string
     *           and is_valid_double(digits) is true.
     * PROMISES: computes and returns the equivalent double value of the string
     *           characters.
     * 23.4
     */
    int sum = 0;
    int i = 0;
    while(*digits){
        if(digits[i] == '.')
        digits++;
    }
    while(digits[i] != '\0'){
        
    }
        
    //did not finish, but would convert to integer with the numbers before thr decimal and convert using 10^-1 and such for after the decimal
    
    return sum;
}

