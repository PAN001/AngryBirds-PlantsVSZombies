//
//  Battery.cpp
//  GameV2
//
//  Created by PAN on 16/5/2.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "Battery.h"

Battery::Battery(GameEngine* engine, int startX, int startY)
: DisplayableObject(engine)
{
    setVisible(true);
    
    m_currentScreenX = startX;
    m_currentScreenY = startY;

    m_drawWidth = 250;
    m_drawHeight = 200;
    
    m_texture -> loadFromFile("img/battery.png");
    
    m_angle = 0;
}

void Battery::doUpdate(int currentTime)
{
    int targetX = m_engine -> getCurrentMouseX() - m_drawWidth/2;
    int targetY = m_engine -> getCurrentMouseY() - m_drawHeight/2;
    
    // calculate angle
    // get distance of separate component
    int dx = targetX - m_currentScreenX;
    int dy = targetY - m_currentScreenY;
    
    // arch tangent 2 gets the angle from dy and dx
    double tangle = round(atan2(dy,dx) * 180 / M_PI) + 90;
    m_angle = tangle;
}

void Battery::draw()
{
    m_texture -> render(m_currentScreenX, m_currentScreenY, m_drawWidth, m_drawHeight, m_angle);
}