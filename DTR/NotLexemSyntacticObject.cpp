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
                             list<shared_ptr<SyntacticResultObject>> subobjects,
                             list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void NotLexemSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<shared_ptr<Lexem>> lexems = data->popArgumentsInStack();
    shared_ptr<Lexem> lexem = lexems.size()>1?shared_ptr<Lexem>(new ListLexem(lexems)):(*lexems.begin());
    if (this->subobjects.size() == 1) {
        data->addedArguments(shared_ptr<Lexem>(new NotLexem(lexem)));
    } else {
        //error
    }
}


NotLexemSyntacticObject::NotLexemSyntacticObject(int priority):SyntacticObject("not","not",priority,true){
}

shared_ptr<SyntacticResultObject> NotLexemSyntacticObject::resultObject(string name,
                                                       list<shared_ptr<SyntacticResultObject>> subobjects,
                                                       list<shared_ptr<SyntacticResultObject>> headerObjects){
    return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}