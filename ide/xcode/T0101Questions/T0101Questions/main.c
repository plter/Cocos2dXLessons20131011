//
//  main.c
//  T0101Questions
//
//  Created by plter on 13-10-11.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * question;
    char * answerA;
    char * answerB;
    char * answerC;
    char * answerD;
    char right;
    
} Question;


int main(int argc, const char * argv[])
{
    int score = 0;
    int qsCount = 10;
    int index = 0;
    char userInputAnswer;
    
    Question* qs[qsCount];
    for (index=0; index<qsCount; index++) {
        qs[index] = malloc(sizeof(Question));
    }
    
    //init questions
    Question* q;
    
    for (index = 0; index<qsCount; index++) {
        q = qs[index];
        q->right = 'a';
        q->question = "哪个数字更大？";
        q->answerA = "a:9";
        q->answerB = "b:2";
        q->answerC = "c:3";
        q->answerD = "d:8";
    }
    
    for (index = 0; index<qsCount; index++) {
        q = qs[index];
        printf("%d. %s\n%s\n%s\n%s\n%s\n",index+1,q->question,q->answerA,q->answerB,q->answerC,q->answerD);
        
        scanf("%c",&userInputAnswer);
        getchar();
        
        if (userInputAnswer==q->right) {
            score+=10;
        }
    }
    
    printf("总分：%d\n",score);
    return 0;
}

