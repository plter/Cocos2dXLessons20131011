//
//  main.cpp
//  L0803Pointer
//
//  Created by plter on 13-10-21.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>


class Hello {
    
public:
    virtual void sayHello(){
        std::cout<<"Hello\n";
    };
};


int main(int argc, const char * argv[])
{

    Hello* h = new Hello();
    long int p = (long int)h;
    
    Hello* h1 = (Hello*)p;
    h1->sayHello();
    
    return 0;
}

