//
//  BBCodeGenerator.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 29/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBCodeGenerator_hpp
#define BBCodeGenerator_hpp

#include <stdio.h>
#include "BBCommand.hpp"
#include "BBMemmoryType.hpp"
#include <map>
#include "BBErrorPool.hpp"

using namespace std;

namespace BB {
    class CodeGenerator{
    public:
        struct Argument{
            string identifier;
            AddresType addresType;
            DataPositionType dataPosition;
            shared_ptr<__uint8_t> data;
            int size;
        };
        struct Command{
            string name;
            list<Argument> arguments;
        };
        struct Label {
            string label;
            DEFAULT_INT_TYPE position;
        };
    private:
        list<Argument> arguments;
        list<Command> inputCommands;
        map<string,Label> labels;
        list<Command_ptr> commands;
        ErrorPool_ptr errorPool;
        DEFAULT_INT_TYPE position;
    public:
        CodeGenerator(list<Command_ptr> commands,ErrorPool_ptr errorPool = NULL);
        
        void pushCommandWithName(string name);
        void popCommand();
        
        void addedLabel(string name,DEFAULT_INT_TYPE positionOffset = 0);
        
        void pushArgument(Argument argument);
        Argument* getLastArgument();
        Argument popArgument();
        
        shared_ptr<__uint8_t> getByteCode();
    };
}


#endif /* BBCodeGenerator_hpp */
