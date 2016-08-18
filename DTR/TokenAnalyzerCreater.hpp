//
//  TokenAnalyzerCreater.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef TokenAnalyzerCreater_hpp
#define TokenAnalyzerCreater_hpp

#include <stdio.h>
#include "DTRLexem.hpp"
#include "DTRSyntacticResultObject.hpp"
#include "DTRTokensAnalyzer.hpp"

namespace DTR {
    class TokenAnalyzerCreater:public SyntacticResultObjectData{
        list< list<Lexem_ptr>> stack;
    public:
        DTRTokensAnalyzer_ptr tokenAnalyzer;
        
        TokenAnalyzerCreater(DTRTokensAnalyzer_ptr analyzer) ;
        TokenAnalyzerCreater();
        
        void addedArguments(Lexem_ptr lexem) ;
        void pushArgumentInStack() ;
        list<Lexem_ptr> popArgumentsInStack();
    };
}


#endif /* TokenAnalyzerCreater_hpp */
