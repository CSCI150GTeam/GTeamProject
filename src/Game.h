#ifndef GAME_H
#define	GAME_H

#include <fstream>

#include "Level.h"
#include "Utility.h"
#include "Timer.h"
#include "Global.h"

class Game
{
public:
    Game(bool);
    ~Game();
    int runGame();
private:
    int currentLevelNumber;
    Level* currentLevel;
    
    int runGameLoop();
    int input();
    int update();
    int draw();
    bool pauseGame();
    void displayDebug();
    
    //bool playerUno;
    //int multiGame(int);
};

#endif