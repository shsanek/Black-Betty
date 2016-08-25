//
//  BBLexemParser.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBCoreLexemParser_hpp
#define BBCoreLexemParser_hpp

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
class BBCoreLexemParser{
protected:
    BBTokensAnalyzer lexAnalyzer;
    BBSyntacticAnalyzer syntacticAnalyzer;
    virtual vector<LexemString> preprocessor(list<LexemString> lexems);
public:
    ErrorPool_ptr errorPool;
    
    bool debugeMod;
    
    BBCoreLexemParser (ErrorPool_ptr errorPool);
    BBTokensAnalyzer_ptr tokensAnalyzerFromString(string str,ErrorPool_ptr errorPool) ;
};

#endif /* BBCoreLexemParser_hpp */
