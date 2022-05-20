//
//  ucla_student.cpp
//  Midterm
//
//  Created by Joanne Qiu on 2/8/22.
//

#include <stdio.h>
#include <iomanip>
#include "ucla_student.h"

using namespace std;
ucla_student::ucla_student(string n, string g, string bth, string fg):student(n, g, bth), fst_gen(fg){}

void ucla_student::print() const
{
    cout << left << setw(16) << student_name << left << setw(8) << gender << left << setw(12) << birthday << fst_gen << endl;

}
