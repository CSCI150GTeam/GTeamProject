#include "Item.h"
#include <string>
using namespace std;

#ifndef FIRSTAID_H
#define	FIRSTAID_H

class FirstAid : public Item {
public:
    FirstAid();
    ~FirstAid();
    
private:
    int health;

};

#endif	/* FIRSTAID_H */

