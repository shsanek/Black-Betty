//
//  LexemSyntacticObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef LexemSyntacticObject_hpp
#define LexemSyntacticObject_hpp

#include <stdio.h>
#include "DTRAllLexems.h"
#include "DTRSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace DTR {
    class LexemSyntacticObject:public SyntacticObject{
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
                if (this->subobjects.size() == 1) {
                    if ((*this->subobjects.begin())->name == "" &&
                        (*this->subobjects.begin())->lexem.lexemName == "const_string") {
                        lexem = shared_ptr<Lexem>(new SymbosLexem((*this->subobjects.begin())->lexem.value));
                    }
                } else if (this->headerObjects.size() == 0) {
                    //error
                }
                data->addedArguments(lexem);
            }
        };
        
        LexemSyntacticObject(int priority):SyntacticObject("open_bracket","close_bracket",priority){
        }
        
        virtual shared_ptr<SyntacticResultObject> resultObject(string name,
                                                               list<shared_ptr<SyntacticResultObject>> subobjects,
                                                               list<shared_ptr<SyntacticResultObject>> headerObjects){
            return shared_ptr<SyntacticResultObject>((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
        }
    };
}
#endif /* LexemSyntacticObject_hpp */
