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

#include "AudioManager.h"
#include "Editor.h"
#include "Game.h"
#include "Global.h"
#include "Menu.h"

using namespace std;

class Application
{
public:
    Application();
    ~Application();
    bool initializeApplication();
    void runApplication();
private:
    int gameState;
    
    AudioManager* audio;
    Editor* editor;
    Menu* menu;
    Game* game;
};

#endif