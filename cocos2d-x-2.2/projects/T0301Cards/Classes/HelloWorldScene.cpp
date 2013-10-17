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
    
    cardArr = new CCArray();
    pointArr = new CCArray();
    
    startGame();
    
    setTouchEnabled(true);
    
    return true;
}

void HelloWorld::startGame(){
    pointArr->removeAllObjects();
    removeAllChildren();
    cardArr->removeAllObjects();
    currentNum=1;
    
    genAllPoint();
    addCards();
}


void HelloWorld::addCards(){
    CCPoint p;
    
    int randNum;
    Card* card;
    
    srand(time(NULL));
    
    for (int i=1; i<=10; i++) {
        randNum = rand()%(pointArr->count());
        p= CCPointFromString(((CCString*)pointArr->objectAtIndex(randNum))->getCString());
        card = Card::create(i);
        addChild(card);
        cardArr->addObject(card);
        card->setPosition(p);
        
        pointArr->removeObjectAtIndex(randNum);
    }
}


void HelloWorld::genAllPoint(){
    for (int i=0; i<10; i++) {
        for (int j=0; j<6; j++) {
            pointArr->addObject(CCString::createWithFormat("{%f,%f}",80.0*i,80.0*j));
        }
    }
}

void HelloWorld::turnAllCardsOver(){
    CCObject* obj;
    Card* c;
    
    CCARRAY_FOREACH(cardArr, obj){
        
        c=(Card*)obj;
        c->showVerso();
    }
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch* t = (CCTouch*)pTouches->anyObject();
    
    CCObject* obj;
    Card* c;
    CCARRAY_FOREACH(cardArr, obj){
        c = (Card*)obj;
        
        if (c->boundingBox().containsPoint(t->getLocation())) {
            
            if (currentNum==c->getNum()) {
                cardArr->removeObject(c);
                removeChild(c);
                
                if (currentNum==1) {
                    turnAllCardsOver();
                }
                
                currentNum++;
                
                if (cardArr->count()<=0) {
                    CCMessageBox("成功", "标题");
                }
            }else{
                CCMessageBox("错误", "标题");
            }
            
            break;
        }
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
