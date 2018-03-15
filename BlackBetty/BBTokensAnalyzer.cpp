//
//  BBTokensAnalyzer.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBTokensAnalyzer.hpp"


BBTokensAnalyzer::BBTokensAnalyzer(ErrorPool_ptr errorPool) {
    lexems = list<Lexem_ptr>();
    this->errorPool = errorPool;
}

void BBTokensAnalyzer::addLexemWithKey(Lexem_ptr lexem,string key) {
    lexem->lexemName = key;
    this->lexems.push_back(lexem);
}

Lexem_ptr BBTokensAnalyzer::lexemWithKey(string key){
    for (list<Lexem_ptr>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
        if ((*lx)->lexemName == key) {
            return *lx;
        }
    }
    return nullptr;
}

list<LexemString> BBTokensAnalyzer::lexemsFromSting(string str) {
    list<LexemString> resultList = list<LexemString>();
    Position currentPosition = Position(0,0);
    Position_ptr errorPosition = Position_ptr(NULL);
    string errorString = "";
    do {
        Lexem::LexemSting resultString = 0;
        Lexem_ptr resultLexem;
        for (list<Lexem_ptr>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
            Lexem::LexemSting value = (*lx)->stringLexemFromString (str);
            if (value) {
                if (!resultString) {
                    resultString = value;
                    resultLexem = *lx;
                } else if (resultString.length() <= value.length()) {
                    resultString = value;
                    resultLexem = *lx;
                }
            }
        }
        if (resultString) {
            resultList.push_back(LexemString(resultString.resultString,resultLexem->lexemName,currentPosition));
        }
        if (!resultString || resultString.length() == 0) {
            if (!errorPosition) {
                errorString = "";
                errorPosition = Position_ptr(new Position(currentPosition));
            }
        } else {
            if (errorLexemName.length()) {
                resultList.push_back(LexemString(errorString,errorLexemName,*errorPosition));
            }
            if (errorPosition) {
                this->errorPool->addErrors(Error_ptr(new TextAnalyzerError(*errorPosition,1,"incorect lexem '" + errorString + "'","LexemAnalyzerError")));
            }
            errorPosition = NULL;
        }
        
        
        unsigned int length = resultString.length();
        if (length == 0 && str.length() > 0) {
            errorString += str[0];
            length = 1;
        }
        for (int i = 0; i < length; i++) {
            char c = str[i];
            if (c == '\n') {
                currentPosition.x = 0;
                currentPosition.y++;
            } else {
                currentPosition.x++;
            }
        }
        str = str.substr(length);
    } while (str.length() > 0);
    
    if (errorPosition) {
        this->errorPool->addErrors(Error_ptr(new TextAnalyzerError(*errorPosition,1,"incorect lexem","LexemAnalyzerError")));
    }
    
    return resultList;
}
