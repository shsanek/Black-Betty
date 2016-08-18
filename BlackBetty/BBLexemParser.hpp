//
//  BBLexemParser.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBLexemParser_hpp
#define BBLexemParser_hpp

#include <stdio.h>
#include "BBSyntacticAnalyzer.hpp"
#include "BBTokensAnalyzer.hpp"
#include "BBAllLexems.h"
#include <list>
#include "BBAllSyntacticObjectsForLexemParse.hpp"
#include "BBTextError.hpp"

using namespace std;
using namespace BB;

/// <summary>
/// BB lexem parser.
/// </summary>
class BBLexemParser{
    BBTokensAnalyzer lexAnalyzer;
    BBSyntacticAnalyzer syntacticAnalyzer;
    
    vector<LexemString> preprocessor(list<LexemString> lexems);
    ErrorPool_ptr errorPool;
public:
    bool debugeMod;
    
    BBLexemParser (ErrorPool_ptr errorPool);
    BBTokensAnalyzer_ptr tokensAnalyzerFromStrin(string str,ErrorPool_ptr errorPool) ;
};

#endif /* BBLexemParser_hpp */
