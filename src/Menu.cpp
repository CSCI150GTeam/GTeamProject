/* 
 * File:   Menu.cpp
 * Author: mcnightthao
 * 
 * Created on December 9, 2013, 1:22 PM
 */

#include "Menu.h"

Menu::Menu()
{
    currentView = MS_MAIN;
    shouldDrawScreen = true;
    menuScreen_1 = Utility::loadImage("resources\\ui_menu1.png");
    menuScreen_3 = Utility::loadImage("resources\\ui_menu3.png");
    menuScreen_5 = Utility::loadImage("resources\\ui_menu5.png");
}

Menu::~Menu()
{

}

int Menu::runMenu()
{
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                return GS_EXIT;
            else if (event.type == SDL_MOUSEBUTTONUP) {
                int x = event.button.x;
                int y = event.button.y;
                int rValue = handleEvents(x, y);
                if (rValue <= MAX_GS)
                    return rValue;
                else {
                    shouldDrawScreen = true;
                    currentView = rValue;
                }
            }
        }
        if (shouldDrawScreen)
            drawScreen(currentView);
    }
}

int Menu::handleEvents(int x, int y)
{
    cout << "DEBUG: (Menu::handleEvents) currentView = " << currentView << endl;
    if (x > 390 && x < 890) {
        switch (currentView)
        {
            case MS_MAIN:
                if (y > 134 && y < 234) {
                    audio->playSound(SFX_BUTTON);
                    return MS_SINGLE;
                } else if (y > 234 && y < 334) {
                    audio->playSound(SFX_BUTTON);
                    return MS_MULTI;
                } else if (y > 334 && y < 434) {
                    audio->playSound(SFX_BUTTON);
                    return MS_EDIT;
                } else if (y > 434 && y < 534) {
                    audio->playSound(SFX_BUTTON);
                    return MS_SET;
                } else if (y > 534 && y < 634) {
                    audio->playSound(SFX_BUTTON);
                    return GS_EXIT;
                } else
                    return currentView;
                break;

            case MS_SINGLE:// single player
                if (y > 134 && y < 234) {
                    audio->playSound(SFX_BUTTON);
                    return GS_GAME_NEW;

                }
                else if (y > 234 && y < 334)
                {
                    if (Utility::checkSaveData())
                    {
                        audio->playSound(SFX_BUTTON);
                        return GS_GAME_CONT;
                    }
                    else
                        return currentView;
                    break;
                }
                else if (y > 334 && y < 434)
                {
                    audio->playSound(SFX_BUTTON);
                    return MS_MAIN;
                }
                else
                    return currentView;
                break;

            case MS_MULTI://multi player
                if (y > 134 && y < 234) {
                    audio->playSound(SFX_BUTTON);
                    return GS_GAME_JOIN;
                } else if (y > 234 && y < 334) {
                    audio->playSound(SFX_BUTTON);
                    return GS_GAME_HOST;
                } else if (y > 334 && y < 434) {
                    audio->playSound(SFX_BUTTON);
                    return MS_MAIN;
                } else
                    return currentView;

                break;

            case MS_EDIT:// edit {
                if (y > 134 && y < 234) {
                    audio->playSound(SFX_BUTTON);
                    return GS_EDIT_NEW;
                } else if (y > 234 && y < 334) {
                    audio->playSound(SFX_BUTTON);
                    return GS_EDIT_LOAD;
                } else if (y > 334 && y < 434) {
                    audio->playSound(SFX_BUTTON);
                    return MS_MAIN;
                } else
                    return currentView;
                break;

            case MS_SET://settings
                if (y > 134 && y < 234) {
                    audio->playSound(SFX_BUTTON);
                    return MS_MAIN;
                } else
                    return currentView;
                break;
        }
    } else
        return currentView;
}

void Menu::drawScreen(int)
{
    Grid* grid = new Grid("resources\\ui_menuBackground.txt");
    grid -> drawGrid();
    int textSize = 46;
    switch (currentView)
    {
        case MS_MAIN:
            //Buttons
            Utility::applySurface(0, 0, menuScreen_5);
            //Text
            text -> displayText(466, 158, "Single Player", textSize);
            text -> displayText(487, 258, "Multiplayer", textSize);
            text -> displayText(562, 358, "Editor", textSize);
            text -> displayText(528, 458, "Settings", textSize);
            text -> displayText(589, 558, "Exit", textSize);
            break;
        case MS_SINGLE:
            //Buttons
            Utility::applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(501, 158, "New Game", textSize);
            if (Utility::checkSaveData())
                text -> displayText(442, 258, "Continue", textSize);
            else
                text -> displayText(422, 258, "No Save Data", textSize);
            text -> displayText(573, 358, "Back", textSize);
            break;
        case MS_MULTI:
            //Buttons
            Utility::applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(499, 158, "Join Game", textSize);
            text -> displayText(495, 258, "Host Game", textSize);
            text -> displayText(573, 358, "Back", textSize);
            break;
        case MS_EDIT:
            //Buttons
            Utility::applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(518, 158, "New Map", textSize);
            text -> displayText(509, 258, "Load Map", textSize);
            text -> displayText(573, 358, "Back", textSize);
            break;
        case MS_SET:
            Utility::applySurface(0, 0, menuScreen_1);
            text -> displayText(573, 158, "Back", textSize);
        default:
            break;
    }

    if (SDL_Flip(mainScreenSurface))
        std::cout << "SDL_Flip failed" << endl;

    shouldDrawScreen = false;
}