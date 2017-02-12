//
//  SmallZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "SmallZombie.h"

SmallZombie::SmallZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 11;
    m_HP = 300;
    m_point = 300;
    m_path = "img/small-zombie/small-zombie-";
    m_xVelocity = -2;
    
    m_drawWidth = 136;
    m_drawHeight = 124;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}