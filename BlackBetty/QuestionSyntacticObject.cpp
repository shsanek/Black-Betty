//
//  QuestionSyntacticObject.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "QuestionSyntacticObject.hpp"


QuestionSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

QuestionSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                                                                                    list<SyntacticResultObject_ptr> subobjects,
                                                                                    list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void QuestionSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    data->pushArgumentInStack();
    this->getDataFromHeadObjects(data);
    list<Lexem_ptr> alexems = data->popArgumentsInStack();
    Lexem_ptr alexem = alexems.size()>1?Lexem_ptr(new ListLexem(alexems)):(*alexems.begin());
    
    data->pushArgumentInStack();
    this->getDataFromSubobjects(data);
    list<Lexem_ptr> blexems = data->popArgumentsInStack();
    Lexem_ptr blexem = blexems.size()>1?Lexem_ptr(new ListLexem(blexems)):(*blexems.begin());
    if (alexems.size() > 0 && blexems.size() > 0) {
        data->addedArguments(Lexem_ptr(new IfLexem(alexem,blexem)));
    } else {
        //error
    }
}


QuestionSyntacticObject::QuestionSyntacticObject(int priority):SyntacticObject("question","question",priority,true){
}

SyntacticResultObject_ptr QuestionSyntacticObject::resultObject(string name,
                                                                        list<SyntacticResultObject_ptr> subobjects,
                                                                        list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr(new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}