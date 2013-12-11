#include <iostream>
#include "SDL/SDL.h"
#include "Timer.h"
#include <string>
using namespace std;

// Unit (Global characteristics for players and enemies)
#ifndef UNIT_H
#define	UNIT_H

class Unit
{
public:
    Unit(){}
    ~Unit(){}
    void setXVel(int iVel) { xVel = iVel; }
    void setYVel(int iVel) { yVel = iVel; }
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
    int health;                   //unit health percentage
    int x;                        //the x offset
    int y;                        //the y offset
    int xVel;                     //the x velocity
    int yVel;                     //the y velocity
    int frame;                    //its current frame
    int status;                   //its animation status
    SDL_Surface* sprite;
};

#endif