//
//  Node.cpp
//  hw5
//
//  Created by Joanne Qiu on 3/14/22.
//

#include <stdio.h>
#include "Node.h"

Node::Node(int s)
{
    data = s;
    previous = NULL;
    next = NULL;
}
