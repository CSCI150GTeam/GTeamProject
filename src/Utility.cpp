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

    if (loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);

        if (optimizedImage != NULL) {
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
        } else
            cout << "Error: (Utility.cpp loadImage(string) Optimized image is NULL" << endl;
    } else
        cout << "Error: (Utility.cpp loadImage(string) Loaded image is NULL" << endl;
    return optimizedImage;
}

bool Utility::checkSaveData()
{
    int temp;
    ifstream infile;
    infile.open("resources\\data_SaveGameData.txt");
    infile >> temp;
    if (infile.fail()) {
        return false;
    }
    infile.close();
    return true;
}

/* ---------------- Audio ------------------------ */

Utility::Audio::Audio()
{
    cout<<"DEBUG: (Utility.cpp) Audio constructor called."<<endl;
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
        cout << "ERROR: (Utility::Audio) Mix_OpenAudio failed to initialize" << endl;
    
    buttonPress = Mix_LoadWAV("resources\\sfx_buttonPress.wav");
    levelBegin = Mix_LoadWAV("resources\\sfx_readyGo.wav");
    levelEnd = Mix_LoadWAV("resources\\sfx_victory.wav");
    music1 = Mix_LoadMUS("resources\\sfx_music1.wav");
    
    if( buttonPress == NULL || levelBegin == NULL || levelEnd == NULL )
        cout<<"ERROR: (Utility::Audio) Sounds effects didn't load!"<<endl;
    else
        ::cout<<"DEBUG: Audio constructor finished successfully."<<endl;
}

Utility::Audio::~Audio()
{
    Mix_CloseAudio();
    
    Mix_FreeChunk(buttonPress);
    Mix_FreeChunk(levelBegin);
    Mix_FreeChunk(levelEnd);
    Mix_FreeMusic(music1);
}

void Utility::Audio::playSound(int soundName)
{
    int rValue;
    switch(soundName)
    {
        case SFX_BUTTON:
            rValue = Mix_PlayChannel(0,buttonPress,0);
            break;
        case SFX_BEGIN:
            rValue = Mix_PlayChannel(1,levelBegin,0);
            break;
        case SFX_END:
            rValue = Mix_PlayChannel(1,levelEnd,0);
            break;
    }
    cout<<"DEBUG: (Audio::playSound) Mix_PlayChannel returned "<<rValue<<endl;
}

void Utility::Audio::playMusic(int musicName)
{
    switch(musicName)
    {
        case SFX_MUS1:
            Mix_PlayMusic(music1,-1);
            break;
        default:
            break;
    }
}

/* ---------------- Text ------------------------ */

Utility::Text::Text()
{
    if (TTF_Init() == -1)
        cout << "TTF didn't inititialize" << endl;

    fontSize = 44;
    font = TTF_OpenFont("resources\\font_Xolonium-Regular.ttf", fontSize);
    color = {255, 255, 255};
}

Utility::Text::~Text()
{

}

void Utility::Text::displayText(int x, int y, char* iStr, int iSize)
{
    if (fontSize != iSize)
        font = TTF_OpenFont("resources\\font_Xolonium-Regular.ttf", iSize);
    SDL_Surface* temp = TTF_RenderText_Solid(font, iStr, color);
    Utility::applySurface(x, y, temp);
    SDL_FreeSurface(temp);
}