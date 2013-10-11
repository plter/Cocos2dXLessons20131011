//
//  main.c
//  T0101Questions
//
//  Created by plter on 13-10-11.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define QUESTIONS_COUNT 10

typedef struct{
    char * question;
    char * answerA;
    char * answerB;
    char * answerC;
    char * answerD;
    char right;
} Question;

Question** createQuestions(){
    Question** qs = malloc(sizeof(Question*)*QUESTIONS_COUNT);
    for (int i=0; i < QUESTIONS_COUNT; i++) {
        qs[i] = malloc(sizeof(Question));
    }
    return qs;
}

void deleteQuestions(Question** qs){
    for (int i=0; i<QUESTIONS_COUNT; i++) {
        free(qs[i]);
    }
    free(qs);
}

void initQuestions(Question** qs){
    Question* q;
    for (int i = 0; i<QUESTIONS_COUNT; i++) {
        q = qs[i];
        q->right = 'a';
        q->question = "哪个数字更大？";
        q->answerA = "a:9";
        q->answerB = "b:2";
        q->answerC = "c:3";
        q->answerD = "d:8";
    }
    
    //TODO Your can provide anthor implementation
}

int main(int argc, const char * argv[])
{
    int score = 0;
    
    Question* q;
    Question** qs = createQuestions();
    initQuestions(qs);
    
    //check user input
    for (int i = 0; i<QUESTIONS_COUNT; i++) {
        q = qs[i];
        printf("%d. %s\n%s\n%s\n%s\n%s\n",i+1,q->question,q->answerA,q->answerB,q->answerC,q->answerD);
        
        if (getchar()==q->right) {
            score+=10;
        }
        
        getchar();
    }
    
    printf("总分：%d\n",score);
    
    deleteQuestions(qs);
    return 0;
}

