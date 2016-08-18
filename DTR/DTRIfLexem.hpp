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
    std::shared_ptr<Lexem> lexem;
    std::shared_ptr<Lexem> resultLexem;
public:
    IfLexem(std::shared_ptr<Lexem> lexem,std::shared_ptr<Lexem> resultLexem);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRIfLexem_hpp */
