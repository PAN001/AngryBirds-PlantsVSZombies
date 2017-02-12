//
//  EvilZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "EvilZombie.h"

EvilZombie::EvilZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 11;
    m_HP = 400;
    m_point = 400;
    m_path = "img/evil-zombie/evil-zombie-";
    m_xVelocity = -2;
    
    m_drawWidth = 144;
    m_drawHeight = 166;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}