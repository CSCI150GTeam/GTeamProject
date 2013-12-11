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
    cout<<"running main app loop"<<endl;
    while (gameState != GS_EXIT)
    {
        cout<<"gameState is "<<gameState<<endl;
        switch (gameState)
        {
            case GS_MENU:
                cout<<"running menu loop"<<endl;
                menu = new Menu();
                gameState = menu -> runMenu();
                delete menu;
                cout<<"exiting menu loop, gameState is "<<gameState<<endl;
                break;
            case GS_EDIT_NEW: case GS_EDIT_LOAD:
                /*
                cout<<"running editor loop"<<endl;
                editor = new Editor();
                //gameState = editor -> runEditor();
                delete editor; */
                gameState = GS_MENU;
                break;
            case GS_GAME_NEW: case GS_GAME_CONT:
                /*
                if( gameState == GS_GAME_NEW )
                    game = new Game(true);
                else game = new Game(false);
                gameState = game -> runGame();
                delete game; */
                gameState = GS_MENU;
                break;
            //assumes new games for multiplayer
            case GS_GAME_JOIN: 
                game= new Game(true);
                game->playerUno= false;
                char serv_ip[16];             
                gameState= game->multiGame(client(serv_ip));
                break;
            case GS_GAME_HOST:
                game= new Game(true);
                game->playerUno= true;
                gameState= game->multiGame(server());
                gameState = GS_MENU;
                break;
        }
    }
}