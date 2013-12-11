#ifndef GLOBAL_H
#define	GLOBAL_H

#include "SDL/SDL.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 768;

const SDL_Surface* mainScreenSurface = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE);

const int GS_EXIT = -1;
const int GS_MENU = 1;
const int GS_EDIT = 2;
const int GS_GAME = 3;

const int MS_MAIN = 4;
const int MS_SINGLE = 5;
const int MS_MULTI = 6;
const int MS_EDIT = 7;
const int MS_SET =8;

#endif