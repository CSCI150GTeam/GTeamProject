#include <cstdlib>
#include <iostream>
#include "Application.h"

using namespace std;
int main(int argc, char* args[])
{
    Application* app = new Application();
    app -> runApplication();
    delete app;
    
    return 0;
 }