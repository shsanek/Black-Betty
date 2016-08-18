//
//  DTRStruct.h
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRStruct_h
#define DTRStruct_h

#include <stdio.h>
#include "DTRPTRDefine.hpp"

using namespace std;

namespace DTR {
    struct Position{
        Position():x(0),y(0){}
        Position(unsigned int x, unsigned int y):x(x),y(y){}
        unsigned int x;
        unsigned int y;
    };
    
    PTRType(Position);
};



#endif /* DTRStruct_h */
