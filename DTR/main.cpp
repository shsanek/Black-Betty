//
//  main.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include <iostream>
#include "DTRLexemParser.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ErrorPool_ptr errorPool = ErrorPool_ptr(new ErrorPool());
    DTRLexemParser lexemParser = DTRLexemParser(errorPool);
    
    ErrorPool_ptr errorPool2 = ErrorPool_ptr(new ErrorPool());
    DTRTokensAnalyzer_ptr analyzer = lexemParser.tokensAnalyzerFromStrin("'const_string' : (('\"')|(((!('\"')),('\\\"'))*)|('\"'));'spasing':(' ')+;'number':['1''9']+|['0''9']*|(('.')?(['0''9']+));",errorPool2);
    
    list<LexemString> testLexems = analyzer->lexemsFromSting("\"hello\"   \"hui\" 9878987 87877.98 98. 09988");
    
    string errorString = errorPool2->allErros();
    printf("%s",errorString.c_str());
    
    return 0;
}
