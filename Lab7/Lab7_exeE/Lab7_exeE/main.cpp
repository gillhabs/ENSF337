//
//  main.cpp
//  Lab7_exeE
//
//  Created by Gillian Habermehl on 2022-11-17.
//





// simpleVector.h
// ENSF 337 - lab-7 Exercise D

#ifndef simpleVector_h
#define simpleVector_h

typedef int TYPE;

class SimpleVector
{
public:
    SimpleVector(): storageM(0), sizeM(0), capacityM(0) { };
    
    SimpleVector(const TYPE *arr, int n);
    // REQUIRES:
    //        arr points to the beginning of a an array with the  elements
    //        arr[0], arr[1], ..., arr[n-1].
    //        n > 0
    // PROMISES:
    //        allocates dynamically memory space for the vector with n elements of
    //        of TYPE. Then copies the values from arr[0] to storageM[0], followed
    //        by copying arr[1]  ..., and arr[n-1] to the dynamically allocate
    //        memory space, and updates the size of the vector with n.
    
    ~SimpleVector() { delete [] storageM;}
    
    SimpleVector(const SimpleVector& source);
    
    SimpleVector& operator= (const SimpleVector& rhs);
    
    int size() const {return sizeM;}
    
    TYPE& at(int i);
    // PROMISES: returns reference to element i of object
    //           - if i < 0 or i >= sizeM terminates the program
    
    const TYPE& at(int i)const;
    // PROMISES: returns reference to element i of object
    //           - if i < 0 or i >= sizeM terminates the program
    
    void push_back(TYPE arg);
    
    // PROMISES: Size of vector is increased by one element, if needed.
    //           Sets the last element to arg.

    
private:
    TYPE *storageM;
    int sizeM;     // number of used elements in the dynamically allocated space
    int capacityM; // total number of dynamically allocated elements for storageM

};

#endif

#include <iostream>








// ENSF 337- lab 7 - Exercise D
//  simpleVector.cpp

/*
 NOTES ON MEMORY ALLOCATION POLICIES FOR SimpleVector OBJECT:
 
 - If vector objects are supposed to be empty storageM will be NULL and the values
   of sizeM and capacityM must be set to zero.
 - If the objects of vector are supposed to be initialize with supplied values of
   an array, the size a and values in the dynamically memory space for storageM
   must be identical to the size and values in the supplied array. And, the
   values of sizeM and capacityM should be both set to the exact size of array.
 
- If any member function need to resize the vector, it should check the values of
  sizeM and capacityM:
  - If sizeM is equal to capacityM and vector is empty (i.e. capaictyM is equal to
    zero), capcityM should be changed to 2.
  - Otherwise, if sizeM is equal to capacityM, and capacityM is not zero (i.e.
    vector is NOT empty), the value of capacityM should be doubled up
  EXAMPLE: if capacityM is 5 and sizeM is also 5:
     1. the value of capacityM should be changed to 10.
     2. the dynamically allocated memory space for storageM should be reallocated
        to 10.
     3. The current values in the vector should be preserved and any unnecessary
        dynamically allocated memory must to deallocated.
*/

//#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
}

TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {

    if(capacityM == sizeM){
        if(capacityM == 0){
            capacityM = 2;
        }
        else{
            capacityM = capacityM * 2;
        }
    }
    sizeM += 1;
    
    int *new_array = new int[capacityM + 1];
    assert(new_array != NULL);
    
    for(int i = 0; i < sizeM-1; i++)
        new_array[i] = storageM[i];
    
    new_array[sizeM-1] = val;
    new_array[sizeM] = '\0';
    
    delete [] storageM;
    storageM = new_array;
}


SimpleVector::SimpleVector(const SimpleVector& source) {

    sizeM = source.sizeM;
    capacityM = source.capacityM;
    
    storageM = new int[sizeM + 1];
    assert(storageM != 0);
    
    for(int i = 0; i < sizeM; i++)
        storageM[i] = source.storageM[i];
}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){

    if(this != &rhs){
        delete [] storageM;
        sizeM = rhs.sizeM;
        storageM = new int[sizeM + 1];

        for(int i = 0; i < sizeM; i++)
            storageM[i] = rhs.storageM[i];
    }
    return *this;
}








// ENSF 337 - lab 7 Exercise E

//#include "simpleVector.h"
#include <iostream>
using namespace std;

void print (const SimpleVector& v);

int main(void)
{
    TYPE bar[] = {45, 69, 12};
    TYPE array[4] = {3000, 6000, 7000, 8000};
    
    SimpleVector v1 (bar, 3);
    SimpleVector v2(array, 4);

    cout << "Object v1 is expected to display: 45 69 12" << endl;
    print(v1);
    
    cout << "Object v2 is expected to diaplay: 3000 6000 7000 8000" << endl;
    print(v2);
    
    v1.at(0) = 1000;
    v1.at(1) = 2000;
    
    cout << "\nAfter two calls to at v1 is expected to display: 1000 2000 12:\n";
    print(v1);
    
    for(int i = 0; i <2; i++)
        v2.push_back((i + 3) * 7);
    
    cout << "\nv2 expected to display: 3000 6000 7000 8000 21 28" << endl;
    print(v2);
    
    
    #if 1
    // When ready to test copying objects, change #if 0 to #if 1. First, try to test
    // your assignment operator by moving the #if 0 to the line before object v4 is
    // is declared.

    v2 = v1;
    //ASSIGNMENT
    v1.at(2) = 8000;
    cout << "\nAfter copy v2 is expected to display: 1000 2000 12" << endl;
    print(v2);
    
    cout << "\nv1 is expected to display: 1000 2000 8000" << endl;
    print(v1);
    
    SimpleVector v3 (v2);
    //NOT A CALL TO CONSTRUCTOR V3 WILL BE INITIALIZED WITH A MEMBER OF V2
    cout << "\nv3 is expected to diplay: 1000 2000 12" << endl;
    v2.at(0) = -333;
    print(v3);
    
    cout << "\nv2 is expected to display: -333 2000 12" << endl;
    print(v2);
    
    SimpleVector v4(v1);
    cout << "\nv4 is expected to diplay: 1000 2000 8000" << endl;
    v1.at(0) = -1000;
    print(v4);
    
    v1 = v1;
    cout << "\nv1 after self-copy is expected to diplay: -1000 2000 8000" << endl;
    print(v1);
    
    v1 = v2 = v3;
    cout << "\nv1 after chain-copy is expected to diplay: 1000 2000 12" << endl;
    print(v1);
    cout << "\nv2 after chain-copy is expected to diplay: 1000 2000 12" << endl;
    print(v2);
#endif
    
    return 0;
}



void print (const SimpleVector& v)
{
    for (int i =0 ; i < v.size();  i++)
    {
        cout <<  v.at(i) << " ";
    }
    cout << endl;
}
