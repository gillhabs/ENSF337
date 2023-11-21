/*
*  File name: Lab3exe_D.c
*  Assignment: ENSF 337, lab3 Exercise D
*  Lab Section: B02
*  Created by: Mohmood Moussavi
*  Completed by: Gillian Habermehl
*  Development Date: October 3, 2022
*  In this program the implementatiom of function pascal_trangle is missing.
*  Studtent must complete this function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
PROMISES: displays a pascal_triangle. the first 5 line of the function's output
should have the following format:
row 0:  1
row 1:  1   1
row 2:  1   2   1
row 3:  1   3   3   1
row 4:  1   4   6   4   1
*/


int main() {
   int nrow;
   // These are ALL of the variables you need!
   printf("Enter the number of rows (Max 20): ");
   scanf("%d", &nrow);
   if(nrow <= 0 || nrow > 20) {
       printf("Error: the maximum number of rows can be 20.\n");
       exit(1);
   }
   
   pascal_triangle(nrow);
   return 0;
}

void pascal_triangle(int n) {
    
    char previous_arr[n];
    char current_arr[n];
    previous_arr[0] = 1;
    
    for (int i = 0; i <= n-1; i++) {
        printf("Row %d: ", i);
        
        for(int j = 0; j <= i; j++){
            
            if(j == 0 || j == i){
                current_arr[j] = 1;
                printf("%d ", current_arr[j]);
            }
            else{
                current_arr[j] = (previous_arr[j-1] + previous_arr[j]);
                printf("%d ", current_arr[j]);
            }
        }
        
        for(int m = 0; m < n; m++){
            
            previous_arr[m] = current_arr[m];

        }
        printf("\n");
    }
    }






