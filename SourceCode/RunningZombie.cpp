//
//  RunningZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "RunningZombie.h"

RunningZombie::RunningZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 16;
    m_HP = 1000;
    m_point = 1000;
    m_path = "img/running-zombie/running-zombie-";
    m_xVelocity = -8;
    
    m_drawWidth = 202;
    m_drawHeight = 216;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}