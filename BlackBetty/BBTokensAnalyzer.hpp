//
//  BBTokensAnalyzer.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBTokensAnalyzer_hpp
#define BBTokensAnalyzer_hpp

#include <stdio.h>
#include <list>
#include "BBLexem.hpp"
#include "BBLexemString.hpp"
#include "BBPTRDefine.hpp"

#include "BBTextError.hpp"

using namespace BB;
using namespace std;


/// <summary>
/// BB tokens analyzer.
/// </summary>
class BBTokensAnalyzer{
    list<Lexem_ptr> lexems;
    ErrorPool_ptr errorPool;
public:
    BBTokensAnalyzer(ErrorPool_ptr errorPool);
    void addLexemWithKey(Lexem_ptr lexem,string key);
    list<LexemString> lexemsFromSting(string str);
};

PTRType(BBTokensAnalyzer);

#endif /* BBTokensAnalyzer_hpp */
