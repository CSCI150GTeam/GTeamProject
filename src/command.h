/* 
 * File:   command.h
 * Author: Blaize
 *
 * Created on December 10, 2013, 12:46 AM
 */

#ifndef COMMAND_H
#define	COMMAND_H

class command{
    int sock;
    int endturn;
    char turn[200];
public:
    command(int);
    ~command();    	    
    void push(char*);
    void take(char*);
    void execute();
};

#endif	/* COMMAND_H */

