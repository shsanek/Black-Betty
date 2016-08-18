//
//  DTRRangeLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRRangeLexem_hpp
#define DTRRangeLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"

namespace DTR {
class RangeLexem:public Lexem{
private:
    char startSymbol;
    char endSymbol;
public:
    RangeLexem(char startSymbol,char endSymbol);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRRangeLexem_hpp */
