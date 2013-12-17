#include "Level.h"

Level::Level(int levelNumber)
{
    grid = new LevelGrid(40, 24);
    loadGrid(levelNumber);
    player1 = new Player(grid -> getP1Spawn().x, grid -> getP1Spawn().y);
    /* player2 = new Player();
       enemies = new vector<Enemy*>;
       projectiles = new vector<Projectile*>; */
}

Level::~Level()
{

}

void Level::update()
{
    player1 -> update();
    /*
    player2 -> update();
    
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> update();
    
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> update();
     */
}

void Level::draw()
{
    grid -> drawGrid();

    player1 -> draw();
    /*player2 -> draw();
    
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> draw();
    
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> draw(); */
}

Player* Level::getPlayer(int player)
{
    if (player == 1)
        return player1;
    //else return player2;
}

bool Level::inEndzone()
{
    bool p1 = grid -> inEndzone(player1 -> getX(), player1 -> getY());
    /*  ,p2 = grid -> inEndzone( player2 -> getX() , player2 -> getY() ); */
    if (p1 /* && p2 */)
        return true;
    else
        return false;
}

void Level::loadGrid(int levelNumber)
{
    switch (levelNumber)
    {
        case 1:
            grid->loadGrid("resources\\s1.txt");
            break;
        case 2:
            grid->loadGrid("resources\\s2.txt");
            break;
        case 3:
            grid->loadGrid("resources\\s3.txt");
            break;
        case 4:
            grid->loadGrid("resources\\s4.txt");
            break;
        case 5:
            grid->loadGrid("resources\\s5.txt");
            break;
    }
}