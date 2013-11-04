#include "GameManager.h"

GameManager::GameManager(Animation_Test* iAnim)
{
    this->gameState = 1;
    this->anim = iAnim;
    runMenuLoop();
}

GameManager::~GameManager()
{
    
}
/*
void GameManager::runGridTestLoop()
{
    LevelGrid* lg = new LevelGrid(10,10);
    lg->loadGrid();
    lg->printGrid();
    lg->drawGrid(screen);
    
    if( SDL_Flip(screen) == -1)
        cout<<"Whoops, screen didn't flip in GameManager::runGridTestLoop()";
    SDL_Delay(3000);
}
*/
void GameManager::runMenuLoop()
{
    anim->drawMenuScreen(0,0);
    cout<<anim->flipScreen()<<endl;
    cout<<"Starting MenuLoop..."<<endl;
    int x = 0;
    while( this->gameState == 1 ) 
    {
        x++;
        //Take input
        SDL_Event event;
        if( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_QUIT: this->gameState = -1; break;
            }
        }
        //Handle logic
        //Update screen
    }
    cout<<"Loop ran "<<x<<" times"<<endl;
    switch (gameState)
    {
        case -1: cout<<"gameState change: -1"<<endl; return; break;
        case 2: cout<<"gameState change: 2"<<endl; runGameLoop(); break;
        case 3: cout<<"gameState change: 3"<<endl; runEditorLoop(); break;
    }
}

void GameManager::runGameLoop()
{
    while( this->gameState == 2 )
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

void GameManager::runEditorLoop()
{
    while( this->gameState == 3 )
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