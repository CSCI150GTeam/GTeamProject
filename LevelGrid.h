#ifndef __GameProject__LevelGrid__
#define __GameProject__LevelGrid__

#include <iostream>
#include <string>
#include "SDL/SDL.h"
using namespace std;

const string GRASS_IMG = "/Users/sammyyuk/Documents/School/7 - Fall 2013/CSCI 150/Project/Xcode Project/GameProject/Resources/grass.bmp";   //1
const string STONE_IMG = "/Users/sammyyuk/Documents/School/7 - Fall 2013/CSCI 150/Project/Xcode Project/GameProject/Resources/stone.bmp";   //2

class LevelGrid
{
public:
    LevelGrid(int,int);
    ~LevelGrid();
    
    //Primary functions
    void drawGrid(SDL_Surface*);
    
    //Auxillary/debug functions
    void printGrid();
    
private:
    //Variables
    int** grid;
    int width;
    int height;
    
    //Primary functions
    SDL_Surface* loadImage(string);
    void applySurface(int,int,SDL_Surface*,SDL_Surface*);
};

#endif
