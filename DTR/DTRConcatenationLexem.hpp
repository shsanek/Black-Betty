//
//  DTRConcatenationLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRConcatenationLexem_hpp
#define DTRConcatenationLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"
#include <list>

namespace DTR {
class ConcatenationLexem:public Lexem{
    list<Lexem_ptr> lexems;
    
public:
    ConcatenationLexem(list<Lexem_ptr> lexems);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRConcatenationLexem_hpp */
