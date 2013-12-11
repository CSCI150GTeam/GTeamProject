#include "Level.h"

Level::Level()
{
    
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

Player* Level::getPlayer(int player)
{
    if( player == 1 )
        return player1;
    //else return player2;
}