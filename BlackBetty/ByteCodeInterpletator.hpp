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

namespace BB {
    class ByteCodeInterpletator{
        typedef void (*Command)(ByteCodeInterpletator*,BB::MemmoryController*) ;
        __uint8_t* byteCode;
        shared_ptr<__uint8_t> linkToByteCode;
        BB::MemmoryController* memoryController;
        Command* commands;
        bool isStop;
        bool isPause;
    public:
        __uint8_t* currentPosition;
        
        ByteCodeInterpletator(vector<void (*)(ByteCodeInterpletator*,BB::MemmoryController*)> commands);
        
        void nextCommand() ;
        
        virtual ~ByteCodeInterpletator();
        
        virtual void load(shared_ptr<__uint8_t> byteCode);
        
        virtual void run(shared_ptr<__uint8_t> byteCode);
        
        virtual void run();
        
        virtual void stop();
        
        virtual void pause();
    };
};

#endif /* BBInterpletator_hpp */
