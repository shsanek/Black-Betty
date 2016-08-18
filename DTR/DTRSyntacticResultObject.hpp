//
//  DTRSyntacticResultObject.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRSyntacticResultObject_hpp
#define DTRSyntacticResultObject_hpp

#include <iostream>
#include <list>
#include <vector>
#include "DTRLexemString.hpp"

using namespace std;

namespace DTR
{
    
    class SyntacticResultObjectData{
    public:
        string name;
        SyntacticResultObjectData(string name = "");
        virtual ~SyntacticResultObjectData();
    };
    
    class SyntacticResultObject{
        string debugingStringInLevel(int level);
    public:
        string name;
        LexemString lexem;
        list<shared_ptr<SyntacticResultObject>> headerObjects;
        list<shared_ptr<SyntacticResultObject>> subobjects;
        
        SyntacticResultObject(LexemString lexem);
        
        SyntacticResultObject(string name,
                              list<shared_ptr<SyntacticResultObject>> subobjects,
                              list<shared_ptr<SyntacticResultObject>> headerObjects) ;
        
        string debugingString();
        
        virtual void getDataFromHeadObjects(SyntacticResultObjectData * dataObject);
        virtual void getDataFromSubobjects(SyntacticResultObjectData * dataObject);
        virtual void getData(SyntacticResultObjectData * dataObject);
    };
}

#endif /* DTRSyntacticResultObject_hpp */
