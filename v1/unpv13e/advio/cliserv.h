#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define REQUEST 400
#define REPLY   400

#define UDP_SERV_PORT   7777
#define TCP_SERV_PORT   8888
#define TTCP_SERV_PORT  9999

#define MAXLINE 4096

#define SA struct sockaddr *

void err_quit(const char *, ...);
void err_sys(const char *, ...);
int read_stream(int, char *, int);
int send_request(const void *, size_t, int, const SA, int);
