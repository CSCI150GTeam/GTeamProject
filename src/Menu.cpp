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
    menuScreen_2 = load_image("resources\\menu2.png");
    menuScreen_3 = load_image("resources\\menu3.png");
    menuScreen_5 = load_image("resources\\menu5.png");
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
                return -1;
            else if (event.type == SDL_MOUSEBUTTONUP) {
                int x = event.button.x;
                int y = event.button.y;
                cout << "received click at (" << x << "," << y << ")" << endl;
                int rValue = handleEvents(x, y);
                cout << "rValue = " << rValue << endl;
                if (rValue <= MAX_GS)
                {
                    cout<<"Received game state change"<<endl;
                    return rValue;
                }
                else
                    currentView = rValue;
            }
        }
        drawScreen(currentView);
    }
}

int Menu::handleEvents(int x, int y)
{
    if (x > 390 && x < 890) {
        switch (currentView)
        {
            case MS_MAIN:
                if (y > 134 && y < 234)
                    return MS_SINGLE;
                else if (y > 234 && y < 334)
                    return MS_MULTI;
                else if (y > 334 && y < 434)
                    return MS_EDIT;
                else if (y > 434 && y < 534)
                    return MS_SET;
                else if (y > 534 && y < 634)
                    return GS_EXIT;
                else
                    return currentView;
                break;

            case MS_SINGLE:// single player 
                if (y > 134 && y < 234)
                    return GS_GAME_NEW;
                else if (y > 234 && y < 334)
                    return GS_GAME_CONT;
                else if (y > 334 && y < 434)
                    return MS_MAIN;
                else
                    return currentView;
                break;

            case MS_MULTI://multi player
                if (y > 134 && y < 234)
                    return GS_GAME_JOIN;
                else if (y > 234 && y < 334)
                    return GS_GAME_HOST;
                else if (y > 334 && y < 434)
                    return MS_MAIN;
                else
                    return currentView;

                break;

            case MS_EDIT:// edit {
                if (y > 134 && y < 234)
                    return GS_EDIT_NEW;
                else if (y > 234 && y < 334)
                    return GS_EDIT_LOAD;
                else if (y > 334 && y < 434)
                    return MS_MAIN;
                else
                    return currentView;
                break;

            case MS_SET://settings
                if (y > 134 && y < 234)
                    return MS_MAIN;
                else
                    return currentView;
                break;
        }
    } else
        return currentView;
}

void Menu::drawScreen(int)
{
    int textSize = 46;
    switch (currentView)
    {
        case MS_MAIN:
            //Buttons
            Menu_applySurface(0, 0, menuScreen_5);
            //Text
            text -> displayText(466, 158, "Single Player", textSize);
            text -> displayText(487, 258, "Multiplayer", textSize);
            text -> displayText(562, 358, "Editor", textSize);
            text -> displayText(528, 458, "Settings", textSize);
            text -> displayText(589, 558, "Exit", textSize);
            break;
        case MS_SINGLE:
            //Buttons
            Menu_applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(501, 158, "New Game", textSize);
            text -> displayText(442, 258, "Continue", textSize);
            text -> displayText(573, 358, "Back", textSize);
            break;
        case MS_MULTI:
            //Buttons
            Menu_applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(499,158, "Join Game", textSize);
            text -> displayText(495,258, "Host Game", textSize);
            text -> displayText(573,358, "Back", textSize);
            break;
        case MS_EDIT:
            //Buttons
            Menu_applySurface(0, 0, menuScreen_3);
            //Text
            text -> displayText(518, 158, "New Map", textSize);
            text -> displayText(509, 258, "Load Map", textSize);
            text -> displayText(573, 358, "Back", textSize);
            break;
        case MS_SET:
            //Buttons
            Menu_applySurface(0, 0, menuScreen_2);
            //Text
            text -> displayText(573, 158, "Back", textSize);
        default:
            break;
    }

    if (SDL_Flip(mainScreenSurface))
        cout << "SDL_Flip failed" << endl;
}

void Menu::Menu_applySurface(int x, int y, SDL_Surface* source)
{
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, NULL, mainScreenSurface, &offset);
}

SDL_Surface *Menu::load_image(std::string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());

    if (loadedImage != NULL) {

        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
        if (optimizedImage != NULL) {
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
        } else cout << "image failed to load in load_image function" << endl;
    }
    return optimizedImage;
}