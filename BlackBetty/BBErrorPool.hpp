//
//  BBErrorPool.hpp
//  BlackBetty
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBErrorPool_hpp
#define BBErrorPool_hpp

#include <iostream>
#include "BBError.hpp"
#include <list>

namespace BB {
    class ErrorPool{
    list<Error_ptr> errors;
    public:
        ErrorPool();
        virtual list<Error_ptr>* getErrors();
        virtual string allErros();
        virtual void addErrors(Error_ptr error);
    };
    PTRType(ErrorPool);
}

#endif /* BBErrorPool_hpp */
