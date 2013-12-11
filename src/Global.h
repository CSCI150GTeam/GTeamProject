#ifndef GLOBAL_H
#define	GLOBAL_H

#include "SDL/SDL.h"

extern SDL_Surface* mainScreenSurface;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 788;

//Game states
const int GS_EXIT = -1;
const int GS_MENU = 0;
const int GS_EDIT_NEW = 1;
const int GS_EDIT_LOAD = 2;
const int GS_GAME_NEW = 3;
const int GS_GAME_CONT = 4;
const int GS_GAME_JOIN = 5;
const int GS_GAME_HOST = 6;

const int MAX_GS = 6;

//Menu screens
const int MS_MAIN = 7;
const int MS_SINGLE = 8;
const int MS_MULTI = 9;
const int MS_EDIT = 10;
const int MS_SET = 11;

#endif