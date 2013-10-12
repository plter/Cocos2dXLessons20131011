//
//  Question.cpp
//  T0201LoadQuestions
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include "Question.h"

Question::Question(string question,string answerA,string answerB,string answerC,string answerD,string right){
    _question = question;
    _answerA = answerA;
    _answerB = answerB;
    _answerC = answerC;
    _answerD = answerD;
    _right = right;
}


string Question::getAnswerA(){
    return _answerA;
}

string Question::getAnswerB(){
    return _answerB;
}

string Question::getAnswerC(){
    return _answerC;
}

string Question::getAnswerD(){
    return _answerD;
}

string Question::getRight(){
    return _right;
}

string Question::getQuestion(){
    return _question;
}