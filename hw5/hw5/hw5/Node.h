/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#ifndef Node_h
#define Node_h
#include <string>
#include "List.h"

class Node
{
public:
    Node(int s);
private:
    int data;
    Node* previous;
    Node* next;
    friend class List;
    friend class Iterator;
};

#endif /* Node_h */
