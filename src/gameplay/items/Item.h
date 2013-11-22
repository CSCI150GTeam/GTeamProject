#include <iostream>
#include "SDL/SDL.h"
#include <string>
using namespace std;

// Item
#ifndef ITEM_H
#define	ITEM_H

class Item {
public:
    Item(){}
    ~Item(){}
    
private:
    string name;
    int icons[];

};


#endif	/* ITEM_H */

