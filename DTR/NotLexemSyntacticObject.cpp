//
//  NotLexemSyntacticObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "NotLexemSyntacticObject.hpp"

NotLexemSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

NotLexemSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<SyntacticResultObject_ptr> subobjects,
                             list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void NotLexemSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<Lexem_ptr> lexems = data->popArgumentsInStack();
    Lexem_ptr lexem = lexems.size()>1?Lexem_ptr(new ListLexem(lexems)):(*lexems.begin());
    if (this->subobjects.size() == 1) {
        data->addedArguments(Lexem_ptr(new NotLexem(lexem)));
    } else {
        //error
    }
}


NotLexemSyntacticObject::NotLexemSyntacticObject(int priority):SyntacticObject("not","not",priority,true){
}

SyntacticResultObject_ptr NotLexemSyntacticObject::resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}