/*
    PIC 10B, Homework 4
    Purpose: ComplexVector
    Author: Joanne Qiu
    Date: 03/04/2022
*/

#ifndef ComplexVector_h
#define ComplexVector_h

#include "Complex.h"
#include <vector>
#include <iostream>

/************************************************
  class definition and methods declarations
 ***********************************************/

class ComplexVector {
private:
    std::vector<Complex> complex_vector;
public:
    /*
        Contruct an empty complex vector
    */
    ComplexVector();
    /*
        Contruct a complex vector with four complex numbers
        @param a the complex number
        @param b the complex number
        @param c the complex number
        @param d the complex number
    */
    ComplexVector(Complex a, Complex b, Complex c, Complex d);
    /*
        get the complex vector
    */
    std::vector<Complex> get_vector() const;
    /*
        append a complex number to the complex vector
        @param obj the complex number
    */
    void append(Complex obj);
    /*
        print the complex vector
        @param output the output stream
    */
    void print(std::ostream& output) const;
    /*
        overload the stream output operator
        @param output the stream output
        @param obj the complex vector
    */
    friend std::ostream& operator<<(std::ostream& output, const ComplexVector& obj);
    
    /*
        overload the arithmetic operators
        @param obj the complex vector
    */
    ComplexVector operator+(const ComplexVector& right);
    ComplexVector operator-(const ComplexVector& right);
    ComplexVector operator*(const ComplexVector& right);
    ComplexVector operator/(const ComplexVector& right);
};

// a recursive function that builds the sequence with a given length and an initial point
void recur_fun(int n, int pos, Complex f_n, ComplexVector& f);

#endif /* ComplexVector_h */
