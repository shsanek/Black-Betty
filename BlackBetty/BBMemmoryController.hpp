//
//  BBMemmoryController.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 19/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBMemmoryController_hpp
#define BBMemmoryController_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "BBStack.hpp"
#include "BBMemmoryType.hpp"


using namespace std;

namespace BB {

    //create new memmory contoller for thread
    class MemmoryController{
    private:
        list<__uint64_t> offsetStack;
        __uint64_t programmOffsetAddress;
        __uint64_t currentOffsetAddress;
    public:
        Stack stack;
        
        void pushOffset(__uint64_t offset){
            currentOffsetAddress = offset;
            offsetStack.push_back(offset);
        }
        
        void popOffset(){
            currentOffsetAddress = offsetStack.back();
            offsetStack.pop_back();
        }
        
        template <enum AddresType addresType>
        inline __uint8_t * getAbsoluteAddress (__uint8_t** arguments);
        
        template <enum AddresType addresType,enum DataPositionType positionType>
        inline __uint8_t *     getDataFromAddres   (__uint8_t** arguments,
                                                    size_t size);
        
        template <enum AddresType addresType,enum DataPositionType positionType>
        inline void            setDataInAddres     (__uint8_t* data,
                                                    __uint8_t** arguments,
                                                    size_t size);
    };
};



#endif /* BBMemmoryController_hpp */
