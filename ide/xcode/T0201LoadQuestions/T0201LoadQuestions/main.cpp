//
//  main.cpp
//  T0201LoadQuestions
//
//  Created by plter on 13-10-12.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "reader.h"
#include "Question.h"

using namespace Json;
using namespace std;

#define DATA_FILE_PATH "/Users/plter/Work/gitroot/plter/github/Cocos2dXLessons20131011/ide/xcode/T0201LoadQuestions/data/questions.json"

string readDataFile(){
    ifstream file(DATA_FILE_PATH);
    stringbuf sb;
    file>>&sb;
    file.close();
    return sb.str();
}

Value parseJsonStr(string json){
    Reader r;
    Value root;
    r.parse(json, root);
    return root;
}

list<Question*> parseJson(Value root){
    int count = root.size();
    list<Question*> qs;
    Value item;
    
    for (int i=0; i<count; i++) {
        item = root[i];
        qs.push_back(new Question(item["question"].asString(),item["a"].asString(),item["b"].asString(),item["c"].asString(),item["d"].asString(),item["right"].asString()));
    }
    return qs;
}



int main(int argc, const char * argv[])
{
    string data = readDataFile();
    Value root = parseJsonStr(data);
    list<Question*> qs = parseJson(root);
    
    list<Question*>::iterator it;
    char userInputChar;
    Question* q;
    int index = 0,score = 0;
    
    for (it = qs.begin(); it!=qs.end(); it++) {
        index++;
        q = *it;
        
        cout<<index<<". "<<q->getQuestion()<<"\n"
        <<q->getAnswerA()<<"\n"
        <<q->getAnswerB()<<"\n"
        <<q->getAnswerC()<<"\n"
        <<q->getAnswerD()<<"\n";
        
        cin>>userInputChar;
        if (q->getRight()[0]==userInputChar) {
            score++;
        }
    }
    
    cout<<"Total score :"<<score<<"\n";
    return 0;
}

