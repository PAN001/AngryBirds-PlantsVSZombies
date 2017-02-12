//
//  MainFunction.cpp
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include "MyGameEngine.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900



int main(int argc, char *argv[])
{
    int result;
    
    MyGameEngine myGameEngine;
    
    char buf[1024];
    sprintf( buf, "Angry Birds & Plants VS Zombies : Size %d x %d", SCREEN_WIDTH, SCREEN_HEIGHT );
    result = myGameEngine.initialise( buf, SCREEN_WIDTH, SCREEN_HEIGHT, "fonts/Arial.ttf", 24 );
    result = myGameEngine.mainLoop();
    return result;
}