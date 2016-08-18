//
//  LexemSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "LexemSyntacticObject.hpp"


LexemSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

LexemSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                                 list<SyntacticResultObject_ptr> subobjects,
                                                                                 list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void LexemSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<Lexem_ptr> lexems = data->popArgumentsInStack();
    Lexem_ptr lexem = lexems.size()>1?Lexem_ptr(new ListLexem(lexems)):(*lexems.begin());
    if (this->subobjects.size() == 1) {
        if ((*this->subobjects.begin())->name == "" &&
            (*this->subobjects.begin())->lexem.lexemName == "const_string") {
            lexem = Lexem_ptr(new SymbosLexem((*this->subobjects.begin())->lexem.value));
        }
    } else if (this->headerObjects.size() == 0) {
        //error
    }
    data->addedArguments(lexem);
}


LexemSyntacticObject::LexemSyntacticObject(int priority):SyntacticObject("open_bracket","close_bracket",priority){
}

SyntacticResultObject_ptr LexemSyntacticObject::resultObject(string name,
                                                                     list<SyntacticResultObject_ptr> subobjects,
                                                                     list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}