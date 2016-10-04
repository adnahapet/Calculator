//
//  main.cpp
//  Calculator
//
//  Created by Armen Nahapetian on 2/20/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include <iostream>
#include "Calculator.h"

int main(int argc, const char * argv[]) {
    
    Calculator myCalculator = *new Calculator;
    
    myCalculator.interpretExp();
    
    myCalculator.eval();
}
