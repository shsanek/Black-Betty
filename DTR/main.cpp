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
    DTRLexemParser lexemParser = DTRLexemParser();
    DTRTokensAnalyzer_ptr analyzer = lexemParser.tokensAnalyzerFromStrin("'const_string' : (('\"')|(((!('\"')),('\\\"'))*)|('\"'));'spasing':(' ')+;'number':['1''9']+|['0''9']*|(('.')?(['0''9']+));");
    list<LexemString> testLexems = analyzer->lexemsFromSting("\"hello\"   \"hui\" 9878987 87877.98 98. 09988");
    return 0;
}
