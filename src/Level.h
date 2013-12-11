#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

using namespace std;

class Level
{
public:
    Level();
    ~Level();
    
    void update();
    void drawUnits();
private:
    Player* player1;
    //Player* player2;
    vector<Enemy*>* enemies;
    vector<Projectile*>* projectiles;
};

#endif