//
//  BBTokensAnalyzerError.cpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBTextError.hpp"

using namespace BB;

TextAnalyzerError::TextAnalyzerError(Position position,unsigned int code,string text,string name):Error(name,code,text),position(position){
    string realText = name;
    realText += " (in row: ";
    realText += to_string(position.y + 1);
    realText += " colum: ";
    realText += to_string(position.x);
    realText += ") information: < text: '" + text + "' code: ";
    realText += to_string(code);
    realText += ">";
    this->text = realText;
}
