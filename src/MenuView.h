/* 
 * File:   MenuView.h
 * Author: mcnightthao
 *
 * Created on December 9, 2013, 1:23 PM
 

#ifndef MENUVIEW_H
#define	MENUVIEW_H

#include "Global.h"

const int SinglePlayer ;

class MenuView {
public:
    MenuView(int x, int y, int w, int h);
    
   int MVS_handleEvents(int x, int y); 
   
    ~MenuView();
private:
    SDL_Surface *sprite ; 
    SDL_Rect box; 
    void loadImage(); 
    void applySurface(); 
    

};

#endif	/* MENUVIEW_H */

*/