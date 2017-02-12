//
//  StairsZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "StairsZombie.h"

StairsZombie::StairsZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 14;
    m_HP = 600;
    m_point = 600;
    m_path = "img/stairs-zombie/stairs-zombie-";
    m_xVelocity = -5;
    
    m_drawWidth = 156;
    m_drawHeight = 183;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}