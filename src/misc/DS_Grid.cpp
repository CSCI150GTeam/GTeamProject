#include "DS_Grid.h"

DS_Grid::DS_Grid(int nWidth, int nHeight)
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

DS_Grid::~DS_Grid()
{
    delete internal;
}

void DS_Grid::addRows(int numRows)
{
    for(int i = 0; i < this->width; i++)
        for(int j = 0; j < numRows; j++)
            internal->at(i)->push_back(0);
    
}

void DS_Grid::addColumns(int numCols)
{
    
}