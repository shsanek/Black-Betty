//
//  BBLexemParser.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBLexemParser.hpp"
#include "IdentifierSyntacticObject.hpp"

using namespace BB;

const char * kBBLexemParserIdentifierLexem = "'identifier':(['a''z'],['A''Z'])|(['a''z'],['A''Z'],['0''9'],'_')*;";

vector<LexemString> BBLexemParser::preprocessor(list<LexemString> lexems){
    vector<LexemString> resultString = vector<LexemString>();
    for (list<LexemString>::iterator i = lexems.begin();
         i != lexems.end();
         ++i) {
        if ((*i).lexemName == "const_string"){
            string str = (*i).value;
            str = this->constantStringAnalyzer->valueFromString(str, nullptr);
            (*i).value = str;
        }
        if ((*i).lexemName != "spasing") {
            resultString.push_back(*i);
        }
    }
    return resultString;
}

BBLexemParser::BBLexemParser (ErrorPool_ptr errorPool):BBCoreLexemParser(errorPool){
    this->constantStringAnalyzer = BB::ConstantStingAnalyzer::instants();
    BBCoreLexemParser identifierParser = BBCoreLexemParser(NULL);
    BBTokensAnalyzer_ptr identifierAnalyzer = identifierParser.tokensAnalyzerFromString(kBBLexemParserIdentifierLexem, NULL);
    this->lexAnalyzer.addLexemWithKey(identifierAnalyzer->lexemWithKey("identifier"), "identifier");
    this->syntacticAnalyzer.addSyntaxObject(SyntacticObject_ptr(new IdentifierSyntacticObject(10)), "identifier");
}