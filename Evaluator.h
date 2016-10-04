//
//  Evaluator.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Evaluator_h
#define Evaluator_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include "ExpStack.h"



class Evaluator{
    
private:
    ExpStack * stack;
    std::vector <std::string> infix;
    std::vector <std::string> postfix;
    
public:
    
    //default constructor
    Evaluator ();
    
    //default destructor
   ~Evaluator ();
   
    // get an expression into infix member variable
    void getExp(std::vector<std::string> expression);
    
    //convert infix expression to postfix using stack
    void infix2postfix ();
    
    // print out postfix expression
    std::string printPostfix ();
    
    
    bool isNum(int i);
    //evaluate the expression in its postfix form using stack
    int eval ();
    
    
};


#endif /* Evaluator_h */