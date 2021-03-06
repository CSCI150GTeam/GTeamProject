#include "Level.h"

Level::Level(int levelNumber)
{
    multiplayer = currentGameGlobal->multiPlayer;
    loadLevel(levelNumber);

    player1 = new Player(p1Spawn.x, p1Spawn.y);
    if ( multiplayer )
	player2 = new Player(p2Spawn.x, p2Spawn.y);
    else
	player2 = NULL;

    currentLevelGlobal = this;
}

Level::~Level()
{
    currentLevelGlobal = NULL;
}

void Level::input(char *inP1, char *inP2)
{
    player1->input(inP1);
    if ( multiplayer )
	player2->input(inP2);
}

void Level::update()
{
    player1 -> update();
    if ( multiplayer )
	player2 -> update();
}

void Level::draw()
{
    grid -> drawGrid();

    player1 -> draw();
    if ( multiplayer )
	player2 -> draw();
}

Player* Level::getPlayer(int player)
{
    if ( player == 1 )
	return player1;
    else return player2;
}

bool Level::victoryCondition()
{
    bool endOne = false, endTwo = false;
    cout << "victory- getting offsets" << endl;
    int x1 = player1->getX();
    int y1 = player1->getY();
    int x2 = 0, y2 = 0;
    if ( currentGameGlobal->multiPlayer )
    {
	x2 = player2->getX();
	y2 = player2->getY();
    }

    cout << "victory- checking if stuff is in the bounds" << endl;
    if ( ( x1 > endzone.x ) &&
	    ( x1 < ( endzone.x + endzone.w ) ) &&
	    ( y1 > endzone.y ) &&
	    ( y1 < ( endzone.y + endzone.h ) )
	    )
	endOne = true;
    if ( currentGameGlobal->multiPlayer )
	if ( ( x2 > endzone.x ) &&
		( x2 < ( endzone.x + endzone.w ) ) &&
		( y2 > endzone.y ) &&
		( y2 < ( endzone.y + endzone.h ) )
		)
	    endTwo = true;
    if(currentGameGlobal->multiPlayer)
	return (endOne || endTwo);
    else
	return endOne;
}

void Level::loadLevel(int level)
{
    cout << "DEBUG: Level is loading file";
    vector<vector<int>*>* temp = new vector<vector<int>*>;

    for ( int i = 0; i < GRID_HEIGHT; i++ )
	temp->push_back(new vector<int>);

    for ( int i = 0; i < GRID_HEIGHT; i++ )
	for ( int j = 0; j < GRID_WIDTH; j++ )
	    temp->at(i)->push_back(1);

    string filepath;
    switch ( level )
    {
	case 1: filepath = "resources\\data_s1.txt";
	    break;
	case 2: filepath = "resources\\data_s2.txt";
	    break;
	case 3: filepath = "resources\\data_s3.txt";
	    break;
	case 4: filepath = "resources\\data_s4.txt";
	    break;
	case 5: filepath = "resources\\data_s5.txt";
	    break;
    }

    ifstream infile;
    infile.open(filepath.c_str());
    for ( int i = 0; i < GRID_HEIGHT; i++ )
    {
	for ( int j = 0; j < GRID_WIDTH; j++ )
	{
	    int input;
	    if ( infile >> input )
		temp->at(i)->at(j) = input;
	    else
		break;
	}
	if ( !infile )
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
    cout << "DEBUG: Level file loaded" << endl;
}

Grid* Level::getGrid()
{
    return grid;
}

vector<string>* Level::getInfoBarData()
{
    vector<string>* vec = new vector<string>;
    stringstream ss;
    string s1, s2, strX, strY, strXVel, strYVel;


    ss << "Level: ";
    ss << currentGameGlobal->getCurrentLevelNumber();
    s1 = ss.str();
    vec->push_back(s1);
    ss.str(string());

    ss << "Health: ";
    ss << player1->getHealth();
    s2 = ss.str();
    vec->push_back(s2);
    ss.str(string());

    ss << player1->getX();
    strX = ss.str();
    vec->push_back(strX);
    ss.str(string());

    ss << player1->getY();
    strY = ss.str();
    vec->push_back(strY);
    ss.str(string());

    ss << player1->getXVel();
    strXVel = ss.str();
    vec->push_back(strXVel);
    ss.str(string());
    
    ss << player1->getYVel();
    strYVel = ss.str();
    vec->push_back(strYVel);
    ss.str(string());


    return vec;
}