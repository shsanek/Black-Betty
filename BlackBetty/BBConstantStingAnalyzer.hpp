//
//  BBConstantStingAnalyzer.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBConstantStingAnalyzer_hpp
#define BBConstantStingAnalyzer_hpp

#include <stdio.h>
#include "BBValueAnalyzer.hpp"
#include "BBPTRDefine.hpp"

class BBTokensAnalyzer;

namespace BB{
    class ConstantStingAnalyzer;
    PTRType(ConstantStingAnalyzer);
    
    class ConstantStingAnalyzer:public ValueAnalyzer{
        shared_ptr<BBTokensAnalyzer> tokenAnalyzer;
        
        ConstantStingAnalyzer();
        
    public:
        static ConstantStingAnalyzer_ptr instants();
        virtual shared_ptr<__uint8_t> dataFromSting(string input,shared_ptr<__uint8_t>* error,size_t* size);
        virtual string valueFromString(string input,shared_ptr<__uint8_t>* error);
        virtual ~ConstantStingAnalyzer();
    };
    
};

#endif /* BBConstantStingAnalyzer_hpp */
