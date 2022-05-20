//
//  ucla_student.h
//  Midterm
//
//  Created by Joanne Qiu on 2/8/22.
//

#ifndef ucla_student_h
#define ucla_student_h
#include "student.h"
#include <iostream>

using namespace std;

class ucla_student: public student {
private:
    string fst_gen;
public:
    ucla_student(string n, string g, string bth, string fg);
    void print() const;
};

#endif /* ucla_student_h */
