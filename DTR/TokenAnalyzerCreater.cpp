//
//  TokenAnalyzerCreater.cpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "TokenAnalyzerCreater.hpp"

using namespace DTR;

TokenAnalyzerCreater::TokenAnalyzerCreater(DTRTokensAnalyzer_ptr analyzer) {
    tokenAnalyzer = analyzer;
}

TokenAnalyzerCreater::TokenAnalyzerCreater():SyntacticResultObjectData("TokenAnalyzerCreater"){
    stack = list< list<Lexem_ptr>>();
}

void TokenAnalyzerCreater::addedArguments(Lexem_ptr lexem) {
    (stack.back()).push_back(lexem);
}

void TokenAnalyzerCreater::pushArgumentInStack() {
    stack.push_back(list<Lexem_ptr>());
}

list<Lexem_ptr> TokenAnalyzerCreater::popArgumentsInStack(){
    list<Lexem_ptr> result = stack.back();
    stack.pop_back();
    return result;
}