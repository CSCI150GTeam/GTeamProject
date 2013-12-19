#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>
#include <fstream>
#include <string>

#include "Enemy.h"
#include "Grid.h"
#include "Player.h"
#include "Projectile.h"
#include "Global.h"

using namespace std;

class Level
{
public:
    Level(int);
    ~Level();
    void input(char*, char*);
    void update();
    void draw(int);
    
    Player* getPlayer(int);
    bool victoryCondition();
private:
    void loadLevel(int);
    
    Grid* grid;
    Player* player1;
    //Player* player2;
    //vector<Enemy*>* enemies;
    //vector<Projectile*>* projectiles;
    
    SDL_Rect p1Spawn;
    SDL_Rect p2Spawn;
    SDL_Rect endzone;
};

#endif