### Types of sockets:
- Stream sockets (SOCK_STREAM) → Used for TCP communication.
- Datagram sockets (SOCK_DGRAM) → Used for UDP communication.
- Raw sockets (SOCK_RAW) → Used for custom protocol implementation.

### Proces
1. Socket Creation
```c
int socket(int domain, int type, int protocol);
```
- domain: AF_INET (IPv4), AF_INET6 (IPv6)
- type: SOCK_STREAM (TCP), SOCK_DGRAM (UDP)
- protocol: Usually 0 (default for TCP/UDP)

2. Bind socket
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
- Associates the socket with an IP and port.

3. Listen for connection (server only)
```c
int listen(int sockfd, int backlog);
```
- places socket in a passive state, ready to accept connection

4. accept connection (sever only)
```c
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
- accept a connection req from clinet

5. Connecting to a server (client only)
```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
- used by client to establish a connection with a server.

6. Sending and Receving data
- TCP
```c
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```
- UDP
```c
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen);
```

7. Closing a socket
```c
int close(int sockfd);
```

## Handling Multiple Clients
For handling multiple clients, you can use:
- Fork-based approach (fork())
- Threads (pthread)
- Multiplexing with select(), poll(), epoll()

## Topic list
- Asynchronous (non-blocking) sockets using fcntl()
- TLS/SSL encryption (OpenSSL)
- Interprocess Communication (IPC) using sockets
- Load balancing and scalability
- IPv6 compatibility (AF_INET6)
- Raw sockets (SOCK_RAW) for custom protocols

## TODO Project
1. Basic TCP/UDP Client-Server
2. Multi-client Chat Server
3. File Transfer Over Sockets
3. HTTP Web Server
4. Custom Protocol using Raw Sockets
5. Implementing a Proxy Server
6. Building an SSH-like Encrypted Socket Communication
