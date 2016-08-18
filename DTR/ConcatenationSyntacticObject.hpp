//
//  ConcatenationSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef ConcatenationSyntacticObject_hpp
#define ConcatenationSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class ConcatenationSyntacticObject:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
            }
            
            CurrentSyntacticResultObject(string name,
                                         list<shared_ptr<SyntacticResultObject>> subobjects,
                                         list<shared_ptr<SyntacticResultObject>> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
            }
            
            shared_ptr<Lexem> getLexem(){
                return NULL;
            }
            
            virtual void getData(SyntacticResultObjectData* inputData) {
                TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
                data->pushArgumentInStack();
                this->getDataFromHeadObjects(data);
                list<shared_ptr<Lexem>> alexems = data->popArgumentsInStack();
                
                data->pushArgumentInStack();
                this->getDataFromSubobjects(data);
                list<shared_ptr<Lexem>> blexems = data->popArgumentsInStack();
                
                alexems.splice(alexems.end(),blexems);
                
                if (alexems.size() > 0) {
                    data->addedArguments(shared_ptr<Lexem>(new ConcatenationLexem(alexems)));
                } else {
                    //error
                }
            }
        };
        
        ConcatenationSyntacticObject(int priority):SyntacticObject("concatenation","concatenation",priority,true){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}

#endif /* ConcatenationSyntacticObject_hpp */
