#include "Level.h"

Level::Level(int levelNumber)
{
    loadLevel(levelNumber);
    player1 = new Player(p1Spawn.x, p1Spawn.y);
    /* player2 = new Player();
       enemies = new vector<Enemy*>;
       projectiles = new vector<Projectile*>; */
}

Level::~Level()
{
    
}

void Level::input(char *inP1, char *inP2)
{
    player1->input(inP1);
    //player2->input(inP12);
}

void Level::update()
{
    player1 -> update();
    /*    
    for( int i = 0; i < enemies->size(); i++)
        enemies -> at(i) -> update();
    
    for( int j = 0; j < projectiles->size(); j++)
        projectiles -> at(j) -> update();
     */
}

void Level::draw(int frame)
{
    grid -> drawGrid();

    player1 -> draw(frame);
    
  /*for( int i = 0; i < enemies->size(); i++)
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

bool Level::victoryCondition()
{
    int x = player1->getX(), y = player1->getY();
    if( ( x > endzone.x ) && ( x < (endzone.x+endzone.w) ) && ( y > endzone.y ) && ( y < (endzone.y+endzone.h) ) )
        return true;
    else return false;
}

void Level::loadLevel(int level)
{
    vector<vector<int>*>* temp = new vector<vector<int>*>;
    
    for (int i = 0; i < GRID_HEIGHT; i++)
        temp->push_back(new vector<int>);

    for (int i = 0; i < GRID_HEIGHT; i++)
        for (int j = 0; j < GRID_WIDTH; j++)
            temp->at(i)->push_back(1);
    
    string filepath;
    switch(level)
    {
        case 1: filepath = "resources\\data_s1.txt"; break;
        case 2: filepath = "resources\\data_s2.txt"; break;
        case 3: filepath = "resources\\data_s3.txt"; break;
        case 4: filepath = "resources\\data_s4.txt"; break;
        case 5: filepath = "resources\\data_s5.txt"; break;
    }
    
    ifstream infile;
    infile.open(filepath.c_str());
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            int input;
            if (infile >> input)
                temp->at(i)->at(j) = input;
            else
                break;
        }
        if (!infile)
            break;
    }
    infile >> p1Spawn.x;
    infile >> p1Spawn.y;
    infile >> p2Spawn.x;
    infile >> p2Spawn.y;
    infile >> endzone.x;
    infile >> endzone.y;
    infile >> endzone.w;
    infile >> endzone.h;
    infile.close();
    
    cout << "DEBUG: (Level.cpp) P1 Spawn = (" << p1Spawn.x << "," << p1Spawn.y << ")"
                            << "P2 Spawn = (" << p2Spawn.x << "," << p2Spawn.y << ")"
                             << "Endzone = (" << endzone.x << "," << endzone.y << ")" << endl;
    
    this->grid = new Grid(temp);
}