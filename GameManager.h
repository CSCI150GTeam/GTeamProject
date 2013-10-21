#ifndef __GameProject__GameManager__
#define __GameProject__GameManager__

#include <iostream>
#include "LevelGrid.h"
using namespace std;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void changeState(int);  //1 = Menu, 2 = Game, 3 = Editor
private:
    int gameState;
    void runGameLoop(int,int);
    void runMenuLoop();
    void runEditorLoop();
};

#endif