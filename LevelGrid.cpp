#include "LevelGrid.h"
using namespace std;

LevelGrid::LevelGrid(int width, int length)
{
    //initialize variables
    this->width = width;
    this->height = length;
    this->grid = new int*[this->width];
    cout<<"Width = "<<this->width<<endl;
    cout<<"Length = "<<this->height<<endl;
    
    //fill grid with int arrays
    for(int i = 0; i < this->width; i++)
        grid[i] = new int[this->height];
    
    //assign 0s to all slots in the grid
    for(int i = 0; i < this->width; i++)
        for(int j = 0; j < this->height; j++)
        {
            if(i%2 == 0)
                grid[i][j] = 2;
            else
                grid[i][j] = 1;
        }
}

LevelGrid::~LevelGrid()
{
    
}

void LevelGrid::printGrid()
{
    for( int i = 0; i < this->width; i++)
    {
        for( int j = 0; j < this->height; j++)
            cout<<this->grid[i][j]<<"\t";
        cout<<endl;
    }
}

void LevelGrid::drawGrid(SDL_Surface* screen)
{
    //Load images
    SDL_Surface* grass = loadImage(GRASS_IMG);
    SDL_Surface* stone = loadImage(STONE_IMG);
    
    for(int i = 0; i < this->width; i++)
        for(int j = 0; j < this->height; j++)
        {
            if( grid[i][j] == 1 )
                applySurface( (i*32), (j*32), grass, screen);
            else if( grid[i][j] == 2 )
                applySurface( (i*32), (j*32), stone, screen);
        }
    
    SDL_FreeSurface(grass);
    SDL_FreeSurface(stone);
    //Loop through the grid and display the textures
}

SDL_Surface* LevelGrid::loadImage(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = SDL_LoadBMP(filename.c_str());
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    return optimizedImage;
}

void LevelGrid::applySurface(int x,int y,SDL_Surface* source,SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source,NULL,destination,&offset);
}
