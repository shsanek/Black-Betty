//
//  BBLexemParser.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBLexemParser_hpp
#define BBLexemParser_hpp

#include <stdio.h>
#include <stdlib.h>
#include "BBCoreLexemParser.hpp"
#include "BBConstantStingAnalyzer.hpp"


class BBLexemParser:public BBCoreLexemParser{
protected:
    ConstantStingAnalyzer_ptr constantStringAnalyzer;
    virtual vector<LexemString> preprocessor(list<LexemString> lexems);
public:
    BBLexemParser (ErrorPool_ptr errorPool);
};

#endif /* BBLexemParser_hpp */
