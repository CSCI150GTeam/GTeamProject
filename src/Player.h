#include "Unit.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player : public Unit
{
public:
    Player();
    ~Player();
    
    void update();
    void draw();
private:
};

#endif