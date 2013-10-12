//
//  main.cpp
//  L0203UsingList
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    list<int> _intList;
    for (int i=0; i<10; i++) {
//        _intList.push_back(i);
        _intList.push_front(i);
    }
    
//    _intList.pop_front();
    
    list<int>::iterator it;
    int item;
    
    for (it = _intList.begin(); it!=_intList.end(); it++) {
        item = *it;
        
        printf("Item : %d\n",item);
    }
    
    
    vector<int> _intVec;
    for (int j = 0; j<10; j++) {
        _intVec.push_back(j*100);
    }
    
    int value = _intVec.at(5);
    printf("Value of index 5:%d\n",value);
    
    printf("Complete\n");
    
    
    return 0;
}

