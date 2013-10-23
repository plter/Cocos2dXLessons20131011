#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;
using namespace CocosDenshion;

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
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sound.mp3");
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    
    btnPlayBgSound = CCLabelTTF::create("Play background sound", "Courier", 30);
    btnPlayBgSound->setPosition(ccp(size.width/2, size.height-50));
    addChild(btnPlayBgSound);
    
    btnStopBgSound = CCLabelTTF::create("Stop background sound", "Courier", 30);
    btnStopBgSound->setPosition(ccp(size.width/2,size.height-90));
    addChild(btnStopBgSound);
    
    btnPauseBgSound = CCLabelTTF::create("Pause background sound", "Courier", 30);
    btnPauseBgSound->setPosition(ccp(size.width/2, size.height-130));
    addChild(btnPauseBgSound);
    
    btnResumeBgSound = CCLabelTTF::create("Resume background sound", "Courier", 30);
    btnResumeBgSound->setPosition(ccp(size.width/2, size.height-170));
    addChild(btnResumeBgSound);
    
    setTouchEnabled(true);
    
    
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch *t = (CCTouch*)pTouches->anyObject();
    CCPoint p = t->getLocation();
    
    if (btnPlayBgSound->boundingBox().containsPoint(p)) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound.mp3");
    }else if (btnStopBgSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }else if (btnPauseBgSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        
        bool playing = SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
        
        if (playing) {
            CCLog("true");
        }else{
            CCLog("false");
        }
    }else if (btnResumeBgSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
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
