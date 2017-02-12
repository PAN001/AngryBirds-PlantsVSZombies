//
//  BirdBullet.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef BirdBullet_h
#define BirdBullet_h

#include "DisplayableObject.h"
#include "GameEngine.h"

class BirdBullet:
public DisplayableObject
{
public:
    BirdBullet(GameEngine* engine, int targetX, int targetY);
    ~BirdBullet();
    void draw();
    void doUpdate( int currentTime );
    bool isDead();
    bool isToDestory();
    void explode();
    int getDamage();
    int getCost();
    
protected:
    // attribute
    int m_numOfExplosionPics;
    int m_curIndexOfExplosionPics;
    int m_cost;
    int m_damage;
    string m_pathOfExplosion;
    int m_velocity;
    bool m_isDead;
    bool m_isToDestory;
    int m_targetX;
    int m_targetY;
    int m_angle;
};

#endif /* BirdBullet_h */
