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
#include "BBPTRDefine.hpp"
#include "BBByteCodeGenerator.hpp"
#include "ByteCodeInterpletator.hpp"
#include <list>

using namespace std;


namespace BB{
    class Command{
        friend class ByteCommand;
        shared_ptr<__uint32_t> fixConstantSizeSize;
        bool getAutoConstantSize;
    public:
        class ArgumentInterface{
        public:
            AddresType addresType;
            DataPositionType dataPosition;
            bool size;
            bool getAutoConstantSize;
        };
        
        __uint32_t code;
        string name;
        void (*implementation)(ByteCodeInterpletator*,MemmoryController*);
        Command(string name,void (*implementation)(ByteCodeInterpletator*,MemmoryController*),vector<ArgumentInterface> arguments);
        Command(string name,void (*implementation)(ByteCodeInterpletator*,MemmoryController*),vector<ArgumentInterface> arguments,__uint32_t constSize);
    private:
        vector<ArgumentInterface> arguments;
    };
    
    PTRType(Command);
}

#endif /* BBCommand_hpp */
