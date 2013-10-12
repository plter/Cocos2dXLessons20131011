//
//  People.h
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0202HelloCPP__People__
#define __L0202HelloCPP__People__

#include <iostream>

using namespace std;

namespace eoe {
    
    class People {
        
    private:
        int _age;
        string _name;
        string _sex;
        
    public:
        People(int age,string name,string sex);
        
        int getAge();
        void setAge(int age);
        
        string getSex();
        string getName();
        virtual void sayHi();
        
        virtual void eat()=0;
        
        static int getType(){
            return 0;
        };
        
        ~People();
    };
    
}

#endif /* defined(__L0202HelloCPP__People__) */
