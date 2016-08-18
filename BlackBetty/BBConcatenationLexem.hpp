//
//  BBConcatenationLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBConcatenationLexem_hpp
#define BBConcatenationLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"
#include <list>

namespace BB {
class ConcatenationLexem:public Lexem{
    list<Lexem_ptr> lexems;
    
public:
    ConcatenationLexem(list<Lexem_ptr> lexems);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* BBConcatenationLexem_hpp */
