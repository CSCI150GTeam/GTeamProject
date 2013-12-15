#include "Application.h"
#include "net.h"

//Constructor

Application::Application()
{
    editor = NULL;
    menu = NULL;
    game = NULL;

    gameState = GS_MENU;
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

    //Set window caption
    SDL_WM_SetCaption("Hello World", NULL);

    return true;
}

void Application::runApplication()
{
    cout << "running main app loop" << endl;
    while (gameState != GS_EXIT) {
        cout << "gameState is " << gameState << endl;
        switch (gameState)
        {
            case GS_MENU:
                cout << "running menu loop" << endl;
                menu = new Menu();
                gameState = menu -> runMenu();
                delete menu;
                cout << "exiting menu loop, gameState is " << gameState << endl;
                break;
            case GS_EDIT_NEW: case GS_EDIT_LOAD:
                /*
                cout<<"running editor loop"<<endl;
                editor = new Editor();
                //gameState = editor -> runEditor();
                delete editor; */
                gameState = GS_MENU;
                break;
            case GS_GAME_NEW:  case GS_GAME_CONT: case GS_GAME_HOST: case GS_GAME_JOIN:
                cout<<"case GS_GAME_NEW"<<endl;
                Game* game = new Game(true);
                cout<<"game object created, running loop"<<endl;
                gameState = game -> runGame();
                cout<<"exiting loop"<<endl;
                delete game;
                break;
        }
    }
}