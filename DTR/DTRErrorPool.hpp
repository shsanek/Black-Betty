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
    list<Error_ptr> errors;
    public:
        ErrorPool();
        virtual list<Error_ptr>* getErrors();
        virtual string allErros();
        virtual void addErrors(Error_ptr error);
    };
}

#endif /* DTRErrorPool_hpp */
