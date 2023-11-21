//
//  main.c
//  Lab_1_exe_A
//
//  Created by Gillian Habermehl on 2022-09-16.
//

#include <stdio.h>

int main ()
{
    int a = 0, b = 0;
    printf("Please enter a value for variable a:\n");
    scanf("%d", &a);
    printf("Please enter a value for variable b:\n");
    scanf("%d", &b);
    printf("The values of a and b are %d for a and %d for b.\n", a, b);
    printf("The value of a %% b is %d.\n", a % b);
    return 0;
}
