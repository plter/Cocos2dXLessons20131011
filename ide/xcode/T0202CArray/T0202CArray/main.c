//
//  main.c
//  T0202CArray
//
//  Created by plter on 13-10-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "PLArray.h"


int main(int argc, const char * argv[])
{
    //create
    PLArray* arr = createPLArray();
    
    //init
    int i=0;
    for (i=0; i<10; i++) {
        PLArrayPush(arr, i);
    }
    
    //read
    PLArrayItem* it;
    for (it = arr->begin; it!=arr->end&&it!=NULL; it=it->next) {
        printf("Current value is %d\n",it->value);
    }
    
    //destory
    destoryPLArray(arr);
    
    return 0;
}

