//
//  Rect.cpp
//  L1201Box2d
//
//  Created by plter on 13-10-25.
//
//

#include "Rect.h"


bool Rect::init(){
    CCSprite::init();
    
    setTextureRect(CCRectMake(0, 0, 40, 40));
    setColor(ccc3(255, 0, 0));
    
    return true;
}