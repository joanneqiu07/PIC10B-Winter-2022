/*  PIC 10B 2A, Midterm Exam
    Purpose: Student Datasets
    Author: Joanne Qiu
    Date: 02/08/2022
    Cite: xxx class use code from textbook page 123.
*/

#ifndef usc_student_h
#define usc_student_h
#include "student.h"
#include <iostream>

class usc_student: public student{
private:
    string scholarship;
public:
    usc_student(string n, string g, string bth, string sch);
    void print() const;
};

#endif /* usc_student_h */
