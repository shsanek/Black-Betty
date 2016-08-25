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
        __uint32_t code;
        string name;
        void (*implementation)(ByteCodeInterpletator*,MemmoryController*);
    };
}

#endif /* BBCommand_hpp */
