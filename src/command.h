/* 
 * File:   command.h
 * Author: Blaize
 *
 * Created on December 10, 2013, 12:46 AM
 */

#ifndef COMMAND_H
#define	COMMAND_H

#include "Game.h"

class command{
    int sock;
    int endturn;
    char turn[200];
    Game *gp;
public:
    command(int, Game*);
    ~command();    	    
    void push(char*);
    void take();
    void execute();
};

#endif	/* COMMAND_H */

