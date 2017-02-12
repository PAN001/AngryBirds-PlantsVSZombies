//
//  CarZombie.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef CarZombie_h
#define CarZombie_h

#include "Zombie.h"
#include "GameEngine.h"

class CarZombie
: public Zombie
{
public:
    CarZombie(GameEngine* engine);
//    ~FlyZombie();
};

#endif /* CarZombie_h */
