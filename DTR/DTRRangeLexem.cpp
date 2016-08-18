//
//  DTRRangeLexem.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRRangeLexem.hpp"
using namespace DTR;

RangeLexem::RangeLexem(char startSymbol,char endSymbol) {
    if (startSymbol <= endSymbol) {
        this->startSymbol = startSymbol;
        this->endSymbol = endSymbol;
    } else {
        this->startSymbol = endSymbol;
        this->endSymbol = startSymbol;
    }
}
Lexem::LexemSting RangeLexem::stringLexemFromString(string str){
    if (str.length() < 1) {
        return 0;
    }
    string value =  str.substr(0, 1);
    if (value [0] >= startSymbol && value [0] <= endSymbol) {
        return value;
    }
    return 0;
}
