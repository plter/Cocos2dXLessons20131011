//
//  PLArray.c
//  T0202CArray
//
//  Created by plter on 13-10-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdlib.h>
#include "PLArray.h"

//PLArrayItem>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PLArrayItem* createPLArrayItem(){
    PLArrayItem* item = malloc(sizeof(PLArrayItem));
    item->next=NULL;
    item->pre=NULL;
    item->value=0;
    return item;
}

void destoryPLArrayItem(PLArrayItem* item){
    free(item);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//PLArray>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PLArray* createPLArray(){
    PLArray* arr = malloc(sizeof(PLArray));
    arr->length=0;
    arr->begin=NULL;
    arr->end=createPLArrayItem();
    return arr;
}

void destoryPLArray(PLArray* arr){
    
    while (arr->length>0) {
        PLArrayPop(arr);
    }
    
    destoryPLArrayItem(arr->end);
    free(arr);
}

void PLArrayPush(PLArray* arr,int value){
    PLArrayItem* newItem = createPLArrayItem();
    newItem->value=value;
    newItem->next=arr->end;
    newItem->pre=arr->end->pre;
    newItem->next->pre=newItem;
    if (newItem->pre!=NULL) {
        newItem->pre->next=newItem;
    }
    
    arr->length++;
    
    if (arr->length<=1) {
        arr->begin=newItem;
    }
}

int PLArrayPop(PLArray* arr){
    PLArrayItem* last = arr->end->pre;
    int value = last->value;
    if (last->pre!=NULL) {
        last->pre->next=last->next;
    }
    last->next->pre=last->pre;
    
    destoryPLArrayItem(last);
    
    arr->length--;
    
    if (arr->length<=0) {
        arr->begin=NULL;
    }
    
    return value;
}



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
