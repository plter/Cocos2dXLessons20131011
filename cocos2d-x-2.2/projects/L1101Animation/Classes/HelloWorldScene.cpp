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
    
    
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("anim.plist", "anim.png");
    cache->addSpriteFramesWithFile("sprite.plist","sprite.png");
    
    CCArray * animArr = new CCArray();
    
    char buf[10];
    for (int i=0; i<30; i++) {
        sprintf(buf, "anim%04d",i);
        animArr->addObject(cache->spriteFrameByName(buf));
    }
    
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(animArr,0.02f);
    CCAnimate *animate = CCAnimate::create(animation);
    
    CCSprite *s = CCSprite::create();
    s->setPosition(ccp(200, 200));
    addChild(s);
    
    s->runAction(CCRepeatForever::create(animate));
    
    ////////////////////////////////
    p=CCSprite::create();
    p->setPosition(ccp(400, 100));
    addChild(p);
    
    CCArray * spriteArr = CCArray::create();
    char spriteBuf[12];
    for (int j=0; j<16; j++) {
        sprintf(spriteBuf, "sprite%04d",j);
        spriteArr->addObject(cache->spriteFrameByName(spriteBuf));
    }
    
    CCAnimate *spriteAnimate = CCAnimate::create(CCAnimation::createWithSpriteFrames(spriteArr,0.1));
    p->runAction(CCRepeatForever::create(
                                         CCSpawn::create(
                                                         spriteAnimate,CCMoveBy::create(1.6f, ccp(-80, 0)                                                                           ),NULL
                                                         )
                                         )
                 );
    
//    p->setScaleX(-1);
//    p->setFlipX(true);
    return true;
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
