//
//  BBByteCommand.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBByteCommand.hpp"

using namespace BB;

shared_ptr<ByteCommand::Argument> ByteCommand::nextArgument(shared_ptr<Argument> argument) {
    if (command->arguments.size() > argument->index + 1) {
        shared_ptr<Argument> result = shared_ptr<Argument>(new Argument);
        result->index = argument->index + 1;
        result->data = argument->data + argument->size;
        this->updateDataForArgument(result);
        return result;
    }
    return shared_ptr<Argument>(NULL);
}

void ByteCommand::updateDataForArgument(shared_ptr<Argument> result) {
    Command::ArgumentInterface* ai = &command->arguments[result->index];
    result->interface = ai;
    if (ai->type == Command::ArgumentInterface::ArgumentTypeConstant) {
        if (ai->size) {
            fixConstantSizeSize = shared_ptr<__uint32_t>(new __uint32_t(*((__uint32_t*)result->data)));
            result->size = sizeof(__uint32_t);
        } else if (this->fixConstantSizeSize) {
            result->size = *fixConstantSizeSize;
        } else {
            //error
        }
    } else {
        if (ai->type == Command::ArgumentInterface::ArgumentTypeConstantOffset) {
            *((DEFAULT_INT_TYPE*)result->data) = *((DEFAULT_INT_TYPE*)result->data) + programmOffset;
        }
        result->size = sizeof(void*);
    }
    
}

void ByteCommand::updateSize() {
    size = 4;
    if (command->arguments.size()) {
        shared_ptr<Argument> result = shared_ptr<Argument>(new Argument);
        result->data = source + 4;
        result->index = 0;
        updateDataForArgument(result);
        do {
            size += result->size;
            result = nextArgument(result);
        } while (result);
    }
}

ByteCommand::ByteCommand(Command* command,__uint8_t* source,DEFAULT_INT_TYPE programmOffset){
    this->command = command;
    source = source;
}

size_t ByteCommand::getSize(){
    return size;
}