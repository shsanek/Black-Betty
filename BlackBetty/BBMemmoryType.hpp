//
//  Header.h
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef Header_h
#define Header_h

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define MEMMORY_TYPE64
#else
#define MEMMORY_TYPE32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define MEMMORY_TYPE64
#else
#define MEMMORY_TYPE32
#endif
#endif

#if MEMMORY_TYPE32

#define DEFAULT_MEMMORY_TYPE MemmoryType32
#define DEFAULT_INT_TYPE __uint32_t

#else

#define DEFAULT_MEMMORY_TYPE MemmoryType64
#define DEFAULT_INT_TYPE __uint64_t

#endif

namespace BB {
    enum AddresType{
        AddresTypeAuto = 0,
        AddresTypeConstant,
        AddresTypeGlobal,
        AddresTypeStack
    };
    
    enum DataPositionType{
        DataPositionTypeLink = 0,
        DataPositionTypeLinkCurrent,
        DataPositionTypeLinkConstant
    };
};

#endif /* Header_h */
