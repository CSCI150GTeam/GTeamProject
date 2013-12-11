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
    int multiGame(int);
    int pauseGame();
    bool playerUno;
    Level* currentLevel;       
};

#endif