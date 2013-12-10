#include <iostream>
#include "SDL/SDL.h"
#include "Timer.h"
#include <string>
using namespace std;

const int SCREEN_WIDTH = 1024; //32 tiles
const int SCREEN_HEIGHT = 768; //24
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;

// Unit (Global characteristics for players and enemies)
#ifndef UNIT_H
#define	UNIT_H

class Unit {
public:
    Unit(){}
    ~Unit(){}
    
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
    {
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
    }
 
private:
    
protected:
    int health;                   //unit health percentage
    int x;                        //the x offset
    int y;                        //the y offset
    int xVel;                     //the x velocity
    int yVel;                     //the y velocity
    string name;                  //name of the unit
    int frame;                    //its current frame
    int status;                   //its animation status
    SDL_Surface *image;
    SDL_Event event;              //the event structure
    SDL_Surface *screen;          //the surfaces

};

#endif	/* UNIT_H */





