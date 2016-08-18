//
//  DTRIfLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRIfLexem_hpp
#define DTRIfLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"

namespace DTR {
class IfLexem:public Lexem{
    Lexem_ptr lexem;
    Lexem_ptr resultLexem;
public:
    IfLexem(Lexem_ptr lexem,Lexem_ptr resultLexem);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRIfLexem_hpp */
