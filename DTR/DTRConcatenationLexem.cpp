//
//  DTRConcatenationLexem.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRConcatenationLexem.hpp"
using namespace DTR;

ConcatenationLexem::ConcatenationLexem(list<std::shared_ptr<Lexem>> lexems) {
    this->lexems = lexems;
}

Lexem::LexemSting ConcatenationLexem::stringLexemFromString(string str){
    LexemSting resultString = 0;
    resultString.found = true;
    for (list<std::shared_ptr<Lexem>>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
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