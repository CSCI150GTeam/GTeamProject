#ifndef __GameProject__AudioManager__
#define __GameProject__AudioManager__

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <string>
using namespace std;

class AudioManager
{
public:
    AudioManager();
    ~AudioManager();
    void loadSound(string);
    void playSound(string);
    //void clean_up();

private:
    Mix_Chunk* soundEffect1;
    Mix_Music* music1;
    // set channel 1 to half volume
};

#endif
