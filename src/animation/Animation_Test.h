#ifndef ANIMATION_TEST_H
#define	ANIMATION_TEST_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
using namespace std;

//Tile images
const string GRASS = "resources\\images\\grass.bmp";                    //1
const string STONE = "resources\\images\\stone.bmp";                    //2
const string ICE = "resources\\images\\ice.bmp";                        //3
const string LAVA = "resources\\images\\lava.bmp";                      //4
const string WATER = "resources\\images\\water.bmp";                    //5
const string WATER_DROPS = "resources\\images\\waterDrops.bmp";         //6
//Menu images

class Animation_Test
{
public:
    Animation_Test();
    ~Animation_Test();
    void apply_surface(int,int,SDL_Surface*);
    bool flipScreen();
    void drawMenuScreen(int,int);
private:
    SDL_Surface* screen;
    vector<SDL_Surface*>* loadedTileImages;
    vector<SDL_Surface*>* loadedMenuImages;
    void loadTileImages();
    void loadMenuImages();
    SDL_Surface* load_image(string);
};

#endif