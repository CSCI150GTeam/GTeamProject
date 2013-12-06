#include "ViewManager.h"

ViewManager::ViewManager()
{
    currentView = 0;
}

ViewManager::~ViewManager()
{
    
}

void ViewManager::handleEvents(SDL_Event event)
{
    views->at(currentView)->handleEvents(event); 
}