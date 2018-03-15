//
//  BBByteCodeGenerator.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 24/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//



#ifndef BBByteCodeGenerator_hpp
#define BBByteCodeGenerator_hpp

#include <list>
#include "BBTokensAnalyzer.hpp"

using namespace std;

namespace BB {
    class Command;
    class ByteCodeGenerator{
        friend class CommandMachine;
        list<shared_ptr<Command>> commands;
        BBTokensAnalyzer_ptr tokenAnalyzer;
        ByteCodeGenerator(list<shared_ptr<Command>> command);
    public:
        shared_ptr<__uint8_t> byteCode(string sourceCommandCode);
        shared_ptr<__uint8_t> byteCodeAdaptedForThisSession(shared_ptr<__uint8_t> sourceByteCode);
    };
}

#endif /* BBByteCodeGenerator_hpp */
