#include "Application.h"

//Constructor

Application::Application()
{
    audio = NULL;
    editor = NULL;
    menu = NULL;
    game = NULL;
}

//Destructor

Application::~Application()
{
    SDL_Quit;
}

//Initializes main SDL subsystems, SDL_Mixer, and sets the window caption

bool Application::initializeApplication()
{
    //Initialize SDL Subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        cout << "\tERROR: SDL subsystem initialization failed!" << endl;
        return false;
    }

    //Initialize SDL_Mixer
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        cout << "Audio didn't open" << endl;
        return false;
    }

    //Set window caption
    SDL_WM_SetCaption("Hello World", NULL);

    audio = new AudioManager();
    return true;
}

void Application::runApplication()
{
    while (gameState != GS_EXIT) {
        switch (gameState)
        {
            case GS_MENU:
                menu = new Menu();
                //menu -> runMenu();
                delete menu;
                break;
            case GS_EDIT:
                editor = new Editor();
                //editor -> runEditor();
                delete editor;
                break;
            case GS_GAME:
                game = new Game();
                //game -> runGame();
                delete game;
                break;
        }
    }
}