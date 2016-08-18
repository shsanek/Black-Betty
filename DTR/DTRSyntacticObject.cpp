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

shared_ptr<SyntacticResultObject> SyntacticObject::resultObject(string name,
                                                                list<shared_ptr<SyntacticResultObject>> subobjects,
                                                                list<shared_ptr<SyntacticResultObject>> headerObjects){
    return shared_ptr<SyntacticResultObject>(new SyntacticResultObject (name, subobjects, headerObjects));
}