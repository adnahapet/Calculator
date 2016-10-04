//
//  Evaluator.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Evaluator.h"

Evaluator::Evaluator():
    stack(new ExpStack),
    infix(*new std::vector <std::string>),
    postfix(*new std::vector <std::string>)
{
    
}

Evaluator::~Evaluator(){
    
    
}

void Evaluator::getExp(std::vector<std::string> expression){
    infix = expression;
}


//uses the inherent ascii values of the operators to manipulate stack
void Evaluator::infix2postfix (){
    
        std::string target;
    
        for (int i = 0; i <infix.size(); i++){
            
            if(infix[i] == "(" || infix[i] == "{" || infix[i] == "[" || infix[i] == "*" || infix[i] == "+" || infix[i] == "-"  || infix[i] == "/"){
                
                if(stack->size_of_stack_ == 0){
                    stack->push(infix[i]);
                }
                
                else{
            
                    if (infix[i] =="/" && stack->peek() != "*"){
                        stack->push(infix[i]);
                    }
                    else if( infix[i] < stack->peek() && stack->peek() != "/"){
                        stack->push(infix[i]);

                    }
                    
                    else if (stack->peek()=="(" || stack->peek()=="[" || stack->peek()=="{" ){
                        stack->push(infix[i]);
                    }
                    
                    else{
                        postfix.push_back(stack->pop());
                        stack->push(infix[i]);
                    }
                
                }
            }
            
            else if(infix[i] == ")" || infix[i] == "]" || infix[i] == "}"){
                if(infix[i] ==")")
                    target = "(";
                else if(infix[i] =="]")
                    target = "[";
                else if(infix[i] =="}")
                    target = "{";
                
                
                while(stack->peek() != target){
                        postfix.push_back(stack->pop());
                    }
                
                stack->pop();
                
            }
            
            else{
                postfix.push_back(infix[i]);
                    //Operand command
            }
            
         
        }//end for loop
    
    while(stack->size_of_stack_ >0){
        postfix.push_back(stack->pop());
    }
}

std::string Evaluator::printPostfix (){
    
    std::string pfixexpression;
    for(int i=0;i<postfix.size();i++){
        pfixexpression += postfix[i];
    }
    std::cout<< pfixexpression << "=";
    return pfixexpression;
}


bool Evaluator::isNum(int i){
    
    if(this->postfix[i] >="0" && this->postfix[i] <="9")
        return true;
    return false;
}

int Evaluator::eval (){
    
    std::vector <int> operandList;
    std::string number;
    int finalValue = 0;
    
    for( int i = 0; i <postfix.size(); i++){
        
        //creates operands
        if(isNum(i) == true){
            number += postfix[i];
            int operand = std::stoi(number);
            number.clear();
            operandList.push_back(operand);
        }
        
        //detects operator
        //moves operands to operandList vector treating it as a stack
        //uses operator on top two ints in stack, pops those ints, and pushes result onto stack in their place
        if(isNum(i)==false){
            int operandOne = operandList.back();
            operandList.pop_back();
            int operandTwo = operandList.back();
            operandList.pop_back();
            
            if(postfix[i] == "+"){
                finalValue = operandOne + operandTwo;
            }
            else if(postfix[i] == "-"){
                finalValue = operandOne - operandTwo;
            }
            else if(postfix[i] == "*"){
                finalValue = operandOne * operandTwo;
            }
            else if(postfix[i] == "/"){
                finalValue = operandOne / operandTwo;
            }
            operandList.push_back(finalValue);
        }
    }
    
    
    finalValue = operandList.front();
    operandList.pop_back();
    std::cout<<finalValue<<std::endl;
    postfix.clear();
    return finalValue;
}
