//
//  DTRSyntacticAnalyzer.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRSyntacticAnalyzer_hpp
#define DTRSyntacticAnalyzer_hpp

#include <iostream>
#include <list>
#include <vector>
#include "DTRLexemString.hpp"
#include "DTRSyntacticObject.hpp"

using namespace std;

using namespace DTR;
class DTRSyntacticAnalyzer{
    class AnalyzerObject{
    public:
        int numberOfLexems;
        vector<LexemString> headerLexems;
        vector<LexemString> lexems;
        AnalyzerObject(list<LexemString> headerLexems,list<LexemString> lexems,int numberOfLexems);
    };
    
    AnalyzerObject searchOfStrartObjectInLexems(vector<LexemString> lexems,
                                                int indexSymbol,
                                                shared_ptr<SyntacticObject> currentObject);
    
    list<shared_ptr<SyntacticObject>> syntacticObject;
public:
    void addSyntaxObject(shared_ptr<SyntacticObject> syntaxObject, string key);
    
    list<shared_ptr<SyntacticResultObject>> objectsFromLexems(vector<LexemString> lexems);
    
    DTRSyntacticAnalyzer ();
};


#endif /* DTRSyntacticAnalyzer_hpp */
