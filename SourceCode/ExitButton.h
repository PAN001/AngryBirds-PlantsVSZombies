//
//  exitButton.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef exitButton_h
#define exitButton_h

#include "GameEngine.h"
#include "Button.h"

class ExitButton:
public Button
{
public:
    ExitButton(GameEngine* engine);
//    ~ExitButton();
    
    void click(int x, int y);
};
#endif /* exitButton_h */
