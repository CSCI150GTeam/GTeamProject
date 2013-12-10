#include "Projectile.h"

Projectile::Projectile() 
{
    name = "projectile";
    
    //Initialize the offsets (position of weapon)
    x = 0;
    y = 0; 
    
    //Initialize the velocity (speed or movement of weapon)
    xVel = 0;
    yVel = 0;
    
    //Load the boss image

    projectile = SDL_LoadBMP ("projectile.bmp");
    if(projectile == NULL)
        cout << "Projectile image is NULL" <<endl;
    
}

Projectile::~Projectile() 
{
    
}

