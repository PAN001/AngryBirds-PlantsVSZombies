//
//  RedBullet.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef RedBullet_h
#define RedBullet_h

#include "BirdBullet.h"

class RedBullet:
public BirdBullet
{
public:
    RedBullet(GameEngine* engine, int targetX, int targetY);
//    ~RedBullet();
};

#endif /* RedBullet_h */
