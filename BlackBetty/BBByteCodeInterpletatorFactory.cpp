//
//  BBByteCodeInterpletatorFactory.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBByteCodeInterpletatorFactory.hpp"
#include <vector>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct ProgrammInformation {
    __uint32_t headSize;
    __uint32_t bodySize;
};