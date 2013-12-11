/*
#include "Editor.h"

Editor::Editor()
{
    editorState = EDT_NLOAD;
    runEditor();
}

Editor::~Editor()
{
    
}

void Editor::editExisting(int input);
{
    //Draw the editor interface
    while( editorState != EDT_EXIT )
    {
        //Take input
        SDL_Event event;
        if( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_QUIT: break;
                case SDL_MOUSEMOTION: break;
                case SDL_MOUSEBUTTONDOWN: break;
                case SDL_MOUSEBUTTONUP:
                    
                    break;
            }
        }
        //Handle events/process logic
        //Update screen
    }
}

void Editor::editNew()
{
    grid = new MapGrid(10,10);
    
}

*/