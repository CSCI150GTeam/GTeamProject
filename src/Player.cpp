#include "Player.h"

Player::Player()
{
    health = 100;
    xVelocity = 0;
    yVelocity = 0;
    
    //Initialize the offsets (position of unit)
    x = 0;
    y = 0;
    
    
    //Initialize animation variables 
    frame = 0;
    status = PLAYER_RIGHT; //Temporarily putting boss facing to the right since I don't have an image to set position
    
    //Load the boss image
    SDL_Surface* image = player;
    player = SDL_LoadBMP ("ghost.bmp");
    if(player == NULL)
        cout << "Player image is NULL" <<endl;

}

Player::~Player()
{

}

void Player::handle_events()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( event.key.keysym.sym)
        {
            case SDLK_UP: yVel -= PLAYER_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += PLAYER_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= PLAYER_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += PLAYER_WIDTH / 2; break;
        }
    }
    
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += PLAYER_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= PLAYER_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += PLAYER_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= PLAYER_WIDTH / 2; break;
        }
    }
    
}

void Player::move()
{
    //Move the dot left or right
    x += xVel;

    //If the dot went too far to the left or right
    if( ( x < 0 ) || ( x + PLAYER_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= xVel;
    }

    //Move the dot up or down
    y += yVel;

    //If the dot went too far up or down
    if( ( y < 0 ) || ( y + PLAYER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= yVel;
    }

}

void Player::show()
{
    //Show the dot
    apply_surface( x, y, player, screen );
    
}

void Player::set_clips()
{

}

