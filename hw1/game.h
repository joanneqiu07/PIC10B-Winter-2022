/*
PIC 10B 1B, Homework 1
Purpose: Tic-tac-toe game
Author: Joanne Qiu
Date: 01/26/2022
*/

#ifndef game_h
#define game_h
#include "person.h"
#include <vector>

/************************************************
  class definition and methods declarations
 ***********************************************/

using namespace std;
class game{
    private:
        // the two players point to person objects
        person* player1;
        person* player2;
    public:
        /*
            Contruct a game with person p1 and person p2
            @param p1 player 1
            @param p1 player 2
        */
        game(person* p1, person* p2);
        /*
            Print the recent grid to the console
            @param r1 the first row of the grid
            @param r2 the second row of the grid
            @param r3 the third row of the grid
        */
        void print_grid(const vector<string>& r1, const vector<string>& r2, const vector<string>& r3);
        /*
            Play the game for a round
        */
        void play();
        /*
            Compare the scores to see who wins
        */
        void win();         
};



#endif
