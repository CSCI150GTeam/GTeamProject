#ifndef __GameProject__LevelGrid__
#define __GameProject__LevelGrid__

#include <iostream>
#include <string>
#include <fstream>
#include "SDL/SDL.h"
using namespace std;

class LevelGrid
{
public:
    LevelGrid(int,int);
    ~LevelGrid();
    void drawGrid(SDL_Surface*);
    void loadGrid();
    void printGrid();
    void saveGrid();
private:
    int** grid;
    int width;
    int height;
    SDL_Surface* loadImage(string);
    void applySurface(int,int,SDL_Surface*,SDL_Surface*);
};

#endif