//
//  BBCommandArgument.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 29/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBCommandArgument.hpp"

using namespace BB;

BBCommandArgument::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

BBCommandArgument::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                              list<SyntacticResultObject_ptr> subobjects,
                                                                              list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void BBCommandArgument::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    
}

BBCommandArgument::BBCommandArgument(string symbol,int priority,bool isOperator):SyntacticObject(symbol,symbol,priority,isOperator){
}

SyntacticResultObject_ptr BBCommandArgument::resultObject(string name,
                                                          list<SyntacticResultObject_ptr> subobjects,
                                                          list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr ((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}