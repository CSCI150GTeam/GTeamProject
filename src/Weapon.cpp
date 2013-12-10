#include "Weapon.h"

Weapon::Weapon(int X, int Y)
{
    name = "Knife";
    damage = 5;
    
    //Initialize the offsets (position of weapon)
    x = 0;
    y = 0; 
    
    //Initialize the velocity (speed or movement of weapon)
    xVel = 0;
    yVel = 0;
    
    //Load the boss image

    weapon = SDL_LoadBMP ("knife.bmp");
    if(weapon == NULL)
        cout << "Knife image is NULL" <<endl;
    
 
    
}

Weapon::~Weapon()
{

}

void Weapon::handle_input()
{

}

void Weapon::move( std::vector<SDL_Rect> &rects )
{

}

void Weapon::show()
{

}

std::vector<SDL_Rect> &Weapon::get_rects()
{

}


