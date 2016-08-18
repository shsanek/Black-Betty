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
            CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
            }
            
            CurrentSyntacticResultObject(string name,
                                         list<shared_ptr<SyntacticResultObject>> subobjects,
                                         list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
            }
            
            virtual void getData(SyntacticResultObjectData* inputData) {
                TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
                data->pushArgumentInStack();
                this->getDataFromSubobjects(data);
                list<shared_ptr<Lexem>> lexems = data->popArgumentsInStack();
                shared_ptr<Lexem> lexem = lexems.size()>1?shared_ptr<Lexem>(new ListLexem(lexems)):(*lexems.begin());
                
                if (this->headerObjects.size() == 1 &&
                    (*this->headerObjects.begin())->name == "" &&
                    (*this->headerObjects.begin())->lexem.lexemName == "const_string") {
                    data->tokenAnalyzer->addLexemWithKey(lexem, (*this->headerObjects.begin())->lexem.value);
                } else {
                    //error
                }
            }
            
        };
        
        DelimiterSyntacticObject(int priority):SyntacticObject("delimiter","delimiter",priority,true){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,list<shared_ptr<SyntacticResultObject>> subobjects,list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject> ((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}

#endif /* DelimiterSyntacticObject_hpp */
