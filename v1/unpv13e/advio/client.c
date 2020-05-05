#include "cliserv.h"

int main(int argc, char *argv[])
{
    struct sockaddr_in serv;
    char request[REQUEST], reply[REPLY];
    int sockfd, n;

    if(argc != 3)
        err_quit("usage: client <IP address of serv> <port#>");

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(argv[1]);
    serv.sin_port = htons(atoi(argv[2]));


    if(fgets(request, sizeof(request), stdin) == NULL)
         err_quit("fgets error");
    if((sockfd = send_request(request, REQUEST, 1, (SA)&serv, sizeof(serv))) < 0)
        err_sys("send_request error %d", sockfd);

    if((n = read_stream(sockfd, reply, REPLY)) < 0)
        err_sys("read error");
    fputs(reply, stdout);

    exit(0);
}
