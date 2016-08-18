//
//  BBStruct.h
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBStruct_h
#define BBStruct_h

#include <stdio.h>
#include "BBPTRDefine.hpp"

using namespace std;

namespace BB {
    struct Position{
        Position():x(0),y(0){}
        Position(unsigned int x, unsigned int y):x(x),y(y){}
        unsigned int x;
        unsigned int y;
    };
    
    PTRType(Position);
};



#endif /* BBStruct_h */
