//
//  main.c
//  L0201CFile
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    FILE* f = fopen("Haha.txt", "a");
    
    fprintf(f, "Hello %d\n",1000);
    
    fclose(f);
    
    printf("Complete\n");
    return 0;
}

