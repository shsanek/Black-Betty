//
//  BBRangeLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBRangeLexem_hpp
#define BBRangeLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"

namespace BB {
class RangeLexem:public Lexem{
private:
    char startSymbol;
    char endSymbol;
public:
    RangeLexem(char startSymbol,char endSymbol);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* BBRangeLexem_hpp */
