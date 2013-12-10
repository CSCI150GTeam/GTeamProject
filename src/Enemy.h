#include "Unit.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
using namespace std;

//The dimensions of the image
const int ENEMY_WIDTH = 32;
const int ENEMY_HEIGHT = 32;
//the direction status of the stick figure
const int ENEMY_RIGHT = 0;
const int ENEMY_LEFT = 1;

// Enemy
#ifndef ENEMY_H
#define	ENEMY_H

class Enemy : public Unit {
public:
    Enemy();
    ~Enemy();
    void handle_events();        //handles input
    void move();                 //moves the figure
    void show();                 //shows the figure
    void set_clips();            //sets the clips for the individual sprites in the sprite sheet
    
private:
  
    SDL_Surface *enemy;           //the surfaces of image

};

#endif	/* ENEMY_H */

