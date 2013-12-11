/* 
 * File:   Menu.cpp
 * Author: mcnightthao
 * 
 * Created on December 9, 2013, 1:22 PM
 */

#include "Menu.h"
#include "Application.h"

Menu::Menu(int x, int y, int w, int h) {
       
    box.x = x; 
    box.y = y; 
    box.w = w; 
    box.h = h; 


}

Menu::Menu() {
}

Menu::~Menu() {
}



int Menu::MS_handleEvents(){
    
    int x; 
    int y; 
    
     if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
       if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;
//( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h )
            //If the mouse clicked the singlep button
            if(( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ))
            {
                //Set the button sprite
                 
              //apply_surface( 0, 0, singlep , screen );  
                 
                 
                
                
                
                          
            }
       }
     }
    
    
    
    
    
    
    
}