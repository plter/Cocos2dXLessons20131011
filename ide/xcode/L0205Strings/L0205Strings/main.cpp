//
//  main.cpp
//  L0205Strings
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[])
{
//    string a = "Hello";
//    string b = "Hello";
//    
//    printf("cmp: %d\n",a.compare(b));
    
//    if(a.compare(b)==0){
//        printf("Same\n");
//    }else{
//        printf("Differend\n");
//    }
    
//    char * a = "Hello";
//    char * b = "Hello";
//    
//    printf("cmp %d\n",strcmp(a, b));
    
//    char buf[10];
//    sprintf(buf, "%d",100);
//    printf("%s\n",buf);
    
//    stringstream ss;
//    ss<<10.9;
//    
//    cout<<ss.str()<<"\n";
    
//    int i = atoi("100");
//    
//    printf("The num is %d\n",i);
    
    string str = "100";
    int d = stoi(str);
    
    printf("The num is %d\n",d);
    
    return 0;
}

