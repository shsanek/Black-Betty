//
//  BBByteCodeGenerator.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 24/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBByteCodeGenerator.hpp"
#include "BBCommand.hpp"
#include "BBFile.hpp"
#include "BBTokensAnalyzer.hpp"
#include "BBLexemParser.hpp"

using namespace BB;

ByteCodeGenerator::ByteCodeGenerator(list<shared_ptr<Command>> command){
    BBLexemParser lexmParser = BBLexemParser(NULL);
    string lexemsText = getStingFromFileWithName("CommandBaseLexem.lex", NULL);
    this->tokenAnalyzer = lexmParser.tokensAnalyzerFromString(lexemsText, NULL);
}
shared_ptr<__uint8_t> ByteCodeGenerator::byteCode(string sourceCommandCode){
    
    return NULL;
}
shared_ptr<__uint8_t> ByteCodeGenerator::byteCodeAdaptedForThisSession(shared_ptr<__uint8_t> sourceByteCode){
    return NULL;
}