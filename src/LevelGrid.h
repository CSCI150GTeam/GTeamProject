/* 
 * File:   LevelGrid.h
 * Author: Lena
 *
 * Created on December 6, 2013, 10:22 PM
 */

#ifndef __GameProject__LevelGrid__
#define __GameProject__LevelGrid__

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <fstream>
#include "Global.h"

using namespace std;

const string BRICK_IMG = "brick32.jpg"; //1
const string DIRT_IMG = "dirt32.jpg"; //2
const string DIRTYBIRCK_IMG = "dirtybrick32.jpg"; //3
const string GRASS_IMG = "grass32.jpg"; //4
const string LAVA_IMG = "lava32.jpg"; //5
const string REDCARPET_IMG = "redcarpet32.jpg"; //6
const string STONE_IMG = "stone32.jpg"; //7
const string WATER_IMG = "water32.jpg"; //8
const string WOOD_IMG = "wood32.jpg"; //8

class LevelGrid
{
public:
    LevelGrid(int x,int y);
    ~LevelGrid();
    
    //Primary functions
    void drawGrid();
    void loadGrid();
   
    //Auxillary/debug functions
    void printGrid();
    
private:
    //Variables
    int** grid;
    int width;
    int height;
    
    //Primary functions
    SDL_Surface* loadImage(string);
    void applySurface(int,int,SDL_Surface*);
};

#endif