/*  main.cpp
 
    *** IMPORTANT ***   This code was imported from a Mac environment, and most likely will not compile correctly on
    Windows due to differences in the headers and directory paths. The file will be updated to work with Netbeans once
    we get Netbeans to play nice with SDL.
 
    main.cpp serves as the entry point for the application. Currently, the main function initializes the necessary SDL
    subsystems, sets up a screen surface, and creates a LevelGrid object, which is then told to draw itself on screen.
 */

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "LevelGrid.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


SDL_Surface* loadImage(string);
void applySurface(int,int,SDL_Surface*,SDL_Surface*);


int main(int argc, char * args[])
{
    //Initialize SDL
    if( SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;
    //Set up the screen
    SDL_Surface* screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if( screen == NULL )
        return 1;
    //Add a caption for the window
    SDL_WM_SetCaption("Hello world", NULL);
    
    LevelGrid* lg = new LevelGrid(SCREEN_WIDTH/32,SCREEN_HEIGHT/32);
    lg->printGrid();
    lg->drawGrid(screen);
    
    if( SDL_Flip(screen) == -1)
        return 1;
    SDL_Delay(20000);
    
    SDL_FreeSurface(screen);
    
    SDL_Quit();
    
    return 0;
}
