//
//  BirdBullet.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "BirdBullet.h"
#include <sstream>

BirdBullet::BirdBullet(GameEngine* engine, int targetX, int targetY)
: m_numOfExplosionPics(6)
, m_curIndexOfExplosionPics(1)
, m_cost(0)
, m_pathOfExplosion("img/bird-explosion/bird-explosion-")
, m_velocity(0)
, m_isDead(false)
, m_isToDestory(false)
, m_angle(0)
, DisplayableObject(engine)
{
    // set the start position
    m_currentScreenX = 780;
    m_currentScreenY = 800;
    
//    m_targetX = targetX - m_drawWidth / 2;
//    m_targetY = targetY - m_drawHeight / 2;
//    
//    // calculate angle
//    // get distance of separate component
//    int dx = m_targetX - m_currentScreenX;
//    int dy = m_targetY - m_currentScreenY;
//    
//    // arch tangent 2 gets the angle from dy and dx
//    double tangle = round(atan2(dy,dx) * 180 / M_PI);
//    m_angle = tangle;
    setVisible(true);
}

BirdBullet::~BirdBullet()
{
    
}

void BirdBullet::draw()
{
    m_texture -> render(m_currentScreenX, m_currentScreenY, m_drawWidth, m_drawHeight);
}

void BirdBullet::doUpdate(int currentTime)
{
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
        else { // in flying
            if((m_currentScreenX < 50 || m_currentScreenY < 0) && !isDead()) { // across the boundary
                m_isToDestory = true;
                setVisible(false);
                return;
            }
            
            m_currentScreenX += cos(m_angle * M_PI / 180.0f) * m_velocity;
            m_currentScreenY += sin(m_angle * M_PI / 180.0f) * m_velocity;
        }
    }
    else {        
    }
}

bool BirdBullet::isDead()
{
    return m_isDead;
}

bool BirdBullet::isToDestory()
{
    return m_isToDestory;
}

void BirdBullet::explode()
{
    m_isDead = true;
}

int BirdBullet::getDamage()
{
    return m_damage;
}

int BirdBullet::getCost()
{
    return m_cost;
}