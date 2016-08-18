//
//  DelimiterSyntacticObject.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DelimiterSyntacticObject.hpp"


DelimiterSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

DelimiterSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<SyntacticResultObject_ptr> subobjects,
                             list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void DelimiterSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<Lexem_ptr> lexems = data->popArgumentsInStack();
    Lexem_ptr lexem = lexems.size()>1?Lexem_ptr(new ListLexem(lexems)):(*lexems.begin());
    
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

SyntacticResultObject_ptr DelimiterSyntacticObject::resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr ((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}