//
//  Woman.h
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0202HelloCPP__Woman__
#define __L0202HelloCPP__Woman__

#include <iostream>
#include "People.h"

namespace eoe {
    
    class Woman:public People{
    public:
        Woman(int age,string name);
        virtual void eat();
    };
}

#endif /* defined(__L0202HelloCPP__Woman__) */
