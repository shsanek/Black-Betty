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

using namespace DTR;
using namespace std;


/// <summary>
/// DTR tokens analyzer.
/// </summary>
class DTRTokensAnalyzer{
    list<PTRLexem> lexems;
public:
    DTRTokensAnalyzer();
    void addLexemWithKey(shared_ptr<Lexem> lexem,string key);
    list<LexemString> lexemsFromSting(string str);
};

#endif /* DTRTokensAnalyzer_hpp */
