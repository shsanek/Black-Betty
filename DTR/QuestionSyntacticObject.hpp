//
//  QuestionSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef QuestionSyntacticObject_hpp
#define QuestionSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class QuestionSyntacticObject:public SyntacticObject{
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
                this->getDataFromHeadObjects(data);
                list<shared_ptr<Lexem>> alexems = data->popArgumentsInStack();
                shared_ptr<Lexem> alexem = alexems.size()>1?shared_ptr<Lexem>(new ListLexem(alexems)):(*alexems.begin());
                
                data->pushArgumentInStack();
                this->getDataFromSubobjects(data);
                list<shared_ptr<Lexem>> blexems = data->popArgumentsInStack();
                shared_ptr<Lexem> blexem = blexems.size()>1?shared_ptr<Lexem>(new ListLexem(blexems)):(*blexems.begin());
                if (alexems.size() > 0 && blexems.size() > 0) {
                    data->addedArguments(shared_ptr<Lexem>(new IfLexem(alexem,blexem)));
                } else {
                    //error
                }
            }
        };
        
        QuestionSyntacticObject(int priority):SyntacticObject("question","question",priority,true){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject>(new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}

#endif /* QuestionSyntacticObject_hpp */
