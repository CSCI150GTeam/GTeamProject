/* 
 * File:   Grid.h
 * Author: Lena
 *
 * Created on December 6, 2013, 10:22 PM
 */

#ifndef __GameProject__Grid__
#define __GameProject__Grid__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Global.h"
#include "Utility.h"

using namespace std;



class Grid
{
public:
    Grid(string);
    Grid(vector<vector<int>*>*);
    ~Grid();
    
    void loadGrid(string);
    void drawGrid();
private:
    void loadImages();
    void printGrid();
    
    vector< vector<int>*>* grid;
    int width;
    int height;
    
    SDL_Surface* brick;
    SDL_Surface* dirt;
    SDL_Surface* dirtybrick;
    SDL_Surface* grass;
    SDL_Surface* lava;
    SDL_Surface* redcarpet;
    SDL_Surface* stone;
    SDL_Surface* water;
    SDL_Surface* wood;
};

#endif