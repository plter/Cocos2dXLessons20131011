//
//  PLArray.h
//  T0202CArray
//
//  Created by plter on 13-10-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef T0202CArray_PLArray_h
#define T0202CArray_PLArray_h

typedef struct __PLArrayItem {
    struct __PLArrayItem * next;
    struct __PLArrayItem * pre;
    int value;
} PLArrayItem;

typedef struct __PLArray{
    PLArrayItem* begin;
    PLArrayItem* end;
    int length;
} PLArray;

PLArray* createPLArray();
void destoryPLArray(PLArray* arr);
void PLArrayPush( PLArray* arr,int value);
int PLArrayPop(PLArray* arr);

#endif
