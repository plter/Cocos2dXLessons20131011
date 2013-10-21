#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    speedX = 0;
    speedY = 0;
    
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    circle = Circle::create();
    circle->setPosition(ccp(200, 200));
    addChild(circle);
    
    setAccelerometerEnabled(true);
    scheduleUpdate();
    
    return true;
}

void HelloWorld::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue){
    speedX+=pAccelerationValue->x;
    speedY+=pAccelerationValue->y;
}

void HelloWorld::update(float dt){
    circle->setPositionX(circle->getPositionX()+speedX);
    circle->setPositionY(circle->getPositionY()+speedY);
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
