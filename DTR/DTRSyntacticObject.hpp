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

namespace DTR
{
    class SyntacticObject{
    public:
        string key;
        string startSymbol;
        string endSymbol;
        int priority;
        bool isOperator;
        SyntacticObject (string startSymbol, string endSymbol,int priority,bool isOperator = false);
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects);
    };
}


#endif /* DTRSyntacticObject_hpp */
