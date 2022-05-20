/*
    PIC 10B 1B, Homework 2
    Purpose: StudentClub
    Author: Joanne Qiu
    Date: 02/04/2022
*/

#include <stdio.h>
#include "Student.h"

/************************************************
           methods implementation
 ***********************************************/

using namespace std;

Student::Student(string n)
{
    name = n;
}

string Student::get_name() const
{
    return name;
}
