#include "cliserv.h"
#include  <errno.h>
#include  <netinet/tcp.h>

int send_request(const void *request, size_t nbytes, int sendeof, const SA servptr
                 , int servsize)
{
    int sockfd, n;
    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        return (-1);
#ifdef  MSG_EOF
    n = 1;
    if(setsockopt(sockfd, IPPROTO_TCP, TCP_NOPUSH, (char *)&n, sizeof(n)) < 0){
        if(errno == ENOPROTOOPT)
            goto doconnect;
        return (-2);
    }
    if(sendto(sockfd, request, nbytes, sendeof, ? MSG_EOF : 0, servptr, servsize) 
       !=  nbytes){
        if(errno == ENOTCONN)
            goto doconnect;
        return (-3);
    }
    return (sockfd);

doconnect:
#endif

    if(connect(sockfd, servptr, servsize) < 0)
        return (-4);
    if(write(sockfd, request, nbytes) != nbytes)
        return (-5);
    if(sendeof && shutdown(sockfd, 1) < 0)
        return (-6);

    return (sockfd);
}
