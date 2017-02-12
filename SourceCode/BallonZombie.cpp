//
//  BallonZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/2.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "BallonZombie.h"

BallonZombie::BallonZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 8;
    m_HP = 200;
    m_point = 100;
    m_path = "img/ballon-zombie/ballon-zombie-";
    m_xVelocity = -3;
    
    m_drawWidth = 146;
    m_drawHeight = 173;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}