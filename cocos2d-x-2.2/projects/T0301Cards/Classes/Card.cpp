//
//  Card.cpp
//  T0301Cards
//
//  Created by plter on 13-10-17.
//
//

#include "Card.h"


Card* Card::create(int num){
    Card* c= new Card();
    c->initWithNum(num);
    c->autorelease();
    return c;
}

bool Card::initWithNum(int num){
    CCSprite::init();
    _num = num;
    
    setContentSize(CCSize(80, 80));
    
    recto = CCSprite::create();
    recto->setTextureRect(CCRect(0, 0, 80, 80));
    recto->setColor(ccc3(0, 0, 255));
    recto->setAnchorPoint(ccp(0,0));
    addChild(recto);
    label = CCLabelTTF::create(CCString::createWithFormat("%d",num)->getCString(), "Courier", 60);
    recto->addChild(label);
    label->setPosition(ccp(40, 40));
    
    verso = CCSprite::create();
    verso->setAnchorPoint(ccp(0, 0));
    verso->setTextureRect(CCRect(0, 0, 80, 80));
    verso->setColor(ccc3(255, 0, 0));
    addChild(verso);
    
    setAnchorPoint(ccp(0, 0));
    
    showRecto();
    return true;
}

void Card::showRecto(){
    recto->setVisible(true);
    verso->setVisible(false);
}

void Card::showVerso(){
    recto->setVisible(false);
    verso->setVisible(true);
}

int Card::getNum(){
    return _num;
}