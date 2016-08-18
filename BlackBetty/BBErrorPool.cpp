//
//  BBErrorPool.cpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBErrorPool.hpp"

using namespace BB;
ErrorPool::ErrorPool(){
    this->errors = list<Error_ptr>();
}

list<Error_ptr>* ErrorPool::getErrors(){
    return &this->errors;
}

string ErrorPool::allErros(){
    string result = "";
    for (list<Error_ptr>::iterator i = this->errors.begin();
         i != this->errors.end();
         ++i) {
        result += (*i)->text + "\n";
    }
    return result;
}

void ErrorPool::addErrors(Error_ptr error){
    this->errors.push_back(error);
}