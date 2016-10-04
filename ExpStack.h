//
//  ExpStack.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

//#ifndef ExpStack_h
//#define ExpStack_h

#ifndef EXPSTACK_h
#define EXPSTACK_h


#include <stdio.h>
#include <vector>
#include <string>


class ExpStack {
    
private:
    
    std::vector <std::string> stack;
    int top_;
    
    
public:
    
    //keeps track of size of stack
    int size_of_stack_;
    
    //initialize member variables; cannot be empty 
    ExpStack ( ) ;
    
    //clean up everything ; cannot be empty
   ~ExpStack ( ) ;
    
    //push an element onto the top of the stack
    void push(std::string element);
    
    //clears stack
    void clear(void);
    
    //pop up the element at the top of the stack and return the element
    std::string pop(void);
    
    //returns top element of stack without popping
    std::string peek(void);
    
    
};

#endif /* ExpStack_h */
