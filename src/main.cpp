/*
 * main.cpp - core module
 * Code contributed by: Sammy
 * Main file - Serves as the entry point for the program. The program is executed in four steps:
 * 1) An Application object is created
 * 2) The Application object's initializeApplication() function is called, and checked for success
 * 3) The Application object's runApplication() function is called, which executes the actual game code
 * 4) The Application object is deleted, and the main function returns 0
 */

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