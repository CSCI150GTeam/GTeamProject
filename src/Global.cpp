#include "Global.h"

SDL_Surface* mainScreenSurface = SDL_SetVideoMode(1280,768,32,SDL_FULLSCREEN);

int GS_EXIT = -1;
int GS_MENU = 1;
int GS_EDIT = 2;
int GS_GAME = 3;

int MS_MAIN = 4;
int 