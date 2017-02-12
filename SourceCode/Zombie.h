//
//  Zombie.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef Zombie_h
#define Zombie_h

#include "DisplayableObject.h"
#include "GameEngine.h"

class Zombie:
public DisplayableObject
{
public:
    Zombie(GameEngine* engine);
    ~Zombie(void);
    void draw();
    void doUpdate( int currentTime );
    bool isDead();
    bool isToDestory();
    void die();
    void setRandomStartPos();
    void takeDamage(int damage);
    int getPoint();
    
protected:
    // attribute
    int m_numOfPics;
    int m_numOfExplosionPics;
    int m_curIndexOfPics;
    int m_curIndexOfExplosionPics;
    int m_HP;
    int m_point;

    string m_pathOfExplosion;
    int m_xVelocity;
    bool m_isDead;
    bool m_isToDestory;
};
    
#endif /* Zombie_h */
