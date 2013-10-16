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
    
    item = CCMenuItemImage::create("bg1.png", "bg2.png", this, menu_selector(HelloWorld::menuItemSelected));
    CCLabelTTF* label = CCLabelTTF::create("Click me", "Courier", 30);
    item->addChild(label);
    item->setTag(0);
    CCSize size = item->getContentSize();
    label->setPosition(ccp(size.width/2, size.height/2));
    
    item1 = CCMenuItemImage::create("bg2.png", "bg1.png", this, menu_selector(HelloWorld::menuItemSelected));
    item1->setTag(1);
    label=CCLabelTTF::create("游戏选项", "宋体", 30);
    size = item->getContentSize();
    item1->setPositionY(item->getPositionY()-size.height-10);
    label->setPosition(ccp(size.width/2, size.height/2));
    item1->addChild(label);
    
    
    CCMenu* menu = CCMenu::create(item,item1,NULL);
    
    addChild(menu);
    return true;
}


void HelloWorld::menuItemSelected(CCObject* pSender)
{
    //    switch (((CCMenuItemImage*)pSender)->getTag()) {
    //        case 0:
    //            CCMessageBox("Menu item clicked", "Hello");
    //            break;
    //        case 1:
    //            CCMessageBox("游戏选项", "");
    //        default:
    //            break;
    //    }
    
    if (pSender==item)
        CCMessageBox("Menu item clicked", "Hello");
    else if (pSender==item1)
        CCMessageBox("游戏选项", "");
}
