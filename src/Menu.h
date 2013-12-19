/* 
 * File:   Menu.h
 * Author: mcnightthao
 *
 * Created on December 9, 2013, 1:22 PM
 */

#ifndef MENU_H
#define	MENU_H

#include <string>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "Global.h"
#include "Utility.h"
#include "Grid.h"

class Menu
{
public:
    Menu();
    ~Menu();
    int runMenu();
    void drawScreen(int);
private:
    int currentView; //keeps track of what screen you're on
    int handleEvents(int, int);
    bool shouldDrawScreen;
    
    SDL_Surface* IMG_MENU1;
    SDL_Surface* IMG_MENU2;
    SDL_Surface* IMG_MENU3;
    SDL_Surface* IMG_MENU5;
    
    SDL_Surface* IMG_HIGHLIGHT;
};

#endif