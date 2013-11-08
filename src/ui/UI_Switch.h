/*
 * UI_Switch.h - UI module
 * Code contributed by: Sammy
 * Header file
 */

#ifndef UI_SWITCH_H
#define	UI_SWITCH_H

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "UI_Element.h"
using namespace std;

class UI_Switch : public UI_Element
{
public:
    UI_Switch(int,int,string,string,bool);
    ~UI_Switch();
    string handleEvents();
    void drawOnScreen();
private:
    bool state;
};

#endif