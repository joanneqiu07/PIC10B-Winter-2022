/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#ifndef Iterator_h
#define Iterator_h

class Node;
class List;

class Iterator
{
private:
    Node* position;
    const List* container;
    friend class List;
public:
    Iterator();
    int operator*() const;
    Iterator& operator++(int unused);
    Iterator& operator--(int unused);
    bool operator==(const Iterator& b) const;
    bool operator!=(const Iterator& b) const;
};

#endif /* Iterator_h */
