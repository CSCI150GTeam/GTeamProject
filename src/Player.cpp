#include "Player.h"

Player::Player()
{
    //Initialize movement variables
    health = 100;
    x = 0;
    y = 0;
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    frame = 0;
    status = PLAYER_RIGHT;
    
    
    //Load the sprite sheet
    player_sprite_up = load_image( "player_sprite_up.png" );   // move up
    player_sprite_right = load_image( "player_sprite_right.png" ); // move right
    player_sprite_down = load_image( "player_sprite_down.png" ); // move down
    player_sprite_left = load_image( "player_sprite_left.png" ); // move left
    
}

Player::~Player()
{
    //Free the surface
    SDL_FreeSurface( player_sprite_up );
    SDL_FreeSurface( player_sprite_right );
    SDL_FreeSurface( player_sprite_down );
    SDL_FreeSurface( player_sprite_left );

}

SDL_Surface* Player::load_image( string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void Player::apply_surface( int x, int y, SDL_Surface* source, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, mainScreenSurface, &offset );
}

void Player::set_clips()
{
    //Clip the sprites Right move
    clipsRight[ 0 ].x = 0;
    clipsRight[ 0 ].y = 0;
    clipsRight[ 0 ].w = PLAYER_WIDTH;
    clipsRight[ 0 ].h = PLAYER_HEIGHT;

    clipsRight[ 1 ].x = PLAYER_WIDTH;
    clipsRight[ 1 ].y = 0;
    clipsRight[ 1 ].w = PLAYER_WIDTH;
    clipsRight[ 1 ].h = PLAYER_HEIGHT;

    clipsRight[ 2 ].x = PLAYER_WIDTH * 2;
    clipsRight[ 2 ].y = 0;
    clipsRight[ 2 ].w = PLAYER_WIDTH;
    clipsRight[ 2 ].h = PLAYER_HEIGHT;
    
   //Clip the sprites Left move
    
    clipsLeft[ 0 ].x = 0;
    clipsLeft[ 0 ].y = 0;
    clipsLeft[ 0 ].w = PLAYER_WIDTH;
    clipsLeft[ 0 ].h = PLAYER_HEIGHT;

    clipsLeft[ 1 ].x = PLAYER_WIDTH;
    clipsLeft[ 1 ].y = 0;
    clipsLeft[ 1 ].w = PLAYER_WIDTH;
    clipsLeft[ 1 ].h = PLAYER_HEIGHT;

    clipsLeft[ 2 ].x = PLAYER_WIDTH * 2;
    clipsLeft[ 2 ].y = 0;
    clipsLeft[ 2 ].w = PLAYER_WIDTH;
    clipsLeft[ 2 ].h = PLAYER_HEIGHT;
    
    //Clip the sprites Down move
    
    clipsDown[ 0 ].x = 0;
    clipsDown[ 0 ].y = 0;
    clipsDown[ 0 ].w = PLAYER_WIDTH;
    clipsDown[ 0 ].h = PLAYER_HEIGHT;

    clipsDown[ 1 ].x = PLAYER_WIDTH;
    clipsDown[ 1 ].y = 0;
    clipsDown[ 1 ].w = PLAYER_WIDTH;
    clipsDown[ 1 ].h = PLAYER_HEIGHT;

    clipsDown[ 2 ].x = PLAYER_WIDTH * 2;
    clipsDown[ 2 ].y = 0;
    clipsDown[ 2 ].w = PLAYER_WIDTH;
    clipsDown[ 2 ].h = PLAYER_HEIGHT;
    //Clip the sprites Up move
    
    clipsUp[ 0 ].x = 0;
    clipsUp[ 0 ].y = 0;
    clipsUp[ 0 ].w = PLAYER_WIDTH;
    clipsUp[ 0 ].h = PLAYER_HEIGHT;

    clipsUp[ 1 ].x = PLAYER_WIDTH;
    clipsUp[ 1 ].y = 0;
    clipsUp[ 1 ].w = PLAYER_WIDTH;
    clipsUp[ 1 ].h = PLAYER_HEIGHT;

    clipsUp[ 2 ].x = PLAYER_WIDTH * 2;
    clipsUp[ 2 ].y = 0;
    clipsUp[ 2 ].w = PLAYER_WIDTH;
    clipsUp[ 2 ].h = PLAYER_HEIGHT;
}

void Player::update()
{
   
}

void Player::draw()
{
    
}