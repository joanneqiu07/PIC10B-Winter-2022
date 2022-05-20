/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#ifndef List_h
#define List_h
#include "Node.h"
#include "Iterator.h"

class List
{
private:
    Node* first;
    Node* last;
    bool the_end;
    friend class Iterator;
public:
    List();
    ~List();
    void set_status(bool a); // set the the_end bool if approaching the end of the program
    void push_front(int data);
    void push_back(int data);
    void insert(Iterator iter, int s);
    void sort();
    void reverse();
    void merge(List other);
    Iterator erase(Iterator iter);
    Iterator begin();
    Iterator end();
};

#endif /* List_h */
