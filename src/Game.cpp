#include "Game.h"
#include "Timer.h"
#include "Application.h"
#include "Global.h"

Game::Game(bool newGame)
{
    if( newGame == true )
        currentLevel = new Level(1);
    else
        currentLevel = new Level(-1); //Should read from save file for which level to load
}

Game::~Game()
{
    delete currentLevel;
}

int Game::runGame()
{
    bool firstRun = true;
    Timer fps;
    const int FRAMES_PER_SECOND = 30;

    SDL_Event event;

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
                            currentLevel->getPlayer(1)->setYVel(-16);
                            //currentLevel->getPlayer(2)->setYVel(-16);
                            break;
                        case SDLK_s:
                            currentLevel->getPlayer(1)->setYVel(+16);
                            //currentLevel->getPlayer(2)->setYVel(+16);
                            break;
                        case SDLK_a:
                            currentLevel->getPlayer(1)->setXVel(-16);
                            //currentLevel->getPlayer(2)->setXVel(-16);
                            break;
                        case SDLK_d:
                            currentLevel->getPlayer(1)->setXVel(+16);
                            //currentLevel->getPlayer(2)->setXVel(+16);
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
                            currentLevel->getPlayer(1)->setYVel(0);
                            //currentLevel->getPlayer(2)->setYVel(0);
                            break;
                        case SDLK_s:
                            currentLevel->getPlayer(1)->setYVel(+0);
                            //currentLevel->getPlayer(2)->setYVel(+0);
                            break;
                        case SDLK_a:
                            currentLevel->getPlayer(1)->setXVel(0);
                            //currentLevel->getPlayer(2)->setXVel(0);
                            break;
                        case SDLK_d:
                            currentLevel->getPlayer(1)->setXVel(+0);
                            //currentLevel->getPlayer(2)->setXVel(+0);
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

int Game::pauseGame()
{
    int pauseValue = 1;
    SDL_Event event;
    SDL_Surface* pauseMenu = Utility::loadImage("resources\\menu3.png");

    while (pauseValue == 1) {
        if (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                /**/case SDL_MOUSEBUTTONDOWN:
                    break;
                /**/case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x > 390 && x < 890) {
                            if (y > 134 && y < 234)
                                return pauseValue;
                            else if (y > 234 && y < 334)
                                pauseValue = 0;
                            else if (y > 334 && y < 444)
                                pauseValue = -1;
                        }
                    }
                    break;
                /**/case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        return pauseValue;
                    break;
                default: break;
            }

        }
        Utility::applySurface(0, 0, pauseMenu);
        text->displayText(523, 158, "Unpause", 46);
        text->displayText(505, 258, "Quit", 46);
        text->displayText(589, 558, "Exit", 46);
    }
    return pauseValue;
}