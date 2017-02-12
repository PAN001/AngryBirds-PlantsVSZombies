//
//  MyGameEngine.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "MyGameEngine.h"
#include "RedBullet.h"
#include "YellowBullet.h"
#include "BlackBullet.h"
#include "FlyZombie.h"
#include "BallonZombie.h"
#include "SmallZombie.h"
#include "EvilZombie.h"
#include "NewspaperZombie.h"
#include "StairsZombie.h"
#include "PolejumpZombie.h"
#include "DivingZombie.h"
#include "CarZombie.h"
#include "RunningZombie.h"
#include "BossZombie.h"

MyGameEngine::MyGameEngine()
: m_curState(initState)
, m_curLevel(easy)
, m_maxNumOfZombies(10)
, m_gameTime(90)
, m_curBullet(red)
, GameEngine()
{
    
}

MyGameEngine::~MyGameEngine()
{
    cleanUp();
}

void MyGameEngine::initialiseObjects()
{
    m_timer = new Timer();
    
    // initialize background textures
    m_easyBg = new MyTexture(m_renderer);
    m_easyBg -> loadFromFile("img/easyBg.png");

    m_mediumBg = new MyTexture(m_renderer);
    m_mediumBg -> loadFromFile("img/mediumBg.png");
    
    m_difficultBg = new MyTexture(m_renderer);
    m_difficultBg -> loadFromFile("img/difficultBg.png");
    
    m_initBg = new MyTexture(m_renderer);
    m_initBg -> loadFromFile("img/initBg.png");
    
    m_levelSelectionBg = new MyTexture(m_renderer);
    m_levelSelectionBg -> loadFromFile("img/levelSelectionBg.png");
    
    m_loseBg = new MyTexture(m_renderer);
    m_loseBg -> loadFromFile("img/loseBg.png");
    
    m_winBg = new MyTexture(m_renderer);
    m_winBg -> loadFromFile("img/winBg.png");
    
    // initialize the utility textures
    m_scorePanel = new MyTexture(m_renderer);
    m_scorePanel -> loadFromFile("img/scorePanel.png");
    
    m_timePanel = new MyTexture(m_renderer);
    m_timePanel -> loadFromFile("img/timePanel.png");
    
    m_pausePanel = new MyTexture(m_renderer);
    m_pausePanel -> loadFromFile("img/pausePanel.png");
    
    // initialize the buttons
    m_exitButton = new ExitButton(this);
    
    
    // initialize the audio
    m_easyBGM = Mix_LoadMUS("audio/easyBGM.mp3");
    if(m_easyBGM == NULL)
        cout << "Failed to load easyBGM effects: " << Mix_GetError() << endl;
    m_mediumBGM = Mix_LoadMUS("audio/mediumBGM.mp3");
    if(m_mediumBGM == NULL)
        cout << "Failed to load mediumBGM effects: " << Mix_GetError() << endl;
    m_difficultBGM = Mix_LoadMUS("audio/difficultBGM.mp3");
    if(m_difficultBGM == NULL)
        cout << "Failed to load difficultBGM effects: " << Mix_GetError() << endl;
    
    m_collisionSound = Mix_LoadWAV("");
    if(m_collisionSound == NULL)
        cout << "Failed to load collisionSound effects: " << Mix_GetError() << endl;
    m_pointSound = Mix_LoadWAV("audio/points.ogg");
    if(m_pointSound == NULL)
        cout << "Failed to load pointSound effects: " << Mix_GetError() << endl;
    m_shootSound = Mix_LoadWAV("audio/shoot.mp3");
    if(m_shootSound == NULL)
        cout << "Failed to load shootSound effects: " << Mix_GetError() << endl;
    
    m_clickSound = Mix_LoadWAV("audio/buttonclick.ogg");
    
    m_startBGM = Mix_LoadMUS("audio/evillaugh.ogg");
    m_loseBGM = Mix_LoadMUS("audio/loseMusic.ogg");
    m_winBGM = Mix_LoadMUS("audio/winMusic.ogg");
    m_initBGM = Mix_LoadMUS("audio/initMusic.ogg");
    
    
    m_curState = initState;
    m_curLevel = easy;
    m_curScore = 0;
    m_curScore = 0;
    m_highestScore = 0;
    getHighScore();
    
    // initialize the text
    stringstream ss;
    ss << m_curScore;
    string scoreStr = ss.str();
    m_scoreText = new Text(this, scoreStr.c_str(), 80, 60, 1250, 60);
    m_scoreText -> setText(scoreStr.c_str());

    
    m_timeText = new Text(this, "120", 130, 80, 720, 50);
    
    ss << m_highestScore;
    string highScoreStr = ss.str();
    m_highestScoreText = new Text(this, highScoreStr.c_str(), 72, 52, 1240, 72);
    m_highestScoreText -> setText(highScoreStr.c_str());
    
    // initialize the pea shooter
    peaShooter = new Battery(this, 675, 700);
    
//    Mix_PlayMusic(m_initBGM, -1);
    renderStaticBackground();
}


