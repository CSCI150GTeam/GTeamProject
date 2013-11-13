/*
 * GameManager.cpp - core module
 * Code contributed by: Sammy
 * Handles the game state (menus, editor, in-game), and is in control of starting the appropriate
 * loops for each state when a change occurs. When the GameManager is initialized, the game state is set to MENU,
 * so that the user will be taken immediately into the menu system when they launch the app
 */

#include "GameManager.h"

//Constructor
GameManager::GameManager()
{
    cout<<"\tGameManager initialized"<<endl;
    cout<<"\tManagers initialized"<<endl;
    this->gameState = GS_MENU;
    cout<<"APP INITIALIZATION COMPLETE"<<endl;
    cout<<"USER IS NOW CONTROLLING THE APP"<<endl;
    this->menuState = 0;
    runMenuLoop(menuState);
    cout<<"USER IS NO LONGER CONTROLLING THE APP"<<endl;
}

//Destructor
GameManager::~GameManager()
{
    
}

//Screen accessor method
SDL_Surface* GameManager::getScreen()
{
    return this->screen;
}

//Menu loop
void GameManager::runMenuLoop(int iMenuState)
{
    cout<<"\tEntering menus..."<<endl;
    int menuState = iMenuState;
    UI_View* currentMenuView; //= UI_Manager::menuViews->at(menuState);
    
    //Test
    string filename = "resources\\images\\mainMenuScreen.jpg";
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if( loadedImage != NULL )
    {
        cout<<"TEST Loaded image isn't Null!"<<endl;
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;
    SDL_BlitSurface(optimizedImage,NULL,mainScreenSurface,&offset);
    
    while( this->gameState == GS_MENU ) 
    {
        //Take input
        SDL_Event event;
        SDL_PollEvent( &event );
        if( event.type == SDL_QUIT )
            gameState = GS_QUIT;
        //Handle logic
        //string result = currentMenuView->handleEvents(event);
        
        SDL_Flip( mainScreenSurface );
    }
    switch (gameState)
    {
        case GS_QUIT: cout<<"\tgameState change: Quit"<<endl; return; break;
        case GS_GAME: cout<<"\tgameState change: Gameplay"<<endl; runGameLoop(); break;
        case GS_EDITOR: cout<<"\tgameState change: Editor"<<endl; runEditorLoop(); break;
    }
}

void GameManager::runEditorLoop()
{
    while( this->gameState == GS_EDITOR )
    {
        //Take input
        SDL_Event event;
        if( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_QUIT: this->gameState = -1; break;
            }
        }
    }
}

void GameManager::runGameLoop()
{
    while( this->gameState == GS_EDITOR )
    {
        SDL_Event event;
        if( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_QUIT: this->gameState = -1; break;
            }
        }
    }
}