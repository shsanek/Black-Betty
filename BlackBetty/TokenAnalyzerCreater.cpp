//
//  TokenAnalyzerCreater.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "TokenAnalyzerCreater.hpp"

using namespace BB;


namespace  BB{
    Error_ptr tokenAnalyzerCreaterError(string name,int code,LexemString* forLexemSting,SyntacticResultObject* forObject) {
        string realText = name;
        realText += " (in row: ";
        realText += to_string(forLexemSting?forLexemSting->position.y:0);
        realText += " colum: ";
        realText += to_string(forLexemSting?forLexemSting->position.x:0);
        realText += ") information: < error in object '" + (forObject?forObject->name:"#incorect_object_name") + "' code: ";
        realText += to_string(code);
        realText += ">";
        return Error_ptr (new Error(name,code,realText));
    }
};



TokenAnalyzerCreater::TokenAnalyzerCreater(BBTokensAnalyzer_ptr analyzer) {
    tokenAnalyzer = analyzer;
    stack = list< list<Lexem_ptr>>();
}

TokenAnalyzerCreater::TokenAnalyzerCreater():SyntacticResultObjectData("TokenAnalyzerCreater"){
    stack = list< list<Lexem_ptr>>();
}

bool TokenAnalyzerCreater::addedArguments(Lexem_ptr lexem,LexemString* forLexemSting,SyntacticResultObject* forObject) {
    if (stack.size() > 0) {
        (stack.back()).push_back(lexem);
        return true;
    }
    this->errorPool->addErrors(tokenAnalyzerCreaterError("TokenAnalyzerCreater::addedArguments",
                                                         3,
                                                         forLexemSting,
                                                         forObject));
    return false;
}

bool TokenAnalyzerCreater::pushArgumentInStack(LexemString* forLexemSting,SyntacticResultObject* forObject) {
    stack.push_back(list<Lexem_ptr>());
    return true;
}

list<Lexem_ptr> TokenAnalyzerCreater::popArgumentsInStack(LexemString* forLexemSting,SyntacticResultObject* forObject){
    if (stack.size() == 0) {
        this->errorPool->addErrors(tokenAnalyzerCreaterError("TokenAnalyzerCreater::popArgumentsInStack",
                                                             3,
                                                             forLexemSting,
                                                             forObject));
        return list<Lexem_ptr> ();
    }
    list<Lexem_ptr> result = stack.back();
    stack.pop_back();
    return result;
}