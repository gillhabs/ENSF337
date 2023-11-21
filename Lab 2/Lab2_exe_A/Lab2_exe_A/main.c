/*
 *  File name: Lab2_exe_A.c
 *  Assignment: Lab 2 Exercise A
 *  Lab Section: B02
 *  Created by Mahmood Moussavi
 *  Completed by: Gillian Habermehl and Nikita Williams
 *  Development Date: September 28, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invalid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    create_table(velocity);
    return 0;
}


void create_table(double v){
    printf("Angle\t\tt\t\t\td\n");
    printf("(deg)\t\t(sec)\t\t(m)\n");
    
    
    for(double degree = 0; degree <= 90; degree += 5){
        
        double theta = degree_to_radian(degree);
        double travel_time = Projectile_travel_time(theta, v);
        double travel_distance = Projectile_travel_distance(theta, v);
        printf("%f\t%f\t%f\t\n", degree, travel_time, travel_distance);
    }
    
}


double Projectile_travel_time(double a, double v){
        double t;
        t = (2 * v * sin(a) / G);
        
        return t;
}


double Projectile_travel_distance(double a, double v){
    double d;
    
    d = pow(v, 2) * sin(2 * a) / G;
    
    return d;
}


double degree_to_radian(double d){
    double theta;
    theta = d * PI / 180;

    return theta;
}




