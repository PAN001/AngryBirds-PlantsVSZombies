//
//  GameEngine.cpp
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "GameEngine.h"
/*
 Constructor.
 */
GameEngine::GameEngine()
: m_keyStatus(NULL)
, m_exitWithCode(-1)
, m_tick(0)
, m_currentMouseX(0)
, m_currentMouseY(0)
, m_currentButtonStates(0)
{
}

/*
 Destructor - destroys moving objects
 */
GameEngine::~GameEngine(void)
{
    destroyOldObjects();
}

/*
 Initialise SDL and create a window of the correct size.
 */
int GameEngine::initialise( char* strCaption, int screenWidth, int screenHeight, char* ontName, int fontSize )
{
    m_screenWidth = screenWidth;
    m_screenHeight = screenHeight;
    
    // Initialize SDL's subsystems
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    //Create window
    m_window = SDL_CreateWindow( "Angry Birds & Plants VS Zombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
    if( m_window == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create vsynced renderer for window
        m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        if( m_renderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        }
    }

    
    // Register SDL_Quit to be called at exit; makes sure things are
    // cleaned up when we quit.
    atexit(SDL_Quit);
    
    // Initialize font
    TTF_Init();
    atexit(TTF_Quit);
    
    m_font = TTF_OpenFont("fonts/Arial.ttf", 12);
    if (m_font == NULL)
    {
        cout << "TTF_OpenFont() failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    }
    
    // Call method to allow custom sub-class initialiation.
    gameInit();
    
    return 0; // success
}

/*
 Initialise game-specific things.
 Base class just calls InitialiseObjects() to create the moving objects
 */
int GameEngine::gameInit()
{
    // Create the moving objects
    initialiseObjects();

    return 0; // success
}

/*
 In here you need to create any movable objects that you wish to use.
 Sub-classes need to implement this function.
 */
void GameEngine::initialiseObjects()
{
    // Destroy any existing objects
    destroyOldObjects();
}

void GameEngine::destroyOldObjects()
{
    for (list<DisplayableObject*>::iterator it = m_displayableObjects.begin(); it != m_displayableObjects.end(); ++it)
    {
        delete (*it);
        (*it) = NULL;
        m_displayableObjects.erase(it);
        it--;
    }
}

/*
 Main loop.
 1) Stores key presses, and calls call-back functions for press/release if necessary.
 2) Calls GameAction
 3) Calls GameRender
 */
int GameEngine::mainLoop(void)
{
    SDL_Event event;
    int keyCode;
    
    // Main loop: loop until told not to
    while (m_exitWithCode==-1)
    {
        // Render stuff
        m_tick = SDL_GetTicks();
        
        // Poll for events, and handle the ones we care about.
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    keyCode = event.key.keysym.sym;
                    keyDown(keyCode);
                    break;
                    
                case SDL_KEYUP:
                    keyCode = event.key.keysym.sym;
                    keyUp(keyCode);
                    break;
                    
                case SDL_MOUSEMOTION:
                    m_currentMouseX = event.motion.x;
                    m_currentMouseY = event.motion.y;
                    mouseMoved( event.motion.x, event.motion.y );
                    break;
                    
                case SDL_MOUSEBUTTONDOWN:
                    m_mouseXClickedDown = event.button.x;
                    m_mouseYClickedDown = event.button.y;
                    mouseDown( event.button.button, event.button.x, event.button.y );
                    break;
                    
                case SDL_MOUSEBUTTONUP:
                    m_mouseXClickedUp = event.button.x;
                    m_mouseYClickedUp = event.button.y;
                    mouseUp( event.button.button, event.button.x, event.button.y );
                    break;
                    
                case SDL_QUIT:
                    return 0;
            }
        }
        
        // Do any updates for movements
        gameAction();
        
        // Render the screen
        gameRender();
    }
    
    cleanUp();
    return 0;
}


void GameEngine::gameAction()
{
    // If too early to act then do nothing
    if ( !timeToAct() )
        return;
    
    // Don't act for another 10 ticks
    setTimeToAct( 10 );
    
    updateAllObjects( getTime() );
}


void GameEngine::gameRender(void)
{
    
}

/* Tell all displayable objects to update themselves. Calls DoUpdate on each displayable object. */
void GameEngine::updateAllObjects( int currentTime )
{
}

void GameEngine::cleanUp(void)
{
}

// Handle a key being released
void GameEngine::keyUp(int keyCode)
{
}

// Handle a key being pressed
void GameEngine::keyDown(int keyCode)
{
}

// Handle the fact that a mouse has moved
// Note: these coordinates are automatically stored for you and there are methods to retrieve them if you wish
void GameEngine::mouseMoved( int x, int y )
{
}

// Handle the fact that a mouse button has been pressed
// Note: these coordinates are automatically stored for you and there are methods to retrieve them if you wish
void GameEngine::mouseDown( int button, int x, int y )
{
    //printf( "GameEngine::MouseDown %d, %d, %d\n", iButton, iX, iY );
}

// Handle the fact that a mouse button has been released
// Note: these coordinates are automatically stored for you and there are methods to retrieve them if you wish
void GameEngine::mouseUp( int button, int x, int y )
{
    //printf( "GameEngine::MouseUp %d, %d, %d\n", iButton, iX, iY );
}
