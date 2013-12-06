#include "AudioManager.h"
using namespace std;
    
AudioManager::AudioManager()
{
    soundEffect1 = Mix_LoadWAV( "resources\\audio\\high.wav" );
    if( soundEffect1 == NULL )
        cout<<"Sound effect 1 is Null"<<endl;
    
    music1 = Mix_LoadMUS( "resources\\audio\\adventuring_song.mp3");
    if( music1 == NULL )
        cout<<"Music 1 is Null"<<endl;

    cout<<"\tAudio initialization complete!"<<endl;
}

AudioManager::~AudioManager()
{
    Mix_FreeChunk( soundEffect1 );
    Mix_FreeMusic( music1 );
    Mix_CloseAudio;
}

void AudioManager ::playSound(string filename)
{
    if(filename == "soundEffect1")
    {
        cout<<"playing SE1"<<endl;
        if( Mix_PlayChannel(-1,soundEffect1,-1) == -1 )
            cout<<"Error in playing sound"<<endl;
    }
    
    if(filename == "music1")
    {
        cout<<"playing M1"<<endl;
        if( Mix_PlayMusic(music1,-1) == -1 )
            cout<<"Error in playing sound"<<endl;
    }
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
*/