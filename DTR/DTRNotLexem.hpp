//
//  DTRNotLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRNotLexem_hpp
#define DTRNotLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"

namespace DTR {
class NotLexem:public Lexem{
    Lexem_ptr lexem;
public:
    NotLexem(Lexem_ptr lexem);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRNotLexem_hpp */
