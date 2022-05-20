/*
PIC 10B 1B, Homework 1
Purpose: Tic-tac-toe game
Author: Joanne Qiu
Date: 01/26/2022
*/

#include "person.h"

/************************************************
           methods implementation
 ***********************************************/

person::person(string n)
{
    name = n;
    score = 0;
}

void person::update_score(int s)
{
    score = score + s;
}

string person::get_name() const
{
    return name;
}

int person::get_score() const
{
    return score;
}
