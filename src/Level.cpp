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
    player2 -> update();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> update();
    for( int j = 0;  < projectiles->size(); j++)
        projectiles -> at(j) -> update();
}

void Level::drawUnits()
{
    player1 -> draw();
    player2 -> draw();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> draw();
    for( int j = 0;  < projectiles->size(); j++)
        projectiles -> at(j) -> draw();
}