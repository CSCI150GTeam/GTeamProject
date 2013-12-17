#include "Game.h"

Game::Game(bool newGame)
{
    if (newGame == true)
        currentLevelNumber = 1;
    else {
        ifstream infile;
        infile.open("resources\\SaveGameData.txt");
        infile >> currentLevelNumber;
        infile.close();
    }
    currentLevel = new Level(currentLevelNumber);
}

Game::~Game()
{
    delete currentLevel;
}

int Game::runGame()
{
    bool quit = false;
    while (!quit) {
        if (runGameLoop() == GS_MENU)
            return GS_MENU;
        cout<<"DEBUG: (Game.cpp) Level complete, loading victory screen"<<endl;
        currentLevelNumber++;

        SDL_Event event;
        SDL_Surface* victoryMenu = Utility::loadImage("Resources\\menu2.png");
        bool atVictoryScreen = true;

        while (atVictoryScreen) {
            if (SDL_PollEvent(&event)) {
                switch (event.type)
                {
                    /**/case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            int x = event.button.x, y = event.button.y;
                            if (x > 390 && x < 890) {
                                if (y > 134 && y < 234) //Continue
                                {
                                    delete currentLevel;
                                    currentLevel = new Level(currentLevelNumber);
                                    atVictoryScreen = false;
                                    if (currentLevelNumber > 5)
                                        quit = true;
                                    break;
                                } else if (y > 234 && y < 334) {
                                    ofstream outfile;
                                    outfile.open("resources\\SaveGameData.txt");
                                    outfile << currentLevelNumber;
                                    outfile.close();
                                    return GS_MENU;
                                }
                            }
                        }
                        break;
                    /**/default:
                        break;
                }
            }
            Utility::applySurface(0, 0, victoryMenu);
            text->displayText(490, 58, "Level Complete!", 46);
            text->displayText(523, 158, "Next Level", 46);
            text->displayText(495, 258, "Save and Quit", 46);
            if (SDL_Flip(mainScreenSurface) == -1)
                cout << "SDL_Flip failed" << endl;
        }
    }
    //display game complete screen
    return GS_MENU;
}

int Game::runGameLoop()
{
    Timer fps;
    const int FRAMES_PER_SECOND = 30;
    bool victory = false;

    while (!victory) {
        fps.start();
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());

        /* 0 = continue
         * 1 = victory
         * 2 = quit (return GS_MENU)
         */

        switch (input())
        {
            case 0: break;
            case 2: return GS_MENU;
            default: break;
        }
        switch (update())
        {
            case 0: break;
            case 1: victory = true;
                break;
            case 2: return GS_MENU;
            default: break;
        }
        switch (draw())
        {
            case 0: break;
            case 2: return GS_MENU;
            default: break;
        }
    }
}

int Game::input()
{
    SDL_Event event;
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
                                return 2;
                                break;
                        }
                        break;
                }
                break;
            default:
                break;
        }

    }
    return 0;
}

int Game::update()
{
    currentLevel -> update();
    if (currentLevel -> inEndzone())
        return 1;
    else return 0;
}

int Game::draw()
{
    currentLevel -> draw();
    //displayDebug();
    if (SDL_Flip(mainScreenSurface) == -1)
        return 2;
    else
        return 0;
}

bool Game::pauseGame()
{
    bool isPaused = true;
    SDL_Event event;
    SDL_Surface* pauseMenu = Utility::loadImage("Resources\\menu2.png");
    if (pauseMenu == NULL)
        cout << "Pause menu image didn't load" << endl;

    while (isPaused) {
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
                            else if (y > 234 && y < 334) {
                                ofstream outfile;
                                outfile.open("resources\\SaveGameData.txt");
                                outfile << currentLevelNumber;
                                outfile.close();
                                return true;
                            }
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
        text->displayText(495, 258, "Save and Quit", 46);
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
    //lol = currentLevel->getPlayer(1)->getX();
    cout << lol << endl;
    text->displayText(0, 0, lol, 20);
}