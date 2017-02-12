//
//  YellowBullet.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef YellowBullet_h
#define YellowBullet_h

#include "BirdBullet.h"

class YellowBullet:
public BirdBullet
{
public:
    YellowBullet(GameEngine* engine, int targetX, int targetY);
//    ~YellowBullet();
    
};


#endif /* YellowBullet_h */
