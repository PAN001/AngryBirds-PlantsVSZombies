//
//  DivingZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "DivingZombie.h"

DivingZombie::DivingZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 18;
    m_HP = 800;
    m_point = 800;
    m_path = "img/diving-zombie/diving-zombie-";
    m_xVelocity = -4;
    
    m_drawWidth = 136;
    m_drawHeight = 167;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}