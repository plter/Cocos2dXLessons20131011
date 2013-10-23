//
//  Plane.h
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#ifndef __L1002AirRaid__Plane__
#define __L1002AirRaid__Plane__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Plane:public CCSprite {
    
public:
    static const char* getPlaneRes();
    virtual bool init();
    CREATE_FUNC(Plane);
    virtual void update(float dt);
    
    inline static CCArray *getPlanes(){
        return planes;
    }
    
    inline static void addPlane(Plane* p){
        if (planes==NULL) {
            planes = new CCArray();
        }
        planes->addObject(p);
    }
    inline static void removePlane(Plane* p){
        if (planes!=NULL) {
            p->unscheduleUpdate();
            p->removeFromParent();
            
            planes->removeObject(p);
        }
    }
    
private:
    static CCArray *planeResArr;
    static CCArray *planes;
    
private:
    float speed;
};

#endif /* defined(__L1002AirRaid__Plane__) */
