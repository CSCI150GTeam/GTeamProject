/* 
 * File:   UI_Buttons.h
 * Author: mcnightthao
 *
 */

#ifndef UI_BUTTONS_H
#define	UI_BUTTONS_H

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "UI_Element.h"
using namespace std; 

class UI_Buttons {
public:
    UI_Buttons();
    UI_Buttons(const UI_Buttons& orig);
    virtual ~UI_Buttons();
private:

};

#endif	/* UI_BUTTONS_H */

