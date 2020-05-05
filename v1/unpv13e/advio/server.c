#include "cliserv.h"

int main(int argc, char *argv[])
{
    struct sockaddr_in serv, cli;
    char request[REQUEST], reply[REPLY];
    int listenfd, sockfd, n, clilen;

    if(argc != 2)
        err_quit("usage: server <port#>");

    if((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(atoi(argv[1]));

    if(bind(listenfd, (SA)&serv, sizeof(serv)) < 0)
        err_sys("bind error");

    if(listen(listenfd, SOMAXCONN) < 0)
        err_sys("listen error");

    for(;;){
        clilen = sizeof(cli);
        if((sockfd = accept(listenfd, (SA) &cli, &clilen)) < 0)
            err_sys("accept error");
        if((n = read_stream(sockfd, request, REQUEST)) < 0)
            err_sys("read error");

        memcpy(reply, request, sizeof request);

#ifndef MSG_EOF
#define MSG_EOF 0
#endif
        if(send(sockfd, reply, REPLY, MSG_EOF) != REPLY)
            err_sys("send error");
        close(sockfd);
    }
}