void MyGameEngine::keyDown(int keyCode)
{
    if(m_curState == initState && (keyCode != SDLK_ESCAPE)) {
        // Clear screen
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);
        m_curState = levelSelectionState;
        renderStaticBackground();
        return;
    }
    else {
        switch(keyCode)
        {
            case SDLK_ESCAPE:
                setExitWithCode(0);
                break;
                
                //        case SDLK_UP:
                //            cout << "keyup" << endl;
                //            break;
                //
                //        case SDLK_DOWN:
                //            cout << "keydown" << endl;
                //            break;
                
            case SDLK_a:
                changeBullet(-1);
                break;
                
            case SDLK_d:
                changeBullet(1);
                break;
                
            case SDLK_LEFT:
                changeBullet(-1);
                break;
                
            case SDLK_RIGHT:
                changeBullet(1);
                break;
                
            case SDLK_SPACE:
                if(m_curState == mainState) fire();
                break;
                
            case SDLK_p:
                if(m_curState == mainState) {
                    m_curState = pauseState;
                    m_timer -> pause();
                    renderStaticBackground();
                    break;
                }
                else if(m_curState == pauseState) {
                    m_curState = mainState;
                    m_timer -> unpause();
                    break;
                }
                
            default:
                break;
        }
    }

}

void MyGameEngine::mouseDown( int button, int x, int y)
{
    switch (m_curState) {
        case initState:
            Mix_PlayChannel(-1, m_clickSound, 0);
            
            // Clear screen
            SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(m_renderer);
            
            m_curState = levelSelectionState;
            renderStaticBackground();
            
            break;
            
        case levelSelectionState:
        {
            Mix_PlayChannel(-1, m_clickSound, 0);
            getHighScore();
            stringstream ss;
            
            if(isInButton(35, 773, 97, 65)) {
                SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(m_renderer);
                m_curState = initState;
                renderStaticBackground();
            }
            if(isInButton(40, 50, 450, 725)) {
                m_curState = mainState;
                m_curLevel = easy;
                m_gameTime = 90;
                m_maxNumOfZombies = 10;
                m_targetScore = 20000;
                m_curScore = 0;
                
                addZombies();
                Mix_PlayMusic(m_startBGM, 1);
                m_timer -> start();
            }
            else if(isInButton(575, 50, 450, 800)) {
                m_curState = mainState;
                m_curLevel = medium;
                m_gameTime = 75;
                m_maxNumOfZombies = 15;
                m_targetScore = 35000;
                m_curScore = 0;
                
                addZombies();
                Mix_PlayMusic(m_startBGM, 1);
                m_timer -> start();
            }
            else if(isInButton(1020, 50, 450, 800)) {
                m_curState = mainState;
                m_curLevel = difficult;
                m_gameTime = 60;
                m_maxNumOfZombies = 20;
                m_targetScore = 100000;
                m_curScore = 0;
                
                addZombies();
                Mix_PlayMusic(m_startBGM, 1);
                m_timer -> start();
            }
            break;
        }
            
        case mainState:
            fire();
            break;
            
        case pauseState:
            Mix_PlayChannel(-1, m_clickSound, 0);
            if(isInButton(610, 280, 375, 90)) {
                m_timer -> unpause();
                m_curState = mainState;
            }
            else if(isInButton(610, 435, 375, 90)) {
                m_curState = initState;
                
                destroyOldObjects();
                SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(m_renderer);
                renderStaticBackground();
            }
            else if(isInButton(610, 595, 375, 90)) {
                setExitWithCode(0);
            }
            break;
            
        case loseState:
            Mix_PlayChannel(-1, m_clickSound, 0);
            if(isInButton(694, 773, 202, 68))
            {
                SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(m_renderer);
                m_curState = initState;
                renderStaticBackground();
            }
            break;
            
        case winState:
            Mix_PlayChannel(-1, m_clickSound, 0);
            if(isInButton(694, 773, 202, 68))
            {
                SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(m_renderer);
                m_curState = initState;
                renderStaticBackground();
            }
            break;
            
        default:
            break;
    }
}

