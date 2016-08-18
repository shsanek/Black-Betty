//
//  DTRErrorPool.cpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRErrorPool.hpp"

using namespace DTR;
ErrorPool::ErrorPool(){
    this->errors = list<PTRError>();
}

list<PTRError>* ErrorPool::getErrors(){
    return &this->errors;
}

string ErrorPool::allErros(){
    string result = "";
    for (list<PTRError>::iterator i = this->errors.begin();
         i != this->errors.end();
         ++i) {
        result += (*i)->text + " ";
    }
    return result;
}

void ErrorPool::addErrors(PTRError error){
    this->errors.push_back(error);
}