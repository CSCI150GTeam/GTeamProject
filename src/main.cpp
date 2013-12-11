#include <cstdlib>
#include <iostream>

#include "Application.h"

using namespace std;

int main(int argc, char * args[])
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