#include "Game.h"
#include "Timer.h"
#include "Application.h"
#include "Global.h"
#include "command.h"
/*

int Game::multiGame(int sockfd)
{
    bool firstRun = true;
    Timer fps;
    const int FRAMES_PER_SECOND = 30;

    SDL_Event event;
    command CMD(sockfd, this);

    bool quit = false;

    while (quit == false) {
        if(firstRun)
            cout<<"Starting game loop"<<endl;
        fps.start();
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());

        if(firstRun)
            cout<<"Input"<<endl;
        //Input
        if (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case (SDL_KEYDOWN):
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_w:
                            CMD.push("goUp");
                            break;
                        case SDLK_s:
                            CMD.push("goDown");
                            break;
                        case SDLK_a:
                            CMD.push("goLeft");
                            break;
                        case SDLK_d:
                            CMD.push("goRight");
                            break;
                        //shoot
                        case SDLK_j:
                            break;
                    }
                    break;

                case (SDL_KEYUP):
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_w:
                            CMD.push("stopVert");
                            break;
                        case SDLK_s:
                            CMD.push("stopVert");
                            break;
                        case SDLK_a:
                            CMD.push("stopHorz");
                            break;
                        case SDLK_d:
                            CMD.push("stopHorz");
                            break;
                        case SDLK_ESCAPE:
                            switch ( pauseGame() )
                            {
                                case 1: break;
                                case 0: return 0;
                                case -1: return -1;
                            }
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        CMD.take();
        CMD.execute();
        
        if(firstRun)
            cout<<"Update"<<endl;
        //Update
        currentLevel -> update();
        
        if(firstRun)
            cout<<"Draw"<<endl;
        
        //Draw
        currentLevel -> drawGrid();
        currentLevel -> drawUnits();
        if(firstRun)
            cout<<"Flip"<<endl;
        if (SDL_Flip(mainScreenSurface) == -1)
            cout << "SDL_Flip failed" << endl;
        firstRun = false;
    }
}
*/