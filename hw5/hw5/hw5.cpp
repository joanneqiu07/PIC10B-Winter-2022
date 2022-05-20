/*
    PIC 10B, Homework 5
    Purpose: LinkedList
    Author: Joanne Qiu
    Date: 03/14/2022
*/

#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include "List.h"

using namespace std;

int main() {
    List num;
    Iterator pos;
    
    cout << "Please input a set of nonnegative numbers for a list" << endl;
    cout << "(Enter -1 when you are finished):" << endl;
    cout << endl;
    
    // get the input from the user and save them to the List
    int input;
    while(cin >> input)
    {
        if (input == -1) break;
        num.push_back(input);
    }
    
    cout << "Your list is" << endl;
    cout << "(";
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        if (pos == num.end()--) cout << *pos;
        else cout << *pos << ",";
    }
    cout << ")\n\n";
    
    // insert input value to the List
    int index = 0;
    int value = 0;
    while(true)
    {
        pos = num.begin();
        cout << "Select an index for insertion (enter -1 when finished): ";
        cin >> index;
        if (index == -1) break;
        cout << "Select a value for insertion: ";
        cin >> value;

        for (int i = 0; i < index; i++) pos++;
        num.insert(pos, value);
    }
    cout << "\n\n";
    cout << "The augmented List is " << endl;
    cout << "(";
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        if (pos == num.end()--) cout << *pos;
        else cout << *pos << ",";
    }
    cout << ")\n\n";
    
    // sort the List
    cout << "When we sort the previous list we obtain" << endl;
    num.sort();
    cout << "(";
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        if (pos == num.end()--) cout << *pos;
        else cout << *pos << ",";
    }
    cout << ")" << endl;
    
    // reverse the List
    cout << "And this sorted list in reverse order is" << endl;
    num.reverse();
    cout << "(";
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        if (pos == num.end()--) cout << *pos;
        else cout << *pos << ",";
    }
    cout << ")" << endl;
    
    // merge the List with (2,3,5,7,11)
    cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << endl;
    List other;
    other.push_front(11);
    other.push_front(7);
    other.push_front(5);
    other.push_front(3);
    other.push_front(2);
    num.merge(other);
    cout << "(";
    for (pos = num.begin(); pos != num.end(); pos++)
    {
        if (pos == num.end()--) cout << *pos;
        else cout << *pos << ",";
    }
    cout << ")" << endl;
    
    // the program approaches the end and will automatically call the destructor
    num.set_status(true);
    other.set_status(true);
    return 0;
}
