#include "net.h"
#include "command.h"

command::command(int sockfd){sock= sockfd; endturn= 0;}
command::~command(){}

//for player commands
void command::push(char* cmd){
    send(sock, cmd, strlen(cmd)+1, 0);
    strcat(turn, cmd);
    endturn+= strlen(cmd)+1;
    turn[endturn]= '~'; endturn++; turn[endturn]= '\0';
}

//for other player commands
void command::take(char* cmd){
    strcat(turn, cmd);
    endturn+= strlen(cmd)+1;
    turn[endturn]= '~'; endturn++; turn[endturn]= '\0';    
}

void command::execute(){
    char* cmd; int j= 0;
    for(int i=0; i<endturn; i++){
      cmd[j]= turn[i];
      if(cmd[j]=='~'){
          cmd[j]= '\0';
          while(true){
              if(strcmp(cmd, "this")) {break;}                         
          break;}
          j= 0;
      }
    }
    endturn= 0; turn[endturn]= '\0';
}
