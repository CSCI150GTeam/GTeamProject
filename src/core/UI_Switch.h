#ifndef UI_SWITCH_H
#define	UI_SWITCH_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <string>
using namespace std;

class UI_Switch
{
public:
    UI_Switch(SDL_Surface*);
    ~UI_Switch();
    void drawOnScreen(int,int);
    void checkMouseClick(int,int);
private:
    int x;
    int y;
    int width;
    int height;
    bool state;
    SDL_Surface* screen;
    SDL_Surface* loadImage(string);
    void applySurface(int,int,SDL_Surface*,SDL_Surface*);
};

#endif