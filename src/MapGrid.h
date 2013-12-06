#ifndef DS_GRID_H
#define	DS_GRID_H

#include <iostream>
#include <vector>
using namespace std;

class MapGrid
{
public:
    MapGrid(int,int);
    ~MapGrid();
    void addRows(int);
    void addColumns(int);
private:
    int width;
    int height;
    vector<vector<int>*>* internal;
};

#endif