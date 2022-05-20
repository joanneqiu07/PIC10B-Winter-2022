/*
    PIC 10B, Homework 4
    Purpose: ComplexVector
    Author: Joanne Qiu
    Date: 03/04/2022
*/

#include <stdio.h>
#include <iomanip>
#include "Complex.h"

/************************************************
           methods implementation
 ***********************************************/

Complex::Complex()
{
    real = imag = 0;
}

Complex::Complex(double r, double i): real(r), imag(i) {}

double Complex::get_real() const
{
    return real;
}

double Complex::get_imag() const
{
    return imag;
}

void Complex::set_real(double r)
{
    real = r;
}

void Complex::set_imag(double i)
{
    imag = i;
}

Complex Complex::operator+(const Complex& right)
{
    return Complex(real + right.real, imag + right.imag);
}

Complex Complex::operator-(const Complex& right)
{
    return Complex(real - right.real, imag - right.imag);
}

Complex Complex::operator*(const Complex& right)
{
    return Complex(real*right.real - imag*right.imag,
                   imag*right.real + real*right.imag);
}

Complex Complex::operator/(const Complex& right)
{
    double real_num = real*right.real + imag*right.imag;
    double imag_num = imag*right.real - real*right.imag;
    double den = right.real * right.real + right.imag * right.imag;
    return Complex(real_num/den, imag_num/den);
}

// overloading the stream output operator for Complex objects
std::ostream & operator<<(std::ostream& output, const Complex& obj)
{
    std::cout << std::fixed << std::setprecision(1);
    if (obj.imag < 0) {
        output << std::right << std::setw(5) << obj.real << " -" << std::right << std::setw(5) << abs(obj.imag) << "i ";
    }
    else
    {
        output << std::right << std::setw(5) << obj.real << " +" << std::right << std::setw(5) << obj.imag << "i ";
    }
    
    return output;
}
