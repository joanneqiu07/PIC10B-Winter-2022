/*
    PIC 10B, Homework 4
    Purpose: ComplexVector
    Author: Joanne Qiu
    Date: 03/04/2022
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Complex.h"
#include "ComplexVector.h"

/************************************************
           methods implementation
 ***********************************************/

ComplexVector::ComplexVector(){};

ComplexVector::ComplexVector(Complex a, Complex b, Complex c, Complex d)
{
    complex_vector.push_back(a);
    complex_vector.push_back(b);
    complex_vector.push_back(c);
    complex_vector.push_back(d);
}

std::vector<Complex> ComplexVector::get_vector() const
{
    return complex_vector;
}

void ComplexVector::append(Complex obj)
{
    complex_vector.push_back(obj);
}

void ComplexVector::print(std::ostream& output) const
{
    output << "{";
    for (int i = 0; i < size(complex_vector); i++)
    {
        if (i == size(complex_vector) - 1) output << complex_vector[i];
        else output << complex_vector[i] << ", ";
    }
    output << "}";
}

std::ostream& operator<<(std::ostream& output, const ComplexVector& obj)
{
    obj.print(output);
    return output;
}

ComplexVector ComplexVector::operator+(const ComplexVector& right)
{
    ComplexVector temp;
    for (int i = 0; i < size(complex_vector); i++)
    {
        temp.append(complex_vector[i] + right.complex_vector[i]);
    }
    return temp;
}

ComplexVector ComplexVector::operator-(const ComplexVector& right)
{
    ComplexVector temp;
    for (int i = 0; i < size(complex_vector); i++)
    {
        temp.append(complex_vector[i] - right.complex_vector[i]);
    }
    return temp;
}

ComplexVector ComplexVector::operator*(const ComplexVector& right)
{
    ComplexVector temp;
    for (int i = 0; i < size(complex_vector); i++)
    {
        temp.append(complex_vector[i] * right.complex_vector[i]);
    }
    return temp;
}

ComplexVector ComplexVector::operator/(const ComplexVector& right)
{
    ComplexVector temp;
    for (int i = 0; i < size(complex_vector); i++)
    {
        temp.append(complex_vector[i] / right.complex_vector[i]);
    }
    return temp;
}

// the function calculates n terms of the sequence
void recur_fun(int n, int pos, Complex f_n, ComplexVector& f)
{
    // the function will stop when n = 0
    if (n == 0) return;
    // append the given complex number to the vector
    f.append(f_n);
    // calculate the next complex number f_n+1
    Complex num(2 * pos, 3 * pos);
    Complex den(7, 5 * pos * pos);
    Complex next = num / den * f.get_vector()[pos - 1];
    // go to the next round of calculation
    recur_fun(n - 1, pos + 1, next, f);
}
