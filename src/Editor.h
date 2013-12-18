/*
 * Editor.h - Editor module
 * Code contributed by: Sammy
 * Header file
 */

#ifndef EDITOR_H
#define	EDITOR_H

#include <fstream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Grid.h"

class Editor
{
public:
    Editor();
    ~Editor();
    int runEditor();
private:
    void input();
    void update();
    void draw();
    
    Grid* grid;
};

#endif