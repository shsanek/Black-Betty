//
//  DTRLexemParser.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRLexemParser_hpp
#define DTRLexemParser_hpp

#include <stdio.h>
#include "DTRSyntacticAnalyzer.hpp"
#include "DTRTokensAnalyzer.hpp"
#include "DTRAllLexems.h"
#include <list>
#include "DTRAllSyntacticObjectsForLexemParse.hpp"

using namespace std;
using namespace DTR;

/// <summary>
/// DTR lexem parser.
/// </summary>
class DTRLexemParser{
    DTRTokensAnalyzer lexAnalyzer;
    DTRSyntacticAnalyzer syntacticAnalyzer;
    
    vector<LexemString> preprocessor(list<LexemString> lexems);
public:
    bool debugeMod;
    
    DTRLexemParser () ;
    DTRTokensAnalyzer_ptr tokensAnalyzerFromStrin(string str) ;
};

#endif /* DTRLexemParser_hpp */
