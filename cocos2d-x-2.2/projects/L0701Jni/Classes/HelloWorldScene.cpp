#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld* HelloWorld::_helloWorld=NULL;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::sharedHelloWorld();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


HelloWorld* HelloWorld::sharedHelloWorld(){
	if (HelloWorld::_helloWorld==NULL) {
		HelloWorld::_helloWorld = HelloWorld::create();
	}
	return HelloWorld::_helloWorld;
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
    
    return true;
}


void HelloWorld::addImg(const char* img){
	CCSprite* s = CCSprite::create(img);
	s->setAnchorPoint(ccp(0,0));
	s->setPosition(ccp(100,100));
	addChild(s);
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
