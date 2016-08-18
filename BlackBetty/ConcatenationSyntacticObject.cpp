//
//  ConcatenationSyntacticObject.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ConcatenationSyntacticObject.hpp"


ConcatenationSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

ConcatenationSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                                         list<SyntacticResultObject_ptr> subobjects,
                                                                                         list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void ConcatenationSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromHeadObjects(data);
    list<Lexem_ptr> alexems = data->popArgumentsInStack();
    
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<Lexem_ptr> blexems = data->popArgumentsInStack();
    
    alexems.splice(alexems.end(),blexems);
    
    if (alexems.size() > 0) {
        data->addedArguments(Lexem_ptr(new ConcatenationLexem(alexems)));
    } else {
        //error
    }
}

ConcatenationSyntacticObject::ConcatenationSyntacticObject(int priority):SyntacticObject("concatenation","concatenation",priority,true){
}

SyntacticResultObject_ptr ConcatenationSyntacticObject::resultObject(string name,
                                                                             list<SyntacticResultObject_ptr> subobjects,
                                                                             list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}