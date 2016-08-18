//
//  BBError.hpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBError_hpp
#define BBError_hpp

#include <iostream>
#include "BBPTRDefine.hpp"

using namespace std;

namespace BB {
    class Error{
    public:
        Error(string name,unsigned int code = 0,string text = "");
        string name;
        string text;
        unsigned int code;
    };
    PTRType(Error);
};


#endif /* BBError_hpp */
