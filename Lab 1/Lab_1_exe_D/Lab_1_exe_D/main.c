// File name: Lab_1_exe_D.c
// Assignment: Lab 1 Exercise D
// Lab section: B02
// Completed by: Gillian Habermehl
// Submission Date: September 23, 2022
//

#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    
    printf("Enter angle in radians: \n");
    scanf("%lf", &x);
    
    double sin_angle = sin(x);
    
    printf("Sine of the angle is: %lf \n", sin_angle);
    
    double taylor_approx = x - (pow(x, 3) / 6.0) + (pow(x, 5) / 120.0) - (pow(x, 7) / 5040.0);
    
    printf("The Taylor series approximation of sin(x) is: %f\n", taylor_approx);
    
    
    return 0;
}
