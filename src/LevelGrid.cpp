#include "LevelGrid.h"

LevelGrid::LevelGrid(int width, int height)
{
    //initialize variables
    width = width;
    height = height;
    grid = new vector<vector<int>*>;

    //fill grid with int arrays
    for (int i = 0; i < height; i++)
        grid->push_back(new vector<int>);

    //assign 1s to all slots in the grid
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            grid->at(i)->push_back(1);

    brick = loadImage(BRICK_IMG);
    dirt = loadImage(DIRT_IMG);
    dirtybrick = loadImage(DIRTYBIRCK_IMG);
    grass = loadImage(GRASS_IMG);
    lava = loadImage(LAVA_IMG);
    redcarpet = loadImage(REDCARPET_IMG);
    stone = loadImage(STONE_IMG);
    water = loadImage(WATER_IMG);
    wood = loadImage(WOOD_IMG);
}

LevelGrid::~LevelGrid()
{
    SDL_FreeSurface(brick);
    SDL_FreeSurface(dirt);
    SDL_FreeSurface(dirtybrick);
    SDL_FreeSurface(grass);
    SDL_FreeSurface(lava);
    SDL_FreeSurface(redcarpet);
    SDL_FreeSurface(stone);
    SDL_FreeSurface(water);
    SDL_FreeSurface(wood);
}

bool LevelGrid::inEndzone(int x, int y)
{
    if ((x > endzone.x) && (x < (endzone.x + endzone.w)) && (y > endzone.y) && (y < (endzone.y + endzone.h)))
        return true;
    else return false;
}

void LevelGrid::loadGrid(string filePath)
{
    ifstream infile;
    infile.open(filePath.c_str());
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 40; j++) {
            int temp;
            if (infile >> temp)
                grid->at(i)->at(j) = temp;
            else
                break;
        }
        if (!infile)
            break;
    }
    infile >> p1Spawn.x;
    infile >> p1Spawn.y;
    infile >> p2Spawn.x;
    infile >> p2Spawn.y;
    infile >> endzone.x;
    infile >> endzone.y;
    infile >> endzone.w;
    infile >> endzone.h;
    
    infile.close();
    //printGrid();
}

void LevelGrid::printGrid()
{
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 40; j++) {
            cout << grid->at(i)->at(j) << " ";
        }
        cout << endl;
    }
    cout << "Player 1 spawn: (" << p1Spawn.x << "," << p1Spawn.y << ")" << endl;
    cout << "Player 2 spawn: (" << p2Spawn.x << "," << p2Spawn.y << ")" << endl;
    cout << "Endzone is the area covered by x = " << endzone.x << " to x = " << endzone.x + endzone.w
            << " and y = " << endzone.y << " to y = " << endzone.y + endzone.h << endl;
}

void LevelGrid::drawGrid()
{
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 40; j++)
            switch (grid->at(i)->at(j))
            {
                case 1:
                    applySurface(j * 32, i * 32, brick);
                    break;
                case 2:
                    applySurface(j * 32, i * 32, dirt);
                    break;
                case 3:
                    applySurface(j * 32, i * 32, dirtybrick);
                    break;
                case 4:
                    applySurface(j * 32, i * 32, grass);
                    break;
                case 5:
                    applySurface(j * 32, i * 32, lava);
                    break;
                case 6:
                    applySurface(j * 32, i * 32, redcarpet);
                    break;
                case 7:
                    applySurface(j * 32, i * 32, stone);
                    break;
                case 8:
                    applySurface(j * 32, i * 32, water);
                    break;
                case 9:
                    applySurface(j * 32, i * 32, wood);
                    break;


            }
    }
}

SDL_Rect LevelGrid::getP1Spawn()
{
    return p1Spawn;
}

SDL_Rect LevelGrid::getP2Spawn()
{
    return p2Spawn;
}

SDL_Rect LevelGrid::getEndzone()
{
    return endzone;
}

SDL_Surface* LevelGrid::loadImage(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if (loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    } else
        cout << "Error: Image file failed to load";
    return optimizedImage;
}

void LevelGrid::applySurface(int x, int y, SDL_Surface* source)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, NULL, mainScreenSurface, &offset);
}