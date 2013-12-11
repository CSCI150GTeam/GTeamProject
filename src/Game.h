#ifndef GAME_H
#define	GAME_H

#include "Level.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    
    int runGameLoop(bool);
    void pauseGameLoop();
private:
    Level* currentLevel;
};

#endif