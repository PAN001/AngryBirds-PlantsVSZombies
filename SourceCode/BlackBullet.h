//
//  BlackBullet.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef BlackBullet_h
#define BlackBullet_h

#include "BirdBullet.h"

class BlackBullet:
public BirdBullet
{
public:
    BlackBullet(GameEngine* engine, int targetX, int targetY);
//    ~BlackBullet();
    
};

#endif /* BlackBullet_h */
