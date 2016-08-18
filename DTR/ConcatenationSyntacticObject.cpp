//
//  ConcatenationSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ConcatenationSyntacticObject.hpp"


ConcatenationSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

ConcatenationSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                                         list<shared_ptr<SyntacticResultObject>> subobjects,
                                                                                         list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void ConcatenationSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromHeadObjects(data);
    list<shared_ptr<Lexem>> alexems = data->popArgumentsInStack();
    
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<shared_ptr<Lexem>> blexems = data->popArgumentsInStack();
    
    alexems.splice(alexems.end(),blexems);
    
    if (alexems.size() > 0) {
        data->addedArguments(shared_ptr<Lexem>(new ConcatenationLexem(alexems)));
    } else {
        //error
    }
}

ConcatenationSyntacticObject::ConcatenationSyntacticObject(int priority):SyntacticObject("concatenation","concatenation",priority,true){
}

shared_ptr<SyntacticResultObject> ConcatenationSyntacticObject::resultObject(string name,
                                                                             list<shared_ptr<SyntacticResultObject>> subobjects,
                                                                             list<shared_ptr<SyntacticResultObject>> headerObjects){
    return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}