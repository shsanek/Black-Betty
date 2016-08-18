//
//  DTRSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRSyntacticObject_hpp
#define DTRSyntacticObject_hpp

#include <stdio.h>
#include "DTRSyntacticResultObject.hpp"
#include "DTRPTRDefine.hpp"

namespace DTR
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


#endif /* DTRSyntacticObject_hpp */
