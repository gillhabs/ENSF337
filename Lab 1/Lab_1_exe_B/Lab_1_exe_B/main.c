// File name: Lab_1_exe_B.c
// Assignment: Lab 1 Exercise B
// Lab section: B02
// Completed by: Gillian Habermehl
// Submission Date: September 23, 2022

#include <stdio.h>

int main()
{
    double num1 = -34.5;
    double num2 = 98.7;
    
    double sum;          // sum of num1 and num2
    double sumSquared;   // the square of num1 plus num2
    
    sum = num1 + num2;       // 1) add the two numbers num1 and num1
    sumSquared = sum * sum;  // 2) Compute the square of the sum
    
    printf("The sum squared is: %f \n", sumSquared);
    
    sumSquared = sumSquared * 2; // 3) Double the sum squared and store in 'sumSquared'
    
    printf("The sum squared is now: %f \n", sumSquared);
    
    
    return 0;
}
