//
//  DTRListLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRListLexem_hpp
#define DTRListLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"
#include <list>

namespace DTR {
    class ListLexem:public Lexem{
        list<std::shared_ptr<Lexem>> lexems;
        
    public:
        ListLexem(list<std::shared_ptr<Lexem>> lexems);
        virtual LexemSting stringLexemFromString(string str);
    };
}

#endif /* DTRListLexem_hpp */
