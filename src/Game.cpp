#include "Game.h"
#include "Command.h"

Game::Game(bool newGame)
{
    if (newGame == true){
        currentLevelNumber = 1;
        multiPlayer= false;
    }
    else {
        ifstream infile;
        infile.open("resources\\data_saveGameData.txt");
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
    while (!quit)
    {
        audio->playMusic(SFX_MUS1);
        if (runGameLoop() == GS_MENU) {
            Mix_HaltMusic();
            cout << "DEBUG: (Game.cpp) game is quitting." << endl;
            return GS_MENU;
        }
        cout << "DEBUG: (Game.cpp) Level complete, loading victory screen" << endl;
        currentLevelNumber++;

        SDL_Event event;
        SDL_Surface* victoryMenu = Utility::loadImage("Resources\\ui_menu2.png");
        bool atVictoryScreen = true;

        while (atVictoryScreen)
        {
            if (SDL_PollEvent(&event)) {
                switch (event.type)
                {
                    /**/case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            int x = event.button.x, y = event.button.y;
                            if (x > 390 && x < 890) {
                                if (y > 134 && y < 234) //Continue
                                {
                                    audio->playSound(SFX_BUTTON);
                                    delete currentLevel;
                                    currentLevel = new Level(currentLevelNumber);
                                    atVictoryScreen = false;
                                    if (currentLevelNumber > 5)
                                        quit = true;
                                    break;
                                } else if (y > 234 && y < 334) {
                                    audio->playSound(SFX_BUTTON);
                                    ofstream outfile;
                                    outfile.open("resources\\data_saveGameData.txt");
                                    outfile << currentLevelNumber;
                                    outfile.close();
                                    Mix_HaltMusic();
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
    Mix_HaltMusic();
    //display game complete screen
    return GS_MENU;
}

int Game::runGameLoop()
{
    audio->playSound(SFX_BEGIN);
    frameCounter = 0;

    bool victory = false;

    gameTimer.start();
    while (!victory) {
        fps.start();

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
            default: break;
        }
        switch (draw(frameCounter))
        {
            case 0: break;
            case 2: return GS_MENU;
            default: break;
        }
        frameCounter++;
        if (frameCounter > 30)
            frameCounter = 0;
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
    }
    audio->playSound(SFX_END);
    return 1;
}

int Game::input()
{
    SDL_Event event;
    if(multiPlayer) CMD.take(); 
    if (SDL_PollEvent(&event)){
        CMD.push(event, multiPlayer);
        currentLevel->input(CMD.slfCmd, CMD.othCmd);
        if (event.type == SDL_KEYUP)
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                bool x = pauseGame();
                switch (x)
                {
                    case false:
                        break;
                    case true:
                        return 2;
                        break;
                }
            }
    }
    return 0;
}

int Game::update()
{
    currentLevel -> update();
    if (currentLevel -> victoryCondition())
        return 1;
    else return 0;
}

int Game::draw(int frame)
{
    SDL_Surface* bar = Utility::loadImage("resources\\ui_topBar.png");
    Utility::applySurface(0, 640, bar);

    currentLevel -> draw(frame);

    //displayDebug();

    if (SDL_Flip(mainScreenSurface) == -1)
        return 2;
    else
        return 0;
}

bool Game::pauseGame()
{
    gameTimer.pause();
    bool isPaused = true;
    SDL_Event event;
    SDL_Surface* pauseMenu = Utility::loadImage("Resources\\ui_menu2.png");
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
                            if (y > 134 && y < 234) {
                                audio->playSound(SFX_BUTTON);
                                return false;
                            } else if (y > 234 && y < 334) {
                                audio->playSound(SFX_BUTTON);
                                ofstream outfile;
                                outfile.open("resources\\data_saveGameData.txt");
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
    gameTimer.unpause();
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

int Game::getFrameCounter()
{
    return frameCounter;
}