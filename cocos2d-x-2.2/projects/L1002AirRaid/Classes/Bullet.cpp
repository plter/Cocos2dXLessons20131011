//
//  Bullet.cpp
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#include "Bullet.h"

Bullet* Bullet::create(float rotation){
    Bullet* b = new Bullet();
    b->initWithRotation(rotation);
    b->autorelease();
    return b;
}

bool Bullet::initWithRotation(float rotation){
    CCSprite::initWithFile("bullet.png");
    setRotation(90-rotation*180/M_PI);
    speedX = 5.0f*cosf(rotation);
    speedY = 5.0f*sinf(rotation);
    
    scheduleUpdate();
    return true;
}

void Bullet::update(float dt){
    setPositionX(getPositionX()+speedX);
    setPositionY(getPositionY()+speedY);
    
    CCObject *obj;Plane *plane;
    CCARRAY_FOREACH(Plane::getPlanes(), obj){
        plane = (Plane*)obj;
        if (plane->boundingBox().intersectsRect(boundingBox())) {
            unscheduleUpdate();
            removeFromParent();
            
            Plane::removePlane(plane);
            break;
        }
    }
    
    if (getPositionX()>550||getPositionY()>400||getPositionX()<0||getPositionY()<0) {
        unscheduleUpdate();
        removeFromParent();
    }
}