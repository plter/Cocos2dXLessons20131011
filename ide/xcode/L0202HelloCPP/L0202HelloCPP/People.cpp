//
//  People.cpp
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include "People.h"

namespace eoe {
    
    People::People(int age,string name,string sex){
        _age = age;
        _name = name;
        _sex = sex;
    }
    
    int People::getAge(){
        return _age;
    }
    
    
    void People::setAge(int age){
        _age = age;
    }
    
    string People::getSex(){
        return _sex;
    }
    
    string People::getName(){
        return _name;
    }
    
    void People::sayHi(){
        cout<<"People say hi \n";
    }
    
    People::~People(){
        printf("Delete People %s\n",getName().c_str());
    }
    
}