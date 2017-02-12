//
//  MyTexture.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#ifndef MyTexture_h
#define MyTexture_h

#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

using namespace std;

class MyTexture
{
public:
    //Initializes variables
    MyTexture(SDL_Renderer* renderer);
    
    //Deallocates memory
    ~MyTexture();
    
    //Loads image at specified path
    bool loadFromFile( string path );
    
    bool createFontTexture( string text, TTF_Font* font);
    
    //Deallocates texture
    void free();
    
    //Renders texture at given point
    void render( int x, int y, int width, int height, int angle = -1);
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* m_texture;
    SDL_Renderer* m_renderer;
    
    //Image dimensions
    int m_width;
    int m_height;
};
#endif /* MyTexture_h */
