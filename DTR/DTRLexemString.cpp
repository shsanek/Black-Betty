//
//  LexemString.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRLexemString.hpp"

using namespace DTR;

LexemString::LexemString(string value, string lexemName) {
    this->value = value;
    this->lexemName = lexemName;
}

LexemString::LexemString(){
    
}