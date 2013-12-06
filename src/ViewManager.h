/*
 * ViewManager.h - UI module
 * Code contributed by: Sammy
 * Header file
 */

#ifndef VIEW_MANAGER_H
#define	VIEW_MANAGER_H

#include <iostream>
#include <vector>
#include "UI_View.h"

const int MV_MainMenu = 0;
const int MV_SinglePlayer = 1;
const int MV_Multiplayer = 2;
const int MV_Editor = 3;
const int MV_Settings = 4;

class ViewManager
{
public:
    ViewManager();
    ~ViewManager();
    
    void handleEvents(SDL_Event);
private:
    vector<UI_View*>* views;
    int currentView;
};

#endif