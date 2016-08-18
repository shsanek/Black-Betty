//
//  BBIfLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBIfLexem_hpp
#define BBIfLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"

namespace BB {
class IfLexem:public Lexem{
    Lexem_ptr lexem;
    Lexem_ptr resultLexem;
public:
    IfLexem(Lexem_ptr lexem,Lexem_ptr resultLexem);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* BBIfLexem_hpp */
