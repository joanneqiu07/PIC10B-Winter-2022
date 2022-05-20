//
//  main.cpp
//  Midterm
//
//  Created by Joanne Qiu on 2/8/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include "student.h"
#include "usc_student.h"
#include "ucla_student.h"

using namespace std;

int main() {
    ifstream ucla;
    ucla.open("UCLA.txt");
    
    ifstream usc;
    usc.open("USC.txt");
    
    string title1, title2, sn, gen, bir, fgcs;
    getline(ucla, title1);
    getline(usc, title2);
    istringstream title(title1);
    title >> sn >> gen >> bir >> fgcs;
    
    cout << left << setw(16) << sn << left << setw(8) << gen << left << setw(12) << bir << left << setw(32) << fgcs << "Scholarship" << endl;
    
    string ucla_in, usc_in, n, g, bth, fg, sch;
    vector<student*> students;
    
    while (getline(ucla, ucla_in))
    {
        istringstream x(ucla_in);
        getline(x, n, '\t');
        getline(x, g, '\t');
        getline(x, bth, '\t');
        getline(x, fg, '\t');

        student* next_uclastudent = new ucla_student(n, g, bth, fg);
        students.push_back(next_uclastudent);
        
        char ucla_test;
        ucla.get(ucla_test);
        if (isalnum(ucla_test)) ucla.unget();
        else break;
    }
    

    while (getline(usc, usc_in))
    {
        istringstream y(usc_in);
        getline(y, n, '\t');
        getline(y, g, '\t');
        getline(y, bth, '\t');
        getline(y, sch, '\t');
        
        student* next_uscstudent = new usc_student(n, g, bth, sch);
        students.push_back(next_uscstudent);
        
        char usc_test;
        usc.get(usc_test);
        if (isalnum(usc_test)) usc.unget();
        else break;
    }
    
    for (int i = 0; i < students.size(); ++i)
    {
        students[i]->print();
    }
    
    for (int j = 0; j < students.size(); ++j) {delete students[j];}
    
    return 0;
}

