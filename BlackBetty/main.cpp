//
//  main.cpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include <iostream>
#include "BBLexemParser.hpp"
#include "BBMemmoryController.hpp"
#include "BBFile.hpp"

using namespace std;
using namespace BB;

int main(int argc, const char * argv[]) {
    ErrorPool_ptr errorPool = ErrorPool_ptr(new ErrorPool());
    ErrorPool_ptr errorPool2 = ErrorPool_ptr(new ErrorPool());
    
    BBLexemParser lexemParser = BBLexemParser(errorPool);
    
    string lexemsText = getStingFromFileWithName("CommandBaseLexem.lex",
                                               errorPool);
    BBTokensAnalyzer_ptr analyzer = lexemParser.tokensAnalyzerFromString(lexemsText,
                                                                         errorPool2);
    
    string errorString1 = errorPool->allErros();
    printf("%s\n",errorString1.c_str());
    
    
    string programmText = getStingFromFileWithName("TestCommandProgramm.com",
                                               errorPool2);
    list<LexemString> testLexems = analyzer->lexemsFromSting(programmText);
    
    string errorString2 = errorPool2->allErros();
    printf("%s",errorString2.c_str());
    
    return 0;
}
