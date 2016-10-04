//
//  Calculator.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h

#include <stdio.h>
#include <string>

#include "Interpreter.h"
#include "Evaluator.h"
#include "LinkedList.h"


class Calculator{
    
private:
    
    Interpreter * interpreter;
    Evaluator * evaluator;
    LinkedList * explist;
    
public:
    
    //default constructor
    Calculator(void);
    
    //default destructor
    ~Calculator(void);
    
    
    void interpretExp();
    
    //
    void eval();
};

#endif /* Calculator_hpp */