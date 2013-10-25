#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D.h"
#include "Rect.h"

USING_NS_CC;

#define RATIO 80

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void update(float dt);
    virtual void addRect(float px,float py);
    
private:
    b2World *world;
    CCArray *rectArr;
    
};

#endif // __HELLOWORLD_SCENE_H__
