/*
    PIC 10B 1B, Homework 2
    Purpose: StudentClub
    Author: Joanne Qiu
    Date: 02/04/2022
*/

#include <stdio.h>
#include <iostream>
#include "StudentClub.h"
#include "Student.h"
#include <vector>

/************************************************
           methods implementation
 ***********************************************/

using namespace std;

StudentClub::StudentClub(Student* p, Student* v, Student* s, Student* t, vector<Student*> m)
{
    president = p;
    vice_president = s;
    secretary = s;
    treasurer = t;
    club_members = m;
}

Student* StudentClub::get_president() const
{
    return president;
}

Student* StudentClub::get_vice_president() const
{
    return vice_president;
}

Student* StudentClub::get_secretary() const
{
    return secretary;
}

Student* StudentClub::get_treasurer() const
{
    return treasurer;
}

vector<Student*> StudentClub::get_members() const
{
    return club_members;
}

void StudentClub::add_member(Student* s)
{
    club_members.push_back(s);
}

size_t StudentClub::number_members() const
{
    // create a vector that copies the club_members
    vector<Student*> members = club_members;
    
    // use a loop to erase the duplicated members' information
    for (int i = 0; i < members.size(); i++)
    {
        for (int j = i + 1; j < members.size(); j++)
        {
            if (members[i]->get_name() == members[j]->get_name())
            {// if there is an element has a duplicate in the vector, erase the element and reduece i by 1
                members.erase(members.begin() + i);
                i--;
                break;
            }
            
        }
    }
    
    // return the size of the vector that has distinct members' information
    return members.size();
}
