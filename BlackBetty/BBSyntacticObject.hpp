//
//  BBSyntacticObject.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBSyntacticObject_hpp
#define BBSyntacticObject_hpp

#include <stdio.h>
#include "BBSyntacticResultObject.hpp"
#include "BBPTRDefine.hpp"

namespace BB
{
    class SyntacticObject;
    PTRType(SyntacticObject);
    class SyntacticObject{
    public:
        string key;
        string startSymbol;
        string endSymbol;
        int priority;
        bool isOperator;
        SyntacticObject (string startSymbol, string endSymbol,int priority,bool isOperator = false);
        
        virtual SyntacticResultObject_ptr resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects);
    };
}


#endif /* BBSyntacticObject_hpp */
