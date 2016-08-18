//
//  TokenAnalyzerCreater.hpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef TokenAnalyzerCreater_hpp
#define TokenAnalyzerCreater_hpp

#include <stdio.h>
#include "BBLexem.hpp"
#include "BBSyntacticResultObject.hpp"
#include "BBTokensAnalyzer.hpp"

namespace BB {
    class TokenAnalyzerCreater:public SyntacticResultObjectData{
        list< list<Lexem_ptr>> stack;
    public:
        BBTokensAnalyzer_ptr tokenAnalyzer;
        
        TokenAnalyzerCreater(BBTokensAnalyzer_ptr analyzer) ;
        TokenAnalyzerCreater();
        
        void addedArguments(Lexem_ptr lexem) ;
        void pushArgumentInStack() ;
        list<Lexem_ptr> popArgumentsInStack();
    };
}


#endif /* TokenAnalyzerCreater_hpp */
