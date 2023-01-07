/*
環境
Ubuntu 20

需要先安裝
1. makefile
2. curl

執行
1. 將此程式碼複製下來,存成檔名 server.c
2. make run-server
3. curl localhost:5003
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>

#define PORT 5003
#define MAX 50000


int main(void){
  int sockfd, connfd;
  struct sockaddr_in address, client;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if( sockfd == -1 ){
    printf("socket create failed\n");
    exit(0);
  }
  else
    printf("sockfd: %d\n", sockfd);

  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(PORT);
  address.sin_family = AF_INET;
  
  int bind_result = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
  if ( bind_result == -1 ){
    printf("bind failed \n");
    exit(0);
  }
  else
    printf("bind success: %d\n", bind_result);
  
  int listen_result = listen(sockfd, 5);
  if ( listen_result == -1 ){
    printf("listen failed\n");
    exit(0);
  }
  else
    printf("listening port: %d\n",PORT);

  
  char buff[MAX];
  while(1){
    unsigned int length = sizeof(client);
    connfd = accept(sockfd, (struct sockaddr *)&client, &length);
    if (connfd == -1){
      printf("accept failed\n");
      exit(0);
    }
    else{
      printf("accept success: %d\n",connfd);
      read(connfd, buff, sizeof(buff));
      printf("[H] message:\n%s",buff);
    }

  }



  printf("hihihihihi\n");
  return 0;
}
