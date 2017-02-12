//
//  Text.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef Text_h
#define Text_h

#include "DisplayableObject.h"
#include "GameEngine.h"

class Text
: public DisplayableObject
{
public:
    Text(GameEngine* engine, string str, int width, int height, int x, int y);
    void doUpdate( int currentTime );
    
    void setText(string newText);
    
private:
    string m_text;
};

#endif /* Text_h */
