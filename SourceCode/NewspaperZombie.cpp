//
//  NewspaperZombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "NewspaperZombie.h"

NewspaperZombie::NewspaperZombie(GameEngine* engine)
: Zombie(engine)
{
    m_numOfPics = 17;
    m_HP = 500;
    m_point = 500;
    m_path = "img/newspaper-zombie/newspaper-zombie-";
    m_xVelocity = -2;
    
    m_drawWidth = 144;
    m_drawHeight = 166;
    
//    m_texture -> loadFromFile(m_path + "1.gif");
}