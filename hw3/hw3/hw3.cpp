/*
    PIC 10B, Homework 3
    Purpose: Textfile
    Author: Joanne Qiu
    Date: 02/18/2022
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>

#include "textfile.h"

using namespace std;


void count(istream& in, int& num_c, int& num_w, int& num_l)
{
   char cur_char;
   char last;
   num_c = 0;
   num_w = 0;
   num_l = 0;

   if (in.get(cur_char)) {
       in.unget();
       num_l++;
   }

   while (in.get(cur_char)) {
      if (cur_char == '\n' || (cur_char == '\f' && last == '\r')) num_l++;
      else num_c++;
      if (cur_char == ' ' && last != ' ') num_w++;
      last = cur_char;
   }
}

int main() {
    string file1_name, file2_name;
    ifstream file1, file2;
    ofstream properties;
    
    cout << "Enter the name of file 1: ";
    cin >> file1_name;
    cout << "Enter the name of file 2: ";
    cin >> file2_name;
    
    file1.open(file1_name);
    file2.open(file2_name);
    properties.open("Properties.txt");
    
    if (file1.fail()) {
        cout << "Error opening " << file1_name << endl;
        return 1;
    }
    
    int c1, w1, l1, c2, w2, l2;
    
    count(file1, c1, w1, l1);
    count(file2, c2, w2, l2);
    
    textfile file_1(file1_name, c1, w1, l1);
    textfile file_2(file2_name, c2, w2, l2);
    
    properties << file_1 << endl;
    properties << file_2 << endl;
    
    if (file_1 > file_2)
    {
        properties << "The file named \"" << file_1.get_name() << "\" has more lines than \""
        << file_2.get_name() << "\"." << endl;
    }
    else if (file_1 == file_2)
    {
        properties << "The file named \"" << file_1.get_name() << "\" has the same amount of lines than \""
        << file_2.get_name() << "\"." << endl;
    }
    else
    {
        properties << "The file named \"" << file_1.get_name() << "\" has less lines than \""
        << file_2.get_name() << "\"." << endl;
    }

    
    file1.close();
    file2.close();
    
    return 0;
}
