//
//  Timer.h
//  GameV2
//
//  Created by PAN on 16/4/30.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#include <SDL2/SDL.h>

class Timer
{
private:
    int startTicks;
    
    int pausedTicks;
    
    //The timer status
    bool paused;
    bool started;
    
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    int getTicks();
    
    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
};

#endif /* Timer_h */
