#include "Game.h"
#include "Timer.h"
#include "Application.h"
#include "Global.h"

Game::Game()
{

}

Game::~Game()
{

}

void clean_up()
{

    //Quit SDL
    SDL_Quit();
}

int Game::runGameLoop(bool)
{
    //Keep track of the current frame
    int frame = 0;
    
    //The frame rate regulator
    Timer fps;
    
    //The frames per second
    const int FRAMES_PER_SECOND = 30;
    
    SDL_Event event;

    //Whether or not to cap the frame rate
    bool cap = true;
    
    bool quit = false;
    while( quit == false )
    {
        //Start the frame timer
        fps.start();
        
        //If a key was pressed
        if( event.type == SDL_KEYDOWN )
        {
            //If enter was pressed
            if( event.key.keysym.sym == SDLK_RETURN )
            {
                //Turn frame rate regulator on/off
                cap = ( !cap );
            }
        }
        //If the user has Xed out the window
        else if( event.type == SDL_QUIT )
        {
            //Quit the program
            quit = true;
        }
        
        //Update the screen
        if( SDL_Flip( mainScreenSurface ) == -1 )
        {
            return 1;
        }

        //Increment the frame counter
        frame++;

        //If we want to cap the frame rate
        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
       
    }

}

void Game::pauseGameLoop()
{
    bool quit = false;
    
    //Make the timer
    Timer myTimer;
    
    //Start the timer
    myTimer.start();
    
    SDL_Event event;
    
    //While the user hasn't quit
    while( quit == false)
    {
        //While there's an event to handle
        while( SDL_PollEvent( &event) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //If p was pressed
                if( event.key.keysym.sym == SDLK_p )
                {
                    //If the timer is paused
                    if( myTimer.is_paused() == true )
                    {
                        //Unpause the timer
                        myTimer.unpause();
                    }
                    else
                    {
                        //Pause the timer
                        myTimer.pause();
                        //Implement the code here to load & display a pause message
                    }
                }
            }
            
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }
    //Clean up
    clean_up();

}