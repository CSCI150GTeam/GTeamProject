/*
 * GameManager.h - core module
 * Code contributed by: Sammy
 * Header file
 */

#ifndef __GameProject__GameManager__
#define __GameProject__GameManager__

//Includes and namespace
#include <iostream>
#include "ui\UI_Manager.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
using namespace std;

//Game state constants
const int GS_QUIT = -1;
const int GS_MENU = 1;
const int GS_EDITOR = 2;
const int GS_GAME = 3;
const int GS_PAUSE = 4;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    SDL_Surface* getScreen();
private:
    SDL_Surface* screen;
    int gameState;
    int menuState;
    void runMenuLoop(int);
    void runEditorLoop();
    void runGameLoop();
};

#endif