/* File: lab5exE.h
 * ENSF 337 lab 5 - Exercise E
 */

#ifndef lab5ExE_h
#define lab5ExE_h

/* a structure that represents a point on a Cartesian coordinates system. */
typedef struct point
{
    char label[10];  // a label for a point
    double x ;       // x coordinate for point in a Cartesian coordinate system
    double y;        // y coordinate for point in a Cartesian coordinate system
    double z;        // z coordinate for point in a Cartesian coordinate system
} Point;

Point mid_point(const Point* p1, const Point* p2, const char* label);
/* REQUIRES:
 *   p1 and p2 point to Point objects
 * PROMISES:
 *   returns an object of Point that its x and y coordinates are the middle-
 *   point of those objects that p1 and p2 are pointing to. The returned
 *   object's label will be the copy of argument label.
 */

void swap(Point* p1, Point *p2);
/* REQUIRES:
 *   p1 and p2 point to objects of Point
 * PROMISES:
 *   swaps the values of data members in the two objects *p1 and *p2.
 */

void display_struct_point(const Point x);

double distance (const Point* a, const Point* b);
/* REQUIRES:
 *   a and b point to objects of Point
 * PROMISES:
 *   returns the distance between objects that a and b are pointing to.
 */
#endif /* lab5ExE_h */









/* File: lab5exE.c
 * ENSF 337 - lab 5 - Exercise E
 */
//
//#include "lab5exE.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point alpha = { "A1", 2.3, 4.5, 56.0};
    Point beta = { "B1", 25.9, 30.0, 97.0};
    printf ("Display the values in alpha, and beta: ");
    display_struct_point(alpha);
    display_struct_point(beta);
    
    Point *stp = &alpha;
    printf ("\n\nDisplay the values in *stp: ");
    display_struct_point(*stp);
    
    Point gamma = mid_point(stp, &beta, "M1");
    printf ("\n\nDisplay the values in gamma after calling mid_point function. ");
    printf ("Expected result is:\nM1 <14.10, 17.25, 76.50>");
    
    printf("\n\nThe actual result of calling mid_point function is: ");
    display_struct_point(gamma);
    
//    swap (stp, &beta);
    printf ("\n\nDisplay the values in *stp, and beta after calling swap function.");
    printf ("Expected to be:\nB1 <25.90, 30.00, 97.00>\nA1 <2.30, 4.50, 56.00>");
    
    
    printf("\n\nThe actual result of calling swap function is: ");
    display_struct_point(*stp);
    display_struct_point(beta);
    
    
    printf("\n\nThe distance between alpha and beta is: %.2f. ", distance(&alpha, &beta));
    printf ("(Expected to be: 53.74)");
    printf("\nThe distance between gamma and beta is: %.2f. ", distance(&gamma, &beta));
    printf ("(Expected to be: 26.87)");
    return 0;
}

void display_struct_point(const Point x)
{
    printf("\n%s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


Point mid_point(const Point* p1, const Point* p2, const char* label)
{
    Point middle = {"M1", 0, 0, 0};
    middle.x = (p1->x + p2->x) / 2;
    middle.y = (p1->y + p2->y) / 2;
    middle.z = (p1->z + p2->z) / 2;
    
    return middle;
}

void swap(Point* p1, Point *p2)
{
    Point p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
}

double distance(const Point* p1, const Point* p2)
{
    double dx, dy, dz;
    dx = (*p2).x - (*p1).x;
    dy = (*p2).y - (*p1).y;
    dz = (*p2).z - (*p1).z;
    double dist = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
    
    return dist;
}
