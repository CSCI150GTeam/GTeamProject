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

using namespace std;

class Menu {
public:
    Menu();
    ~Menu();
    int runMenu();
    void drawScreen(int);
    
    void Menu_applySurface(int x, int y, SDL_Surface* source); 
    SDL_Surface *load_image( std::string filename );
private:
    int currentView; //keeps track of what screen you're on
    int handleEvents(int,int);
    
    SDL_Surface* menuScreen_2;
    SDL_Surface* menuScreen_3;
    SDL_Surface* menuScreen_5;
};

#endif