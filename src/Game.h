#ifndef GAME_H
#define	GAME_H

#include "Level.h"
#include "Utility.h"

class Game
{
public:
    Game(bool);
    ~Game();
    
    int runGame();
    bool pauseGame();
    void displayDebug();
    Level* currentLevel;
    
    //bool playerUno;
    //int multiGame(int);
};

#endif