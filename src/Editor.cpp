#include "Editor.h"

Editor::Editor()
{
    grid = new Grid("resources\\data_c1.txt");
}

Editor::~Editor()
{
    
}

int Editor::runEditor()
{
    input();
    update();
    draw();
}

void Editor::input()
{
    SDL_Event event;
    if( SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_MOUSEBUTTONUP:
                break;
        }
    }
}

void Editor::update()
{
    //take coordinates of click, and either update the grid, switch active tile, or save & close the file
}

void Editor::draw()
{
    SDL_Surface* bar = Utility::loadImage("resources\\ui_topBar.png");
    Utility::applySurface(0, 640, bar);
    grid->drawGrid();
}