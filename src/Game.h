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
    int pauseGame();
private:
    Level* currentLevel;
};

#endif