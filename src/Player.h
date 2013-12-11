#include "Unit.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
using namespace std;

//The dimensions of the image
const int PLAYER_WIDTH = 32;
const int PLAYER_HEIGHT = 32;
//the direction status of the stick figure
const int PLAYER_RIGHT = 0;
const int PLAYER_LEFT = 1;

// Player
#ifndef PLAYER_H
#define	PLAYER_H

class Player : public Unit
{
public:
    Player();
    ~Player();
    void handle_events();        //handles input
    void move();                 //moves the figure
    void show();                 //shows the figure
    void set_clips();            //sets the clips for the individual sprites in the sprite sheet
private:
};

#endif	/* PLAYER_H */