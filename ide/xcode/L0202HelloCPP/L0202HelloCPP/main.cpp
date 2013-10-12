//
//  main.cpp
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <string>
#include "People.h"
#include "Man.h"
#include "Woman.h"

using namespace std;
using namespace eoe;

int main(int argc, const char * argv[])
{

//    People* p = new People(18,"ChenYu","女");
    
//    People p1(20,"QinWeidong");
    
//    delete p;
    
//    People * m = new People(20,"QinWeidong","女");
    
//    printf("Sex of m:%s",m->getSex().c_str());
    
//    cout<<m->getSex()<<"\n";
    
//    m->sayHi();
    
    Man* m = new Man(21,"ChenChao");
    m->eat();
    
//    Woman* wm = new Woman(16,"LuoGang");
//    
//    m->fuck(*wm);
//    
//    delete wm;
    
//    People::getType();
    delete m;
    return 0;
}

