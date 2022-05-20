/*
PIC 10B 1B, Homework 1
Purpose: Tic-tac-toe game
Author: Joanne Qiu
Date: 01/26/2022
*/

#ifndef person_h
#define person_h
#include <string>

/************************************************
  class definition and methods declarations
 ***********************************************/

using namespace std;
class person{
    private:
        string name;
        int score;

    public:
        /*
            Contruct a person with a name and 0 score
            @param n the name
        */
        person(string n);
        /*
            update the score
            @param s the point that will be added to the score
        */
        void update_score(int s);
        /*
            get the name of the person
        */
        string get_name() const;
        /*
            get the score of the person
        */
        int get_score() const;

};

#endif
