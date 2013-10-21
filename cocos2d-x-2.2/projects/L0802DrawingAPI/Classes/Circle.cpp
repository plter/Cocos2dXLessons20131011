//
//  Circle.cpp
//  L0802DrawingAPI
//
//  Created by plter on 13-10-21.
//
//

#include "Circle.h"

void Circle::draw(){
    ccDrawCircle(ccp(0, 0), 25, 360, 50, false);
}