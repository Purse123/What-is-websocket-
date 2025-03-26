#include <stdio.h>
#include <sys/socket.h>

#define PORT 6969

int main(int argc, char *argv[]) {
  if (argc != 0) {
    /* printf("Hello %s\n", argv[1]); */
    return 0;
  }

  // protocol number is defined in IANA website
  // HOPOPT = 0
  // IPv4 = 4
  // TCP = 6
  // UDP = 17
  // IPv6 = 41
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket faield");
    exit(-1);
  }

  // BIND
  /* struct in_addr sin_addr = { */
  /*   .s_addr = sizeof(addr); */
  /* }; */
  struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_port = htons(PORT),
    .sin_addr.s_addr = htonl();
  };

  bind(sockfd, &addr, sizeof(addr));

  return 0;
}
