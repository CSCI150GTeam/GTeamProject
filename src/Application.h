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

#include "Global.h"
//#include "Editor.h"
#include "Game.h"
#include "Menu.h"

#include "AudioManager.h"

using namespace std;

class Application
{
public:
    Application();
    ~Application();
    bool initializeApplication();
    void runApplication();
    SDL_Surface* getScreen();
private:
    SDL_Surface* mainScreenSurface;
    int gameState;
    
    //Editor* editor;
    Game* game;
    
    AudioManager* audio;
};

#endif