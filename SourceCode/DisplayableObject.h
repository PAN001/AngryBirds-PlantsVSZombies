//
//  DisplayableObject.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef DisplayableObject_h
#define DisplayableObject_h

#include "GameEngine.h"
#include "MyTexture.h"

class DisplayableObject
{
public:
    // Constructor
    DisplayableObject(GameEngine* engine);
    // Destructor
    ~DisplayableObject(void);
    
    // Draw the object - override to implement the actual drawing of the correct object
    virtual void draw();
    
    // Handle the update action, moving the object and/or handling any game logic
    virtual void doUpdate( int currentTime );

    // Get pointer to game object
    inline GameEngine* getEngine() { return m_engine; }
    
    /** Get the X centre position of the object */
    int getXCentre() { return m_currentScreenX + m_startDrawPosX + m_drawWidth/2; }
    
    /** Get the Y centre position of the object */
    int getYCentre() { return m_currentScreenY + m_startDrawPosY + m_drawHeight/2; }
    
    int getCurrentX() { return m_currentScreenX; }

    int getCurrentY() { return m_currentScreenY; }
    
    int getWidth() { return m_drawWidth; }
    
    int getHeight() { return m_drawHeight; }
    
    // Call this to make the item visible or invisible
    void setVisible( bool visible ) { m_visible = visible; }
    
    // Returns true if the object should be visible
    bool isVisible() { return m_visible; }
    
//    // Fix coords if they are off the screen
//    void fixPosition()
//    {
//        if ( ( m_iCurrentScreenX+m_iStartDrawPosX) < 0 )
//            m_iCurrentScreenX = -m_iStartDrawPosX;
//        else if ( ( m_iCurrentScreenX+m_iStartDrawPosX+m_iDrawWidth) >= m_pEngine->GetScreenWidth() )
//            m_iCurrentScreenX = m_pEngine->GetScreenWidth() - m_iStartDrawPosX - m_iDrawWidth;
//        
//        if ( ( m_iCurrentScreenY + m_iStartDrawPosY) < 0 )
//            m_iCurrentScreenY = -m_iStartDrawPosY;
//        else if ( ( m_iCurrentScreenY + m_iStartDrawPosY + m_iDrawHeight) >= m_pEngine->GetScreenHeight() )
//            m_iCurrentScreenY = m_pEngine->GetScreenHeight() - m_iStartDrawPosY - m_iDrawHeight;
//    }
    
private:

protected:
    // Pointer to the game object
    GameEngine* m_engine;
    
    // Texture
    MyTexture* m_texture;
    string m_path;
    
    // We expect the sub-class to specify where to draw the object, and where it came from
    // Current position of object on the screen
    int m_currentScreenX;
    int m_currentScreenY;
    // Previous position of object on the screen
    int m_previousScreenX;
    int m_previousScreenY;
    
    // Size of the object to draw
    int m_drawWidth;
    int m_drawHeight;
    
    // start postion
    int m_startDrawPosX;
    int m_startDrawPosY;
    
    // True if item is visible
    bool m_visible;
};

#endif /* DisplayableObject_h */
