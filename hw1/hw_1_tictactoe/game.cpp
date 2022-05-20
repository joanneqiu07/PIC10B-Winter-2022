/*
PIC 10B 1B, Homework 1
Purpose: Tic-tac-toe game
Author: Joanne Qiu
Date: 01/26/2022
*/


#include "game.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

/************************************************
           methods implementation
 ***********************************************/

using namespace std;
game::game(person* p1, person* p2)
{
    player1 = p1;
    player2 = p2;
}

void game::print_grid(const vector<string>& r1, const vector<string>& r2, const vector<string>& r3)
{
    
    cout << "     1      2       3" << endl;
    cout << "         |       |   " << endl;
    cout << "1   " << r1[0] << "    |   " << r1[1] << "   |   " << r1[2] << endl;
    cout << "         |       |   " << endl;
    cout << "  ------- ------- -----" << endl;
    cout << "         |       |   " << endl;
    cout << "2   " << r2[0] << "    |   " << r2[1] << "   |   " << r2[2] << endl;
    cout << "         |       |   " << endl;
    cout << "  ------- ------- -----" << endl;
    cout << "         |       |   " << endl;
    cout << "3   " << r3[0] << "    |   " << r3[1] << "   |   " << r3[2] << endl;
    cout << "         |       |   " << endl;
}

void game::win()
{
    if (player1->get_score() > player2->get_score())
    {
        cout << "Congratulations " << player1->get_name() << " . You won!" << endl;
    }
    else if (player1->get_score() < player2->get_score())
    {
        cout << "Congratulations " << player2->get_name() << " . You won!" << endl;
    }
    else if (player1->get_score() == player2->get_score())
    {
        cout << "The game ended in a tie." << endl;
    }

}

void game::play()
{
    // create three rows
    vector<string> r1(3, " ");
    vector<string> r2(3, " ");
    vector<string> r3(3, " ");
    
    cout << "     Tic Tac Toe" << endl;
    cout << "  " << player1->get_name() << " (X) - " << player2->get_name() << " (O)" << endl;
    cout << endl;
    
    print_grid(r1, r2, r3);
    cout << endl;

    // initialize the variables
    bool end = false;
    int turn = 0;
    string mark = " ";
    while(end == false && turn < 9)
    {
        // update the turn and renew the mark
        turn = turn + 1;
        if (turn%2 != 0)
        {
            mark = "X";
            cout << player1->get_name() << " (X) Mark Location: ";
        }
        else if (turn%2 == 0)
        {
            mark = "O";
            cout << player2->get_name() << " (O) Mark Location: ";
        }
        
        // get the coordinate from the input
        string s1, s2;
        cin >> s1 >> s2;

        
        // the game only continues when the coordinates are from (1, 1) to (3, 3)
        if ((s1 == "1" || s1 == "2" || s1 == "3") && (s2 == "1" || s2 == "2" || s2 == "3"))
        {
            if (s1 == "1") // first row
            {
                if (r1[stoi(s2) - 1] != " ") // code doesn’t take already marked coordinates
                {
                    cout << "This coordinate is occupied" << endl;
                    cout << endl;
                    turn = turn - 1;
                    continue;
                }
                else r1[stoi(s2) - 1] = mark; // update the first row with the mark
            }
            else if (s1 =="2") // second row
            {
                if (r2[stoi(s2) - 1] != " ") // code doesn’t take already marked coordinates
                {
                    cout << "This coordinate is occupied" << endl;
                    cout << endl;
                    turn = turn - 1;
                    continue;
                }
                else r2[stoi(s2) - 1] = mark; // update the second row with the mark
            }
            else if (s1 == "3") //third row
            {
                if (r3[stoi(s2) - 1] != " ") // code doesn’t take already marked coordinates
                {
                    cout << "This coordinate is occupied" << endl;
                    cout << endl;
                    turn = turn - 1;
                    continue;
                }
                else r3[stoi(s2) - 1] = mark; // update the third row with the mark
            }
        }
        else
        {
            // code doesn’t take wrong coordinates or letters.
            cout << "The input is invalid. Please choose coordinates from (1,1) to (3,3)" << endl;
            cout << endl;
            turn = turn - 1;
            continue;
        }

        // print the updated grid
        cout << endl;
        print_grid(r1, r2, r3);
        cout << endl;
        
        // check if one of the players win in two situations
        if ((r1[0] == r2[1] && r2[1] == r3[2] && r2[1] != " ") || (r1[2] == r2[1] && r2[1] == r3[0] && r2[1] != " ")) // three consecutive same marks in the diagonal
        {
            end = true;
            break;
        }
        else if (equal(r1.begin() + 1, r1.end(), r1.begin()) && r1[0] != " ")
        {// three same marks in the first row
            end = true;
            break;
        }
        else if (equal(r2.begin() + 1, r2.end(), r2.begin()) && r2[0] != " ")
        {// three same marks in the second row
            end = true;
            break;
        }
        else if (equal(r3.begin() + 1, r3.end(), r3.begin()) && r3[0] != " ")
        {// three same marks in the third row
            end = true;
            break;
        }
        
        // check if one of the players win when three same marks in a column
        for(int i = 0; i < 3; ++i)
        {
            if (r1[i] == r2[i] && r2[i] == r3[i] && r2[i] != " ")
            {
                end = true;
                break;
            }
        }

    }
    
    // prepare a string to hold the winner's name
    string winner = "player";

    if (end == false)
    {// if game ended in 9 turns without knowing who wins, it is a draw
        cout << "This round ended in a tie." << endl;
    }
    else
    {
        if (mark == "X") // player 1 wins
        {
            player1->update_score(1);
            winner = player1->get_name();
        }
        else if (mark == "O") // player 2 wins
        {
            player2->update_score(1);
            winner = player2->get_name();
        }
        cout << winner << " wins this round" << endl;
    }
    
    // print this round's result
    int len = max((player1->get_name()).length(),(player2->get_name()).length());
    cout << right << setw(len) << player1->get_name() << " : " << player1->get_score() << endl;
    cout << right << setw(len) << player2->get_name() << " : " << player2->get_score() << endl;

}


