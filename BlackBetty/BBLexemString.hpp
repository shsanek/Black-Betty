//
//  LexemString.hpp
//  BlackBetty
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef LexemString_hpp
#define LexemString_hpp

#include <iostream>
#include "BBStruct.hpp"

using namespace std;

/// <summary>
/// Lexem string.
/// </summary>
namespace BB {
    struct LexemString{
    public:
        string value;
        string lexemName;
        Position position;
        LexemString(string value, string lexemName,Position position = Position());
        LexemString(Position position = Position());
    };
};

#endif /* LexemString_hpp */
