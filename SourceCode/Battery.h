//
//  Battery.h
//  GameV2
//
//  Created by PAN on 16/5/2.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef Battery_h
#define Battery_h

#include "DisplayableObject.h"
#include "GameEngine.h"

class Battery:
public DisplayableObject
{
public:
    Battery(GameEngine* engine, int targetX, int targetY);
//    ~Battery();
    void draw();
    void doUpdate( int currentTime );
    
protected:
    // attribute
    int m_angle;
};


#endif /* Battery_h */
