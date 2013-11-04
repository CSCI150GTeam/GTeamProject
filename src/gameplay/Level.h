#ifndef LEVEL_H
#define	LEVEL_H

#include <string>
#include "misc/DS_Grid.h"
using namespace std;

class Level
{
public:
    Level();
    ~Level();
private:
    DS_Grid* grid;
    string levelName;
};

#endif