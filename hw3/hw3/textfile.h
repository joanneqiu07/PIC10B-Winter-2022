/*
    PIC 10B, Homework 3
    Purpose: Textfile
    Author: Joanne Qiu
    Date: 02/18/2022
*/

#ifndef textfile_h
#define textfile_h

#include <iostream>
#include <fstream>
#include <string>

class textfile {
public:
    textfile();
    textfile(std::string n, int c, int w, int l);
    
    std::string get_name() const;
    int get_num_char() const;
    int get_num_word() const;
    int get_num_line() const;
    void print(std::ostream& out) const;
    
private:
    std::string name;
    int num_char;
    int num_word;
    int num_line;
};
std::ostream& operator<<(std::ostream& out, const textfile& in);

bool operator>(const textfile& left, const textfile& right);

bool operator==(const textfile& left, const textfile& right);

#endif /* textfile_h */
