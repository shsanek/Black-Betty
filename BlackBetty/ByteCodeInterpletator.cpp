//
//  BBInterpletator.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ByteCodeInterpletator.hpp"

ByteCodeInterpletator::ByteCodeInterpletator(shared_ptr<__uint8_t> byteCode,
                                             vector<void (*)(ByteCodeInterpletator*,BB::MemmoryController*)> commands){
    this->byteCode = byteCode.get();
    this->linkToByteCode = byteCode;
    this->commands = commands;
    isStop = true;
}

void ByteCodeInterpletator::nextCommand() {
    __uint32_t code = *((__uint32_t*)byteCode);
    currentPosition += 4;
    this->commands[code](this,memoryController);
}

void ByteCodeInterpletator::run() {
    if (!isStop) {
        currentPosition = byteCode;
    }
    isStop = true;
    isPause = true;
    while (isStop && isPause) {
        this->nextCommand();
    }
}

void ByteCodeInterpletator::stop(){
    isStop = false;
}

void ByteCodeInterpletator::pause(){
    isPause = false;
}