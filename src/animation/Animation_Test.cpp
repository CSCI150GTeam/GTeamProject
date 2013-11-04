#include "Animation_Test.h"

Animation_Test::Animation_Test()
{
    this->screen = SDL_SetVideoMode(1024, 768, 32, SDL_SWSURFACE);
    if( this->screen == NULL )
        cout<<"Error: Screen didn't initialize"<<endl;
    this->loadedTileImages = new vector<SDL_Surface*>;
    //this->loadedMenuImages = new vector<SDL_Surface*>;
    this->loadTileImages();
    //this->loadMenuImages();
}

void Animation_Test::loadTileImages()
{
    loadedTileImages->push_back(load_image(GRASS));
    loadedTileImages->push_back(load_image(STONE));
    loadedTileImages->push_back(load_image(ICE));
    loadedTileImages->push_back(load_image(LAVA));
    loadedTileImages->push_back(load_image(WATER));
    loadedTileImages->push_back(load_image(WATER_DROPS));
    cout<<"Loaded "<<loadedTileImages->size()<<" tile images"<<endl;
}

void Animation_Test::loadMenuImages()
{
    //loadedMenuImages->push_back(load_image(MENU_MAIN));
    cout<<"Loaded "<<loadedMenuImages->size()<<" menu images"<<endl;
}

Animation_Test::~Animation_Test()
{
    delete loadedTileImages;
}

SDL_Surface* Animation_Test::load_image( string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
    }
    return optimizedImage;
}

void Animation_Test::apply_surface( int x, int y, SDL_Surface* source )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, this->screen, &offset );
}

void Animation_Test::drawMenuScreen(int iX, int iY)
{
    SDL_Surface* menuMain = load_image("resources\\images\\mainMenuScreen");
    apply_surface(iX,iY,menuMain);
}

bool Animation_Test::flipScreen()
{
    if( SDL_Flip( this->screen ) == -1 )
        return false;
    else return true;
}