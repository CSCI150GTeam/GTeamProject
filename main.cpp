/*  main.cpp
 * main.cpp serves as the entry point for the application.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "LevelGrid.h"
#include "GameManager.h"

using namespace std;

const int SCREEN_WIDTH = 320; //1280;
const int SCREEN_HEIGHT = 320; //640;
const int SCREEN_BPP = 32;

SDL_Surface* screen;
bool initializeApp();
bool cleanUp();

int main(int argc, char * args[])
{
    
    
    //Initialize app
    if( initializeApp() == false )
        return 1;
    
    //Create GameManager object that will handle which state the game is in (menu, in-game, editor)
    GameManager* gm = new GameManager();
    
//----- Test code ----- //
    
    //In the future the LevelGrid objects will be created when the game loop is initialized, as well as the other related function calls
    LevelGrid* lg = new LevelGrid(SCREEN_WIDTH/32,SCREEN_HEIGHT/32);
    lg->loadGrid();
    lg->printGrid();
    lg->drawGrid(screen);
    
    if( SDL_Flip(screen) == -1)
        return 1;
    SDL_Delay(20000);
    
//----- End test code ----- //
    
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
    
    //Set up screen surface
    cout<<"Setting up screen..."<<endl;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if( screen == NULL )
        return false;
    cout<<"Screen setup complete"<<endl;
    cout<<"Screen width = "<<SCREEN_WIDTH<<endl;
    cout<<"Screen height = "<<SCREEN_HEIGHT<<endl;

    //Set window caption - this function isn't working right now for some reason
    SDL_WM_SetCaption("Hello World", NULL);
    
    cout<<"Initialization complete, entering menu system..."<<endl;

    
    return true;
}

bool cleanUp()
{
    SDL_FreeSurface(screen);
    SDL_Quit();
    return true;
}