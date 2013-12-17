#include "Application.h"
#include "net.h"

//Constructor

Application::Application()
{
    editor = NULL;
    menu = NULL;
    game = NULL;

    gameState = GS_MENU;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        cout << "\tERROR: SDL subsystem initialization failed!" << endl;
        gameState = GS_EXIT;
    }

    SDL_WM_SetCaption("Hello World", NULL);
}

//Destructor

Application::~Application()
{
    SDL_Quit;
}

void Application::runApplication()
{
    while (gameState != GS_EXIT) {
        switch (gameState)
        {
            case GS_MENU:
                menu = new Menu();
                gameState = menu -> runMenu();
                delete menu;
                break;
            case GS_EDIT_NEW: case GS_EDIT_LOAD:
                /*
                editor = new Editor();
                //gameState = editor -> runEditor();
                delete editor; */
                gameState = GS_MENU;
                break;
            case GS_GAME_NEW:
                game = new Game(true);
                gameState = game -> runGame();
                delete game;
                break;
            case GS_GAME_CONT:
                game = new Game(false);
                gameState = game -> runGame();
                delete game;
                break;
            case GS_GAME_HOST: case GS_GAME_JOIN:
                gameState = GS_MENU;
                break;
        }
    }
}