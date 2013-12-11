/* 
 * File:   MenuView.cpp
 * Author: mcnightthao
 * 
 * Created on December 9, 2013, 1:23 PM
 

#include "MenuView.h"

MenuView::MenuView(int x, int y, int w, int h) {
    
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
 
    
    
    
    
    
}



MenuView::~MenuView() {
}

void MenuView::applySurface(int x, int y, SDL_Surface* source){
    
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    //mainScreenSurface is the destination of surface 
    
    SDL_BlitSurface( source, NULL, mainScreenSurface, &offset );
    
    

}

int MenuView::MVS_handleEvents(int x, int y){
    
     // decides what to do 
    
    
    

    
}
    
    
    
    
    

    
   

void MenuView::loadImage(){
    
    
    
    
}
 * 
 * */