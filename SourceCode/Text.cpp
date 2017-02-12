//
//  Text.cpp
//  GameV2
//
//  Created by PAN on 16/5/2.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "Text.h"

Text::Text(GameEngine* engine, string str, int width, int height, int x, int y)
: m_text(str)
, DisplayableObject(engine)
{
    m_currentScreenX = x;
    m_currentScreenY = y;
    m_drawWidth = width;
    m_drawHeight = height;
    m_texture -> createFontTexture(m_text, m_engine -> getFont());
}

void Text::setText(string newText)
{
    m_text = newText;
}

void Text::doUpdate( int currentTime )
{
    m_texture -> createFontTexture(m_text, m_engine -> getFont());
}