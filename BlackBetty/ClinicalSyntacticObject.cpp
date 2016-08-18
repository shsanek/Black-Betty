//
//  ClinicalSyntacticObject.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ClinicalSyntacticObject.hpp"


ClinicalSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

ClinicalSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<SyntacticResultObject_ptr> subobjects,
                             list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void ClinicalSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromHeadObjects(data);
    list<Lexem_ptr> lexems = data->popArgumentsInStack();
    Lexem_ptr lexem = lexems.size()>1?Lexem_ptr(new ListLexem(lexems)):(*lexems.begin());
    if (lexems.size() > 0) {
        lexem = Lexem_ptr(new SequenceLexem(lexem,0));
    } else {
        //error
    }
    data->addedArguments(lexem);
}

ClinicalSyntacticObject::ClinicalSyntacticObject(int priority):SyntacticObject("clinical","clinical",priority){
}

SyntacticResultObject_ptr ClinicalSyntacticObject::resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}