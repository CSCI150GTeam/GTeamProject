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

#include "Editor.h"
#include "Game.h"

#include "AudioManager.h"

using namespace std;

const int GS_EXIT = -1;
const int GS_MENU = 1;
const int GS_EDIT = 2;
const int GS_GAME = 3;

class Application
{
public:
    Application();
    ~Application();
    bool initializeApplication();
    void runApplication();
private:
    Editor* editor;
    Game* game;
    
    AudioManager* audio;
    
    int gameState;
};

#endif