//
//  ExpStack.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "ExpStack.h"


ExpStack::ExpStack ( ):
    top_(-1),
    size_of_stack_(0)
{
    
    stack = *new std::vector <std::string> (100);
    
}


ExpStack::~ExpStack(void){
    
    stack.clear();
    
}



void ExpStack::push(std::string element){
    
    top_++;
    stack[top_]=element;
    size_of_stack_++;
}


std::string ExpStack::pop(void){
    
    std::string target = stack[top_];
    --top_;
    --size_of_stack_;
    return target;
}

void ExpStack::clear(void){
    while(size_of_stack_>0){
        this->pop();
        --top_;
    }
}

std::string ExpStack::peek(void){
    return stack[top_];
}