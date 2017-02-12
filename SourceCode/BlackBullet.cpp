//
//  BlackBullet.cpp
//  GameV2
//
//  Created by PAN on 16/5/2.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "BlackBullet.h"

BlackBullet::BlackBullet(GameEngine* engine, int targetX, int targetY)
: BirdBullet(engine, targetX, targetY)
{
    m_drawWidth = 50;
    m_drawHeight = 58;
    m_targetX = targetX - m_drawWidth/2;
    m_targetY = targetY - m_drawHeight/2;
    
    m_texture -> loadFromFile("img/blackBullet.png");
    // calculate angle
    // get distance of separate component
    int dx = m_targetX - m_currentScreenX;
    int dy = m_targetY - m_currentScreenY;
    
    // arch tangent 2 gets the angle from dy and dx
    double tangle = round(atan2(dy,dx) * 180 / M_PI);
    m_angle = tangle;
    
    m_damage = 200;
    m_cost = 30;
    m_velocity = 30;
}
