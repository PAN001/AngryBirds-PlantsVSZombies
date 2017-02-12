//
//  CarZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "CarZombie.h"

CarZombie::CarZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 7;
    m_HP = 900;
    m_point = 900;
    m_path = "img/car-zombie/car-zombie-";
    m_xVelocity = -6;
    
    m_drawWidth = 182;
    m_drawHeight = 171;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}