//
//  BBSequenceLexem.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBSequenceLexem.hpp"
using namespace BB;

SequenceLexem::SequenceLexem(Lexem_ptr lexem,int minNumberLexemsInSequence) {
    this->lexem = lexem;
    this->minNumberLexemsInSequence = minNumberLexemsInSequence;
}

Lexem::LexemSting SequenceLexem::stringLexemFromString(string str){
    LexemSting resultString = LexemSting();
    resultString.found = true;
    
    int numberOfLexems = 0;
    do {
        LexemSting currentString = lexem->stringLexemFromString(str);
        if (!currentString || currentString.length() == 0) {
            break;
        }
        numberOfLexems++;
        resultString.resultString += currentString.resultString;
        if (str.length() > currentString.length()) {
            str = str.substr(currentString.length());
        } else {
            str = "";
        }
    } while (true);
    
    if (numberOfLexems >= this->minNumberLexemsInSequence) {
        return resultString;
    }
    return 0;
}