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
    
    rectArr = new CCArray();
    
    b2Vec2 vec(0,-10);
    world = new b2World(vec);
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    
    //create ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.x = 400.0f/RATIO;
    groundBodyDef.type = b2_staticBody;
    b2Body * groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBodyShape;
    groundBodyShape.SetAsBox(400.0f/RATIO, 0.1);
    b2FixtureDef groundBodyFd;
    groundBodyFd.friction = 0.3;
//    groundBodyFd.restitution = 0.75;
    groundBodyFd.shape = &groundBodyShape;
    groundBody->CreateFixture(&groundBodyFd);
    
    addRect(400, 400);
    
    scheduleUpdate();
    
    setTouchEnabled(true);
    
    return true;
}


void HelloWorld::addRect(float px, float py){
    
    Rect * rect = Rect::create();
    addChild(rect);
    
    b2BodyDef bodyDef;
    bodyDef.linearDamping = 1;
    bodyDef.position.x = px/RATIO;
    bodyDef.position.y = py/RATIO;
    bodyDef.angularDamping = 0.8;
//    bodyDef.linearVelocity = b2Vec2(0,-1);
//    bodyDef.angularVelocity = M_PI;
    bodyDef.type = b2_dynamicBody;
    b2Body * body = world->CreateBody(&bodyDef);
    body->SetUserData(rect);
    
    b2PolygonShape bodyShape;
    bodyShape.SetAsBox(20.0f/RATIO, 20.0f/RATIO);
    
    b2FixtureDef bodyFd;
    bodyFd.density = 0.3;
    bodyFd.friction = 0.3;
    bodyFd.shape = &bodyShape;
//    bodyFd.restitution = 0.5;
    body->CreateFixture(&bodyFd);
    
//    rect->setB2Body(body);
    
//    rectArr->addObject(rect);
    
}

void HelloWorld::update(float dt){
    world->Step(dt, 8, 3);
    
    CCSprite *r;
    for (b2Body *b = world->GetBodyList(); b!=NULL; b=b->GetNext()) {
        r = (Rect*)(b->GetUserData());
        if (r!=NULL) {
            
            if (b->GetPosition().y<=3) {
                
                b->ApplyForceToCenter(b2Vec2(0, 10*1*0.5*0.5*(
                                                                3-b->GetPosition().y>0.5?1:3-b->GetPosition().y/0.5
                                             )
                                             )
                                      );
            }
            
            r->setPositionX(b->GetPosition().x*80);
            r->setPositionY(b->GetPosition().y*80);
            r->setRotation(-b->GetAngle()*180/M_PI);
            
        }
//        CCLog("%f",b->GetPosition().x);
//        CCLog("%f",b->GetPosition().y);
    }
    
//    CCObject *obj;
//    Rect *rect;
//    CCARRAY_FOREACH(rectArr, obj){
//        rect = (Rect*)obj;
//        rect->syncStatus();
//    }
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch * t = (CCTouch*)pTouches->anyObject();
    
    CCPoint p = t->getLocation();
    addRect(p.x, p.y);
    
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
