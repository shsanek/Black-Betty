//
//  IdentifierSyntacticObject.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef IdentifierSyntacticObject_hpp
#define IdentifierSyntacticObject_hpp

#include <stdio.h>
#include "BBAllLexems.h"
#include "BBSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace BB {
    class IdentifierSyntacticObject:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem);
            
            CurrentSyntacticResultObject(string name,
                                         list<SyntacticResultObject_ptr> subobjects,
                                         list<SyntacticResultObject_ptr> headerObjects);
            
            virtual void getData(SyntacticResultObjectData* inputData);
            
        };
        
        IdentifierSyntacticObject(int priority);
        
        virtual SyntacticResultObject_ptr resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects);
    };
}

#endif /* IdentifierSyntacticObject_hpp */
