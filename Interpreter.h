//
//  Interpreter.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Interpreter_h
#define Interpreter_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>


#include "ExpQueue.h"
#include "ExpStack.h"
#include "LinkedList.h"




class Interpreter{

private:
    ExpQueue * expqueue;
    ExpStack * expstack ;
    
public:
    // a linked list of valid expressions ∗/
    LinkedList * explist ;
    
    //Initialize member variables; cannot be empty ∗/
    Interpreter ();
    
    // clean up everything
    ~Interpreter ();
    
    // get user input into expqueue
    void getExp ( ) ;
    
    //
    void parse ();
    
    // tokenize an expression
    std::vector<std::string> tokenize(std::string expression);
    
    //check parenthesis balance using expstack
    bool isBalanced(std::vector<std::string> expression );
    
    //return the explist ∗/
    LinkedList * getExpList (); 
    
};

#endif /* Interpreter_h */