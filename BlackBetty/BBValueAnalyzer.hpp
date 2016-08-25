//
//  BBValueAnalyzer.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBValueAnalyzer_hpp
#define BBValueAnalyzer_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace BB{
    class ValueAnalyzer{
    public:
        virtual shared_ptr<__uint8_t> dataFromSting(string input,shared_ptr<__uint8_t>* error,size_t* size);
        virtual ~ValueAnalyzer();
    };
};

#endif /* BBValueAnalyzer_hpp */
