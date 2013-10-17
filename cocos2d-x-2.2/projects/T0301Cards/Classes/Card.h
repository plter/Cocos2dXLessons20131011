//
//  Card.h
//  T0301Cards
//
//  Created by plter on 13-10-17.
//
//

#ifndef __T0301Cards__Card__
#define __T0301Cards__Card__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class Card:public CCSprite {
    
public:
    virtual bool initWithNum(int num);
    virtual void showRecto();
    virtual void showVerso();
    virtual int getNum();
    static Card* create(int num);
    
private:
    int _num;
    CCSprite* recto,*verso;
    CCLabelTTF* label;
};

#endif /* defined(__T0301Cards__Card__) */
