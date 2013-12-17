#include "Utility.h"

Utility::Audio* audio = new Utility::Audio();
Utility::Text* text = new Utility::Text();

void Utility::applySurface(int x, int y, SDL_Surface* source)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, NULL, mainScreenSurface, &offset);
}

SDL_Surface* Utility::loadImage(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = IMG_Load(filename.c_str());
    
    if (loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
        
        if (optimizedImage != NULL)
        {
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
        }
        else
            cout << "Error: (Utility.cpp loadImage(string) Optimized image is NULL" << endl;
    }
    else
        cout << "Error: (Utility.cpp loadImage(string) Loaded image is NULL" << endl;
    return optimizedImage;
}

bool Utility::checkSaveData()
{
    int temp;
    ifstream infile;
    infile.open("resources\\SaveGameData.txt");
    infile >> temp;
    if ( infile.fail() )
    {
        return false;
    }
    infile.close();
    return true;
}

Utility::Audio::Audio()
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        cout << "Audio didn't open" << endl;
    loadSounds();
}

Utility::Audio::~Audio()
{
    Mix_FreeChunk(soundEffect1);
    Mix_FreeMusic(music1);
    Mix_CloseAudio;
}

void Utility::Audio::playSound(string filename)
{
    if (filename == "soundEffect1") {
        cout << "playing SE1" << endl;
        if (Mix_PlayChannel(-1, soundEffect1, -1) == -1)
            cout << "Error in playing sound" << endl;
    }

    if (filename == "music1") {
        cout << "playing M1" << endl;
        if (Mix_PlayMusic(music1, -1) == -1)
            cout << "Error in playing sound" << endl;
    }
}

bool Utility::Audio::loadSounds()
{
    soundEffect1 = Mix_LoadWAV("resources\\high.wav");
    if (soundEffect1 == NULL)
        cout << "Sound effect 1 is Null" << endl;

    music1 = Mix_LoadMUS("resources\\adventuring_song.mp3");
    if (music1 == NULL)
        cout << "Music 1 is Null" << endl;
    return true;
}

Utility::Text::Text()
{
    if (TTF_Init() == -1)
        cout << "TTF didn't inititialize" << endl;

    fontSize = 44;
    font = TTF_OpenFont("resources\\Xolonium-Regular.ttf", fontSize);
    color = {255, 255, 255};
}

Utility::Text::~Text()
{

}

void Utility::Text::displayText(int x, int y, char* iStr, int iSize)
{
    if (fontSize != iSize)
        font = TTF_OpenFont("resources\\Xolonium-Regular.ttf", iSize);
    SDL_Surface* temp = TTF_RenderText_Solid(font, iStr, color);
    Utility::applySurface(x, y, temp);
    SDL_FreeSurface(temp);
}