//
//  DTRSequenceLexem.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRSequenceLexem_hpp
#define DTRSequenceLexem_hpp

#include <stdio.h>
#include "DTRLexem.hpp"

namespace DTR {
class SequenceLexem:public Lexem{
    Lexem_ptr lexem;
    int minNumberLexemsInSequence;
public:
    SequenceLexem(Lexem_ptr lexem,int minNumberLexemsInSequence);
    virtual LexemSting stringLexemFromString(string str);
};
}

#endif /* DTRSequenceLexem_hpp */
