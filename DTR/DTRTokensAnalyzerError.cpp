//
//  DTRTokensAnalyzerError.cpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRTokensAnalyzerError.hpp"

using namespace DTR;

TextAnalyzerError::TextAnalyzerError(Position position,unsigned int code,string text,string name):Error(name,code,text){
    string realText = "Error '" + name;
    
    realText += "' (in row: ";
    realText += position.y;
    realText += " colum: ";
    realText += position.x;
    realText += ") information: < text: '" + text + "' code: ";
    realText += code;
    realText += ">";
    text = realText;
    this->position = position;
}
