/*
PIC 10B 1B, Homework 1
Purpose: Tic-tac-toe game
Author: Joanne Qiu
Date: 01/26/2022
*/

#include "game.h"
#include "person.h"
#include <iostream>

using namespace std;

int main()
{
    int num;
    string p1, p2;
    
    cout << "Number of games: ";
    cin >> num;
    cout << "Player 1 Name = ";
    cin >> p1;
    cout << "Player 2 Name = ";
    cin >> p2;

    // construct a person on the heap and return a pointer to the person object
    person* player1 = new person(p1);
    person* player2 = new person(p2);

    // create a game
    game g(player1, player2);

 
    // play num rounds of games
    for (int i = 0; i < num; ++i)
    {
        g.play();
    }

    // check who wins
    g.win();

    // free the memory allocation of the pointers
    delete player1;
    delete player2;
}
