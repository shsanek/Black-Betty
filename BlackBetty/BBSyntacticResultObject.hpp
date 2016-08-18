//
//  BBSyntacticResultObject.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBSyntacticResultObject_hpp
#define BBSyntacticResultObject_hpp

#include <iostream>
#include <list>
#include <vector>
#include "BBLexemString.hpp"
#include "BBPTRDefine.hpp"

using namespace std;

namespace BB
{
    
    class SyntacticResultObjectData{
    public:
        string name;
        SyntacticResultObjectData(string name = "");
        virtual ~SyntacticResultObjectData();
    };
    
    class SyntacticResultObject;
    PTRType(SyntacticResultObject);
    
    class SyntacticResultObject{
        string debugingStringInLevel(int level);
    public:
        string name;
        LexemString lexem;
        list<SyntacticResultObject_ptr> headerObjects;
        list<SyntacticResultObject_ptr> subobjects;
        
        SyntacticResultObject(LexemString lexem);
        
        SyntacticResultObject(string name,
                              list<SyntacticResultObject_ptr> subobjects,
                              list<SyntacticResultObject_ptr> headerObjects) ;
        
        string debugingString();
        
        virtual void getDataFromHeadObjects(SyntacticResultObjectData * dataObject);
        virtual void getDataFromSubobjects(SyntacticResultObjectData * dataObject);
        virtual void getData(SyntacticResultObjectData * dataObject);
    };
    
}

#endif /* BBSyntacticResultObject_hpp */
