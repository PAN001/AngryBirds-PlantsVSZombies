//
//  DuckZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "DuckZombie.h"

DuckZombie::DuckZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 14;
    m_HP = 1000;
    m_point = 100;
    m_path = "img/duck-zombie/duck-zombie-";
    m_xVelocity = -3;
    
    m_drawWidth = 134;
    m_drawHeight = 151;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}