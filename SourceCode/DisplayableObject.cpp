//
//  DisplayableObject.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "DisplayableObject.h"

// Constructor
DisplayableObject::DisplayableObject(GameEngine* engine)
// Current position of object on the screen
: m_currentScreenX(-1)
, m_currentScreenY(-1)
// Previous position of object on the screen
, m_previousScreenX(-1)
, m_previousScreenY(-1)
// Size of the thing inside the tile:
, m_drawWidth(10)
, m_drawHeight(10)
, m_visible(false)
// Store pointer to the game object, for later use
, m_engine(engine)
{
    m_visible = false;
    m_texture = new MyTexture(engine -> getRenderer());
}

// Destructor
DisplayableObject::~DisplayableObject(void)
{
    m_texture -> free();
}

// Draw the object - override to implement the actual drawing of the correct object
// This just draws a magenta square at the current location
void DisplayableObject::draw()
{
    m_texture -> render(m_currentScreenX, m_currentScreenY, m_drawWidth, m_drawHeight);
}

// Handle the update action, moving the object and/or handling any game logic
void DisplayableObject::doUpdate( int currentTime )
{
    // Override can handle player input or do some AI actions to redirect object and set the current screen position
    // Set m_iCurrentScreenX, m_iCurrentScreenY
}

