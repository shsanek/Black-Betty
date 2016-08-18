//
//  TokenAnalyzerCreater.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "TokenAnalyzerCreater.hpp"

using namespace DTR;

TokenAnalyzerCreater::TokenAnalyzerCreater(shared_ptr<DTRTokensAnalyzer> analyzer) {
    tokenAnalyzer = analyzer;
}

TokenAnalyzerCreater::TokenAnalyzerCreater():SyntacticResultObjectData("TokenAnalyzerCreater"){
    stack = list< list<shared_ptr<Lexem>>>();
}

void TokenAnalyzerCreater::addedArguments(shared_ptr<Lexem> lexem) {
    (stack.back()).push_back(lexem);
}

void TokenAnalyzerCreater::pushArgumentInStack() {
    stack.push_back(list<shared_ptr<Lexem>>());
}

list<shared_ptr<Lexem>> TokenAnalyzerCreater::popArgumentsInStack(){
    list<shared_ptr<Lexem>> result = stack.back();
    stack.pop_back();
    return result;
}