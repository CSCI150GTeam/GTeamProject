#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include <vector>
using namespace std;

#ifndef PROJECTILE_H
#define	PROJECTILE_H

class Projectile {
public:
    Projectile();
    ~Projectile();
    
private:
    int x;                        //the x offset
    int y;                        //the y offset
    int xVel;                     //the x velocity
    int yVel;                     //the y velocity
    string name;                  //name of the unit
    SDL_Surface* projectile;
    SDL_Event event;              //the event structure
    SDL_Surface *screen;          //the surfaces

};

#endif	/* PROJECTILE_H */

