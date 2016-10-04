//
//  ExpQueue.h
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef ExpQueue_h
#define ExpQueue_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>




class ExpQueue{
    
private:
    
    std::vector <std::string> queue;
    
    int front_;
    
    int back_;
    
    
public:
    int size_of_queue_;
    
    //default constructor
     ExpQueue ( ) ;
    
    //default destructor
    ~ExpQueue ( ) ;
    
    //insert an element into the end of the queue
    void enqueue (std::string element) ;
    
    void remove(int index);
    
    //get an element from the beginning of the queue
    std::string dequeue ();
    
    std::string getQueue(int i);
    
};

#endif /* ExpQueue_h */