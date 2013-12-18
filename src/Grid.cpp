#include "Grid.h"

Grid::Grid(string input)
{
    //initialize variables
    this->width = 40;
    this->height = 24;
    grid = new vector<vector<int>*>;

    //fill grid with int arrays
    for (int i = 0; i < height; i++)
        grid->push_back(new vector<int>);

    //assign 1s to all slots in the grid
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            grid->at(i)->push_back(1);

    loadGrid(input);
    loadImages();
}

Grid::Grid(vector<vector<int>*>* iGrid)
{
    this -> grid = iGrid;
    height = grid -> size();
    width = grid -> at(0) -> size();
    loadImages();
}

Grid::~Grid()
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

void Grid::loadGrid(string filePath)
{
    ifstream infile;
    infile.open(filePath.c_str());
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp;
            if (infile >> temp)
                grid->at(i)->at(j) = temp;
            else
                break;
        }
        if (!infile)
            break;
    }
    infile.close();
    //printGrid();
}

void Grid::drawGrid()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            switch (grid->at(i)->at(j))
            {
                case 1:
                    Utility::applySurface(j * 32, i * 32, brick);
                    break;
                case 2:
                    Utility::applySurface(j * 32, i * 32, dirt);
                    break;
                case 3:
                    Utility::applySurface(j * 32, i * 32, dirtybrick);
                    break;
                case 4:
                    Utility::applySurface(j * 32, i * 32, grass);
                    break;
                case 5:
                    Utility::applySurface(j * 32, i * 32, lava);
                    break;
                case 6:
                    Utility::applySurface(j * 32, i * 32, redcarpet);
                    break;
                case 7:
                    Utility::applySurface(j * 32, i * 32, stone);
                    break;
                case 8:
                    Utility::applySurface(j * 32, i * 32, water);
                    break;
                case 9:
                    Utility::applySurface(j * 32, i * 32, wood);
                    break;
            }
    }
}

void Grid::loadImages()
{
    brick = Utility::loadImage("resources\\tile_brick32.jpg");
    dirt = Utility::loadImage("resources\\tile_dirt32.jpg");
    dirtybrick = Utility::loadImage("resources\\tile_dirtybrick32.jpg");
    grass = Utility::loadImage("resources\\tile_grass32.jpg");
    lava = Utility::loadImage("resources\\tile_lava32.jpg");
    redcarpet = Utility::loadImage("resources\\tile_redcarpet32.jpg");
    stone = Utility::loadImage("resources\\tile_stone32.jpg");
    water = Utility::loadImage("resources\\tile_water32.jpg");
    wood = Utility::loadImage("resources\\tile_wood32.jpg");
}

void Grid::printGrid()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid->at(i)->at(j) << " ";
        }
        cout << endl;
    }
}