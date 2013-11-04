/* main.cpp
 * main.cpp serves as the entry point for the application.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "SDL/SDL_ttf.h"
#include "LevelGrid.h"
#include "GameManager.h"
#include "animation/Animation_Test.h"
#include "audio/Audio.h"

using namespace std;

const int SCREEN_WIDTH = 1024; //32 tiles
const int SCREEN_HEIGHT = 768; //24
const int SCREEN_BPP = 32;

bool initializeApp();
bool cleanUp();


int main(int argc, char * args[])
{
    //Initialize app
    if( initializeApp() == false )
        return 1;
   Animation_Test* anim = new Animation_Test();
    if( anim != NULL ) cout<<"Animation_Test object created"<<endl;
    GameManager* gm = new GameManager(anim);
    delete gm;
    if( cleanUp() == true )
        return 0;
    else
        return 1;
    
}

bool initializeApp()
{
    //Initialize SDL Subsystems
    cout<<"Initializing SDL subsystems..."<<endl;
    if( SDL_Init(SDL_INIT_EVERYTHING) )
        return false;
    cout<<"SDL subsystems initialized OK"<<endl;

    SDL_WM_SetCaption("Hello World", NULL);    
    cout<<"Initialization complete, entering menu system..."<<endl;    
    return true;
}

bool cleanUp()
{
    SDL_Quit();
    cout<<"Clean up complete"<<endl;
    return true;
}