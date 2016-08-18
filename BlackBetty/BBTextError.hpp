//
//  BBTokensAnalyzerError.hpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBTokensAnalyzerError_hpp
#define BBTokensAnalyzerError_hpp

#include <stdio.h>
#include "BBError.hpp"
#include "BBStruct.hpp"
#include "BBErrorPool.hpp"

namespace BB {
    class TextAnalyzerError:public Error{
    public:
        TextAnalyzerError(Position position,unsigned int code,string text,string name = "Error");
        Position position;
    };
    PTRType(TextAnalyzerError);
}

#endif /* BBTokensAnalyzerError_hpp */
