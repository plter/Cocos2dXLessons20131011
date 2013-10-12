//
//  Man.cpp
//  L0202HelloCPP
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include "Man.h"

namespace eoe {
    
    Man::Man(int age,string name):People(age,name,"男"){
    }
    
    void Man::sayHi(){
        cout<<"Man say hi\n";
    }
    
    void Man::eat(){
        cout<<"Man eat \n";
    }
    
    void Man::fuck(eoe::Woman *wm){
        
    }
}