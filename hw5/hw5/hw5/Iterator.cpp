/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#include <stdio.h>
#include "Node.h"
#include "Iterator.h"
#include <cassert>

Iterator::Iterator()
{
    position = NULL;
    container = NULL;
}

int Iterator::operator*() const
{
    assert(position != nullptr);
    return position->data;
}

Iterator& Iterator::operator++(int unused)
{
    assert(position != nullptr);
    position = position->next;
    return *this;
}

Iterator& Iterator::operator--(int unused)
{
    assert(position != container->first);
    if (position == nullptr) position = container->last;
    else position = position->previous;
    return *this;
}

bool Iterator::operator==(const Iterator& b) const
{
    return position == b.position;
}

bool Iterator::operator!=(const Iterator& b) const
{
    return position != b.position;
}
