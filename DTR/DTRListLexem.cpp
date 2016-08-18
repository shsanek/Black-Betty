//
//  DTRListLexem.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRListLexem.hpp"
using namespace DTR;

ListLexem::ListLexem(list<std::shared_ptr<Lexem>> lexems) {
    this->lexems = lexems;
}

Lexem::LexemSting ListLexem::stringLexemFromString(string str){
    LexemSting resultString = LexemSting();
    for (list<std::shared_ptr<Lexem>>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
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