//
//  DTRIfLexem.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRIfLexem.hpp"
using namespace DTR;

IfLexem::IfLexem(Lexem_ptr lexem,Lexem_ptr resultLexem) {
    this->lexem = lexem;
    this->resultLexem = resultLexem;
}

Lexem::LexemSting IfLexem::stringLexemFromString(string str){
    LexemSting a = lexem->stringLexemFromString (str);
    if (a) {
        if (str.length() > a.length()) {
            str = str.substr(a.length());
        } else {
            str = "";
        }
        LexemSting b = resultLexem->stringLexemFromString (str);
        if (b) {
            return a + b;
        }
    } else {
        return LexemSting("");
    }
    return LexemSting();
}