void MyGameEngine::addZombies()
{
    int i;
    for(i = m_zombies.size();i < m_maxNumOfZombies;i++) {
        m_zombies.push_back(zombieFactory());
    }
}

Zombie* MyGameEngine::zombieFactory()
{
    int randNum;
    Zombie* newZombie;
    switch (m_curLevel) {
        case easy:
            randNum = rand() % 4;
            break;
        
        case medium:
            randNum = rand() % 8;
            break;
            
        case difficult:
            randNum = rand() % 11;
            break;
            
        default:
            randNum = 0;
            break;
    }
    
    switch (randNum) {
        case 0:
            newZombie = new FlyZombie(this);
            break;
            
        case 1:
            newZombie = new BallonZombie(this);
            break;
            
        case 2:
            newZombie = new SmallZombie(this);
            break;
            
        case 3:
            newZombie = new EvilZombie(this);
            break;
            
        case 4:
            newZombie = new NewspaperZombie(this);
            break;
            
        case 5:
            newZombie = new PolejumpZombie(this);
            break;
            
        case 6:
            newZombie = new DivingZombie(this);
            break;
            
        case 7:
            newZombie = new BallonZombie(this);
            break;
            
        case 8:
            newZombie = new CarZombie(this);
            break;
            
        case 9:
            newZombie = new RunningZombie(this);
            break;
            
        case 10:
            newZombie = new BossZombie(this);
            break;
            
            
        default:
            newZombie = new BallonZombie(this);
            break;
    }
    
    return newZombie;
}

void MyGameEngine::fire()
{
    Mix_PlayChannel(-1, m_shootSound, 0);
    BirdBullet* newBullet;
    if(m_curScore <= 0) {
        newBullet = new RedBullet(this, m_currentMouseX, m_currentMouseY);
    }
    else {
        switch (m_curBullet) {
            case red:
                newBullet = new RedBullet(this, m_currentMouseX, m_currentMouseY);
                break;
            case yellow: {
                newBullet = new YellowBullet(this, m_currentMouseX, m_currentMouseY);
                BirdBullet* newBullet2 = new YellowBullet(this, m_currentMouseX - 150, m_currentMouseY);
                BirdBullet* newBullet3 = new YellowBullet(this, m_currentMouseX - 300, m_currentMouseY);
                BirdBullet* newBullet4 = new YellowBullet(this, m_currentMouseX + 150, m_currentMouseY);
                BirdBullet* newBullet5 = new YellowBullet(this, m_currentMouseX + 300, m_currentMouseY);
                m_bullets.push_back(newBullet2);
                m_bullets.push_back(newBullet3);
                m_bullets.push_back(newBullet4);
                m_bullets.push_back(newBullet5);
                m_curScore -= (newBullet -> getCost()) * 4;
                break;
            }
            case black:
                newBullet = new BlackBullet(this, m_currentMouseX, m_currentMouseY);
                break;
            default:
                break;
        }
    }
    
    m_bullets.push_back(newBullet);
//    m_displayableObjects.push_back(newBullet);
    m_curScore -= newBullet -> getCost();
}

