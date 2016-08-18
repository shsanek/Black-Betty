//
//  DTRSyntacticAnalyzer.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRSyntacticAnalyzer.hpp"


DTRSyntacticAnalyzer::AnalyzerObject::AnalyzerObject(list<LexemString> headerLexems,
                                                     list<LexemString> lexems,
                                                     int numberOfLexems){
    this->headerLexems = vector<LexemString>();
    for (list<LexemString>::iterator i = headerLexems.begin();
         i != headerLexems.end();
         ++i) {
        this->headerLexems.push_back(*i);
    }
    this->lexems = vector<LexemString>();
    for (list<LexemString>::iterator i = lexems.begin();
         i != lexems.end();
         ++i) {
        this->lexems.push_back(*i);
    }
    this->numberOfLexems = numberOfLexems;
}

DTRSyntacticAnalyzer::AnalyzerObject DTRSyntacticAnalyzer::searchOfStrartObjectInLexems(vector<LexemString> lexems,
                                                                                        int indexSymbol,
                                                                                        shared_ptr<SyntacticObject> currentObject){
    int startSymbol = indexSymbol;
    list<LexemString> bodyLexems = list<LexemString>();
    int stack = 0;
    while (indexSymbol >= 0) {
        LexemString lex = lexems [indexSymbol];
        if (startSymbol != indexSymbol) {
            bodyLexems.push_front(lex);
        }
        indexSymbol--;
        if (lex.lexemName == currentObject->endSymbol) {
            stack++;
        }
        if (lex.lexemName == currentObject->startSymbol) {
            stack--;
            if (stack == 0) {
                if (bodyLexems.size() > 0) {
                    bodyLexems.pop_front();
                }
                break;
            }
        }
        
    }
    
    list<LexemString> headerLexems = list<LexemString>();
    while (indexSymbol >= 0) {
        LexemString lex = lexems [indexSymbol];
        bool addInHeader = true;
        for (list<shared_ptr<SyntacticObject>>::iterator i = syntacticObject.begin();
             i != syntacticObject.end();
             ++i) {
            if ((*i)->priority <= currentObject->priority &&
                (*i)->endSymbol == lex.lexemName &&
                stack == 0) {
                addInHeader = false;
                break;
            }
            if ((*i)->endSymbol == lex.lexemName) {
                stack++;
            }
            if ((*i)->startSymbol == lex.lexemName){
                stack--;
            }
        }
        if (!addInHeader) {
            break;
        }
        indexSymbol--;
        headerLexems.push_front(lex);
    }
    return AnalyzerObject (headerLexems, bodyLexems, startSymbol - indexSymbol);
}


void DTRSyntacticAnalyzer::addSyntaxObject(shared_ptr<SyntacticObject> syntaxObject, string key) {
    syntaxObject->key = key;
    this->syntacticObject.push_front(syntaxObject);
    
}

list<shared_ptr<SyntacticResultObject>> DTRSyntacticAnalyzer::objectsFromLexems(vector<LexemString> lexems){
    if (lexems.size() == 0) {
        return list<shared_ptr<SyntacticResultObject>>();
    }
    list<shared_ptr<SyntacticResultObject>> result = list<shared_ptr<SyntacticResultObject>>();
//    if (lexems.size() == 1) {
//        result.push_front(shared_ptr<SyntacticResultObject>(new SyntacticResultObject (lexems [0])));
//        return result;
//    }
    int indexSymbol = (int)lexems.size() - 1;
    while (indexSymbol >= 0) {
        LexemString lex = lexems [indexSymbol];
        
        bool objectFound = false;
        for (list<shared_ptr<SyntacticObject>>::iterator i = syntacticObject.begin();
             i != syntacticObject.end();
             ++i) {
            if ((*i)->endSymbol == lex.lexemName) {
                AnalyzerObject analyzerObject = searchOfStrartObjectInLexems(lexems,indexSymbol,(*i));
                shared_ptr<SyntacticResultObject> resultObject = (*i)->resultObject ((*i)->key,
                                                                                     objectsFromLexems (analyzerObject.lexems),
                                                                                     objectsFromLexems (analyzerObject.headerLexems));
                if ((*i)->isOperator && result.size() > 0) {
                    resultObject->subobjects.push_back((*(result.begin())));
                    result.erase(result.begin());
                } else if ((*i)->isOperator) {
                    //error
                }
                result.push_front(resultObject);
                indexSymbol = indexSymbol - analyzerObject.numberOfLexems;
                objectFound = true;
                break;
            }
        }
        if (!objectFound) {
            result.push_front(shared_ptr<SyntacticResultObject>(new SyntacticResultObject (lexems [indexSymbol])));
            indexSymbol--;
        }
    }
    return result;
}

DTRSyntacticAnalyzer::DTRSyntacticAnalyzer (){
    this->syntacticObject = list<shared_ptr<SyntacticObject>> ();
}