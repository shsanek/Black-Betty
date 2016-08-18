//
//  BBError.cpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBError.hpp"

using namespace BB;

Error::Error(string name,unsigned int code,string text){
    this->name = name;
    this->code = code;
    this->text = text;
}