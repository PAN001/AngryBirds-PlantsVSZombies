//
//  BossZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "BossZombie.h"

BossZombie::BossZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 17;
    m_HP = 3000;
    m_point = 5000;
    m_path = "img/boss-zombie/boss-zombie-";
    m_xVelocity = -3;
    
    m_drawWidth = 246;
    m_drawHeight = 261;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}