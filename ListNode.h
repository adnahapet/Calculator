//
//  ListNode.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


class ListNode{
    
    friend class LinkedList;
    
private:
    
    std::vector <std::string> element;
    ListNode * next;
    
public:
    
    ListNode();
    
    ListNode(std::vector <std::string> expression);//, ListNode * oldHead);
    
    std::string getNodeExp();
    
    std::vector <std::string> getNodeElement();
    
    ~ListNode();
    
};


#endif /* ListNode_h */