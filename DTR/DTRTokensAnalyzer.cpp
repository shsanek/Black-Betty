//
//  DTRTokensAnalyzer.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRTokensAnalyzer.hpp"


DTRTokensAnalyzer::DTRTokensAnalyzer(ErrorPool_ptr errorPool) {
    lexems = list<Lexem_ptr>();
    this->errorPool = errorPool;
}

void DTRTokensAnalyzer::addLexemWithKey(Lexem_ptr lexem,string key) {
    lexem->lexemName = key;
    this->lexems.push_back(lexem);
}

list<LexemString> DTRTokensAnalyzer::lexemsFromSting(string str) {
    list<LexemString> resultList = list<LexemString>();
    Position currentPosition = Position(0,0);
    Position_ptr errorPosition = Position_ptr(NULL);
    do {
        Lexem::LexemSting resultString = 0;
        Lexem_ptr resultLexem;
        for (list<Lexem_ptr>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
            Lexem::LexemSting value = (*lx)->stringLexemFromString (str);
            if (value) {
                if (!resultString) {
                    resultString = value;
                    resultLexem = *lx;
                } else if (resultString.length() < value.length()) {
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
                errorPosition = Position_ptr(new Position(currentPosition));
            }
        } else {
            if (errorPosition) {
                this->errorPool->addErrors(Error_ptr(new TextAnalyzerError(*errorPosition,1,"incorect lexem","LexemAnalyzerError")));
            }
            errorPosition = NULL;
        }
        
        
        unsigned int length = resultString.length();
        if (length == 0 && str.length() > 0) {
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