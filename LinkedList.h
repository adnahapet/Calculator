//
//  LinkedList.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <string>

#include "ListNode.h"



class LinkedList {
 
private:
    
public:
    
    ListNode * head;
    ListNode * tail;
    
    int size;
    
    
    //default constructor
    LinkedList();
    
    //default destructor
    ~LinkedList();
    
    //insert a node at the tail of the list
    void Insert(ListNode * node);
    
    //remove and return the node at head
    ListNode  * removeAtHead ( ) ;
    
};


#endif /* LinkedList_h */