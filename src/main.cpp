#define build
#ifndef test

#include <cstdlib>
#include <iostream>
#include "Application.h"

using namespace std;
int main(int argc, char* args[])
{
     //Create application object
    Application* app = new Application();
    
    //Initialize SDL subsystems and sets the window caption
    if ( app -> initializeApplication() == false )
        return 1;
     
    cout<<"Running application..."<<endl;
    //Starts the actual game, beginning with the menu loop
    app -> runApplication();
    
    cout<<"Deleting application..."<<endl;
    //Clean up
    delete app;
    
    return 0;
 }
 


#endif
//--------------------------------------------------------------------------//
#ifndef build

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char * args[])
{
    if( TTF_Init() == -1 )
        return 1;
    
    int w = 0, h = 0, x = 0, y = 0, button = 0, size;
    const char* string;
    
    size = 46;
    string = "Single Player";
    button = 1;
    
    TTF_Font* font = TTF_OpenFont("resources\\Xolonium-Regular.ttf", size);

    char* mp = "Multiplayer";
    char* ed = "Editor";
    char* st = "Settings";
    char* ex = "Exit";
    vector<char*> vector;
    vector.push_back("Join Game");
    vector.push_back("Host Game");    
    
    
    for (int i = 0; i < vector.size(); i++) {
        TTF_SizeText(font, vector.at(i), &w, &h);
        x = ((500 - w) / 2) + 390;
        y = ((100 - h) / 2) + 134 + ( 100 * i );

        cout << "\"" << vector.at(i) << "\" " << "in " << size << " pt. font" << endl;
        cout << "Size: " << w << " x " << h << endl;
        cout << "Offset: (" << x << "," << y << ")" << endl<<endl<<endl;
    }
    
    return 0;
}
#endif