//
//  DelimiterSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DelimiterSyntacticObject.hpp"


DelimiterSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

DelimiterSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<shared_ptr<SyntacticResultObject>> subobjects,
                             list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void DelimiterSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<shared_ptr<Lexem>> lexems = data->popArgumentsInStack();
    shared_ptr<Lexem> lexem = lexems.size()>1?shared_ptr<Lexem>(new ListLexem(lexems)):(*lexems.begin());
    
    if (this->headerObjects.size() == 1 &&
        (*this->headerObjects.begin())->name == "" &&
        (*this->headerObjects.begin())->lexem.lexemName == "const_string") {
        data->tokenAnalyzer->addLexemWithKey(lexem, (*this->headerObjects.begin())->lexem.value);
    } else {
        //error
    }
}

DelimiterSyntacticObject::DelimiterSyntacticObject(int priority):SyntacticObject("delimiter","delimiter",priority,true){
}

shared_ptr<SyntacticResultObject> DelimiterSyntacticObject::resultObject(string name,
                                                       list<shared_ptr<SyntacticResultObject>> subobjects,
                                                       list<shared_ptr<SyntacticResultObject>> headerObjects){
    return shared_ptr<SyntacticResultObject> ((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}