//
//  Interpreter.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Interpreter.h"



Interpreter::Interpreter():
    expqueue(new ExpQueue),
    expstack(new ExpStack),
    explist(new LinkedList)
{
    
    
}

Interpreter::~Interpreter(){
    
    
}

void Interpreter :: parse(){
    
    std::vector <std::string> temp;
    
    for(int i=0;i < expqueue->size_of_queue_;i++){
        temp = tokenize(expqueue->getQueue(i));
        if(isBalanced(temp)==true){
            explist->Insert(new ListNode(temp));
        }
        else if(isBalanced(temp)== false){
            std::cout<<expqueue->getQueue(i)<<"is an Unbalanced Expression sorry... discarding"<<std::endl;
        }
    }
   
    
    //std::cout<<explist->head->getNodeExp()<<std::endl;
    //explist->removeAtHead();
    //std::cout<<explist->head->getNodeExp()<<std::endl;
    //std::cout<<explist->tail->getNodeExp()<<std::endl;
    
}


void Interpreter::getExp(){
    std::string input;
    std::cout<<"Please enter one expression per line with spaces between all operators and operands."<<std::endl;
    std::cout<<"Enter 'End' on its own line to continue to calculations."<<std::endl;
    while(input != "End"){
        getline(std::cin,input);
        if(input=="End")
            break;
        expqueue->enqueue(input);
    }
    
}

std::vector <std::string> Interpreter::tokenize(std::string expression){
    
    std::vector <std::string> temp;
    std::stringstream ss(expression);
    std::string token;
    
    while(ss >> token){
        temp.push_back(token);
    }
    return temp;
}


bool Interpreter::isBalanced(std::vector<std::string> expression ){
    
    for(int i = 0; i < expression.size(); i++){
        if (expression[i] == "(" || expression[i] == "{" || expression[i] =="["){
            expstack->push(expression[i]);
        }
        else if (expression[i] == ")"){
            if(expstack->size_of_stack_==0 || expstack->pop() != "(")
                return false;
        }
        else if(expression[i] == "}"){
            if(expstack->size_of_stack_==0 || expstack->pop() != "{")
                return false;
        }
        else if(expression[i] == "]"){
            if(expstack->size_of_stack_==0 || expstack->pop() != "[")
                return false;
        }
    }
    if(expstack->size_of_stack_==0)
        return true;
    expstack->clear();
    return false;
}


LinkedList * Interpreter:: getExpList (){
    
    return this->explist;
    
}