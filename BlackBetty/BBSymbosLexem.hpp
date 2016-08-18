//
//  BBSymbosLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBSymbosLexem_hpp
#define BBSymbosLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"

namespace BB {
class SymbosLexem:public Lexem{
private:
    string symbols;
public:
    SymbosLexem(string symbols);
    virtual LexemSting stringLexemFromString(string str);
};
}


#endif /* BBSymbosLexem_hpp */
