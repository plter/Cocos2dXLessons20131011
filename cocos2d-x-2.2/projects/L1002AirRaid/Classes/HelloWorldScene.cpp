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
    
    btnStart = CCLabelTTF::create("Start Game", "Courier", 30);
    btnStart->setPosition(ccp(size.width/2, size.height/2));
    addChild(btnStart);
    
    setTouchEnabled(true);
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
//    CCSetIterator it;
//    CCTouch *touch;
//    for (it=pTouches->begin(); it!=pTouches->end(); it++) {
//        touch = (CCTouch*)*it;
//        //Your Custom Code
//    }
    
    CCTouch * t = (CCTouch*)pTouches->anyObject();
    if (btnStart->boundingBox().containsPoint(t->getLocation())) {
        CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(0.5, GameLayer::scene()));
    }
    
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
