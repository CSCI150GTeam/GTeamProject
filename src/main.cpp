#include <cstdlib>
#include <iostream>
#include "Application.h"

int main(int argc, char* args[])
{
    Application* app = new Application();
    app -> runApplication();
    delete app;
    
    return 0;
 }