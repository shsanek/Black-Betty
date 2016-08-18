//
//  BBNotLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBNotLexem_hpp
#define BBNotLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"

namespace BB {
class NotLexem:public Lexem{
    Lexem_ptr lexem;
public:
    NotLexem(Lexem_ptr lexem);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* BBNotLexem_hpp */
