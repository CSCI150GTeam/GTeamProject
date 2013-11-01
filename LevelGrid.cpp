#include "LevelGrid.h"
using namespace std;

LevelGrid::LevelGrid(int width, int length)
{
    //initialize variables
    this->width = width;
    this->height = length;
    this->grid = new int*[this->width];
    
    //fill grid with int arrays
    for(int i = 0; i < this->width; i++)
    {
        grid[i] = new int[this->height];
        for(int j = 0; j < this->height; j++)
            grid[i][j] = 0;
    }
}

LevelGrid::~LevelGrid()
{
    
}

void LevelGrid::loadGrid()
{
    ifstream infile;
    infile.open("Resources\\level.txt");
    if( !infile.is_open() )
        cout<<"File read failed";
    else
        for( int j = 0; j < width; j++)
        {
            for( int i = 0; i < height; i++ )
            {
                if( !(infile >> grid[i][j]) )
                    break;
            }
            if( !infile )
                break;
        }
    infile >> this->height;
    infile >> this->width;
    cout<<this->height<<"\t"<<this->width;
    infile.close();
}

void LevelGrid::printGrid()
{
    for( int y = 0; y < height; y++)
    {
        for( int x = 0; x < width; x++ )
        {
            cout<<grid[x][y]<<"\t";
        }
        cout<<endl;
    }
}

void LevelGrid::saveGrid()
{
    
}

void LevelGrid::drawGrid(SDL_Surface* screen)
{
    //Load images
    SDL_Surface* grass = loadImage("Resources\\grass.bmp");          //1
    SDL_Surface* ice = loadImage("Resources\\ice.bmp");              //2
    SDL_Surface* lava = loadImage("Resources\\lava.bmp");            //3
    SDL_Surface* stone = loadImage("Resources\\stone.bmp");          //4
    SDL_Surface* water = loadImage("Resources\\water.bmp");          //5
    SDL_Surface* waterDrops = loadImage("Resources\\waterDrops.bmp");       //6
    
    if(grass == NULL || stone == NULL)
        cout<<"Error: Tile images didn't load"<<endl;
    
    for(int i = 0; i < this->width; i++)
        for(int j = 0; j < this->height; j++)
        {
            switch( grid[i][j] )
            {
                case 1:
                    applySurface(i*32, j*32, grass, screen);
                    break;
                case 2:
                    applySurface(i*32, j*32, ice, screen);
                    break;
                case 3:
                    applySurface(i*32, j*32, lava, screen);
                    break;
                case 4:
                    applySurface(i*32, j*32, stone, screen);
                    break;
                case 5:
                    applySurface(i*32, j*32, water, screen);
                    break;
                case 6:
                    applySurface(i*32, j*32, waterDrops, screen);
                    break;
            }
        }
    //Clean up memory
    SDL_FreeSurface(grass);
    SDL_FreeSurface(ice);
    SDL_FreeSurface(lava);
    SDL_FreeSurface(stone);
    SDL_FreeSurface(water);
    SDL_FreeSurface(waterDrops);
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