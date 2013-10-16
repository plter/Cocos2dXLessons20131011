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
    
    dataArr = new CCArray();
    for (int i=0; i<100; i++) {
        dataArr->addObject(CCString::createWithFormat("Item %d",i));
    }
    
    
    table = CCTableView::create(this, CCSizeMake(300, 300));
    table->setAnchorPoint(ccp(0, 0));
    table->setPosition(ccp(100, 100));
    table->setDelegate(this);
    addChild(table);
    
    return true;
}


void HelloWorld::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell){
    CCLabelTTF* label = (CCLabelTTF*)cell->getChildByTag(2);
    
    CCMessageBox(CCString::createWithFormat("Clicked Item is %s",label->getString())->getCString(), "Hello");
}

unsigned int HelloWorld::numberOfCellsInTableView(cocos2d::extension::CCTableView *table){
    return dataArr->count();
}

CCSize HelloWorld::tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx){
    return CCSizeMake(300, 60);
}


CCTableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx){
    
    CCTableViewCell* cell = table->dequeueCell();
    CCLabelTTF* label;
    if (cell==NULL) {
        cell = new CCTableViewCell();
        label= CCLabelTTF::create("No Data", "Courier", 40);
        label->setAnchorPoint(ccp(0, 0));
        label->setTag(2);
        cell->addChild(label);
    }else{
        label= (CCLabelTTF*)cell->getChildByTag(2);
    }
    
    //init data
    label->setString(((CCString*)dataArr->objectAtIndex(idx))->getCString());
    
    return cell;
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
