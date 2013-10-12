//
//  Man.h
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0202HelloCPP__Man__
#define __L0202HelloCPP__Man__

#include <iostream>
#include <string>
#include "People.h"
#include "Woman.h"

using namespace std;

namespace eoe {
    
    
    class Man:public People{
        
    public:
        Man(int age,string name);
        
        virtual void sayHi();
        virtual void eat();
        
        virtual void fuck(Woman& wm);
    };
}

#endif /* defined(__L0202HelloCPP__Man__) */
