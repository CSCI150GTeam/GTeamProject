#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include <vector>
using namespace std;

#ifndef PROJECTILE_H
#define	PROJECTILE_H

class Projectile {
public:
    Projectile();
    ~Projectile();
    
    void update();
    void draw();
private:
};

#endif