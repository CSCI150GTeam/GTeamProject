#include "Application.h"
#include "net.h"

//Constructor

Application::Application()
{
    editor = NULL;
    menu = NULL;
    game = NULL;

    gameState = GS_MENU;

    if ( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    {
	cout << "ERROR: SDL subsystem initialization failed!" << endl;
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
    while ( gameState != GS_EXIT )
    {
	switch ( gameState )
	{
	    case GS_MENU:
		menu = new Menu();
		gameState = menu -> runMenu();
		delete menu;
		break;
	    case GS_EDIT_NEW:
		editor = new Editor();
		gameState = editor -> runEditor();
		delete editor;
		break;
	    case GS_EDIT_LOAD: //Disabled
		gameState = GS_MENU;
		break;
	    case GS_GAME_NEW:
		game = new Game(true,0);
		gameState = game -> runGame();
		delete game;
		break;
	    case GS_GAME_CONT:
		game = new Game(false,0);
		gameState = game -> runGame();
		delete game;
		break;
	    case GS_GAME_HOST:
	    {
		SDL_Surface* blk = Utility::loadImage("resources\\ui_blackScreen");
		Utility::applySurface(0,0,blk);
		text->displayText(0, 0, "waiting for other player",44);
		int sock = server();
		game = new Game(false,sock);
		gameState = game -> runGame();
		delete game;
		break;
	    }
	    case GS_GAME_JOIN:
	    {
		ifstream infile;
		infile.open("resources\\data_ip.txt");
		char IP[16];
		infile >> IP;
		cout<<"IP is: "<<IP<<endl;
		int socket = client(IP);
		game = new Game(false,socket);
		gameState = game -> runGame();
		delete game;
		break;
	    }
	}
    }
}