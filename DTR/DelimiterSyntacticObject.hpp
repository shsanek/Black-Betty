//
//  DelimiterSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DelimiterSyntacticObject_hpp
#define DelimiterSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class DelimiterSyntacticObject:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem);
            
            CurrentSyntacticResultObject(string name,
                                         list<shared_ptr<SyntacticResultObject>> subobjects,
                                         list<shared_ptr<SyntacticResultObject>> headerObjects);
            
            virtual void getData(SyntacticResultObjectData* inputData);
            
        };
        
        DelimiterSyntacticObject(int priority);
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects);
    };
}

#endif /* DelimiterSyntacticObject_hpp */
