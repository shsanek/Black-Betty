//
//  BBFile.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 24/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBFile_hpp
#define BBFile_hpp

#include <stdio.h>
#include <string>
#include "BBErrorPool.hpp"

using namespace std;


namespace BB {
    string getStingFromFileWithName(string fileName,ErrorPool_ptr errorPool);
}

#endif /* BBFile_hpp */
