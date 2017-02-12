//
//  Zombie.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "Zombie.h"
#include <sstream>

Zombie::Zombie(GameEngine* engine)
: m_numOfPics(7)
, m_numOfExplosionPics(7)
, m_HP(0)
, m_xVelocity(0)
, m_isDead(false)
, m_isToDestory(false)
, m_point(0)
, m_pathOfExplosion("img/zombieExplosion/zombieExplosion-")
, m_curIndexOfPics(1)
, m_curIndexOfExplosionPics(1)
, DisplayableObject(engine)
{
    setRandomStartPos();
    setVisible(true);
}

Zombie::~Zombie()
{
    
    
}

void Zombie::draw()
{
    m_texture -> render(m_currentScreenX, m_currentScreenY, m_drawWidth, m_drawHeight);
}

void Zombie::doUpdate(int currentTime)
{
//    printf("zombie updated\n");
    if(!isToDestory()) {
        if(isDead()) { // in explosion
            if(m_curIndexOfExplosionPics >= m_numOfExplosionPics) {
                m_isToDestory = true;
                setVisible(false);
                return;
            }
            else {
                m_curIndexOfExplosionPics++;
                stringstream ss;
                ss<<m_curIndexOfExplosionPics;
                string s = ss.str();
                m_texture -> loadFromFile(m_pathOfExplosion + s + ".gif");
            }
        }
        else {
            if(m_currentScreenX < 50 && !isDead()) { // across the boundary
                m_isToDestory = true;
                setVisible(false);
                return;
            }
            if(m_curIndexOfPics > m_numOfPics) {
                m_curIndexOfPics = m_curIndexOfPics % (m_numOfPics) + 1;
            }
            m_currentScreenX += m_xVelocity;
            
            stringstream ss;
            ss<<m_curIndexOfPics;
            string s = ss.str();
            m_texture -> loadFromFile(m_path + s + ".gif");
            
            m_curIndexOfPics++;
        }
    }
    else {
//        printf("should be destroyed\n");
    }
}

bool Zombie::isDead()
{
    return m_isDead;
}

bool Zombie::isToDestory()
{
    return m_isToDestory;
}

void Zombie::die()
{
    m_isDead = true;
}

void Zombie::setRandomStartPos()
{
    int randY = rand() % (m_engine -> getScreenHeight() - 300) + 100;
    m_currentScreenX = m_engine -> getScreenWidth() - 300;
    m_currentScreenY = randY;
}

void Zombie::takeDamage(int damage) {
    m_HP -= damage;
    if(m_HP <= 0) {
        m_isDead = true;
    }
}

int Zombie::getPoint()
{
    return m_point;
}