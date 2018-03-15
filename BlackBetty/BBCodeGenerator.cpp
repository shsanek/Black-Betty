//
//  BBCodeGenerator.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 29/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBCodeGenerator.hpp"

using namespace BB;

CodeGenerator::CodeGenerator(list<Command_ptr> commands,ErrorPool_ptr errorPool){
    this->commands = commands;
    this->errorPool = errorPool;
    this->position = 0;
}

void CodeGenerator::pushCommandWithName(string name){
    Command command = 
}

void CodeGenerator::popCommand(){
    
}

void CodeGenerator::addedLabel(string name,DEFAULT_INT_TYPE positionOffset){
    Label label = {name,position + positionOffset};
    this->labels[name] = label;
}

void CodeGenerator::pushArgument(Argument argument){
    
}

CodeGenerator::Argument* CodeGenerator::getLastArgument(){
    return NULL;
}

CodeGenerator::Argument CodeGenerator::popArgument(){
    return Argument();
}

shared_ptr<__uint8_t> CodeGenerator::getByteCode(){
    return NULL;
}