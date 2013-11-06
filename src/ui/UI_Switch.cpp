#include "UI_Switch.h"

UI_Switch::UI_Switch(SDL_Surface* iScreen)
{
    this->state = true;
    this->screen = iScreen;
    this->width = 256;
    this->height = 64;
    //this->screen = SDL_SetVideoMode(1024,768,32,SDL_SWSURFACE);
}

UI_Switch::~UI_Switch()
{
    
}

void UI_Switch::drawOnScreen(int iX, int iY)
{
    SDL_Surface* tile = NULL;
    if( this->state == true )
        tile = loadImage("Resources\\images\\UI_Switch_ON.png");
    else tile = loadImage("Resources\\images\\UI_Switch_OFF.png");
    if( tile == NULL )
        cout<<"TILE DIDN'T LOAD"<<endl;
    applySurface(iX,iY,tile,screen);
    SDL_Flip(screen);
}

void UI_Switch::checkMouseClick(int x, int y)
{
    if( (x > this->x) && (x < this->x + this->width) && (y > this->y) && (y < this->y+this->height) )
    {
        if(state == true)
            state = false;
        else state = true;
        drawOnScreen(0,0);
    }
}

SDL_Surface* UI_Switch::loadImage(string filename)
{
     SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    return optimizedImage;
}

void UI_Switch::applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source,NULL,destination,&offset);
}