/*
 * UI_Element.h - UI module
 * Code contributed by: Sammy
 * UI_Element is an abstract class (abstract classes are used only for other classes to inherit from) that all UI
 * elements (buttons, switches, etc.) inherit from. It contains variables all elements need, such as (x,y)
 * coordinates, width, and height
 */

#ifndef UI_ELEMENT_H
#define	UI_ELEMENT_H

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "core/Global.h"
using namespace std;

class UI_Element
{
public:
    UI_Element(int iX, int iY, string iSize, string iId)
    {
        this->x = iX;
        this->y = iY;
        this->size = iSize;
        this->identifier = iId;
    }
    ~UI_Element() {}
    virtual string handleEvents() = 0;
    virtual void drawOnScreen() = 0;
protected:
    string identifier, size;
    int x, y, width, height;
    SDL_Surface* loadImage(string filename)
    {
        SDL_Surface* loadedImage = NULL;
        SDL_Surface* optimizedImage = NULL;
        loadedImage = IMG_Load(filename.c_str());
        if( loadedImage != NULL )
        {
            optimizedImage = SDL_DisplayFormat(loadedImage);
            SDL_FreeSurface(loadedImage);
        }
        return optimizedImage;
    }
    void applySurface(int x, int y, SDL_Surface* source)
    {
        SDL_Rect offset;
        offset.x = x;
        offset.y = y;
        SDL_BlitSurface(source,NULL,mainScreenSurface,&offset);
    }
};
#endif