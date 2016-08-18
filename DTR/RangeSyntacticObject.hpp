//
//  RangeSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef RangeSyntacticObject_hpp
#define RangeSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class RangeSyntacticObject:public SyntacticObject{
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
                if (this->subobjects.size() == 2) {
                    string value1 = "";
                    string value2 = "";
                    if (this->subobjects.front()->name == "" &&
                        this->subobjects.front()->lexem.lexemName == "const_string") {
                        value1 = this->subobjects.front()->lexem.value;
                    }
                    if (this->subobjects.back()->name == "" &&
                        this->subobjects.back()->lexem.lexemName == "const_string") {
                        value2 = this->subobjects.back()->lexem.value;
                    }
                    if (value1.length() == 1 && value2.length() == 1) {
                        data->addedArguments(shared_ptr<DTR::Lexem>(new RangeLexem(value1[0],value2[0])));
                    }
                } else {
                    //error
                }
            }
        };
        
        RangeSyntacticObject(int priority):SyntacticObject("open_square_bracket","close_square_bracket",priority){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}

#endif /* RangeSyntacticObject_hpp */
