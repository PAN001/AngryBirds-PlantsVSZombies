//
//  ExitButton.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "ExitButton.h"

ExitButton::ExitButton(GameEngine* engine)
: Button(engine)
{
    m_path = "img/exitButton.png";
    m_texture -> loadFromFile(m_path);
    
    m_currentScreenX = 800;
    m_currentScreenY = 800;
    
    m_visible = true;
}

void ExitButton::click(int x, int y)
{
    // is the mouse axis within the boundary of the button?
    if((x <= m_currentScreenX + m_drawWidth) && (x >= m_currentScreenX) && (y <= m_currentScreenY + m_drawHeight) && (y >= m_currentScreenY))
        m_engine -> setExitWithCode(0);
}