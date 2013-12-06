#ifndef LEVEL_H
#define	LEVEL_H

#include <string>
#include "MapGrid.h"
using namespace std;

class Level
{
public:
    Level();
    ~Level();
private:
    MapGrid* grid;
    string levelName;
};

#endif