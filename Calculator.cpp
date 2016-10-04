//
//  Calculator.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Calculator.h"


Calculator::Calculator():
    interpreter(new Interpreter),
    explist(new LinkedList),
    evaluator(new Evaluator)
{
    
}

Calculator::~Calculator(){
    
}

void Calculator :: interpretExp(){
    this->interpreter->getExp();
    this->interpreter->parse ();
    this->explist = interpreter->getExpList();
}

void Calculator :: eval(){
   while(explist->size > 0 ){
       this->evaluator->getExp(explist->head->getNodeElement());
       this->evaluator->infix2postfix();
       this->evaluator->printPostfix();
       this->evaluator->eval();
       this->explist->removeAtHead();
    }
}