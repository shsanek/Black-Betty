//
//  BBCommand.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBCommand_hpp
#define BBCommand_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "BBMemmoryType.hpp"

using namespace std;

namespace BB{
    class ByteCodeInterpletator;
    class MemmoryController;
    
    struct ExternalSymbols{
        string symbol;
        __uint8_t* positionInProgramm;
        __uint8_t* point;
    };
    
    class Command{
    public:
        class Argument{
        public:
            enum ArgumentType{
                ArgumentTypeTo,
                ArgumentTypeFrom,
                ArgumentTypeConstant
            };
            size_t size;
            ArgumentType type;
        };
        
        
        __uint32_t code;
        string name;
        vector<Argument> arguents;
        vector<__uint32_t> constantOffsetPossition;
        void (*implementation)(ByteCodeInterpletator*,MemmoryController*);
        
        size_t sizeFromCurrentConst(__uint8_t* source){
            source = source + sizeof(__uint32_t);
            return 0;
        }
        
        shared_ptr<__uint8_t> linkExetrnalSymbols(__uint8_t** source,__uint32_t programmOffset){
            __uint8_t* result = new __uint8_t[sizeFromCurrentConst(*source)];
            memcpy(result, *source, sizeFromCurrentConst(*source));
            shared_ptr<__uint8_t> constant = shared_ptr<__uint8_t>(result);
            for (int i = 0; i < constantOffsetPossition.size(); i++) {
                DEFAULT_INT_TYPE point = *((DEFAULT_INT_TYPE*)&result[constantOffsetPossition[i]]);
                point += programmOffset;
                memcpy(result + i, &point, sizeof(point));
            }
            return NULL;
        }
        
    };
}

#endif /* BBCommand_hpp */
