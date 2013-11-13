/*
 * main.cpp - core module
 * Code contributed by: Sammy
 * Main file - Serves as the entry point for the application. The app run process is as follows:
 *     1) initializeApp() takes care of initialization of SDL subsystems and sets up the screen surface
 *     2) Animation and audio managers are created
 *     3) The game manager is created. In the game manager constructor, the actual app launches and goes into the
 *        menu system
 *     4) The user interacts with the game, using the menu systems, editor, and engaging in gameplay
 *     5) When the user quits, the program moves on from the game manager initialization line
 *     6) The animation, audio, and game managers are deleted, and the screen surface is freed
 *     7) cleanUp() is called, which shuts down the SDL subsystems
 *     8) Lastly, the program returns 0 and exits
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "SDL/SDL_ttf.h"
#include "GameManager.h"
#include "audio/Audio.h"
#include "ui/UI_Switch.h"
#include "Global.h"

using namespace std;

const int SCREEN_WIDTH = 1024; //32 tiles
const int SCREEN_HEIGHT = 768; //24
const int SCREEN_BPP = 32;

bool initializeApp();
void cleanUp();

int main(int argc, char * args[])
{
    
    cout<<"STARTING APP INITIALIZATION"<<endl;
    
//Initialize app
    if( initializeApp() == false )
    {
        cout<<"\tinitializeApp() returned false"<<endl;
        return 1;
    }
    
//Setup Game, Animation, and Audio Managers
    cout<<"\tInitializing managers"<<endl;
    //AnimationManager* anm = animationManager(screen);
    
    //AudioManager* aum = audioManager;
    
    cout<<"\t\tInitializing GameManager...";
    GameManager* gm = new GameManager();
    if( gm == NULL )
    {
        cout<<"\t\tGameManager failed to initialize"<<endl;
        return 1;
    }
    
// --- User interaction with the program occurs here --- //
    
    cout<<"STARTING APP CLEANUP"<<endl;
//Delete Game, Animation, and Audio Managers
    cout<<"\tDeleting managers...";
    //delete anm;
    //delete aum;
    delete gm;
    cout<<"\t\tManager deletion successful"<<endl;
    
//Free screen surface
    cout<<"\tDeleting screen surface...";
    delete mainScreenSurface;
    cout<<"\tDeleted screen surface"<<endl;
    
//Cleanup app
    cleanUp();
    
    cout<<"APP CLEANUP COMPLETE"<<endl;
    
//Exit program
    return 0;
}

bool initializeApp()
{
    cout<<"\tRunning initializeApp()"<<endl;
    
    //Initialize SDL Subsystems
    cout<<"\t\tInitializing SDL subsystems...";
    if( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    {
        cout<<"\tERROR: SDL subsystem initialization failed!"<<endl;
        return false;
    }
    cout<<"\tSDL subsystem initialization succeeded"<<endl;

    cout<<"\t\tSetting window caption...";
    SDL_WM_SetCaption("Hello World", NULL);
    cout<<"\tWindow caption setup succeeded"<<endl;
    
    /*
    cout<<"\t\tSetting up screen...";
    SDL_Surface* s = SDL_SetVideoMode(1024,768,32,SDL_SWSURFACE);
    if( s == NULL )
    {
        cout<<"\t\tScreen setup failed"<<endl;
        return NULL;
    }
    cout<<"\t\tScreen setup succeeded"<<endl;
    */
    cout<<"\tinitializeApp() ran successfully"<<endl;
    return true;
}

void cleanUp()
{
    cout<<"\tRunning cleanUp()...";
    SDL_Quit();
    cout<<"\t\tcleanUp() ran successfully"<<endl;
}

//Source file top comment template
/*
 * Name.cpp/h - <module> module
 * Code contributed by: <names here>
 * "Header file" || "Main file - " || <Description>
 */