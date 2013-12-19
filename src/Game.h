#ifndef GAME_H
#define	GAME_H

#include <fstream>
#include <string>
#include <vector>

#include "Level.h"
#include "Utility.h"
#include "Timer.h"
#include "Global.h"
#include "Command.h"

class Game
{
public:
    Game(bool);
    ~Game();
    
    int runGame();
    
    int getFrameCounter();
    int getCurrentLevelNumber();
private:
    Level* currentLevel;
    
    int currentLevelNumber, frameCounter;
    Timer fps, gameTimer; bool multiPlayer;
    command CMD;
    
    int runGameLoop();
    int input();
    int update();
    int draw(int);
    
    bool pauseGame();
    void displayInfoBar();
    void displayDebug();
    
    SDL_Surface* IMG_MENU2;
    
    SDL_Surface* IMG_HIGHLIGHT;
    SDL_Surface* IMG_INFOBAR;
};

#endif
