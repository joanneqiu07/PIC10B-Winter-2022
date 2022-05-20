/*
    PIC 10B, Homework 3
    Purpose: Textfile
    Author: Joanne Qiu
    Date: 02/18/2022
*/

#include <stdio.h>

#include "textfile.h"

using namespace std;

textfile::textfile(){};
textfile::textfile(std::string n, int c, int w, int l)
    : name(n), num_char(c), num_word(w), num_line(l)
{}

std::string textfile::get_name() const
{
    return name;
}

int textfile::get_num_char() const
{
    return num_char;
}

int textfile::get_num_word() const
{
    return num_word;
}

int textfile::get_num_line() const
{
    return num_line;
}

void textfile::print(ostream& out) const
{
    out << "File Name: " << name << endl;
    out << "Number of characters: " << num_char << endl;
    out << "Number of words: " << num_word << endl;
}

ostream& operator<<(ostream& out, const textfile& in)
{
    in.print(out);
    return out;
}

bool operator>(const textfile& left, const textfile& right)
{
    return (left.get_num_line() > right.get_num_line());
}

bool operator==(const textfile& left, const textfile& right)
{
    return (left.get_num_line() == right.get_num_line());
}
