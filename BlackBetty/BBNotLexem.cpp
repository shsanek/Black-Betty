//
//  BBNotLexem.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBNotLexem.hpp"
using namespace BB;

NotLexem::NotLexem(Lexem_ptr lexem){
    this->lexem = lexem;
}
Lexem::LexemSting NotLexem::stringLexemFromString(string str){
    LexemSting resultString = lexem->stringLexemFromString(str);
    if (!resultString && str.length() > 0) {
        return str.substr (0, 1);
    }
    return 0;
}