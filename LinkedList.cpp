//
//  LinkedList.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "LinkedList.h"


LinkedList::LinkedList():
    head(nullptr),
    tail(nullptr),
    size(0)
{
    
    
}


LinkedList::~LinkedList(){
    while(head->next !=nullptr){
        removeAtHead();
    }
    delete tail;
}



void LinkedList::Insert(ListNode * node){
    if(tail==nullptr){
        node->next = nullptr;
        tail = node;
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
    size++;
}


ListNode *  LinkedList::removeAtHead(){
    
   
    ListNode *oldHead = head;
    head = head->next;
    delete oldHead;
    
    --size;
    
    return head;

}