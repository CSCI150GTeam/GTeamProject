#include "Level.h"

Level::Level(int startingLevel)
{
    cout<<"Creating level object"<<endl;
    grid = new LevelGrid(40,24);
    grid -> loadGrid("Resources\\sLv1.txt");
    player1 = new Player(0,0);
    /*player2 = new Player();
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
    } */
    cout<<"level object created"<<endl;
}

Level::~Level()
{
    
}

void Level::update()
{
    player1 -> update();
    /*player2 -> update();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> update();
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> update(); */
}

void Level::drawUnits()
{
    player1 -> draw();
    /*player2 -> draw();
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> draw();
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> draw(); */
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