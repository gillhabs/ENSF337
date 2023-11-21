//
//  main.cpp
//  Lab7_exeD
//
//  Created by Gillian Habermehl on 2022-11-17.
//


// DynString.cpp
// ENSF 337 Fall 2022 lab 7 exercise D
//
// completed by:
// lab section:
#include <assert.h>
#include <string.h>
using namespace std;
//#include "DynString.h"

// DynString.h
// ENSF 337 Fall 2022 lab 7 exercise D


#ifndef DYNSTRING_H
#define DYNSTRING_H

// WARNING
//   The DynString class has a major defect.  If you try to
//   copy a DynString object, bad things will happen.

class DynString {
public:
    DynString();
    // PROMISES: Empty string object is created.
    
    DynString(const char *s);
    // PROMISES: s points to first char of a built-in string.
    // REQUIRES: String object is created by copying chars from s.
    
    ~DynString();
    
    int length() const;
    // PROMISES: Return value is number of chars in string.
    
    const char at(int pos)const;
    // REQUIRES: pos >= 0 && pos < length()
    // PROMISES:
    //   Return value is char at position pos.
    //   (The first char in the string is at position 0.)
    
    
    const char * c_str() const;
    // PROMISES:
    //   Return value points to first char in built-in string
    //   containing the chars of the string object.
    
    void append(const DynString& tail);
    // PROMISES: chars are copied from tail to the end of the
    //     string object.
    
    void truncate(int new_length);
    // REQUIRES: new_length >= 0 && new_length <= length()
    // PROMISES:
    //   Length of string is reduced to new_length.
    
private:
    int lengthM;
    char *storageM;
};

#endif







DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
}

DynString::~DynString()
{
    delete [] storageM;
}

int DynString::length() const
{
    return lengthM;
}

const char DynString::at(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

const char * DynString::c_str() const
{
    return storageM;
}


void DynString::append(const DynString& tail)
{
    int new_length = lengthM + tail.lengthM;
    char *new_array = new char[new_length + 1] ;
    assert(new_array != NULL);
    
    for(int i = 0; i < lengthM; i++)
        new_array[i] = storageM[i];
    
    int k = 0;
    for(int i = lengthM; i < new_length; i++){
        new_array[i] = tail.storageM[k];
        k++;
    }
    new_array[new_length] = '\0';
    
    delete [] storageM;
    storageM = new_array;
    lengthM = new_length;
}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    // Point one
}





// part1.cpp
// ENSF 337 Fall 2022 exercise D
//


#include <iostream>
using namespace std;

//#include "DynString.h"

//int main()
//{
//    DynString a("Apple");
//    DynString *b;
//
//    // NOTE: The fact that the following code is within an extra pair of
//    // braces means that the object b will disappear before the object c
//    // is created.
//    {
//        b = new DynString("film");
//        char ch = b -> at(2);
//        cout << "ch is: " << ch << endl;
//        cout << "a before call to truncate function is: " << a.c_str() << endl;
//        a.truncate(3);
//        cout << "a after truncate is: " << a.c_str() << endl;
//        DynString c("Debug");
//    }
//    // point two
//    delete b;
//    return 0;
//}






// part2.cpp
// ENSF 337 2022 Lab 7 Exercise D


//
//#include <iostream>
//using namespace std;

//#include "DynString.h"

int main()
{
    DynString x("foot");
    DynString y;
    DynString z("ball");
    
    x.truncate(3);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foo\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 3).\n" << endl;
    
    x.truncate(0);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 0).\n" << endl;
#if 1
    x.append("foot");
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foot\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 4).\n" << endl;
    x.append(y);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foot\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 4).\n" << endl;
    x.append(z);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"football\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 8).\n" << endl;;
#endif
    
  return 0;
}
