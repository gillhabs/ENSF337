//
//  main.cpp
//  Lab7_exeA
//
//  Created by Gillian Habermehl on 2022-11-17.
//

#include <iostream>
//  ENSF 337- Fall 2022 lab 7, Exercise A
//  cplx.h

#ifndef cplx_h
#define cplx_h

class Cplx {
public:
    
    Cplx(): realM(-99), imagM(-99) {}
    
    Cplx (double r, double i);
    
    double getRealPart () const;
    
    double getImaginaryPart () const;
    
    void setRealPart(double arg);

    void setImaginaryPart(double arg);
    
    Cplx add(const Cplx& other)const;
    
    Cplx subtract(const Cplx* other)const;

private:
    double realM;
    double imagM;
};

#endif /* cplx_h */


//  ENSF 337, Exercise A
//  cplx.cpp
//  By: M. Moussavi

//#include "cplx.h"

Cplx::Cplx(double real , double imag ): realM(real), imagM(imag) {
    // point one
}

double Cplx::getRealPart() const {
    return realM;
}

double Cplx::getImaginaryPart( ) const {
    return imagM;
}

void Cplx::setRealPart(double arg) {
    
    realM = arg;
}

void Cplx::setImaginaryPart(double arg) {
    imagM = arg;
    // point two
}



// ENSF 337 - Lab 7 exercise A
//
//#include "cplx.h"

void global_print(const Cplx& n);


int main(void)
{
    Cplx num1;
    
    num1.setRealPart(666);
    
    Cplx num2(34, 5);

    num1.setImaginaryPart(500);
    
    return 0;
}

