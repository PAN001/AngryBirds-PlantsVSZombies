//
//  MyTexture.cpp
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//

#include <stdio.h>
#include "MyTexture.h"

MyTexture::MyTexture(SDL_Renderer* renderer)
{
    //Initialize
    m_texture = NULL;
    m_width = 0;
    m_height = 0;
    m_renderer = renderer;
}

MyTexture::~MyTexture()
{
    //Deallocate
    free();
}

bool MyTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();
    
    //The final texture
    SDL_Texture* newTexture = NULL;
    
    //Load image at specified path 将图片装进surface
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        
        //Create texture from surface pixels 从装有图片的surface创建texture
        newTexture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            m_width = loadedSurface->w;
            m_height = loadedSurface->h;
        }
        
        //Get rid of old loaded surface 删掉surface
        SDL_FreeSurface( loadedSurface );
    }
    
    //Return success
    m_texture = newTexture;
    return m_texture != NULL;
}

bool MyTexture::createFontTexture( string text, TTF_Font* font)
{
    //Get rid of preexisting texture
    free();
    
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                                                 text.c_str(),
                                                 color
                                                 );
    
    m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_FreeSurface(surface);
    return true;
}

void MyTexture::free()
{
    //Free texture if it exists
    if( m_texture != NULL )
    {
        SDL_DestroyTexture( m_texture );
        m_texture = NULL;
        m_width = 0;
        m_height = 0;
    }
}

void MyTexture::render( int x, int y, int width, int height, int angle )
{
    if(angle == -1) {
        SDL_Rect renderQuad;
        //Set rendering space and render to screen
        if(width == -1 && height == -1)
            renderQuad = { x, y, m_width, m_height };
        else
            renderQuad = { x, y, width, height };
        //Render to screen
        SDL_RenderCopy( m_renderer, m_texture, NULL, &renderQuad );
    }
    else {
        SDL_Rect renderQuad;
        SDL_Point p;
        if(width == -1 && height == -1) {
            renderQuad = { x, y, m_width, m_height };
            p = {m_width/2, m_height/2};
        }
        else {
            renderQuad = { x, y, width, height };
            p = {width/2, height/2};
        }
        SDL_RenderCopyEx(m_renderer, m_texture, NULL, &renderQuad, angle, &p, SDL_FLIP_NONE);
    }
}