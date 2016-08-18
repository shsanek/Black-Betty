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
    list<std::shared_ptr<Lexem>> lexems;
    
public:
    ConcatenationLexem(list<std::shared_ptr<Lexem>> lexems);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRConcatenationLexem_hpp */
