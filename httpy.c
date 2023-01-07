#include "httpy"

#define PORT 5555

int handle_request(){
  //handle accept request
}


int main(void){
  
  int sockfd = listeny(PORT);
  log("listening: %d\n", PORT);
  
  while(1){
    client = accept(sockfd, , );
    pthread_create(thread, null, handle_request, client);
  }
  
  close(sockfd);
  
  return 0;
}
