//
//  ClinicalSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "ClinicalSyntacticObject.hpp"


ClinicalSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

ClinicalSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<shared_ptr<SyntacticResultObject>> subobjects,
                             list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void ClinicalSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromHeadObjects(data);
    list<shared_ptr<Lexem>> lexems = data->popArgumentsInStack();
    shared_ptr<Lexem> lexem = lexems.size()>1?shared_ptr<Lexem>(new ListLexem(lexems)):(*lexems.begin());
    if (lexems.size() > 0) {
        lexem = shared_ptr<Lexem>(new SequenceLexem(lexem,0));
    } else {
        //error
    }
    data->addedArguments(lexem);
}

ClinicalSyntacticObject::ClinicalSyntacticObject(int priority):SyntacticObject("clinical","clinical",priority){
}

shared_ptr<SyntacticResultObject> ClinicalSyntacticObject::resultObject(string name,
                                                       list<shared_ptr<SyntacticResultObject>> subobjects,
                                                       list<shared_ptr<SyntacticResultObject>> headerObjects){
    return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}