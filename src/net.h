/* 
 * File:   net.h
 * Author: Blaize
 *
 * Created on December 10, 2013, 12:51 AM
 */

#ifndef NET_H
#define	NET_H

#define _WIN32_WINNT 0x0501 //assert compatible windows version
#include <winsock2.h>
#include <ws2tcpip.h>

void server();
void client(char*);

#endif	/* NET_H */

