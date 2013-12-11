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

int Game::runGame(bool)
{
    Timer fps;
    const int FRAMES_PER_SECOND = 30;

    SDL_Event event;

    bool quit = false;

    while (quit == false) {
        fps.start();
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());

        //Input
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case (SDL_KEYDOWN):
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:
                        currentLevel -> getPlayer(1) -> setYVel(-16);
                        break;
                    case SDLK_s:;
                        break;
                    case SDLK_a:;
                        break;
                    case SDLK_d:;
                        break;
                }
                break;
            case (SDL_KEYUP):
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:;
                        break;
                    case SDLK_s:;
                        break;
                    case SDLK_a:;
                        break;
                    case SDLK_d:;
                        break;
                    case SDLK_j:;
                        break;
                    case SDLK_ESCAPE:
                        pauseGame();
                        ;
                        break;
                }
                break;
            default:
                break;
        }

        //Update
        currentLevel -> update();

        //Draw
        currentLevel -> drawGrid();
        currentLevel -> drawUnits();
        if (SDL_Flip(mainScreenSurface) == -1)
            return -1;
    }
}

void Game::pauseGame()
{
    
}