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
    class Lexem;
    PTRType(Lexem);
    
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
        virtual Lexem_ptr copy();
    };
    
};


#endif /* BBLexem_hpp */
