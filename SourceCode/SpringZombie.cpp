//
//  SpringZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "SpringZombie.h"

SpringZombie::SpringZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 5;
    m_HP = 700;
    m_point = 700;
    m_path = "img/spring-zombie/spring-zombie-";
    m_xVelocity = -6;
    
    m_drawWidth = 100;
    m_drawHeight = 175;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}