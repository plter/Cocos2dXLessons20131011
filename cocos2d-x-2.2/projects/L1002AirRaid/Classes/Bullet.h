//
//  Bullet.h
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#ifndef __L1002AirRaid__Bullet__
#define __L1002AirRaid__Bullet__

#include <iostream>
#include <cocos2d.h>
#include "Plane.h"
USING_NS_CC;

class Bullet:public CCSprite {
    
public:
    virtual bool initWithRotation(float rotation);
    static Bullet* create(float rotation);
    virtual void update(float dt);
    
private:
    float speedX,speedY;
};

#endif /* defined(__L1002AirRaid__Bullet__) */
