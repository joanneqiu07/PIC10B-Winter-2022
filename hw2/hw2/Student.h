/*
    PIC 10B 1B, Homework 2
    Purpose: StudentClub
    Author: Joanne Qiu
    Date: 02/04/2022
*/

#ifndef Student_h
#define Student_h

/************************************************
  class definition and methods declarations
 ***********************************************/

using namespace std;
#include <string>

class Student
{
    private:
        string name;
    public:
        /**
         Constructs a student with given name
         @param n the student name
         */
        Student(std::string n);
        /**
         Get the name of the student
         */
        string get_name() const;
    
};

#endif /* Student_h */
