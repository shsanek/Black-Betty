//
//  BBSequenceLexem.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBSequenceLexem_hpp
#define BBSequenceLexem_hpp

#include <stdio.h>
#include "BBLexem.hpp"

namespace BB {
class SequenceLexem:public Lexem{
    Lexem_ptr lexem;
    int minNumberLexemsInSequence;
public:
    SequenceLexem(Lexem_ptr lexem,int minNumberLexemsInSequence);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* BBSequenceLexem_hpp */
