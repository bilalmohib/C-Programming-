//Example 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int main(void)
// {
//     int pipefds[2];
//     if (pipe(pipefds) == -1)
//     {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }
//     printf("Read File Descriptor Value: %d\n", pipefds[0]);
//     printf("Write File Descriptor Value: %d\n", pipefds[1]);
//     return EXIT_SUCCESS;
// }

//Example 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    int pipefds[2];
    char buffer[5];
    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    char *pin = "4128\0";
    printf("Writing PIN to pipe...\n");
    write(pipefds[1], pin, 5);
    printf("Done.\n\n");
    printf("Reading PIN from pipe...\n");
    read(pipefds[0], buffer, 5);
    printf("Done.\n\n");
    printf("PIN from pipe: %s\n", buffer);
    return EXIT_SUCCESS;
}