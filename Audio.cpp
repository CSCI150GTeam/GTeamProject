//Audio and Sound Effects of the game
#include "Audio.h"
using namespace std;

//The music that will be played
Mix_Music *music = NULL;
    
//The sound effects that will be used
Mix_Chunk *soundeffect1 = NULL;
Mix_Chunk *soundeffect2 = NULL;
Mix_Chunk *soundeffect3 = NULL;
    
Audio::Audio()
{   

}

Audio::~Audio()
{

    
}

void Audio::loadMusic()
{
    
    //Load the music
    music = Mix_LoadMUS( "Sounds\\beat.wav" );
    
    //If there was a problem loading the music
    if( music == NULL )
    {
        return;
    }
  
    
}

void Audio::loadSoundEffects()
{
    //Load the sound effects
    soundeffect1 = Mix_LoadWAV( "Sounds\\high.wav" );
    soundeffect2 = Mix_LoadWAV( "Sounds\\medium.wav" );
    soundeffect3 = Mix_LoadWAV( "Sounds\\low.wav" );
    
    //If there was a problem loading the sound effects
    if( ( soundeffect1 == NULL ) || ( soundeffect2 == NULL ) || ( soundeffect3 == NULL ) )
    {
        return;
    }
       
}

void clean_up()
{
    //Free the music
    Mix_FreeMusic( music );
    
    //Free the sound effects
    Mix_FreeChunk( soundeffect1 );
    Mix_FreeChunk( soundeffect2 );
    Mix_FreeChunk( soundeffect3 );

    //Quit SDL_mixer
    Mix_CloseAudio();
}