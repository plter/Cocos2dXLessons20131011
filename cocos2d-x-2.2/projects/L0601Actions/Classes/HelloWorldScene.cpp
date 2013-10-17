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
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    setTouchEnabled(true);
    
    scheduleUpdate();
//    unscheduleUpdate();
    
    s = CCSprite::create("img.jpg");
    
//    s->setRotationX(45);
//    s->setRotationY(90);
    s->setPosition(ccp(size.width/2, size.height/2));
//    s->setAnchorPoint(ccp(1, 1));
//    s->setPosition(ccp(size.width-200, size.height-200));
    addChild(s);
    
//    s->runAction(CCSpawn::create(CCRotateBy::create(5, 360),CCMoveBy::create(5, ccp(200, 200)),NULL));
    
//    s->runAction(CCSequence::create(
//                                    CCRotateBy::create(2, 360),
//                                    CCMoveBy::create(2, ccp(200, 200)),
//                                    NULL
//                 ));
    
//    s->runAction(CCRepeatForever::create(CCRotateBy::create(1, 360)));
    
//    s->runAction(CCSequence::create(
//                                    CCRotateBy::create(5, 360),
//                                    CCCallFuncN::create(this, callfuncN_selector(HelloWorld::actionCompleteHandler)),
//                                    NULL
//                 ));
    
//    s->runAction(CCFlipX::create(true));
    
//    s->runAction(CCMoveBy::create(3, ccp(200, 200))->reverse());
    return true;
}

void HelloWorld::update(float dt){
//    s->setPositionX(s->getPositionX()+1);
//    s->setPositionY(s->getPositionY()+1);
//    s->setRotationX(s->getRotationX()+3);
//    s->setRotationY(s->getRotationY()+3);
//    s->setRotation(s->getRotation()+3);
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
//    s->runAction(CCOrbitCamera::create(5, 5000, 0, 0, 0, 0, 360));
}

void HelloWorld::actionCompleteHandler(cocos2d::CCNode *node){
    CCMessageBox("Action completed", "Title");
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
