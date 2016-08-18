//
//  DTRSymbosLexem.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRSymbosLexem.hpp"
using namespace DTR;

SymbosLexem::SymbosLexem(string symbols) {
    this->symbols = symbols;
}

Lexem::LexemSting SymbosLexem::stringLexemFromString(string str){
    if (!(symbols.length() <= str.length())) {
        return 0;//null
    }
    string value =  str.substr(0, symbols.length());
    if (value == symbols) {
        return symbols;
    }
    return 0;//null
}