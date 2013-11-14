#ifndef __GameProject__Audio__
#define __GameProject__Audio__

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <string>
using namespace std;

class Audio
{
public:
    Audio();
    ~Audio();
    void loadSound(string);
    void playSound(string);
    //void clean_up();

private:
    Mix_Chunk* soundEffect1;
    Mix_Music* music1;
};

#endif
