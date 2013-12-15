#include "Game.h"
#include "Timer.h"
#include "Application.h"
#include "Global.h"

Game::Game(bool newGame)
{
    cout << "Creating game object..." << endl;
    if (newGame == true)
        currentLevel = new Level(1);
    else
        currentLevel = new Level(1); //should read level from save file
    cout << "game object created" << endl;
}

Game::~Game()
{
    delete currentLevel;
}

int Game::runGame()
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
                            int x = pauseGame();
                            switch (x)
                            {
                                case false:
                                    break;
                                case true:
                                    return GS_MENU;
                            }
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        //Update
        currentLevel -> update();

        //Draw
        currentLevel -> drawGrid();
        currentLevel -> drawUnits();
        //displayDebug();
        if (SDL_Flip(mainScreenSurface) == -1)
            cout << "SDL_Flip failed" << endl;
    }
}

bool Game::pauseGame()
{
    bool isPaused = true;
    SDL_Event event;
    SDL_Surface* pauseMenu = Utility::loadImage("Resources\\menu2.png");
    if(pauseMenu == NULL)
        cout<<"Pause menu image didn't load"<<endl;

    while (isPaused)
    {
        cout<<"in pause loop";
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
                                return false;
                            else if (y > 234 && y < 334)
                                return true;
                        }
                    }
                    break;
                /**/case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        return false;
                    break;
                default: break;
            }

        }
        Utility::applySurface(0, 0, pauseMenu);
        text->displayText(523, 158, "Unpause", 46);
        text->displayText(505, 258, "Quit", 46);
        if (SDL_Flip(mainScreenSurface) == -1)
            cout << "SDL_Flip failed" << endl;
    }
    SDL_FreeSurface(pauseMenu);
    return false;
}

void Game::displayDebug()
{
    cout << "Displaying debug" << endl;
    char* lol;
    lol = currentLevel->getPlayer(1)->getX();
    cout << lol << endl;
    text->displayText(0, 0, lol, 20);
}