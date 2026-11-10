#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, n;
    char fname[100], buffer[1000];

    printf("Enter the filename to be written:\n");
    scanf("%99s", fname);

    fd = open(fname, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd == -1)
    {
        printf("Open error");
        return 1;
    }

    printf("Enter the contents to be written:\n");

    while(1)
    {
        n = read(0, buffer, sizeof(buffer));

        if(n > 0)
        {
            write(fd, buffer, n);
        }
        else if(n == 0)
        {
            break;
        }
        else
        {
            printf("Read error");
            close(fd);
            return 1;
        }
    }

    close(fd);

    printf("Contents written to %s\n", fname);

    return 0;
}
