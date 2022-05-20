/*
    PIC 10B, Homework 4
    Purpose: ComplexVector
    Author: Joanne Qiu
    Date: 03/04/2022
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Complex.h"
#include "ComplexVector.h"

using namespace std;

int main() {

    // construct v1 and v2
    Complex a1(2, 4), a2(3, 5), a3(-1, -3), a4(8, 10);
    Complex b1(-10, 3.5), b2(4, 7.3), b3(2, -8), b4(10, -142);
    
    ComplexVector v1(a1, a2, a3, a4);
    ComplexVector v2(b1, b2, b3, b4);
    
    // print v1 + v2, v1 - v2, v1 * v2, v1 / v2 to the console
    cout << right << setw(10) << "v1 = " << v1 << endl;
    cout << right << setw(10) << "v2 = " << v2 << endl;
    cout << right << setw(10) << "v1 + v2 = " << v1 + v2 << endl;
    cout << right << setw(10) << "v1 - v2 = " << v1 - v2 << endl;
    cout << right << setw(10) << "v1 * v2 = " << v1 * v2 << endl;
    cout << right << setw(10) << "v1 / v2 = " << v1 / v2 << endl;
 
    // print the first 6 terms in the sequence to a file;
    ComplexVector f;
    Complex f_1(1, 1);
    recur_fun(6, 1, f_1, f);
    ofstream out;
    out.open("ComplexSequence.txt");
    cout << "Writing Complex Sequence to File ...Done" << endl;
    out << f << endl;
    out.close();
    
    return 0;
}
