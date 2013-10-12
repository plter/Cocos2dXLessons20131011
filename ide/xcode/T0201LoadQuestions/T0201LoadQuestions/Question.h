//
//  Question.h
//  T0201LoadQuestions
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __T0201LoadQuestions__Question__
#define __T0201LoadQuestions__Question__

#include <iostream>
#include <string>

using namespace std;

class Question {
    
private:
    string _question,_answerA,_answerB,_answerC,_answerD,_right;
    
public:
    Question(string question,string answerA,string answerB,string answerC,string answerD,string right);
    
    string getQuestion();
    string getAnswerA();
    string getAnswerB();
    string getAnswerC();
    string getAnswerD();
    string getRight();
};

#endif /* defined(__T0201LoadQuestions__Question__) */
