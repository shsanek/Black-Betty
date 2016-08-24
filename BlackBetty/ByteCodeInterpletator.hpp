//
//  BBInterpletator.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBInterpletator_hpp
#define BBInterpletator_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "BBMemmoryController.hpp"

using namespace std;

class ByteCodeInterpletator{
    __uint8_t* byteCode;
    __uint8_t* currentPosition;
    shared_ptr<__uint8_t> linkToByteCode;
    BB::MemmoryController* memoryController;
    vector<void (*)(ByteCodeInterpletator*,BB::MemmoryController*)> commands;
    bool isStop;
    bool isPause;
public:
    ByteCodeInterpletator(shared_ptr<__uint8_t> byteCode,
                          vector<void (*)(ByteCodeInterpletator*,BB::MemmoryController*)> commands);
    
    virtual void nextCommand() ;
    
    virtual void run();
    
    virtual void stop();
    
    virtual void pause();
};

#endif /* BBInterpletator_hpp */
