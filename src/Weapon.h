#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include <vector>
using namespace std;

// Weapons
#ifndef WEAPON_H
#define	WEAPON_H

class Weapon {
public:
    
    void Attack();
    
    //Initializes the variables
    Weapon( int X, int Y );

    ~Weapon();
    
    //Takes key presses and adjusts the weapon's velocity
    void handle_input();

    //Moves the weapon
    void move( std::vector<SDL_Rect> &rects );

    //Shows the weapon on the screen
    void show();

    //Gets the collision boxes
    std::vector<SDL_Rect> &get_rects();
    
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
    
    int damage;
    int ammo;
    int x;                        //the x offset
    int y;                        //the y offset
    int xVel;                     //the x velocity
    int yVel;                     //the y velocity
    string name;                  //name of the unit
    SDL_Surface* weapon;
    SDL_Event event;              //the event structure
    SDL_Surface *screen;          //the surfaces
    
    //The collision boxes of the weapon
    std::vector<SDL_Rect> box;

    //Moves the collision boxes relative to the dot's offset
    void shift_boxes();
      
};


#endif	/* WEAPON_H */

