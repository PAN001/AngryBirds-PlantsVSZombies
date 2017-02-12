//
//  FlyZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "FlyZombie.h"

FlyZombie::FlyZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 6;
    m_HP = 100;
    m_point = 100;
    m_path = "img/fly-zombie/fly-zombie-";
    m_xVelocity = -3;
    
    m_drawWidth = 126;
    m_drawHeight = 169;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}