// File name: Lab_1_exe_E.c
// Assignment: Lab 1 Exercise E
// Lab section: B02
// Completed by: Gillian Habermehl
// Submission Date: September 23, 2022
//

#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    
    printf("Enter coefficient a:\n");
    scanf("%f", &a);
    printf("Enter coefficient b:\n");
    scanf("%f", &b);
    printf("Enter coefficient c:\n");
    scanf("%f", &c);
    
    float discriminant = (pow(b,2) - 4 * a * c);
    float sqrt_discriminant = sqrt(discriminant);
    
    
    float root_pos;
    float root_neg;
    
    if (discriminant >= 0)
    {
        root_pos = ((b * -1) + sqrt_discriminant) / (2 * a);
        root_neg = ((b * -1) - sqrt_discriminant) / (2 * a);
        
        printf("The roots are %f and %f.\n", root_pos, root_neg);
    }
    
    else
    {
        
        float abs_discriminant = discriminant * -1.0;
        float sqrt_abs_discriminant = sqrt(abs_discriminant);
        float root_abs_discriminant = sqrt_abs_discriminant / (2 * a);
        float root = ((b * -1) / (2 * a));

        printf("The roots are %f + %fi and %f - %fi.\n", root, root_abs_discriminant, root, root_abs_discriminant);
    }
    
    return 0;
}
