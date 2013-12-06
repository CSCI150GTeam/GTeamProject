/*
 * UI_View.h - UI module
 * Code contributed by: Sammy
 * Header file
 */
#ifndef UI_VIEW_H
#define	UI_VIEW_H

#include <iostream>
#include <vector>
#include "SDL/SDL.h"
using namespace std;

class UI_View
{
public:
    UI_View();
    ~UI_View();
    string handleEvents(SDL_Event);
private:
};

#endif