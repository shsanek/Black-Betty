//
//  DTRPTRDefine.hpp
//  DTR
//
//  Created by Alexander Shipin on 18/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRPTRDefine_hpp
#define DTRPTRDefine_hpp

#include <stdio.h>

#define PTRType(type) typedef shared_ptr<type> PTR##type;

#endif /* DTRPTRDefine_hpp */
