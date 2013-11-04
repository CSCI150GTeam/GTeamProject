#ifndef __GameProject__GameManager__
#define __GameProject__GameManager__

#include <iostream>
#include "LevelGrid.h"
#include "animation/Animation_Test.h"
#include "SDL/SDL_ttf.h"

using namespace std;

class GameManager
{
public:
    GameManager(Animation_Test*);
    ~GameManager();
    void changeState(int);  //-1 = Quit, 1 = Menu, 2 = Game, 3 = Editor
    void runGridTestLoop();
private:
    SDL_Surface* screen;
    Animation_Test* anim;
    int gameState;
    void runMenuLoop();
    void runGameLoop();
    void runEditorLoop();
};

#endif