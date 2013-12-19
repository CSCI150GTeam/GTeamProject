/*
 * %<%name%>%.h - <module> module
 * Code contributed by: <names here>
 * Header file
 */

#ifndef UTILITY_H
#define	UTILITY_H

#include <iostream>
#include <fstream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "Global.h"

using namespace std;

namespace Utility
{
    void applySurface(int,int,SDL_Surface*);
    SDL_Surface* loadImage(std::string);
    bool checkSaveData();

    class Audio
    {
    public:
        Audio();
        ~Audio();
        void playSound(int);
        void playMusic(int);
    private:
        Mix_Chunk* buttonPress;
        Mix_Chunk* levelBegin;
        Mix_Chunk* levelEnd;
        Mix_Music* music1;
    };

    class Text
    {
    public:
        Text();
        ~Text();
        void displayText(int, int, char*, int);
        void displayTextCentered(SDL_Rect,char*,int);
    private:
        TTF_Font* font;
        int fontSize;
        SDL_Color color;
    };

};

extern Utility::Audio* audio;
extern Utility::Text* text;

#endif