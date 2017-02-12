//
//  MyGameEngine.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef MyGameEngine_h
#define MyGameEngine_h

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "GameEngine.h"
#include "Timer.h"
#include "Zombie.h"
#include "BirdBullet.h"
#include "Button.h"
#include "ExitButton.h"
#include "Text.h"
#include "Battery.h"

using namespace std;

class MyGameEngine:
public GameEngine
{
public:
    // overridden virtual functions
    MyGameEngine();
    ~MyGameEngine();
//    void setupBackgroundBuffer();
    void initialiseObjects();
    void keyDown(int keyCode);
    void mouseDown( int button, int x, int y);
    void cleanUp(void);

    void gameAction();
    void gameRender();
    void updateAllObjects( int iCurrentTime );
    
public:
    void renderStaticBackground();
    void addZombies();
    void updateZombies();
    void updateBullets();
    void renderZombies();
    void renderBullets();
    void updateTime();
    void updateScore();
    void renderTime();
    void renderScore();
    void checkWin();
    void destroyOldObjects();
    void storeHighScore();
    void getHighScore();
    
private:
    void fire();
    void changeBullet(int direction);
    bool isInButton(int x, int y, int width, int height);
    void checkCollision();
    bool isCollided(Zombie* a, BirdBullet* b);
    Zombie* zombieFactory();
    
    
    // current info
    State m_curState;
    Level m_curLevel;
    int m_maxNumOfZombies;
    int m_gameTime;
    Timer* m_timer;
    
    // score part
    int m_curScore;
    int m_targetScore;
    int m_highestScore;
    
    
    // text
    Text* m_scoreText;
    Text* m_timeText;
    Text* m_highestScoreText;
    
    // background image
    MyTexture* m_easyBg;
    MyTexture* m_mediumBg;
    MyTexture* m_difficultBg;
    MyTexture* m_initBg;
    MyTexture* m_levelSelectionBg;
    MyTexture* m_loseBg;
    MyTexture* m_winBg;
    
    // bird bullets
    enum Bullet {red, yellow, black};
    Bullet m_curBullet;
    
    // button
    ExitButton* m_exitButton;
    
    // audio
    Mix_Music* m_easyBGM;
    Mix_Music* m_mediumBGM;
    Mix_Music* m_difficultBGM;
    
    Mix_Chunk* m_collisionSound;
    Mix_Chunk* m_pointSound;
    Mix_Chunk* m_shootSound;
    Mix_Chunk* m_clickSound;
    
    Mix_Music* m_startBGM;
    Mix_Music* m_loseBGM;
    Mix_Music* m_winBGM;
    Mix_Music* m_initBGM;
    
    list<BirdBullet*> m_bullets;
    list<Zombie*> m_zombies;
    
    // textures
    MyTexture* m_pausePanel;
    MyTexture* m_scorePanel;
    MyTexture* m_timePanel;
    
    // battery
    Battery* peaShooter;
    
    
};
#endif /* MyGameEngine_h */
