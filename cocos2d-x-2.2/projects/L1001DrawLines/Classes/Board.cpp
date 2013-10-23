//
//  Board.cpp
//  L1001DrawLines
//
//  Created by plter on 13-10-23.
//
//

#include "Board.h"


bool Board::init(){
    
    clear();
    
    return true;
}

void Board::draw(){
    ccDrawPoly(_ps, _length, false);
}