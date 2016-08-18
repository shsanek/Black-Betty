//
//  DTRSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRSyntacticObject.hpp"

using namespace DTR;

SyntacticObject::SyntacticObject (string startSymbol, string endSymbol,int priority,bool isOperator){
    this->startSymbol = startSymbol;
    this->endSymbol = endSymbol;
    this->priority = priority;
    this->isOperator = isOperator;
}

SyntacticResultObject_ptr SyntacticObject::resultObject(string name,
                                                                list<SyntacticResultObject_ptr> subobjects,
                                                                list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr(new SyntacticResultObject (name, subobjects, headerObjects));
}