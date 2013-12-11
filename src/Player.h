#ifndef PLAYER_H
#define	PLAYER_H

#include "Unit.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Global.h"
using namespace std;

class Player : public Unit
{
public:
    Player();
    ~Player();
    //void handle_events();        //handles input
    //void move();                 //moves the figure
    //void show();                 //shows the figure
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    void set_clips();
    SDL_Surface *load_image( string );
    
    void update();
    void draw();
private:
    
    //The dimensions of the image
    const int PLAYER_WIDTH = 32;
    const int PLAYER_HEIGHT = 32;

    //The direction status of the stick figure
    const int PLAYER_UP = 0;
    const int PLAYER_RIGHT = 1;
    const int PLAYER_DOWN = 2;
    const int PLAYER_LEFT = 3;

    //The surfaces
    SDL_Surface *player_sprite_up = NULL;
    SDL_Surface *player_sprite_down = NULL;
    SDL_Surface *player_sprite_right = NULL;
    SDL_Surface *player_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The event structure
    SDL_Event event;

    //The areas of the sprite sheet
    SDL_Rect clipsUp[ 3 ];
    SDL_Rect clipsDown[ 3 ];
    SDL_Rect clipsRight[ 3 ];
    SDL_Rect clipsLeft[ 3 ];

};

#endif