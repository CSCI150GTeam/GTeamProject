#include <iostream>
#include "SDL/SDL.h"
#include <string>
using namespace std;

// Unit (Global characteristics for players and enemies)
#ifndef UNIT_H
#define	UNIT_H

class Unit {
public:
    Unit(){}
    ~Unit(){}
    
private:
    int health;
    int x;
    int y;
    char* name;

};

#endif	/* UNIT_H */





