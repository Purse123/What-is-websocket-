#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 6969

int main() {

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket faield");
    exit(-1);
  }

  // BIND
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  // htonl -> host to network long
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // sin_addr is ip address of socket

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { // assigns an address to socket
    perror("Bind failed");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // listen
  if (listen(sockfd, 5)) {
    perror("Listening Failed");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // accept
  int client_fd;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr); // 32 bit integer

  client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
  if (client_fd < 0) {
    perror("Accept Failed");
    close(sockfd);
    exit(EXIT_FAILURE);
  }
  printf("Client Connected!\n");

  // receive from client recv()
  char buffer[1024] = {0};

  // send to client send()
  char msg[1024] = "hello from server";
  
  // multiple clients
  // 1. use multithreading or select()
  close(sockfd);
  return 0;
}
