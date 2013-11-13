#include "Audio.h"
using namespace std;

//The music that will be played
Mix_Music *music1 = NULL;
Mix_Music *music2 = NULL;
Mix_Music *music3 = NULL;

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

bool Audio::loadMusic(string filename)
{
    
    if(filename == "music1")
    {
        //Load the music
        music1 = Mix_LoadMUS( "Sounds\\beat.wav" );
        cout << "This is working!";
    }
    else if (music1 == NULL)
    {
        return false;
    }
    if(filename == "music2")
    {
        //Load the music
        music2 = Mix_LoadMUS( "Sounds\\high.wav");
    }
    else if (music2 == NULL)
    {
        return false;
    }
           
    //Free the music
    Mix_FreeMusic( music1 );
    Mix_FreeMusic( music2 );
    
}

bool Audio::loadSoundEffects(string filename)
{
    
    if(filename == "soundeffect1")
    {
        //Load the sound effects
        soundeffect1 = Mix_LoadWAV( "Sounds\\low.wav" );
    }
    //If there was a problem loading the sound effects
    else if (soundeffect1 == NULL)
    {
        return false;
    }
    if(filename == "soundeffect1")
    {
        //Load the sound effects
        soundeffect2 = Mix_LoadWAV( "Sounds\\medium.wav" );
    }
    //If there was a problem loading the sound effects
    else if (soundeffect2 == NULL)
    {
        return false;
    }
    if(filename == "soundeffect1")
    {
        //Load the sound effects
        soundeffect3 = Mix_LoadWAV( "Sounds\\high.wav" );
    }
    //If there was a problem loading the sound effects
    else if (soundeffect3 == NULL)
    {
        return false;
    }
    
    //Free the sound effects
    Mix_FreeChunk( soundeffect1 );
    Mix_FreeChunk( soundeffect2 );
    Mix_FreeChunk( soundeffect3 );
       
}
/*
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
 * */