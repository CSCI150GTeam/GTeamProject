/* 
 * File:   Unit.h
 * Author: JSG
 *
 * Created on November 15, 2013, 3:02 PM
 */

#include <iostream>
#include "SDL/SDL.h"
#include <string>
using namespace std;

// Unit (Global characteristics for players and enemies)
#ifndef UNIT_H
#define	UNIT_H

class Unit {
public:
    Unit();
    ~Unit();
    
private:
    int health;
    int x;
    int y;
    char* name;

};

#endif	/* UNIT_H */





