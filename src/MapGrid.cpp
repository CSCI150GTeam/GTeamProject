#include "MapGrid.h"

MapGrid::MapGrid(int nWidth, int nHeight)
{
    this->width = nWidth;
    this->height = nHeight;
    this->internal = new vector<vector<int>*>;
    for(int i = 0; i < this->width; i++)
    {
        internal->push_back(new vector<int>);
        for(int j = 0; j < this->height; j++)
        {
            internal->at(i)->push_back(0);
        }
        cout<<"internal["<<i<<"] contains "<<internal->at(i)->size()<<" elements"<<endl;
    }
    cout<<"interal contains "<<internal->size()<<" elements";
}

MapGrid::~MapGrid()
{
    delete internal;
}

void MapGrid::addRows(int numRows)
{
    
}

void MapGrid::addColumns(int numCols)
{
    
}