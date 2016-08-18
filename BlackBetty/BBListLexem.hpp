//
//  BBListLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBListLexem_hpp
#define BBListLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"
#include <list>

namespace BB {
    class ListLexem:public Lexem{
        list<Lexem_ptr> lexems;
        
    public:
        ListLexem(list<Lexem_ptr> lexems);
        virtual LexemSting stringLexemFromString(string str);
    };
}

#endif /* BBListLexem_hpp */