bool MyGameEngine::isInButton(int x, int y, int width, int height)
{
    if((m_currentMouseX <= x + width) && (m_currentMouseX >= x) && (m_currentMouseY <= y + height) && (m_currentMouseY >= y))
        return true;
    else
        return false;
}

void MyGameEngine::gameAction(){
    // If too early to act then do nothing
    if (!timeToAct())
        return;
    
    setTimeToAct(40); // act every 5 ticks
    
    switch (m_curState) {
        case initState:
            break;
            
        case levelSelectionState:
            break;
            
        case mainState:
            updateTime();
            updateScore();
            updateAllObjects(-1);
            checkCollision();
            checkWin();
            addZombies();
            break;
            
        default:
            break;
    }
    
}

void MyGameEngine::checkWin()
{
    int passedTime = (m_timer -> getTicks()) / 1000.f;
    if(m_curScore <= m_targetScore && (m_gameTime - passedTime) <= 0) { // lose
        m_curState = loseState;
        destroyOldObjects();
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);
        renderStaticBackground();
    }
    else if(m_curScore >= m_targetScore && (m_gameTime - passedTime) == 0) {// win
        m_curState = winState;
        storeHighScore();
        destroyOldObjects();
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);
        renderStaticBackground();
    }

}

void MyGameEngine::updateTime()
{
    stringstream ss;
    ss << (m_gameTime - (m_timer -> getTicks()) / 1000.f);
    string timeStr = ss.str();
    m_timeText -> setText(timeStr.c_str());
    m_timeText -> doUpdate(-1);
}

void MyGameEngine::updateScore()
{
    stringstream ss;
    ss << m_curScore;
    string scoreStr = ss.str();
    m_scoreText -> setText(scoreStr.c_str());
    m_scoreText -> doUpdate(-1);

}


void MyGameEngine::updateAllObjects(int currentTime)
{
    updateBullets();
    updateZombies();
    peaShooter -> doUpdate(-1);
}

