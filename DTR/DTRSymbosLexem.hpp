//
//  DTRSymbosLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRSymbosLexem_hpp
#define DTRSymbosLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"

namespace DTR {
class SymbosLexem:public Lexem{
private:
    string symbols;
public:
    SymbosLexem(string symbols);
    virtual LexemSting stringLexemFromString(string str);
};
}


#endif /* DTRSymbosLexem_hpp */
