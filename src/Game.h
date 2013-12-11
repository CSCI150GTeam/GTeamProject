#ifndef GAME_H
#define	GAME_H

#include "Level.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    
    int runGame(bool);
    void pauseGame();
private:
    Level* currentLevel;
};

#endif