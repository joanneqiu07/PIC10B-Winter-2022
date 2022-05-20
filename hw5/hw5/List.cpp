/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#include <stdio.h>
#include <iostream>
#include "Iterator.h"
#include "List.h"

List::List()
{
    first = NULL;
    last = NULL;
    the_end = false;
}

List::~List()
{
    if (the_end){
        Iterator iter = begin();
        delete iter.position->previous;
        while(iter != end())
        {
            Node* pos = iter.position;
            iter++;
            delete pos;
        }
        delete iter.position;
    }
}

void List::set_status(bool a)
{
    the_end = a;
}

Iterator List::begin()
{
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

Iterator List::end()
{
    Iterator iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}

void List::push_front(int data)
{
    Node* new_node = new Node(data);
    if (last == NULL) // List is empty
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->next = first;
        first->previous = new_node;
        first = new_node;
    }
}

void List::push_back(int data)
{
    Node* new_node = new Node(data);
    if (last == NULL) // List is empty
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}

void List::insert(Iterator iter, int s)
{
    if (iter.position == NULL)
    {
        push_back(s);
        return;
    }
    Node* after = iter.position;
    Node* before = after->previous;
    Node* new_node = new Node(s);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == NULL)
        first = new_node;
    else
        before->next = new_node;
}


void List::sort()
{
    int len = 0;
    Iterator iter = begin();
    
    // find the length of the List
    if (first != NULL) len++;
    for (iter = begin(); iter != end(); iter++) len++;
    
    for (int i = 0; i < len - 1; i++)
    {
        iter = begin();
        int min = *iter;
        int temp = i;
        
        // find the minimum
        for (int j = 1; j < len - temp - 1; j++)
        {
            iter++;
            if (min > *iter) min = *iter;
            else min = min;
        }
        
        // locate the minimum (for only once) and erase it
        iter = begin();
        for (int k = 0; k < len - temp - 1; k++)
        {
            if (*iter == min)
            {
                erase(iter);
                break;
            }
            iter++;
        }
        
        // add the min to the end of the List
        push_back(min);
    }
    
}

void List::reverse()
{
    Node* pos = first;
    Node* after = NULL;
    Node* before = NULL;
    
    last = first;
    while(pos != NULL) {
        after = pos->next;
        pos->next = before;
        pos->previous = after;
        before = pos;
        pos = after;
    }
    first = before;
}


void List::merge(List other)
{
    int len1 = 0;
    int len2 = 0;
    
    if (first != NULL) len1++;
    if (other.first != NULL) len2++;
    
    // find the lengths of the two Lists
    Iterator r1, r2;
    for (r1 = begin(); r1 != end(); r1++) len1++;
    for (r2 = other.begin(); r2 != other.end(); r2++) len2++;
    
    int i = 1; // the holder of the index of the whole List
    int j = 1; // the holder of the index of the second List
    r1 = begin();
    r2 = other.begin();
    while (i < len1 + len2)
    {
        if (j < len1) // merge the two list when len1 > len2 or the index of the second list < len1
        {
            r1++;
            insert(r1, *r2);
            i += 2;
        }
        else if (j >= len1 && len2 >= len1) // when j >= len1, add the rest of the second list directly
        {
            push_back(*r2);
            i++;
        }

        if (j == len2 - 1) break; // exit when approaching the end of the second list
        r2++;
        j++;
        
    }
    
}

Iterator List::erase(Iterator iter)
{
    assert(iter.position != NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    
    if (remove == last)
        last = before;
    else
        after->previous = before;
    delete remove;
    
    Iterator r;
    r.position = after;
    r.container = this;
    return r;
}
