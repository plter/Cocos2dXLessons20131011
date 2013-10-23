//
//  GameScene.cpp
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#include "GameScene.h"
#include "Bullet.h"

CCScene* GameLayer::scene(){
    CCScene* s = CCScene::create();
    GameLayer * layer = GameLayer::create();
    s->addChild(layer);
    return s;
}


bool GameLayer::init(){
    CCLayer::init();
    
    setTouchEnabled(true);
    
    bg = CCSprite::create("bg.jpg");
    bg->setAnchorPoint(ccp(0, 0));
    addChild(bg);
    
    gun = CCSprite::create("gun.png");
    gun->setAnchorPoint(ccp(0.5, 0));
    gun->setPosition(ccp(275, 20));
    addChild(gun);
    
    schedule(schedule_selector(GameLayer::addPlane), 2);
    
    return true;
}


void GameLayer::addPlane(float t){
    
    addChild(Plane::create());
}


void GameLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch * touch = (CCTouch*)pTouches->anyObject();
    CCPoint tp = touch->getLocation();
    float r = atan2f(tp.y-gun->getPositionY(), tp.x-gun->getPositionX());
    
    gun->setRotation(90-r*180/M_PI);
    float gunHeight = gun->getContentSize().height;
    
    Bullet * b = Bullet::create(r);
    b->setAnchorPoint(ccp(0.5, 0));
    b->setPosition(ccp(gun->getPositionX()+gunHeight*cosf(r), gun->getPositionY()+gunHeight*sinf(r)));
    addChild(b);
    
}