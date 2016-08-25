//
//  BBByteCommand.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 25/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBByteCommand_hpp
#define BBByteCommand_hpp

#include <stdio.h>
#include "BBCommand.hpp"

namespace BB{
    class ByteCommand{
        class Argument{
        public:
            __uint32_t index;
            const __uint8_t* data;
            const Command::ArgumentInterface* interface;
            __uint32_t size;
        };
        
        shared_ptr<__uint32_t> fixConstantSizeSize;
        Command* command;
        __uint8_t* source;
        DEFAULT_INT_TYPE programmOffset;
        __uint32_t size;
        
        shared_ptr<Argument> nextArgument(shared_ptr<Argument> argument);
        
        void updateDataForArgument(shared_ptr<Argument> result) ;
        
        void updateSize();
        
    public:
        ByteCommand(Command* command,__uint8_t* source,DEFAULT_INT_TYPE programmOffset);
        size_t getSize();
    };
};

#endif /* BBByteCommand_hpp */
