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
                list<shared_ptr<Lexem>> lexems = data->popArgumentsInStack();
                shared_ptr<Lexem> lexem = lexems.size()>1?shared_ptr<Lexem>(new ListLexem(lexems)):(*lexems.begin());
                if (lexems.size() > 0) {
                    lexem = shared_ptr<Lexem>(new SequenceLexem(lexem,1));
                } else {
                    //error
                }
                data->addedArguments(lexem);
            }
        };
        
        PlusSyntacticObject(int priority):SyntacticObject("plus","plus",priority){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}

#endif /* PlusClinicalSyntacticObject_hpp */
