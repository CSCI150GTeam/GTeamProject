/*
 * Application.h - core module
 * Code contributed by: Sammy
 * Header file
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "Editor.h"
#include "Game.h"
#include "Menu.h"

#include "Global.h"

using namespace std;

class Application
{
public:
    Application();
    ~Application();
    
    void runApplication();
private:
    int gameState;
    Editor* editor;
    Menu* menu;
    Game* game;
};

#endif