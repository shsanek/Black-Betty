//
//  BBLexem.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBLexem.hpp"

using namespace BB;

Lexem::LexemSting Lexem::LexemSting::operator +(LexemSting& lexemSting){
    if (this->found && lexemSting.found) {
        return LexemSting(this->resultString + lexemSting.resultString);
    }
    return LexemSting();
}
Lexem::LexemSting Lexem::stringLexemFromString(string str){
    return Lexem::LexemSting();
}

Lexem::LexemSting::LexemSting(string string) {
    this->found = true;
    this->resultString = string;
}

Lexem::LexemSting::LexemSting(void* a){
    this->found = false;
}

Lexem::LexemSting::LexemSting(int a) {
    this->found = !!a;
}

Lexem::LexemSting::LexemSting() {
    this->found = false;
}

Lexem::LexemSting::operator bool(){
    return this->found;
}

unsigned int Lexem::LexemSting::length() {
    return (unsigned int)resultString.length();
}

Lexem_ptr Lexem::copy() {
    return Lexem_ptr(this);
}