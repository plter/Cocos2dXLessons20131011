#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *scene = HelloWorld::scene();
//    CCScene * scene = CCScene::create();
//    CCLayer* layer = CCLayer::create();
//    scene->addChild(layer);
//    
//    CCLabelTTF* label = CCLabelTTF::create();
//    label->setString("Hello Cocos2d-x");
//    label->setFontSize(60);
//    label->setAnchorPoint(ccp(1, 1));
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//    CCSize size = label->getContentSize();
////    label->setPosition(ccp(size.width/2, size.height/2));
//    label->setPosition(ccp(visibleSize.width, visibleSize.height));
//    layer->addChild(label);
    
    // run
    pDirector->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
