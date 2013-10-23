//
//  Board.h
//  L1001DrawLines
//
//  Created by plter on 13-10-23.
//
//

#ifndef __L1001DrawLines__Board__
#define __L1001DrawLines__Board__

#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

class Board:public CCSprite {
    
public:
    virtual bool init();
    virtual void draw();
    inline void addPoint(CCPoint p){
        _ps[_position] = p;
        _position++;
        _length++;
    }
    inline void clear(){
        _position = 0;
        _length = 0;
    }
    CREATE_FUNC(Board);
    
private:
    CCPoint _ps[10000];
    int _position;
    int _length;
};

#endif /* defined(__L1001DrawLines__Board__) */
