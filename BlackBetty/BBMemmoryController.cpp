//
//  BBMemmoryController.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include <stdio.h>
#include "BBMemmoryController.hpp"

using namespace BB;

template <>
__uint8_t * MemmoryController::getAbsoluteAddress<AddresTypeConstant>(__uint8_t** arguments){
    __uint8_t* address = *arguments;
    arguments += sizeof(__uint8_t*);
    return address;
}

template <>
inline __uint8_t * MemmoryController::getAbsoluteAddress<AddresTypeAuto>(__uint8_t** arguments){
    __uint8_t* address = *arguments + currentOffsetAddress;
    arguments += sizeof(__uint8_t*);
    return address;
}


template <>
__uint8_t * MemmoryController::getAbsoluteAddress<AddresTypeGlobal>(__uint8_t** arguments){
    __uint8_t* address = *arguments;
    arguments += sizeof(__uint8_t*);
    return address;
}

template <>
__uint8_t * MemmoryController::getAbsoluteAddress<AddresTypeStack>(__uint8_t** arguments){
    __uint8_t* address = stack.popStack();
    return address;
}


template <enum AddresType addresType,enum DataPositionType positionType>
inline __uint8_t *     MemmoryController::getDataFromAddres   (__uint8_t** arguments,
                                                               size_t size){
    if (positionType == DataPositionTypeLink) {
        return **((__uint8_t***)this->getAbsoluteAddress<addresType>(arguments));
    } else if (positionType == DataPositionTypeLinkCurrent) {
        return *((__uint8_t**)this->getAbsoluteAddress<addresType>(arguments));
    } else if (positionType == DataPositionTypeLinkConstant) {
        __uint8_t* address = *arguments;
        arguments += size;
        return address;
    }
}


template <enum AddresType addresType,enum DataPositionType positionType>
inline void            MemmoryController::setDataInAddres     (__uint8_t* data,
                                                               __uint8_t** arguments,
                                                               size_t size){
    
    if (addresType == AddresTypeStack && positionType == DataPositionTypeLinkCurrent) {
        stack.pushStackWithSize(data, size);
    } else {
        __uint8_t* dsc = NULL;
        if (positionType == DataPositionTypeLink) {
            dsc = **((__uint8_t***)this->getAbsoluteAddress<addresType>(arguments));
        } else if (positionType == DataPositionTypeLinkCurrent) {
            dsc =  *((__uint8_t**)this->getAbsoluteAddress<addresType>(arguments));
        } else if (positionType == DataPositionTypeLinkConstant) {
            //error
        }
        memcpy(dsc, data, size);
    }
}