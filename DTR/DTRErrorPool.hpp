//
//  DTRErrorPool.hpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRErrorPool_hpp
#define DTRErrorPool_hpp

#include <iostream>
#include "DTRError.hpp"
#include <list>

namespace DTR {
    class ErrorPool{
    list<PTRError> errors;
    public:
        ErrorPool();
        virtual list<PTRError>* getErrors();
        virtual string allErros();
        virtual void addErrors(PTRError error);
    };
}

#endif /* DTRErrorPool_hpp */
