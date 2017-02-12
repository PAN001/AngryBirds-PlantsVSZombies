//
//  Button.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "Button.h"

Button::Button(GameEngine* engine)
: DisplayableObject(engine)
{
    setVisible(true);
}

Button::~Button()
{
    
}

void Button::click(int x, int y)
{
    
}

void Button::draw() {
    m_texture -> render(m_currentScreenX, m_currentScreenY, m_drawWidth, m_drawHeight);
}

void Button::doUpdate( int currentTime ) {
    return;
}
