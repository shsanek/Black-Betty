//
//  BBConstantStingAnalyzer.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBConstantStingAnalyzer.hpp"
#include "BBCoreLexemParser.hpp"
#include <stdio.h>
#include <stdlib.h>

const char kBBConstantStingAnalyzerSettingForLexemParser[] = "\
'otherSymbol':!('\\\\');\
'escapeSymbol':('\\\\')|(!(['1''9']));\
'codeForSymbol':('\\\\')|(['1''9'])|(['0''9'])*;\
'newRow':('\\\\n');\
\
";

shared_ptr<ConstantStingAnalyzer> kConstantStingAnalyzerObject = nullptr;

using namespace BB;

ConstantStingAnalyzer_ptr ConstantStingAnalyzer::instants() {
    if (!kConstantStingAnalyzerObject) {
        kConstantStingAnalyzerObject = ConstantStingAnalyzer_ptr(new ConstantStingAnalyzer());
    }
    return kConstantStingAnalyzerObject;
}

shared_ptr<__uint8_t> ConstantStingAnalyzer::dataFromSting(string input,shared_ptr<__uint8_t>* error,size_t* size){
    string resultString = this->valueFromString(input, error);
    shared_ptr<__uint8_t> result = shared_ptr<__uint8_t>(new __uint8_t[resultString.length()]);
    if (size){
        *size = resultString.length();
        memcpy(result.get(), resultString.c_str(), resultString.length());
    }
    return result;
}

string ConstantStingAnalyzer::valueFromString(string input,shared_ptr<__uint8_t>* error){
    string result = input.substr(1,input.length() - 2);
    list<LexemString> lexemString = this->tokenAnalyzer->lexemsFromSting(result);
    result = "";
    for (list<LexemString>::iterator i = lexemString.begin();
         i != lexemString.end();
         ++i){
        if ((*i).lexemName == "otherSymbol") {
            result += (*i).value;
        }
        if ((*i).lexemName == "escapeSymbol") {
            result += (*i).value[1];
        }
        if ((*i).lexemName == "codeForSymbol") {
            string number = (*i).value.substr(1);
            int value = stoi(number);
            result += value;
        }
        if ((*i).lexemName == "newRow") {
            result += "\n";
        }

    }
    return result;
}

ConstantStingAnalyzer::ConstantStingAnalyzer(){
    BBCoreLexemParser parser = BBCoreLexemParser(NULL);
    this->tokenAnalyzer = parser.tokensAnalyzerFromString(kBBConstantStingAnalyzerSettingForLexemParser, NULL);
}

ConstantStingAnalyzer::~ConstantStingAnalyzer(){
}