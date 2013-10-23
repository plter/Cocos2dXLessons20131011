//
//  Plane.cpp
//  L1002AirRaid
//
//  Created by plter on 13-10-23.
//
//

#include "Plane.h"

CCArray* Plane::planeResArr = NULL;
CCArray* Plane::planes = NULL;



const char * Plane::getPlaneRes(){
    if (planeResArr==NULL) {
        planeResArr = new CCArray();
        planeResArr->addObject(CCString::create("p1.png"));
        planeResArr->addObject(CCString::create("p2.png"));
        planeResArr->addObject(CCString::create("p3.png"));
        planeResArr->addObject(CCString::create("p4.png"));
        planeResArr->addObject(CCString::create("p5.png"));
        
        srand(time(NULL));
    }
    
    return ((CCString*)planeResArr->objectAtIndex(rand()%planeResArr->count()))->getCString();
}



bool Plane::init(){
    CCSprite::initWithFile(getPlaneRes());
    
    addPlane(this);
    
    speed = CCRANDOM_0_1()*4+1;
    
    if(rand()%100<50){
        setScaleX(1);
        setPosition(ccp(570, 370));
        speed = -speed;
    }else{
        setScaleX(-1);
        setPosition(ccp(-20, 370));
    }
    
    scheduleUpdate();
    return true;
}

void Plane::update(float dt){
    setPositionX(getPositionX()+speed);
    
    if (getPositionX()>580||getPositionX()<-30) {
        removePlane(this);
    }
}