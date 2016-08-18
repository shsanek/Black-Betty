//
//  BBListLexem.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBListLexem.hpp"
using namespace BB;

ListLexem::ListLexem(list<Lexem_ptr> lexems) {
    this->lexems = lexems;
}

Lexem::LexemSting ListLexem::stringLexemFromString(string str){
    LexemSting resultString = LexemSting();
    for (list<Lexem_ptr>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
        LexemSting value = (*lx)->stringLexemFromString (str);
        if (value.found) {
            if (!resultString) {
                resultString.found = true;
                resultString.resultString = value.resultString;
            } else if (resultString.length() < value.length()) {
                resultString.resultString = value.resultString;
            }
        }
    }
    return resultString;
}