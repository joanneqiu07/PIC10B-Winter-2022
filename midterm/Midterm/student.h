//
//  student.h
//  Midterm
//
//  Created by Joanne Qiu on 2/8/22.
//

#ifndef student_h
#define student_h
#include <iostream>


using namespace std;
class student
{
protected:
    string student_name, gender, birthday;
public:
    student(string n, string g, string bth);
    virtual void print() const = 0;
};


#endif /* student_h */
