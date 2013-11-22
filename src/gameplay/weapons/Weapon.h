#include <iostream>
#include "SDL/SDL.h"
#include <string>
using namespace std;

// Weapons
#ifndef WEAPON_H
#define	WEAPON_H

class Weapon {
public:
    Weapon();
    ~Weapon();
    void Attack();
    
private:
    int damage;
    SDL_Surface* image;
    int ammo;
      
};


#endif	/* WEAPON_H */

