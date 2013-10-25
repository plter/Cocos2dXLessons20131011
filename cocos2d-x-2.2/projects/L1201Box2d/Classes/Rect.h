//
//  Rect.h
//  L1201Box2d
//
//  Created by plter on 13-10-25.
//
//

#ifndef __L1201Box2d__Rect__
#define __L1201Box2d__Rect__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"

using namespace cocos2d;

class Rect:public CCSprite {
    
public:
    virtual bool init();
    inline void setB2Body(b2Body *b){
        body = b;
    }
    inline b2Body *getB2Body(){
        return body;
    }
    inline void syncStatus(){
        setPositionX(body->GetPosition().x*80);
        setPositionY(body->GetPosition().y*80);
        setRotation(-body->GetAngle()*180/M_PI);
    }
    
    CREATE_FUNC(Rect);
    
private:
    b2Body *body;
};

#endif /* defined(__L1201Box2d__Rect__) */
