//
//  BBInterpletator.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ByteCodeInterpletator.hpp"

using namespace BB;

ByteCodeInterpletator::ByteCodeInterpletator(vector<void (*)(ByteCodeInterpletator*,BB::MemmoryController*)> commands){
    this->commands = new Command[commands.size()];
    for (int i = 0; i < commands.size(); i++) {
        this->commands[i] = commands[i];
    }
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

void ByteCodeInterpletator::load(shared_ptr<__uint8_t> byteCode){
    this->byteCode = byteCode.get();
    this->linkToByteCode = byteCode;
    isStop = true;
}

void ByteCodeInterpletator::run(shared_ptr<__uint8_t> byteCode){
    this->load(byteCode);
    this->run();
}

void ByteCodeInterpletator::stop(){
    isStop = false;
}

void ByteCodeInterpletator::pause(){
    isPause = false;
}

ByteCodeInterpletator::~ByteCodeInterpletator(){
    delete[] this->commands;
}