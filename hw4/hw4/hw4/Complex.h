/*
    PIC 10B, Homework 4
    Purpose: ComplexVector
    Author: Joanne Qiu
    Date: 03/04/2022
*/

#ifndef Complex_h
#define Complex_h

#include <iostream>

/************************************************
  class definition and methods declarations
 ***********************************************/

class Complex {
private:
    double real;
    double imag;

public:
    /*
        Contruct a default complex number 0 + 0i
    */
    Complex();
    /*
        Contruct a complex number with given real part and imaginary part
        @param r the real part
        @param i the imaginary part
    */
    Complex(double r, double i);
    /*
        get the real part
    */
    double get_real() const;
    /*
        get the imaginary part
    */
    double get_imag() const;
    /*
        set the real part with the given double
        @param r the real part
    */
    void set_real(double r);
    /*
        set the imaginary part with the given double
        @param r the imaginary part
    */
    void set_imag(double i);
    /*
        overload the stream output operator
        @param output the stream output
        @param obj the complex vector
    */
    friend std::ostream& operator<<(std::ostream& output, const Complex& obj);
    
    /*
        overload the arithmetic operators
        @param obj the complex vector
    */
    Complex operator+(const Complex& right);
    Complex operator-(const Complex& right);
    Complex operator*(const Complex& right);
    Complex operator/(const Complex& right);
};



#endif /* Complex_h */
