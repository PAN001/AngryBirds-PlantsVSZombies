//
//  PolejumpZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "PolejumpZombie.h"

PolejumpZombie::PolejumpZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 8;
    m_HP = 700;
    m_point = 700;
    m_path = "img/polejump-zombie/polejump-zombie-";
    m_xVelocity = -6;
    
    m_drawWidth = 246;
    m_drawHeight = 205;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}