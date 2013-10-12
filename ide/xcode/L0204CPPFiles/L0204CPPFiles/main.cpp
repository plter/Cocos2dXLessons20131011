//
//  main.cpp
//  L0204CPPFiles
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_PATH "/Users/plter/Desktop/Haha.txt"

int main(int argc, const char * argv[])
{

//    ofstream of(FILE_PATH);
//    of<<"Hello \n"<<22<<"CPP\n";
//    of.close();
    
    ifstream _if(FILE_PATH);
    
//    char c;
//    
//    for (int i=0; i<5; i++) {
//        _if>>c;
//        
//        cout<<c<<"\n";
//    }
    
    //read all string
    
    stringbuf ss;
    _if>>&ss;
    
    cout<<ss.str()<<"\n";
    
    _if.close();
    
    
    return 0;
}

