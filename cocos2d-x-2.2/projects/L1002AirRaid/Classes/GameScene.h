//
//  GameScene.h
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#ifndef __L1002AirRaid__GameScene__
#define __L1002AirRaid__GameScene__

#include <iostream>
#include <cocos2d.h>
#include "Plane.h"

USING_NS_CC;

class GameLayer:public CCLayer {
    
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(GameLayer);
    virtual void addPlane(float t);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
private:
    CCSprite *bg,*gun;
};

#endif /* defined(__L1002AirRaid__GameScene__) */
