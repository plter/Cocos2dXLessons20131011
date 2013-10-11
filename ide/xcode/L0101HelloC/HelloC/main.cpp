//
//  main.cpp
//  HelloC
//
//  Created by plter on 13-10-11.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

#define M_PI 3.141592654

#define _MAX(a,b) a>b?a:b

//typedef int EOE_INT_32;
//typedef long int EOE_INT_64;

typedef struct{
    int age;
    char* name;
} People;


void sayHello(People* __this){
    printf("%s say hello\n",__this->name);
}


typedef struct{
    People* __super;
} Man;

Man* createMan(){
    Man* m = (Man*)malloc(sizeof(Man));
    m->__super = (People*)malloc(sizeof(People));
    return m;
}

void deleteMan(Man* m){
    free(m->__super);
    free(m);
}


int max(int a,int b){
    return a>b?a:b;
}


int main(int argc, const char * argv[])
{

//    printf("%f\n",_MAX(2.1,4.2));
    
//    struct People p;
//    p.age = 18;
//    p.name = "ChenYu";
//    
//    struct People p1 = p;
//    p1.age = 20;
    
    
    People * p = (People*)malloc(sizeof(People));
    p->age = 18;
    p->name = "QinWeidong";
    
//    string name = "LuoGang";
    
    People * p1 = p;
    p1->age = 20;
    
    printf("Age of p:%d\n",p->age);
    
    Man* m = createMan();
    m->__super->age = 18;
    m->__super->name = "LuoGang";
    
    sayHello(m->__super);
    
//    printf("Man age:%d\n",m->__super->age);
    
    deleteMan(m);
    
    return 0;
}

