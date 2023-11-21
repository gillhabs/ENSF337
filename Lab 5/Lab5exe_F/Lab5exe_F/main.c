// lab5exF.h
// ENSF 337, Lab 5 Exercise F

#ifndef lab5ExF_h
#define lab5ExF_h
typedef struct point
{
    char label[10];
    double x ;  // x coordinate for point in a Cartesian coordinate system
    double y;   // y coordinate for point in a Cartesian coordinate system
    double z;   // z coordinate for point in a Cartesian coordinate system
}Point;

void reverse (Point *a, int n);
/* REQUIRES: Elements a[0] ... a[n-2], a[n-1] exists.
 * PROMISES: places the existing Point objects in array a, in reverse order.
 *           The new a[0] value is the old a[n-1] value, the new a[1] is the
 *           old a[n-2], etc.
 */

int search(const Point* struct_array, const char* target, int n);
/* REQUIRES: Elements struct-array[0] ... struct_array[n-2], struct_array[n-1]
 *           exists. target points to string to be searched for.
 * PROMISES: returns the index of the element in the array that contains an
 *           instance of point with a matching label. Otherwise, if there is
 *           no point in the array that its label matches the target-label,
 *           it should return -1.
 *           If there are more than one match in the struct_array, returns
 *           the index of the first occurrence.
 *           In this exercise you are NOT allowed to use any C Library functions
 */

void display_struct_point(const Point x, int i);

void populate_struct_array(Point* array, int n);

#endif /* lab5ExF_h */



// lab5exF.c
// ENSF 337, Exercise F

//#include "lab5exF.h"
#include <stdio.h>
#include <math.h>
#include<string.h>

int main(void)
{
    Point struct_array[10];
    int i;
    int position;
    
    populate_struct_array(struct_array, 10);
    
    printf("\nArray of Points contains: \n");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    
    printf("\nTest the search function");
    
    position = search(struct_array, "v0", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "v0");
    
    position = search(struct_array, "E1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E1");
    
    position = search(struct_array, "C5", 10);
    
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "C5");
    
    position = search(struct_array, "B7", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "B7");
    position = search(struct_array, "A9", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "A9");
    position = search(struct_array, "E11", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E11");
    
    position = search(struct_array, "M1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "M1");
    
    printf("\n\nTesting the reverse function:");
    
    reverse(struct_array, 10);
    
    printf("\nThe reversed array is:");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    return 0;
}


void display_struct_point(const Point x , int i)
{
    printf("\nstruct_array[%d]: %s <%.2lf, %.2lf, %.2lf>\n",
           i, x.label, x.x, x.y, x.z);
}

void populate_struct_array(Point* array, int n)
{
    int i;
    char ch1 = 'A';
    char ch2 = '9';
    char ch3 = 'z';
    
    for( i = 0; i < 10; i++)
    {
        /* generating some random values to fill them elements of the array: */
        array[i].x = (7 * (i + 1) % 11) * 100 - i /2;
        array[i].y = (7 * (i + 1) % 11) * 120 - i / 3;
        array[i].z = (7 * (i + 1) % 11) * 150 - i /4;
        
        if(i % 2 == 0)
            array[i].label[0] = ch1++;
        else
            array[i].label[0] = ch3--;
        array[i].label[1] = ch2--;
        array[i].label[2] = '\0';
    }
}

int search(const Point* struct_array, const char* label, int n)
{
    int output = -1;
    int h = 0;
    int i = 0;

    
    while(i < n)
    {
        while(*(struct_array[i].label + h) == *(label + h))
        {
            if(*(struct_array[i].label + h) == '\0' && *(label + h) == '\0')
            {
                break;
            }
            h++;
        }
        if(*(struct_array[i].label + h) - *(label + h) == 0){
            output = i;
            break;
        }
        else{
            i++;
        }
    }
    return output;
}



void reverse (Point *a, int n)
{
    int j = 9;
    
    for(int i = 0; i < n/2; i++){
        Point b = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = b;
        j--;
    }
    // Students should complete the definiton of this function
}

