/*
    PIC 10B 1B, Homework 2
    Purpose: StudentClub
    Author: Joanne Qiu
    Date: 02/04/2022
*/

#ifndef StudentClub_h
#define StudentClub_h
#include "Student.h"
#include <string>
#include <vector>
#include <iostream>


/************************************************
  class definition and methods declarations
 ***********************************************/

using namespace std;

class StudentClub
{
    private:
        Student* president;
        Student* vice_president;
        Student* secretary;
        Student* treasurer;
        vector<Student*> club_members;
    public:
        /**
         Constructs a student club with given president, vice-president, secretary, treasurer, and members.
         @param p the president
         @param v the vice-president
         @param s the secretary
         @param t the treasurer
         @param m the members
         */
        StudentClub(Student* p, Student* v, Student* s, Student* t,
                    vector<Student*> m);
        /**
         Get the president of this student club.
         */
        Student* get_president() const;
        /**
         Get the vice president of this student club.
         */
        Student* get_vice_president() const;
        /**
        Get the secretary of this student club.
        */
        Student* get_secretary() const;
        /**
         Get the treasurer of this student club.
         */
        Student* get_treasurer() const;
        /**
         Get the members of this student club.
         */
        vector<Student*> get_members() const;
        /**
         Adds a member to the student club.
         @param s the studentclub's member
         */
        void add_member(Student* s);
        /**
         Get the size  of this student club.
         */
        size_t number_members() const;
};

#endif /* StudentClub_h */
