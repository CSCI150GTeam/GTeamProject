#include "LevelGrid.h"
#include "Application.h"

LevelGrid::LevelGrid(int width, int length)
{
    //initialize variables
    this->width = width;
    this->height = length;
    this->grid = new int*[this->width];
    cout<<"\nWidth = "<<this->width<<endl;
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

void LevelGrid::loadGrid()
{
    ifstream infile;
    infile.open("level.txt");
    if( infile.fail() )
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
    cout<<this->height<<"\t"<<this->width<<endl;
    infile.close();
}
void LevelGrid::printGrid()
{
    for( int i = 0; i < this->width; i++)
    {
        for( int j = 0; j < this->height; j++)
        {
            cout<<this->grid[i][j]<<"\t"<<endl;
        }
    }
}

void LevelGrid::drawGrid()
{
    //Load images
    SDL_Surface* brick = loadImage(BRICK_IMG);
    SDL_Surface* dirt = loadImage(DIRT_IMG);
    SDL_Surface* dirtybrick = loadImage(DIRTYBIRCK_IMG);
    SDL_Surface* grass = loadImage(GRASS_IMG);
    SDL_Surface* lava = loadImage(LAVA_IMG);
    SDL_Surface* redcarpet = loadImage(REDCARPET_IMG);
    SDL_Surface* stone = loadImage(STONE_IMG);
    SDL_Surface* water = loadImage(WATER_IMG);
    SDL_Surface* wood = loadImage(WOOD_IMG);
    
    for(int i = 0; i < this->width; i++)
    {
        for(int j = 0; j < this->height; j++)
        {
            if( grid[i][j] == 1 )
                applySurface( (i*32), (j*32), brick);
            else if( grid[i][j] == 2 )
                applySurface( (i*32), (j*32), dirt);

            //addition
            else if( grid[i][j] == 3 )
                applySurface( (i*32), (j*32), dirtybrick);
            else if( grid[i][j] == 4 )
                applySurface( (i*32), (j*32), grass);
            else if( grid[i][j] == 5 )
                applySurface( (i*32), (j*32), lava);
            else if( grid[i][j] == 6 )
                applySurface( (i*32), (j*32), redcarpet);
            else if( grid[i][j] == 7 )
                applySurface( (i*32), (j*32), stone);
            else if( grid[i][j] == 8 )
                applySurface( (i*32), (j*32), water);
            else if ( grid[i][j] == 9 )
                applySurface( (i*32), (j*32), wood);
                              
        }
    }
    
    SDL_FreeSurface(brick);
    SDL_FreeSurface(dirt);
    SDL_FreeSurface(dirtybrick);
    SDL_FreeSurface(grass);
    SDL_FreeSurface(lava);
    SDL_FreeSurface(redcarpet);
    SDL_FreeSurface(stone);
    SDL_FreeSurface(water);
    SDL_FreeSurface(wood);
 
    //Loop through the grid and display the textures
}

SDL_Surface* LevelGrid::loadImage(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        cout<<"Error: Image file failed to load";
    return optimizedImage;
}

void LevelGrid::applySurface(int x,int y,SDL_Surface* source)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source,NULL,mainScreenSurface,&offset);
}