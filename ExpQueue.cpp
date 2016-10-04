//
//  ExpQueue.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "ExpQueue.h"

ExpQueue::ExpQueue ( ):
    front_(0),
    back_(0),
    size_of_queue_(0)
{
    queue = * new std::vector <std::string> ();
}

//default destructor
ExpQueue::~ExpQueue ( ){
    
    queue.clear();
}

//insert an element into the end of the queue
void ExpQueue::enqueue (std::string element){
    
    queue.push_back(element);
    back_++;
    size_of_queue_++;
    
}


void ExpQueue::remove(int index){
    queue.erase(queue.begin() + index);
}

//get an element from the beginning of the queue
std::string ExpQueue::dequeue (void){
    
    std::string target = queue[front_];
    
    front_++;
    
    --size_of_queue_;
    
    return target;
    
}

std::string ExpQueue::getQueue (int i){
    return queue[i];
}

