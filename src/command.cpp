#include "net.h"
#include "command.h"
/*

command::command(int sockfd, Game *gameID){sock= sockfd; endturn= 0; gp= gameID;}
command::~command(){}

//for player commands
void command::push(char* cmd){
    send(sock, cmd, strlen(cmd)+1, 0);
    strcat(turn, cmd);
    endturn+= strlen(cmd)+1;
    if(gp->playerUno) turn[endturn]= '~';
    else turn[endturn]= '$';
    endturn++; turn[endturn]= '\0';
}

//for other player commands
void command::take(){
    char cmd[16];
    recv(sock, cmd, 16, 0);
    strcat(turn, cmd);
    endturn+= strlen(cmd)+1;
    turn[endturn]= '~'; endturn++; turn[endturn]= '\0';    
}

//need to change player 1 detection now
void command::execute(){
    char cmd[16]; int j= 0;
    for(int i=0; i<endturn; i++){
      cmd[j]= turn[i];
      if(cmd[j]=='~'){
          cmd[j]= '\0';
          if(strcmp(cmd, "goUp")){
              gp->currentLevel->getPlayer(1)->setYVel(-16);                                                
          break;}
          else if(strcmp(cmd, "goDown")){
              gp->currentLevel->getPlayer(1)->setYVel(+16);                  
          break;}
          else if(strcmp(cmd, "goLeft")){
              gp->currentLevel->getPlayer(1)->setXVel(-16);                  
          break;}
          else if(strcmp(cmd, "goRight")){
              gp->currentLevel->getPlayer(1)->setXVel(+16);
          break;}
          else if(strcmp(cmd, "stopVert")){
              gp->currentLevel->getPlayer(1)->setYVel(0);
          break;}
          else if(strcmp(cmd, "stopHorz")){
              gp->currentLevel->getPlayer(1)->setXVel(0);
          break;}          
          j= 0;
      }
      else if(cmd[j]=='$'){
          cmd[j]= '\0';
          if(strcmp(cmd, "goUp")){
              gp->currentLevel->getPlayer(2)->setYVel(-16);                                                
          break;}
          else if(strcmp(cmd, "goDown")){
              gp->currentLevel->getPlayer(2)->setYVel(+16);                  
          break;}
          else if(strcmp(cmd, "goLeft")){
              gp->currentLevel->getPlayer(2)->setXVel(-16);                  
          break;}
          else if(strcmp(cmd, "goRight")){
              gp->currentLevel->getPlayer(2)->setXVel(+16);
          break;}
          else if(strcmp(cmd, "stopVert")){
              gp->currentLevel->getPlayer(2)->setYVel(0);
          break;}
          else if(strcmp(cmd, "stopHorz")){
              gp->currentLevel->getPlayer(2)->setXVel(0);
          break;}          
          j= 0;
      }
    }
    endturn= 0; turn[endturn]= '\0';
}
*/