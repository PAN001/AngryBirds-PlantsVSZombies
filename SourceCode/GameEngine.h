//
//  GameEngine.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef GameEngine_h
#define GameEngine_h

// Prototype the class, so we can use pointers of type DisplayableObject*
class DisplayableObject;

#include <list>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

using namespace std;

class GameEngine
{
public:
    /* Constructor. */
    GameEngine();
    
    /* Virtual destructor */
    virtual ~GameEngine(void);
    
    //
    // Internal functions
    //
    
    /* Initialise the SDL and create a window of the designated size */
    int initialise( char* strCaption, int screenWidth, int screenHeight, char* fontName, int fontSize );
    
    /* The main game loop - will call the draw and gamel logic functions in turn */
    int mainLoop(void);
    
    /* Destroy any existing displayable objects */
    virtual void destroyOldObjects();
    
public:
    //
    // Utility functions: (call these)
    //
    enum State {initState, levelSelectionState, mainState, pauseState, loseState, winState};
    enum Level {easy, medium, difficult};
    
    /*
     Is the key with the specified code currently being pressed?
     Returns 1 for Yes, 0 for No.
     */
    int isKeyPressed(int iKeyCode);
    
    /* Last clicked X coordinate of mouse - button down */
    int getMouseXClickedDown() { return m_mouseXClickedDown; }
    
    /* Last clicked Y coordinate of mouse - button down */
    int getMouseYClickedDown() { return m_mouseYClickedDown; }
    
    /* Last clicked X coordinate of mouse - button up */
    int getMouseXClickedUp() { return m_mouseXClickedUp; }
    
    /* Last clicked Y coordinate of mouse - button up */
    int getMouseYClickedUp() { return m_mouseYClickedUp; }
    
    /* Current X coordinate of mouse */
    int getCurrentMouseX() { return m_currentMouseX; }
    
    /* Current Y coordinate of mouse */
    int getCurrentMouseY() { return m_currentMouseY; }
    
    /* Current states of buttons */
    int getCurrentButtonStates() { return m_currentButtonStates; }
    
    SDL_Renderer* getRenderer() { return m_renderer; }
    /*
     Function to get the time, in terms of the number of ticks.
     Can be used to decide which animation to display, or whether it's time to do something yet
     */
    inline int getTime() { return m_tick; }
    
    
    /* Return true if it is time to act, false otherwise */
    inline bool timeToAct() { return m_tick >= m_nextTickToActOn; }
    
    /* Specify the next time at which to act - current time plus the delay, in ticks */
    inline void setTimeToAct( int delay ) { m_nextTickToActOn = m_tick + delay; }
    
    /*
     Gets the specified displayable object.
     You may need to dynamic_cast the resulting pointer to the correct type.
     */
    DisplayableObject* getDisplayableObject();
    
    /* Set the exit code - effectively ending the program! */
    void setExitWithCode( int iCode ) { m_exitWithCode = iCode; }
    
    TTF_Font* getFont() { return m_font; }
public:
    //
    // Overridables:
    //
    
    /* Override if necessary - a key was released. See also IsKeyPressed() */
    virtual void keyUp(int keyCode);
    /* Override if necessary - a key was pressed. See also IsKeyPressed() */
    virtual void keyDown(int keyCode);
    
    /* Override if necessary - Mouse event - mouse was moved */
    virtual void mouseMoved( int x, int y );
    /* Override if necessary - Mouse event - mouse button pressed */
    virtual void mouseDown( int button, int x, int y);
    /* Override if necessary - Mouse event - mouse button released */
    virtual void mouseUp( int buton, int x, int y);
    
    /* Override if necessary - handle initialisation */
    virtual int gameInit(void);
    
    /* Override if necessary - handle cleanup - e.g. delete allocated objects */
    virtual void cleanUp(void);
    
    /*
     In here you need to create any movable objects that you wish to use.
     Sub-classes need to implement this function.
     */
    virtual void initialiseObjects();
    
//    /*
//     You probably need to override this:
//     Do any setup of back buffer prior to locking the screen buffer.
//     Basically do the drawing of the background in here and it'll be copied to the screen for you as needed.
//     */
//    virtual void setupBackgroundBuffer();
    
    /*
     You may need to override this.
     The game logic - move things and change the state if necessary.
     Must call Redraw(true/false) if anything changes that shows on the screen.
     */
    virtual void gameAction();
    
    /*
     You probably don't need to change this.
     Render the screen.
     Base version delegates to DrawScreen() or DrawChanges() as appropriate, so you can probably override those instead.
     */
    virtual void gameRender();
    
    /* Tell all displayable objects to update themselves. Calls DoUpdate on each displayable object. */
    virtual void updateAllObjects( int iCurrentTime );
    
public:
    
    /* Screen width */
    int getScreenWidth() { return m_screenWidth; }
    
    /* Screen height */
    int getScreenHeight() { return m_screenHeight; }
    
protected:
    
    /*
     If set to other than -1 the program will exit with this exit code.
     */
    int m_exitWithCode;
    
    /* Array of key status information saying what is currently pressed. See IsKeyPressed(). */
    int *m_keyStatus;
    
    /* Screen width, in pixels */
    int m_screenWidth;
    
    /* Screen height, in pixels */
    int m_screenHeight;
    
    /* Current tick/time */
    int m_tick;
    
//    /* The next tick to act on - to prevent continuous updates */
    int m_nextTickToActOn;
//
    /* Last clicked X coordinate of mouse - button down */
    int m_mouseXClickedDown;
    /* Last clicked Y coordinate of mouse - button down */
    int m_mouseYClickedDown;
    
    /* Last clicked X coordinate of mouse - button up */
    int m_mouseXClickedUp;
    /* Last clicked Y coordinate of mouse - button up */
    int m_mouseYClickedUp;
    
    /* Current X coordinate of mouse */
    int m_currentMouseX;
    
    /* Current Y coordinate of mouse */
    int m_currentMouseY;
    
    /* Current states of buttons */
    int m_currentButtonStates;
    
    SDL_Window* m_window;
    
    SDL_Renderer* m_renderer;
    
    TTF_Font* m_font;

    /* Array of displayable objects - expect it to be modified by sub-class(es) */
    list<DisplayableObject*> m_displayableObjects;
};

#endif /* GameEngine_h */