void MyGameEngine::destroyOldObjects()
{
    m_curScore = 0;
    m_timer -> stop();
    
    for (list<Zombie*>::iterator it = m_zombies.begin(); it != m_zombies.end(); ++it)
    {
        delete (*it);
        (*it) = NULL;
        m_zombies.erase(it);
        it--;
    }
    
    for (list<BirdBullet*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    {
        delete (*it);
        (*it) = NULL;
        m_bullets.erase(it);
        it--;
    }
    
//    m_displayableObjects.clear();
    m_zombies.clear();
    m_bullets.clear();
}

void MyGameEngine::updateBullets()
{
    // update bullets
    for (list<BirdBullet*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    {
        BirdBullet* curBullet = *it;
        if(curBullet -> isToDestory()) { // need to be drstroyed
            delete curBullet;
            (*it) = NULL;
            it = m_bullets.erase(it);
            it--;
        }
        else {
            curBullet -> doUpdate(-1);
        }
    }
}

void MyGameEngine::updateZombies()
{
    // update zombies
    for (list<Zombie*>::iterator it = m_zombies.begin(); it != m_zombies.end(); ++it)
    {
        Zombie* curZombie = *it;
        if(curZombie -> isToDestory()) { // need to be drstroyed
            delete curZombie;
            (*it) = NULL;
            it = m_zombies.erase(it);
            it--;
        }
        else {
            curZombie -> doUpdate(-1);
        }
    }
}

// Check the collision between the bullet and zombie.
// Explode the collided bullet and give damage to the zombie
// If the zombie is dead, update the score
void MyGameEngine::checkCollision()
{
    for (list<BirdBullet*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    {
        BirdBullet* curBullet = *it;
        if((curBullet != NULL) && !(curBullet -> isDead())) {
            for (list<Zombie*>::iterator it2 = m_zombies.begin(); it2 != m_zombies.end(); ++it2)
            {
                Zombie* curZombie = *it2;
                if(!(curZombie -> isDead())) {
                    if(isCollided(curZombie, curBullet)) {
                        curZombie -> takeDamage(curBullet -> getDamage());

                        curBullet -> explode();
                        Mix_PlayChannel(-1, m_collisionSound, 0); // emit the collision sound
                        if(curZombie -> isDead()) { // if the zombie is killed
                            m_curScore += curZombie -> getPoint();
                            Mix_PlayChannel(-1, m_pointSound, 0); // emit the reward sound
                        }
                    }
                }
            }
        }
    }
}

bool MyGameEngine::isCollided(Zombie* a, BirdBullet* b)
{
    bool collided = true;
    
    // calculate a rect;
    int aleft = a -> getCurrentX() ;
    int aright = a -> getCurrentX() + a -> getWidth();
    int atop = a -> getCurrentY();
    int abottom = a -> getCurrentY() + a -> getHeight();
    
    // calculate b rect;
    int bleft = b -> getCurrentX();
    int bright = b -> getCurrentX() + b -> getWidth();
    int btop = b -> getCurrentY();
    int bbottom = b -> getCurrentY() + b -> getHeight();
    
    if(aleft >= bright) collided = false;
    if(abottom <= btop) collided = false;
    if(aright <= bleft) collided = false;
    if(atop >= bbottom) collided = false;
    
    return collided;
}

void MyGameEngine::renderStaticBackground()
{
    switch (m_curState) {
        case initState:
            Mix_PlayMusic(m_initBGM, -1);
            m_initBg -> render(0, 0, m_screenWidth, m_screenHeight);
            SDL_RenderPresent(m_renderer);
            break;
            
        case levelSelectionState:
        {
            m_levelSelectionBg -> render(0, 0, m_screenWidth, m_screenHeight);
            getHighScore();
            stringstream ss;
            ss << m_highestScore;
            string highScoreStr = ss.str();
            m_highestScoreText -> setText(highScoreStr.c_str());
            m_highestScoreText -> doUpdate(-1);
            m_highestScoreText -> draw();
            
            SDL_RenderPresent(m_renderer);
            break;
        }
            
        case mainState:
            switch (m_curLevel) {
                case easy:
                    if( Mix_PlayingMusic() == 0 )
                    {
                        Mix_PlayMusic(m_easyBGM, -1); //Play the music
                    }
                    m_easyBg -> render(0, 0, m_screenWidth, m_screenHeight);
                    break;
                    
                case medium:
                    if( Mix_PlayingMusic() == 0 )
                    {
                        Mix_PlayMusic(m_mediumBGM, -1); //Play the music
                    }
                    m_mediumBg -> render(0, 0, m_screenWidth, m_screenHeight);
                    break;
                    
                case difficult:
                    if( Mix_PlayingMusic() == 0 )
                    {
                        Mix_PlayMusic(m_difficultBGM, -1); //Play the music
                    }
                    m_difficultBg -> render(0, 0, m_screenWidth, m_screenHeight);
                    break;
                    
                default:
                    break;
            }
//            SDL_RenderPresent(m_renderer);
            break;
            
        case pauseState:
            m_pausePanel -> render(360, 110, 880, 680);
            SDL_RenderPresent(m_renderer);
            break;
            
        case loseState:
            Mix_PlayMusic(m_loseBGM, -1);
            m_loseBg -> render(0, 0, m_screenWidth, m_screenHeight);
            SDL_RenderPresent(m_renderer);
            break;
            
        case winState:
            Mix_PlayMusic(m_winBGM, -1);
            m_winBg -> render(0, 0, m_screenWidth, m_screenHeight);
            SDL_RenderPresent(m_renderer);
            break;
            
        default:
            break;
    }
}

void MyGameEngine::gameRender()
{
    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);
    
    switch (m_curState) {
        case initState:
            break;
            
        case levelSelectionState:
            break;
            
        case mainState:
            renderStaticBackground();
            renderZombies();
            renderBullets();
            renderTime();
            renderScore();
            peaShooter -> draw();
            SDL_RenderPresent(m_renderer);
            break;
        
        case pauseState:
            break;
            
        case loseState:
//            m_loseBg -> render(0, 0, m_screenWidth, m_screenHeight);
            break;
            
        case winState:
//            m_winBg -> render(0, 0, m_screenWidth, m_screenHeight);
            break;
            
        default:
            break;
    }
    
}



void MyGameEngine::renderZombies()
{
    for (list<Zombie*>::iterator it = m_zombies.begin(); it != m_zombies.end(); ++it)
    {
        Zombie* curZombie = *it;
        curZombie -> draw();
    }
}

void MyGameEngine::renderBullets()
{
    for (list<BirdBullet*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    {
        BirdBullet* curBullet = *it;
        curBullet -> draw();
    }
}

void MyGameEngine::renderTime()
{
    m_timePanel -> render(680, 40, 240, 100);
    m_timeText -> draw();
}

void MyGameEngine::renderScore()
{
    m_scorePanel-> render(1100, 10, 500, 150);
    m_scoreText -> draw();
}

void MyGameEngine::changeBullet(int direction)
{
    if(direction == 1) { // left change
        switch (m_curBullet) {
            case red:
                m_curBullet = black;
                break;
            case yellow:
                m_curBullet = red;
                break;
            case black:
                m_curBullet = yellow;
                break;
            default:
                break;
        }
    }
    else { // right change
        switch (m_curBullet) {
            case red:
                m_curBullet = yellow;
                break;
            case yellow:
                m_curBullet = black;
                break;
            case black:
                m_curBullet = red;
                break;
            default:
                break;
        }
    }
}

void MyGameEngine::storeHighScore()
{
    // Add a score to a file if it's higher than in the file

    getHighScore();
    printf("read sciore is %d\n", m_highestScore);
    if (m_curScore > m_highestScore)
    {
        ofstream scoresFile("highestScore.txt");
        if (scoresFile.is_open())
        {
            scoresFile << m_curScore;
            scoresFile.close();
        }
        else cout << "Unable to open file";
    }
}

void MyGameEngine::getHighScore()
{
    string highestScore;
    
    // read the highest score from the text
    ifstream scoresFile("highestScore.txt");
    printf("high score is %d\n", m_highestScore);
    if (scoresFile.is_open())
    {
        while (getline(scoresFile, highestScore))
        {
            stringstream(highestScore) >> m_highestScore;
        }
        scoresFile.close();
    }
    else 
    {
        m_highestScore = 0;
    }
}

void MyGameEngine::cleanUp(void)
{
    destroyOldObjects();
    
    // destroy
    delete m_scoreText;
    m_scoreText = NULL;
    delete m_timeText;
    m_timeText = NULL;
    delete m_highestScoreText;
    m_highestScoreText = NULL;
    
    // background image
    m_easyBg -> free();
    m_mediumBg -> free();
    m_difficultBg -> free();
    m_initBg -> free();
    m_levelSelectionBg -> free();
    m_loseBg -> free();
    m_winBg -> free();
    
    // button
    delete m_exitButton;
    m_exitButton = NULL;
    
    // audio
    Mix_FreeMusic(m_easyBGM);
    m_easyBGM = NULL;
    Mix_FreeMusic(m_mediumBGM);
    m_mediumBGM = NULL;
    Mix_FreeMusic(m_difficultBGM);
    m_difficultBGM = NULL;
    
    Mix_FreeChunk(m_collisionSound);
    m_collisionSound = NULL;
    Mix_FreeChunk(m_pointSound);
    m_pointSound = NULL;
    Mix_FreeChunk(m_shootSound);
    m_shootSound = NULL;
    Mix_FreeChunk(m_clickSound);
    m_clickSound = NULL;
    
    Mix_FreeMusic(m_startBGM);
    m_startBGM = NULL;
    Mix_FreeMusic(m_loseBGM);
    m_loseBGM = NULL;
    Mix_FreeMusic(m_winBGM);
    m_winBGM = NULL;
    Mix_FreeMusic(m_initBGM);
    m_initBGM = NULL;
    
    // textures
//    m_pausePanel -> free();
    m_pausePanel = NULL;
//    m_scorePanel -> free();
    m_scorePanel = NULL;
//    m_timePanel -> free();
    m_timePanel = NULL;
    
    // battery
    delete peaShooter;
    peaShooter = NULL;
    
    Mix_Quit();
    TTF_Quit();
    
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    
    SDL_Quit();
}

