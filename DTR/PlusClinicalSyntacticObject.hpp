//
//  PlusClinicalSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef PlusClinicalSyntacticObject_hpp
#define PlusClinicalSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class PlusSyntacticObject:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem);
            
            CurrentSyntacticResultObject(string name,
                                         list<SyntacticResultObject_ptr> subobjects,
                                         list<SyntacticResultObject_ptr> headerObjects);
            
            virtual void getData(SyntacticResultObjectData* inputData);
        };
        
        PlusSyntacticObject(int priority);
        
        virtual SyntacticResultObject_ptr resultObject(string name,
                                                               list<SyntacticResultObject_ptr> subobjects,
                                                               list<SyntacticResultObject_ptr> headerObjects);
    };
}

#endif /* PlusClinicalSyntacticObject_hpp */
