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
    
    class Command{
        friend class ByteCommand;
        class ArgumentInterface{
        public:
            enum ArgumentType{
                ArgumentTypeDefault,
                ArgumentTypeConstantOffset,
                ArgumentTypeConstant
            };
            ArgumentType type;
            bool size;
        };
        
        vector<ArgumentInterface> arguments;
        shared_ptr<__uint32_t> fixConstantSizeSize;
        bool getAutoConstantSize;
    public:
        class ByteCommand{
            class Argument{
            public:
                __uint32_t index;
                const __uint8_t* data;
                const ArgumentInterface* interface;
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
        
        __uint32_t code;
        string name;
        void (*implementation)(ByteCodeInterpletator*,MemmoryController*);
    };
}

#endif /* BBCommand_hpp */
