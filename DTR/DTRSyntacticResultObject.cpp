//
//  DTRSyntacticResultObject.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRSyntacticResultObject.hpp"
#include "DTRLexemString.hpp"

using namespace DTR;

SyntacticResultObjectData::SyntacticResultObjectData(string name){
    name = name;
}

SyntacticResultObjectData::~SyntacticResultObjectData(){
    
}

void SyntacticResultObject::getDataFromHeadObjects(SyntacticResultObjectData * dataObject){
    for (list<SyntacticResultObject_ptr>::iterator i = this->headerObjects.begin();
         i != this->headerObjects.end();
         ++i) {
        (*i)->getData(dataObject);
    }
}

void SyntacticResultObject::getDataFromSubobjects(SyntacticResultObjectData * dataObject){
    for (list<SyntacticResultObject_ptr>::iterator i = this->subobjects.begin();
         i != this->subobjects.end();
         ++i) {
        (*i)->getData(dataObject);
    }
}

void SyntacticResultObject::getData(SyntacticResultObjectData * dataObject){
    this->getDataFromHeadObjects(dataObject);
    this->getDataFromSubobjects(dataObject);
}

string SyntacticResultObject::debugingStringInLevel(int level){
    string spasing = "";
    for (int i = 0; i < level; i++) {
        spasing += "   ";
    }
    string value = name;
    if (value.length() == 0) {
        value = "lex: \'" + this->lexem.lexemName + "\' value: \'" + this->lexem.value + "\'";
    }
    
    if (value.length() == 0) {
        value = "empty ";
    }
    
    
    string resultString =  spasing + "< " + value;
    
    if (this->headerObjects.size() > 0) {
        resultString += "\n" + spasing + "HeaderObjects:{";
        for (list<SyntacticResultObject_ptr>::iterator i = this->headerObjects.begin();
             i != this->headerObjects.end();
             i++) {
            resultString += "\n" + (*i)->debugingStringInLevel (level + 1);
        }
        resultString += "}\n";
    }
    
    if (this->subobjects.size() > 0) {
        resultString += "\n" + spasing + "Subobjects:{";
        for (list<SyntacticResultObject_ptr>::iterator i = this->subobjects.begin();
             i != this->subobjects.end();
             ++i) {
            resultString += "\n" + (*i)->debugingStringInLevel (level + 1);
        }
        resultString += "}\n";
    }
    
    
    
    resultString += "\n" + spasing +  ">";
    return resultString;
}

SyntacticResultObject::SyntacticResultObject(LexemString lexem){
    this->lexem = lexem;
}

SyntacticResultObject::SyntacticResultObject(string name,
                      list<SyntacticResultObject_ptr> subobjects,
                      list<SyntacticResultObject_ptr> headerObjects) {
    this->name = name;
    this->subobjects = subobjects;
    this->headerObjects = headerObjects;
}

string SyntacticResultObject::debugingString(){
    return debugingStringInLevel (0);
};