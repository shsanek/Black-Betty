//
//  BBCommand.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBCommand.hpp"

using namespace BB;

Command::Command(string name,void (*implementation)(ByteCodeInterpletator*,MemmoryController*),vector<ArgumentInterface> arguments){
    this->name = name;
    this->implementation = implementation;
    this->arguments = arguments;
}

Command::Command(string name,void (*implementation)(ByteCodeInterpletator*,MemmoryController*),vector<ArgumentInterface> arguments,__uint32_t constSize){
    this->name = name;
    this->implementation = implementation;
    this->arguments = arguments;
    this->fixConstantSizeSize = shared_ptr<__uint32_t>(new __uint32_t(constSize));
}