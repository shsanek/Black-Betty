//
//  BBCommandArgument.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 29/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBCommandArgument_hpp
#define BBCommandArgument_hpp

#include <stdio.h>

#include <stdio.h>
#include "BBAllLexems.h"
#include "BBSyntacticObject.hpp"

namespace BB {
    class BBCommandArgument:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem);
            
            CurrentSyntacticResultObject(string name,
                                         list<SyntacticResultObject_ptr> subobjects,
                                         list<SyntacticResultObject_ptr> headerObjects);
            
            virtual void getData(SyntacticResultObjectData* inputData);
        };
        
        BBCommandArgument(string symbol,int priority,bool isOperator);
        
        virtual SyntacticResultObject_ptr resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects);
    };
}

#endif /* BBCommandArgument_hpp */
