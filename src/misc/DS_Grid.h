#ifndef DS_GRID_H
#define	DS_GRID_H

#include <iostream>
#include <vector>
using namespace std;

class DS_Grid
{
public:
    DS_Grid(int,int);
    ~DS_Grid();
    void addRows(int);
    void addColumns(int);
private:
    int width;
    int height;
    vector<vector<int>*>* internal;
};

#endif