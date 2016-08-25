//
//  IdentifierSyntacticObject.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "IdentifierSyntacticObject.hpp"

using namespace BB;

IdentifierSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

IdentifierSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                                     list<SyntacticResultObject_ptr> subobjects,
                                                                                     list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void IdentifierSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    string name = this->lexem.value;
    Lexem_ptr lexem = data->tokenAnalyzer->lexemWithKey(name);
    if (lexem) {
        data->addedArguments(lexem);
    } else {
        //error
        data->errorPool->addErrors(Error_ptr(new TextAnalyzerError(this->lexem.position, 2 , "IdentifierSyntacticObject" )));
    }
}

IdentifierSyntacticObject::IdentifierSyntacticObject(int priority):SyntacticObject("identifier","identifier",priority,false){
}

SyntacticResultObject_ptr IdentifierSyntacticObject::resultObject(string name,
                                                                 list<SyntacticResultObject_ptr> subobjects,
                                                                 list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr ((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}