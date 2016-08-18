//
//  DTRTokensAnalyzerError.hpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRTokensAnalyzerError_hpp
#define DTRTokensAnalyzerError_hpp

#include <stdio.h>
#include "DTRError.hpp"
#include "DTRStruct.hpp"
#include "DTRErrorPool.hpp"

namespace DTR {
    class TextAnalyzerError:public Error{
    public:
        TextAnalyzerError(Position position,unsigned int code,string text,string name = "Error");
        Position position;
    };
    PTRType(TextAnalyzerError);
}

#endif /* DTRTokensAnalyzerError_hpp */
