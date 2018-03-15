//
//  BBCommandMachine.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 19/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBCommandMachine_hpp
#define BBCommandMachine_hpp

#include <stdio.h>
#include <string>
#include "BBCommand.hpp"
#include <list>

using namespace std;


namespace BB{
        
    class CommandMachine{
        list<Command_ptr> commands;
    public:
        void addCommand(Command_ptr command);
        shared_ptr<ByteCodeGenerator> byteCodeGenerator();
        shared_ptr<ByteCodeInterpletator> byteCodeInterpletator();
    };
}



#endif /* BBCommandMachine_hpp */
