#include "Enemy.h"

Enemy::Enemy()
{
    health = 100;
    name = "Zombie";
    
    //Initialize the offsets (position of unit)
    x = 0;
    y = 0; 
    
    //Initialize the velocity (speed or movement of unit)
    xVel = 0;
    yVel = 0;
    
    //Initialize animation variables 
    frame = 0;
    status = ENEMY_RIGHT; //Temporarily putting boss facing to the right since I don't have an image to set position
    
    //Load the boss image
    SDL_Surface* image = enemy;
    enemy = SDL_LoadBMP ("enemy.bmp");
    if(enemy == NULL)
        cout << "Enemy image is NULL" <<endl;

}

Enemy::~Enemy()
{

}

void Enemy::handle_events()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( event.key.keysym.sym)
        {
            case SDLK_UP: yVel -= ENEMY_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += ENEMY_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= ENEMY_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += ENEMY_WIDTH / 2; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += ENEMY_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= ENEMY_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += ENEMY_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= ENEMY_WIDTH / 2; break;
        }
    }
    
}

void Enemy::move()
{
    //Move the dot left or right
    x += xVel;

    //If the dot went too far to the left or right
    if( ( x < 0 ) || ( x + ENEMY_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= xVel;
    }

    //Move the dot up or down
    y += yVel;

    //If the dot went too far up or down
    if( ( y < 0 ) || ( y + ENEMY_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= yVel;
    }

}

void Enemy::show()
{
    //Show the dot
    apply_surface( x, y, enemy, screen );
    
}

void Enemy::set_clips()
{

}