//
//  LexemString.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef LexemString_hpp
#define LexemString_hpp

#include <iostream>

using namespace std;

/// <summary>
/// Lexem string.
/// </summary>
namespace DTR {
    struct LexemString{
    public:
        string value;
        string lexemName;
        LexemString(string value, string lexemName);
        LexemString();
    };
};

#endif /* LexemString_hpp */
