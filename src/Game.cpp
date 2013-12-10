#include "Game.h"
#include "Timer.h"
#include "Application.h"

Game::Game()
{
    
    //PAUSE KEY
////////////////////////////////////////////////////////////////////////////////    
    //Quit flag
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
////////////////////////////////////////////////////////////////////////////////    

}

Game::~Game()
{

}