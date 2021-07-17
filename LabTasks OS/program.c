#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t = fork();

    if(pid<0)
    {
        // Error Occured
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid==0)
    {
        // child process
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        // parent process
        // parent will wait for the child to complete
        wait(NULL);
        printf("\nChild Complete\n");
    }
    return 0;
}

