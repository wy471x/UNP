#include <func.h>

int main(void)
{
    struct servent *sptr;
    /*
    sptr = getservbyname("domain", "udp");
    if(sptr == NULL){
        perror("getservbyname error");
        exit(1);  
    }
    printf("server name = %s\n", sptr->s_name);
    if(sptr == NULL){
        perror("getservbyname error");
        exit(1);   
    }
    sptr = getservbyname("ftp", "tcp");
    if(sptr == NULL){
        perror("getservbyname error");
        exit(1); 
    }
    printf("server name = %s\n", sptr->s_name);
    sptr = getservbyname("ftp", NULL);
    if(sptr == NULL){
        perror("getservbyname error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);
    sptr = getservbyname("ftp", "udp");
    if(sptr == NULL){
        perror("getservbyname error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);
    */

    /**
     * test example for getservbyport.
     * */

    sptr = getservbyport(htons(53), "udp");
    if(sptr == NULL){
        perror("getservbyport error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);
    sptr = getservbyport(htons(21), "tcp");
    if(sptr == NULL){
        perror("getservbyport error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);
    sptr = getservbyport(htons(21), NULL);
    if(sptr == NULL){
        perror("getservbyport error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);
    sptr = getservbyport(htons(21), "udp");
    if(sptr == NULL){
        perror("getservbyport error");
        exit(1);
    }
    printf("server name = %s\n", sptr->s_name);

    return 0;
}

