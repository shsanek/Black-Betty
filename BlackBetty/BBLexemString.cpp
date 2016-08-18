//
//  LexemString.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBLexemString.hpp"

using namespace BB;

LexemString::LexemString(string value, string lexemName,Position position):position(position) {
    this->value = value;
    this->lexemName = lexemName;
}

LexemString::LexemString(Position position):position(position){
    
}