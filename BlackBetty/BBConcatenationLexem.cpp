//
//  BBConcatenationLexem.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBConcatenationLexem.hpp"
using namespace BB;

ConcatenationLexem::ConcatenationLexem(list<Lexem_ptr> lexems) {
    this->lexems = lexems;
}

Lexem::LexemSting ConcatenationLexem::stringLexemFromString(string str){
    LexemSting resultString = 0;
    resultString.found = true;
    for (list<Lexem_ptr>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
        LexemSting value = (*lx)->stringLexemFromString (str);
        if (!value) {
            return 0;
        }
        resultString.resultString += value.resultString;
        if (str.length() > value.length()) {
            str = str.substr(value.length());
        } else {
            str = "";
        }
    }
    return resultString;
}