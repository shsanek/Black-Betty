//
//  DTRError.hpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRError_hpp
#define DTRError_hpp

#include <iostream>
#include "DTRPTRDefine.hpp"

using namespace std;

namespace DTR {
    class Error{
    public:
        Error(string name,unsigned int code = 0,string text = "");
        string name;
        string text;
        unsigned int code;
    };
    PTRType(Error);
};


#endif /* DTRError_hpp */
