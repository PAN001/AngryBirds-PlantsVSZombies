//
//  Button.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef Button_h
#define Button_h

#include "DisplayableObject.h"
#include "GameEngine.h"

class Button:
public DisplayableObject
{
public:
    Button(GameEngine* engine);
    ~Button();
    void draw();
    void doUpdate( int currentTime );
    virtual void click(int x, int y);
};
#endif /* Button_h */
