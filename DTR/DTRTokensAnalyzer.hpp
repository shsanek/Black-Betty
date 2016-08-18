//
//  DTRTokensAnalyzer.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRTokensAnalyzer_hpp
#define DTRTokensAnalyzer_hpp

#include <stdio.h>
#include <list>
#include "DTRLexem.hpp"
#include "DTRLexemString.hpp"
#include "DTRPTRDefine.hpp"

#include "DTRTextError.hpp"

using namespace DTR;
using namespace std;


/// <summary>
/// DTR tokens analyzer.
/// </summary>
class DTRTokensAnalyzer{
    list<Lexem_ptr> lexems;
    ErrorPool_ptr errorPool;
public:
    DTRTokensAnalyzer(ErrorPool_ptr errorPool);
    void addLexemWithKey(Lexem_ptr lexem,string key);
    list<LexemString> lexemsFromSting(string str);
};

PTRType(DTRTokensAnalyzer);

#endif /* DTRTokensAnalyzer_hpp */
