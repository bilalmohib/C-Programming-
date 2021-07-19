#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048

int main(int argc, char **argv)
{
    if (argv != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = "127.0.0.1";
    int port = atoi(argv[1]);

    int option =1;
    int listenfd = 0;
    int connfd = 0;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    pthread_t tid;

    //Socket Settings
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    //Signals
    signal(SIGPIPE,SIG_IGN);

    if(setsockopt(listenfd,SOL_SOCKET,(SO_REUSEPORT | SO_REUSEADDR),(char*)&option,sizeof(option)) < 0)
    {
        printf("ERROR: setsockopt\n");
        return EXIT_FAILURE;
    }

    //Bind
    if(bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
    {
        printf("ERROR: bind\n");
        return EXIT_FAILURE;
    }

    //listen
    if(listen(listenfd,10)<0)
    {
        printf("ERROR: listen\n");
        return EXIT_FAILURE;
    }

    printf("=== WELCOME TO THE CHATROOM ===\n");

    return EXIT_SUCCESS;
}

