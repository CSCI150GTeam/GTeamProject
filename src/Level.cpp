#include "Level.h"

Level::Level(int startingLevel)
{
    grid = new LevelGrid(SCREEN_WIDTH/32,SCREEN_HEIGHT/32);
    player1 = new Player();
    //player2 = new Player();
    enemies = new vector<Enemy*>;
    projectiles = new vector<Projectile*>;
    
    switch( startingLevel )
    {
        case 1:
            grid->loadGrid("Resources\\level1.txt");
            break;
        case 2:
            //etc...
            break;
    }
}

Level::~Level()
{
    
}

void Level::update()
{
    player1 -> update();
    //player2 -> update();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> update();
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> update();
}

void Level::drawUnits()
{
    player1 -> draw();
    //player2 -> draw();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> draw();
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> draw();
}

void Level::drawGrid()
{
    grid->drawGrid();
}

Player* Level::getPlayer(int player)
{
    if( player == 1 )
        return player1;
    //else return player2;
}