//
//  ListNode.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "ListNode.h"


ListNode::ListNode():
element(*new std::vector <std::string>),
next(nullptr)
{
    
}

ListNode::ListNode(std::vector <std::string> expression){
    element = expression;
    
}


//for testing purposes
std::string ListNode::getNodeExp(){
    std:: string temp;
    for (int i = 0; i <element.size();i++){
        temp += element[i];
    }
    return temp;
    
}

std::vector <std::string> ListNode::getNodeElement(){
    return element;
}


ListNode::~ListNode(){
    
    //delete  next;
    
}