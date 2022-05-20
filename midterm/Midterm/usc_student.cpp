//
//  usc_student.cpp
//  Midterm
//
//  Created by Joanne Qiu on 2/8/22.
//

#include <stdio.h>
#include <iomanip>
#include "usc_student.h"

using namespace std; 
usc_student::usc_student(string n, string g, string bth, string sch):student(n, g, bth), scholarship(sch){}

void usc_student::print() const
{
    cout << left << setw(16) << student_name << left << setw(8) << gender << left << setw(44) << birthday << scholarship << endl;
}
