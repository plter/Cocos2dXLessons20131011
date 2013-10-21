//
//  Circle.h
//  L0802DrawingAPI
//
//  Created by plter on 13-10-21.
//
//

#ifndef __L0802DrawingAPI__Circle__
#define __L0802DrawingAPI__Circle__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Circle :public CCSprite{
    
public:
    CREATE_FUNC(Circle);
    
    virtual void draw();
};

#endif /* defined(__L0802DrawingAPI__Circle__) */
