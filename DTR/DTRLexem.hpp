//
//  DTRLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRLexem_hpp
#define DTRLexem_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
namespace DTR {
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
};


#endif /* DTRLexem_hpp */
