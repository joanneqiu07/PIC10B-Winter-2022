/*
    PIC 10B 1B, Homework 2
    Purpose: StudentClub
    Author: Joanne Qiu
    Date: 02/04/2022
*/

#include "Student.h"
#include "StudentClub.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{
    // ask user for the name of the officers
    string p, v, s, t;
    cout << "President: ";
    getline(cin, p);
    cout << endl;
    
    cout << "Vice-president: ";
    getline(cin, v);
    cout << endl;
    
    cout << "Secretary: ";
    getline(cin, s);
    cout << endl;
    
    cout << "Treasurer: ";
    getline(cin, t);
    cout << endl;
    
    // construct the officers and the club
    Student* president = new Student(p);
    Student* vice_president = new Student(v);
    Student* secretary = new Student(s);
    Student* treasurer = new Student(t);
    vector<Student*> club_members;
    club_members.push_back(president);
    club_members.push_back(vice_president);
    club_members.push_back(secretary);
    club_members.push_back(treasurer);
    
    StudentClub math(president, vice_president, secretary, treasurer, club_members);
    
    // ask user for the first new member
    string member;
    cout << "New Member (Q to quit): ";
    getline(cin, member);
    cout << endl;
    
    // ask user for new members until the user wants to quit
    while(member != "Q")
    {
        Student* new_member = new Student(member);
        math.add_member(new_member);
        cout << "New Member (Q to quit): ";
        getline(cin, member);
        cout << endl;
    }
    
    // print the club's officers' information to the console
    cout << "MATHLETES( " + to_string(math.number_members()) + " total members)" << endl;
    cout << right << setw(17) << "President: " << math.get_president()->get_name() << endl;
    cout << right << setw(17) << "Vice President: " << math.get_vice_president()->get_name() << endl;
    cout << right << setw(17) << "Secretary: " << math.get_secretary()->get_name() << endl;
    cout << right << setw(17) << "Treasurer: " << math.get_treasurer()->get_name() << endl;
    
    // reclaim memory for the pointers
    delete president;
    delete vice_president;
    delete secretary;
    delete treasurer;
    
    return 0;
}
