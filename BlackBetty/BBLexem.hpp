//
//  BBLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBLexem_hpp
#define BBLexem_hpp

#include <stdio.h>
#include <iostream>
#include "BBPTRDefine.hpp"

using namespace std;
namespace BB {
    class Lexem{
    public:
        class LexemSting{
        public:
            bool found;
            string resultString;
            
            LexemSting(string string);
            LexemSting(void* a);
            LexemSting(int a);
            LexemSting();
            operator bool();
            LexemSting operator +(LexemSting& lexemSting);
            unsigned int length();
        };
        
        string lexemName;
        virtual LexemSting stringLexemFromString(string str);
    };
    PTRType(Lexem);
};


#endif /* BBLexem_hpp */
