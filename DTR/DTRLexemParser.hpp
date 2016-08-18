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
#include "DTRTextError.hpp"

using namespace std;
using namespace DTR;

/// <summary>
/// DTR lexem parser.
/// </summary>
class DTRLexemParser{
    DTRTokensAnalyzer lexAnalyzer;
    DTRSyntacticAnalyzer syntacticAnalyzer;
    
    vector<LexemString> preprocessor(list<LexemString> lexems);
    ErrorPool_ptr errorPool;
public:
    bool debugeMod;
    
    DTRLexemParser (ErrorPool_ptr errorPool);
    DTRTokensAnalyzer_ptr tokensAnalyzerFromStrin(string str,ErrorPool_ptr errorPool) ;
};

#endif /* DTRLexemParser_hpp */
