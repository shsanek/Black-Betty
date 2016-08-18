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
        list< list<shared_ptr<Lexem>>> stack;
    public:
        shared_ptr<DTRTokensAnalyzer> tokenAnalyzer;
        
        TokenAnalyzerCreater(shared_ptr<DTRTokensAnalyzer> analyzer) ;
        TokenAnalyzerCreater();
        
        void addedArguments(shared_ptr<Lexem> lexem) ;
        void pushArgumentInStack() ;
        list<shared_ptr<Lexem>> popArgumentsInStack();
    };
}


#endif /* TokenAnalyzerCreater_hpp */
