#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>

#include "Enemy.h"
#include "LevelGrid.h"
#include "Player.h"
#include "Projectile.h"

using namespace std;

class Level
{
public:
    Level();
    ~Level();
    
    void update();
    void drawGrid();
    void drawUnits();
    
    Player* getPlayer(int);
private:
    LevelGrid* grid;
    Player* player1;
    //Player* player2;
    vector<Enemy*>* enemies;
    vector<Projectile*>* projectiles;
};

#endif